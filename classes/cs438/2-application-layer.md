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



### 2.1.6 - Network Applications Covered in this Book



## 2.2 - The Web and HTTP

### 2.2.1 - Overview of HTTP



### 2.2.2 - Non-Persistent and Persistent Connections



### 2.2.3 - HTTP Message Format



### 2.2.4 - User-Server Interaction: Cookies



### 2.2.5 - Web Caching



### 2.2.6 - HTTP/2



## 2.3 - Electronic Mail in the Internet

### 2.3.1 - SMTP



### 2.3.2 - Mail Message Formats



### 2.3.3 - Mail Access Protocols



## 2.4 - DNS: The Internet's Directory Service

### 2.4.1 - Services Provided by DNS



### 2.4.2 - Overview of How DNS Works



### 2.4.3 - DNS Records and Messages



## 2.5 - Peer-to-Peer File Distribution



## 2.6 - Video Streaming and Content Distribution Networks

### 2.6.1 - Internet Video



### 2.6.2 - HTTP Streaming and DASH



### 2.6.3 - Content Distribution Networks



### 2.6.4 - Case Studies: Netflix and YouTube



## 2.7 - Socket Programming: Creating Network Applications

### 2.7.1 - Socket Programming with UDP



### 2.7.2 - Socket Programming with TCP


