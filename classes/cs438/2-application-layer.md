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



### 2.1.4 - Transport Services Provided by the Internet



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


