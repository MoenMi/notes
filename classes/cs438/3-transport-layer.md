# 3 - Transport Layer

## 3.1 - Introduction and Transport-Layer Services

The transport layer provides for **logical communication** between application processes running on different hosts, meaning that the application processes seem to be directly connected when using them.

On the sending side, the transport layer converts the application-layer messages it receives into transport-layer packets, known as **segments** at this level.

### 3.1.1 - Relationship between Transport and Network Layers

A transport-layer protocol provides logical communication between processes, and a network-layer protocol provides logical communication between hosts.

### 3.1.2 - Overview of the Transport Layer and the Internet

The Internet's network layer protocol, which is used to implement TCP and UDP, is the **Internet Protocol (IP)**. IP makes its best effort to deliver segments between hosts, but it makes no guarantees. It is thus unreliable.

Extending host-to-host delivery to process-to-process delivery is called transport-layer multiplexing and demultiplexing.

## 3.2 - Multiplexing and Demultiplexing

The job of delivering the data in a transport-layer segment to the correct socket using a set of fields in the segment is called **demultiplexing**.

The job of gathering data chunks at the source host from different sockets, encapsulating each data chunk in header info to create segments, and passing the header info to the network layer is called **multiplexing**.

The first headers required for multiplexing and demultiplexing are the source port number and destination port number. Port numbers range from 0 to 65535, and ports 0 to 1023 are **well-known port numbers** that are restricted to well-known application protocols.

#### Connectionless Multiplexing and Demultiplexing

When the `bind()` method binds a socket to a port in Python's `socket` library, it is either assigned to a specified port or automatically assigned to an open port.

In UDP, the transport layer on each communicating host uses the source and destination port numbers to figure out where to send the request and response.

#### Connection-Oriented Multiplexing and Demultiplexing

TCP sockets require the source and destination IP addresses in addition to the source and destination port numbers. The TCP server then uses this data to create a new socket at a new port for each incoming connection, different than how UDP handles incoming requests.

#### Web Servers and TCP

To handle multiple TCP connections at one time, web servers typically create a new thread to handle each TCP connection, while only one process on one port handles incoming connections.

## 3.3 - Connectionless Transport: UDP

UDP provides few services not provided from IP, adding only the source and destination port numbers and some light error checking.

UDP offers a few advantages over TCP:
- *Finer application-level control over what data is sent, and when.* TCP throttles the transport-layer sender when one or more links between source and destination are excessively congested.
- *No connection establishment.* UDP does not introduce any delay to establish a connection.
- *No connection state.* UDP does not track congestion-control or acknowledgement number parameters. For this reason, a server can typically support more active clients over UDP than TCP.
- *Small packet overhead.* TCP segments have 20 bytes of header overhead per segment, while UDP only has 8.

### 3.3.1 - UDP Segment Structure

The UDP header contains 4 fields, each made up of 2 bytes: source port number, destination port number, length, and checksum. The length field specifies the number of bytes in the UDP segment (header and data). The checksum is used by the receiving host for error checking.

### 3.3.2 - UDP Checksum

UDP at the sender side performs the 1s complement of the sum of all the 16-bit words in a segment, with any overflow being wrapped around.

## 3.4 - Principles of Reliable Data Transfer

### 3.4.1 - Building a Reliable Data Transfer Protocol



### 3.4.2 - Pipelined Reliable Data Transfer Protocols



### 3.4.3 - Go-Back-N (GBN)



### 3.4.4 - Selective Repeat (SR)



## 3.5 - Connection-Oriented Transport (TCP)

### 3.5.1 - The TCP Connection



### 3.5.2 - TCP Segment Structure



### 3.5.3 - Round-Trip Time Estimation and Timeout



### 3.5.4 - Reliable Data Transfer



### 3.5.5 - Flow Control



### 3.5.6 - TCP Connection Management



## 3.6 - Principles of Congestion Control

### 3.6.1 - The Causes and Costs of Congestion



### 3.6.2 - Approaches to Congestion Control



## 3.7 - TCP Congestion Control

### 3.7.1 - Classic TCP Congestion Control



### 3.7.2 - Network-Assisted Explicit Congestion Notification and Delayed-based Congestion Control



### 3.7.3 - Fairness



## 3.8 - Evolution of Transport-Layer Functionality


