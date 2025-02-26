# 2 - Application Layer

## 2.1 - Principles of Network Applications

### 2.1.1 - Network Application Architectures

The **application architecture** is defined by the application developer for a system (as opposed to the network architecture which is determined by hardware).
- In a **client-server** architecture, there is an always-on host, called the *server*, which services requests from many other hosts, called *clients*. The server is available at all times through its IP address.
  - Examples include web servers, FTP, and email.
  - Large applications cannot be handled by a single host, so large **data centers** house many hosts to service clients.
- In a **peer-to-peer (P2P) architecture**, hosts, called **peers** in this context, communicate directly with one another.
  - Examples include BitTorrent.
  - P2P applications are **self-scalable**, but the main concerns include security, performance, and reliability.

### 2.1.2 - Processes Communicating

Instead of thinking about how programs communicate with each other, we must understand that it is **processes** on different hosts that interact with one another. They communicate with each other through **messages** across the computer network.
- We typically call assign these processes the titles client and server, but this can get muddled in P2P architecture.

A process sends and receives messages through a software interface called a **socket**. A socket is also commonly referred to as an **Application Programming Interface (API)** between the application and the network.

In the Internet, the host is identified by its **IP address**, which is a 32-bit unique identifier. A destination **port number** can be used to identify where to look for a certain application running on the host, since the host can run multiple network applications. For example, a web server is identified by port 80 and an email (SMTP) server is identified by port 25.

### 2.1.3 - Transport Services Available to Applications

The socket is the interface between the application process and the transport-layer protocol. On the sending side, the application pushes messages through the socket. On the receiving sidde, the transport-layer protocol has the responsibility of getting the messages to the socket of the receiving process.

There are a variety of transport-layer protocols available, and the following are some of the factors that go into considering which to use:
- *Reliable Data Transfer*: If a protocol provides a guaranteed data delivery service, it is said to provide **reliable data transfer**. This may not be needed in **loss-tolerant applications**.
- *Throughput*: Some applications may need to guarantee a certain throughput/transfer rate. Such applications that have throughput requirements are called **bandwidth-sensitive applications**. Alternatively, **elastic applications** can make use of as much or as little throughput as happens to be available.
- *Timing*: A transport-layer protocol can provide timing guarantees. For example, there might be a guarantee that the receiver socket receives a message within 100 ms of the sender socket sending it.
- *Security*: A transport protocol can manage encryption, data integrity, and end-point authentication.

### 2.1.4 - Transport Services Provided by the Internet

The Internet make the TCP and UDP transport-level protocols available for applications.
- **Transmission Control Protocol (TCP)** is a connection-oriented reliable data transfer service.
  - TCP has the client and server exchange transport-layer control information with each other before the application-level messages flow. After the handshake, a **TCP connection** is said to exist between the sockets of the two processes. This connection is a full-duplex connection, meaning both sockets can send each other messages over this connection at the same time. The connection must be closed when the sockets are done sending messages.
  - The communicating processes can rely on TCP to deliver all data sent without error and in the proper order.
  - TCP also has a congestion-control mechanism that attempts to limit each connection to its fair share of bandwidth.
- **User Datagram Protocol (UDP)** is a lightweight transfer protocol that is connectionless and provides unreliable data transfer.

### 2.1.5 - Application-Layer Protocols

An **application-layer protocol** defines how an application's processes, running on different end systems, pass messages to each other.

Some application-layer protocols are in the public domain, such as HTTP, while others are proprietary, such as Skype.

It is important to note that application-layer protocols are only one part of network applications. For example, the Web is made up of web servers, standard document formats (HTML), and a application-layer protocols (HTTP/HTTPS).

## 2.2 - The Web and HTTP

### 2.2.1 - Overview of HTTP

The **HyperText Transfer Protocol (HTTP)** is the Web's application-layer protocol and is implemented in a client program and a server program. HTTP defines the structure of the messages sent between these two programs.

The HTTP client first initiates a TCP connection with the server. Once the connection is established, the client and server access TCP through their client interfaces. Note that it is the job of TCP to ensure that each message arrives intact.

HTTP is said to be a **stateless protocol** because it does not store any information about the client. Instead, it just returns whatever resource is requested.

The original version of HTTP was HTTP/1.0, but the majority of requests today use HTTP/1.1. Some browsers and servers have begun to use HTTP/2.0.

### 2.2.2 - Non-Persistent and Persistent Connections

In many Internet applications, the client and server communicate for an extended period of time. When these sorts of client-server interactions occur over TCP, the application developer must decide whether to send each request/response pair over the same **persistent connection** or to close and re-establish **non-persistent connections**. HTTP uses persistent connections in its default mode, but can be configured to use non-persistent connections.

#### HTTP with Non-Persistent Connections

Let's consider a web page that consists of a base HTML file and 10 JPEG images, totally to 11 objects. Suppose the URL of the HTML file is `http://www.someSchool.edu/someDepartment/home.index`.

1. The client process initiates a TCP connection with the server `www.someSchool.edu` at port 80, which is the default for HTTP. Sockets associated with the client and server are created.
2. The client process sends an HTTP request to the server via its socket. This message includes the path `/someDepartment/home.index`.
3. The server process receives the request message, retrieves the the object `/someDepartment/home.index` from its storage (RAM or disk), encapsulates the object in an HTTP response message, and sends the response message to the client.
4. The server process tells TCP to close the connection.
5. The client receives the response message. The TCP connection terminates. The client extracts the HTML file from the response and finds referrences to the 10 JPEG images.
6. The first 4 steps are repeated for each image.

The **round-trip time (RTT)** is the time it takes for a small packet to travel from the client to the server and back to the client.

It takes two RTTs plus the transmission time at the server to complete the "three-way handshake." The client first sends a small TCP segment to the server, which the server acknowledges with a response. This takes one RTT. The client then sends the request for the object and receives it in the response, composing the second RTT.

#### HTTP with Persistent Connections

With HTTP/1.1 persistent connections, a request to close the connection is not sent along with the results. This leaves the connection open for a configurable amount of time, allowing resources and other web pages from the same server to be sent over the same connection, reducing the overhead of establishing more TCP connections.

### 2.2.3 - HTTP Message Format

The HTTP specifications include the definitions of the HTTP message formats.

#### HTTP Request Message

Below is the typical HTTP request message:

```
GET /somedir/page.html HTTP/1.1
Host: www.someschool.edu
Connection: close
User-agent: Mozilla/5.0
Accept-language: fr
```

The first line of the request is called the **request line**, and the subsequent lines are called **header lines**.
- The `Connection: close` line indicates that there will be a non-persistent connection.
- The server can handle different `User-agent`s differently (e.g. sending different data to different browsers).
- The `Accept-language` header is one many content negotiation headers available in HTTP.

The entity body of a GET request is empty, but it may be populated when using a POST method.

The HEAD method can be used to retrieve only an HTTP response with no object. The PUT method can be used to upload objects to web servers. The DELETE method can be used to delete an object on a web server. 

#### HTTP Response Message

```
HTTP/1.1 200 OK
Connection: close
Date: Tue, 18 Aug 2015 12:44:04 GMT
Server: Apache/2.2.3 (CentOS)
Last-Modified: Tue, 18 Aug 2015 15:11:03 GMT
Content-Length: 6821
Content-Type: text/html
(data data data data data ...)
```

The response has a **status line**, six **header lines**, and an **entity body**.

Some common response codes include:
- `200 OK`: Request succeeded and info is returned in response.
- `301 Moved Permanently`: Requested object has been moved permanently, and the new URL is available in the `Location` response header. Web browsers should automatically go to this new site.
- `400 Bad Request`: A generic error code indicating the request cannot be understood by the server.
- `404 Not Found`: Requested document does not exist on the server.
- `505 HTTP Version Not Supported`: Requested HTTP protocol version is not supported by the server.

### 2.2.4 - User-Server Interaction: Cookies

Cookies allow sites to keep track of users despite HTTP being a stateless protocol. Cookie technology has 4 components:
1. A cookie header (`Set-cookie`) in the HTTP response.
2. A cookie header (`Cookie`) in the HTTP request.
3. A cookie file on the client managed by the browser.
4. A back-end database at the website.

### 2.2.5 - Web Caching

A **web cache**, also called a **proxy server**, is a network entity that keeps copies of recently requested objects in its storage. A browser can be configured so that all of the user's HTTP requests are first directed toward the web cache. If this is set up, then this is what happens when a browser sends a request using caching:
1. The browser establishes a TCP connection to the cache and sends an HTTP request for the object to the cache.
2. The cache checks to see if it has a copy of the object stored locally. If it does, the web cache returns the object within an HTTP response message to the client browser.
3. If the object is not in the cache, the cache opens a TCP connection to the origin server. The cache then sends an HTTP request for the object.
4. The cache stores a copy of the object and sends a copy to the client browser in an HTTP response.

A web cache is typically configured by an ISP. An enterprise network may also set up an inexpensive web cache using open-source software.

A **conditional GET** request can be used to determine if the object in the cache is stale using the `If-Modified-Since` header. When a web cache sends a request to the origin server with this header, the server will only return the object if the object has been modified more recently than the data given. Otherwise, it returns `304 Not Modified`.

### 2.2.6 - HTTP/2

HTTP/2 allows browsers to multiplex multiple requests for resources, allowing parallel HTTP requests over the same TCP connection. This helps prevent the **Head of Line (HOL) blocking** problem, since a large object does not delay future requests over a persistent connection (multiple TCP connections would otherwise be required).

## 2.3 - Electronic Mail in the Internet

The 3 main components of email are **user agents**, **mail servers**, and the **Simple Mail Transfer Protocol (SMTP)**.

### 2.3.1 - SMTP

SMTP is older than HTTP and has certain archaic characteristics as a result. Notably, the body of SMTP messages is confined to 7-bit ASCII characters, requiring binary data to be encoded as ASCII when it is sent and received.

Here is an example involving a simple ASCII message:
1. The user provides a user agent for his email and an email address for the recipient. The user composes a message and instructs the user agent to send a message.
2. The user agent sends the message to the sender's email server, where it is placed in the message queue.
3. The SMTP client opens a TCP connection with the recipient's mail server. This uses **port 25**, which is the default for SMTP.
4. After an SMTP handshake, the client sends the message over the TCP connection.
5. The recipient mail server receives the message and places it in the recipient's mailbox.
6. The recipient invokes his user agent to read the message.

### 2.3.2 - Mail Message Formats

The response begins with the headers, and then a blank line (`CRLF`/`\r\n`) separates the headers from the returned data. Every SMTP message must have the following headers: `From`, `To`, and `Subject`.

```
From: user@mtmoen.com
To: user2@gmail.com
Subject: Pondering the implications of fried rice
```

### 2.3.3 - Mail Access Protocols

Email infrastructure requires a server that is always on to receive messages. The sender's mail server also sends requests to the receiver's mail server so that it can resend requests if the receiver's mail server is unavailable.

There are two ways that a user can retrieve their emails from the mail server:
- Using HTTP, which is how Gmail works.
- Using the **Internet Mail Access Protocol (IMAP)**, which is what Outlook uses.

## 2.4 - DNS: The Internet's Directory Service

A **hostname** is a generally human-readable alias for locations on the Internet.

An **IP address** is a unique ID for hosts on the Internet. It consists of 4 numbers in the range from 0 to 255 separated by periods (e.g. 121.7.106.83).

### 2.4.1 - Services Provided by DNS

The **domain name service (DNS)** translates hostnames to IP addresses. DNS is a distributed database implemented in a hierarchy of **DNS servers** and an application-layer protocol that allows hosts to query the distributed database.
- The DNS servers are typically UNIX machines running the Berkeley Internet Name Domain (BIND) software.
- The DNS protocol runs over UDP and uses port 53.

In order to find the IP address associated with a domain name,
1. The user runs the client side of the DNS application.
2. The browser extracts the hostname from the URL and passes the hostname to the client side DNS application.
3. The DNS client client sends a query containing the hostname to a DNS server.
4. The DNS client receives a reply, which includes the IP address for the given hostname.

DNS lookup adds an additional delay, but common IP addresses are often cached to avoid this, reducing DNS network traffic and average DNS delay.

DNS provides a few other services:
- **Host aliasing**: A long hostname could have aliases, where the original hostname is called the **canonical hostname**.
- **Mail server aliasing**: Aliasing for email address domains.
- **Load distribution**: Busy sites can be replicated over multiple servers to reduce load on each server.

### 2.4.2 - Overview of How DNS Works

All DNS query and reply messages are sent within UDP datagrams to port 53.

There are 3 classes of DNS servers in the DNS hierarchy:
- **Root DNS servers**: There are over 1000 root server instances that are copies of 13 different root servers. They contain IP addresses of TLDs.
- **Top-level domain (TLD) servers**: Top-level domain servers are managed by various companies, and include things like com, gov, edu, us, and more. These servers manage the IP addresses for the authoritative servers.
- **Authoritative DNS servers**: Organizations with publicly accessible hosts have authoritative hosts to manage their DNS records. These are often handled by a third-party company.

Each ISP has a **local DNS server**, which receives outgoing DNS queries from a user and sends them on through the DNS hierarchy. The query from the client to the local DNS server is an **recursive query**, but the local DNS server typically sends **iterative queries** to root DNS, the TLD server, and the authoritative DNS server. **DNS caching** on this server reduces traffic.

### 2.4.3 - DNS Records and Messages

The DNS servers store **resource records (RRs)** to implement DNS lookup. An RR is a four-tuple that contains the following fields: `(Name, Value, Type, TTL)`. `TTL` specifies when a resource should be removed from a cache, and it is largely ignored for our purposes. The meaning of `Name` and `Value` depend on the `Type`:
- If `Type=A`, then `Name` is a hostname and `Value` is the IP address for the hostname. For example, `(relay1.bar.foo.com, 145.37.93.126, A)`.
- If `Type=NS`, then `Name` is a domain and `Value` is the hostname of an authoritative DNS server that knows how to obtain the IP addresses for hosts in the domain.
- If `Type=CNAME`, then `Value` is a canonical hostname for the alias hostname `Name`.
- If `Type=MX`, then `Value` is the canonical name of a mail server that has an alias hostname `Name`. For example, `(foo.com, mail.bar.foo.com, MX)`.

If a DNS server is authoritative for a particular hostname, then the DNS server will contain a Type A record for the hostname. If it is not authoritative for a hostname, it will contain a Type NS record for the domain that includes the hostname. Consider the edu TLD server when resolving `gaia.cs.umass.edu`. We would expect it to contain both `(umass.edu, dns.umass.edu, NX)` and `(dns.umass.edu, 128.119.40.111, A)`.

#### DNS Messages

Both query and reply messages have the same format:
- The first 12 bytes is the *header section* that contain various bits of metadata.
- The *question section* contains the `Name` and `Type` fields of the query.
- In a reply, the *answer section* contains the resource records for the name that was originally queried. Multiple RRs can be returned in a single query.
- The **authority section* contains records of other authoritative servers.
- The *additional section* contains other helpful records. For example, the answer section in an MX request might contain the canonical name of the mail server while this section includes the Type A record containing the IP address.

#### Inserting Records into the DNS Database

A **registrar** is a commercial entity that verifies the uniqueness of the domain name, enters the domain name into the DNS database, and collects a small fee for these services. The Internet Corporation for Assigned Names and Numbers (ICANN) accredits the various registrars. The registrar ensures that a Type NS and a Type A record are added to the TLD servers.

## 2.5 - Peer-to-Peer File Distribution



## 2.6 - Video Streaming and Content Distribution Networks

### 2.6.1 - Internet Video



### 2.6.2 - HTTP Streaming and DASH



### 2.6.3 - Content Distribution Networks



### 2.6.4 - Case Studies: Netflix and YouTube



## 2.7 - Socket Programming: Creating Network Applications

### 2.7.1 - Socket Programming with UDP



### 2.7.2 - Socket Programming with TCP


