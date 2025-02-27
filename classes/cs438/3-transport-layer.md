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

The layer below TCP is IP, which is unreliable.

The `rdt` protocol is the reliable data transfer protocol.

### 3.4.1 - Building a Reliable Data Transfer Protocol

#### Reliable Data Transfer over a Perfectly Reliable Channel: `rdt1.0`

The sending side of `rdt1.0` simply accepts data from the upper layer via the `rdt_send(data)` event, creates a packet containing the data using `make_pkt(data)`, and sends the packet into the channel.

On the receiving side, rdt receives the packet from the underlying channel via `rdt_rcv(packet)`, removes the data from the packet via `extract(packet, data)`, and passes the data up to the upper layer via `deliver_data(data)`.

#### Reliable Data Transfer over a Channel with Bit Errors: `rdt2.0`

The protocol uses positive and negative acknowledgements that allow the receiver to let the sender know that the messages were received correctly. Reliable data transfer protocols based on retransmission are known as **Automatic Repeat reQuest (ARQ) protocols**. To achieve this, 3 mechanisms are required:
- *Error detection*: A mechanism is needed to allow the receiver to detect when bit errors have occurred
- *Receiver feedback*: Positive (ACK) and negative (NAK) acknowledgement replies are sent from the receiver to the sender.
- *Retransmission*: A packet that is received in error will be retransmitted by the sender.

The send side of `rdt2.0` has two states:
1. Waiting for data to be passed down from the upper level. When it is received, a packet is created and sent to the receiver. We then go to state 2.
2. Waiting for an ACK or NAK from the receiver. If an ACK is received, we return to state 1. If a NAK is received, we retransmit the last packet and stay at state 2.

The receiver side has one state:
1. On packet arrival, respond with either ACK or NAK.

This protocol has no way of handling corrupted ACK/NAK packets. A simple solution is to add a new field to the data packet and have the sender number its packets with a **sequence number**.

#### Reliable Data Transfer over a Lossy Channel with Bit Errors: `rdt3.0`

- Stop-and-wait, adds retransmission based on timeouts

### 3.4.2 - Pipelined Reliable Data Transfer Protocols

- send multiple packets at a time, increasing throughput
- makes acknowlegement more complicated, can't have a one-bit sequence number
- Two basic approaches to handle errors: GBN and SR

### 3.4.3 - Go-Back-N (GBN)

- Constrained to have at most $N$ unacknowledged packets in the pipeline.
- If error/timeout, resend everything including it and after

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


