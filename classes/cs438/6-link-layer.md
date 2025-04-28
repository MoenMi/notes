# 6 - Link Layer and LANs

## 6.1 - Introduction to the Link Layer

We'll refer to any device that runs a link-layer protocol a **node**, which includes hosts, routers, switches, and WiFi access points. The communication channels that connect nodes are called **links**. Over a given link, a transmitting node encapsulates a datagram in a **link-layer frame** and transmits the frame into the link.

### 6.1.1 - The Services Provided by the Link Layer

Possible services that can be offered by a link-layer protocol include:
- *Framing:* Almost all link-layer protocols encapsulate each network-layer datagram in a link-layer frame before transmission over the link. A frame consists of a data field and a number of headers.
- *Link access:* A median access control (MAC) protocol specifies the rules by which a frame is transmitted onto the link.
- *Reliable delivery:* A link-layer protocol can guarantee to move each network-layer datagram across the link without error.
- *Error detection and correction:* Hardware can cause bit errors, and these can be identified and corrected here.

### 6.1.2 - Where Is the Link Layer Implemented?

For the most part, the link layer is implemented on a chip called **network adapter**, also sometimes known as a **network interface controller (NIC)**. As such, many of the link-layer services are implemented in hardware.

## 6.2 - Error-Detection and -Correction Techniques

At the sending node, the data $D$ is augmented with error detection and correction $EDC$ bits. At the receiving node, both $D'$ and $EDC'$ are received. These new values may differ from the originals as a result of in-transit bit flips. Even with this system, there may still be **undetected bit errors**.

### 6.2.1 - Parity Checks

The simplest form of error detection is the use of a single **parity bit**. The value of this bit is set so that the number of 1s in the binary string is even. If an odd number of bits is received, then the receiver knows there was an error in transmission. Since bit errors occur in bursts, this is vulnerable to having multiple bit errors occurring for the same string, leaving us vulnerable to errors.

A **two-dimensional parity** scheme divides the string into rows and columns and computes the row and column sums. With this, any errors can be detected and corrected.

The ability of the receiver to both detect and correct errors is known as **forward error correction (FEC)**.

### 6.2.2 - Checksumming Methods

The **Internet checksum** treats bytes of data as 16-bit integers and sums them. The 1s complement of this sum then forms the checksum carried in the segment header. Checksums are not the most effective methods of error detection, but they do offer nice redundancy are easy to implement in software.

### 6.2.3 - Cyclic Redundancy Checks (CRC)

An error-detection technique used in today's computer networks is based on **cyclic redundancy check (CRC) codes**, which are also known as **polynomial codes**.

CRC codes operate as follows. Consider a $d$-bit piece of data $D$ that the sending node wants to send to the receiving node. The sender and receiver must first agree on an $r + 1$ bit pattern, known as a **generator**, which we will denote as $G$. We will require that the most significant bit of $G$ be a 1. For a given piece of data $D$, the sender will choose $r$ additional bits, $R$, and append them to $D$ such that the resulting $d + r$ bit pattern is exactly divisible by $G$.

All CRC calculations are done in modulo-2 arithmetic without carries in addition or borrows in subtraction. This means addition and subtraction are identical, and both are equivalent to the bitwise XOR.

## 6.3 - Multiple Access Links and Protocols

There are 2 types of network links:
1. A **point-to-point link** consists of a single sender at one end of the link and a single receiver at the other end of the link.
2. A **broadcast link** can have multiple sending and receiving nodes all connected to the same, single, shared broadcast channel.

The issue of coordinating the access of multiple sending and receiving nodes to a shared broadcast channel is called the **multiple access problem**.

Computer networks have protocols called **multiple access protocols** that nodes use to regulate their transmission into the shared broadcast channel.

Because all nodes are capable of transmitting frames, more than two nodes can transmit frames at the same time. When this happens, all of the nodes receive multiple frames at the same time (i.e., the transmitted frames **collide** at all of the receivers). Typically, when there is a collision, all of the colliding frames become tangled and lost.

Multiple access protocols can generally be classified into the following categories:
1. Channel partitioning protocols
2. Random access protocols
3. Taking-turns protocols

A multiple access protocol for a broadcast channel of rate $R$ bits per second should have the following desirable traits:
1. When only one node has data to send, that node has a throughput of $R$ bps.
2. When $M$ nodes have data to send, each of these nodes have a throughput of $R/M$ bps.
3. The protocol is decentralized.
4. The protocol is simple and inexpensive to implement.

### 6.3.1 - Channel Partitioning Protocols



### 6.3.2 - Random Access Protocols



### 6.3.3 - Taking-Turns Protocols



### 6.3.4 - DOCSIS: The Link-Layer Protocol for Cable Internet Access



## 6.4 - Switched Local Area Networks

### 6.4.1 - Link-Layer Addressing and ARP



### 6.4.2 - Ethernet



### 6.4.3 - Link-Layer Switches



### 6.4.4 - Virtual Local Area Networks (VLANs)



## 6.5 - Link Virtualization: A Network as a Link Layer

### 6.5.1 - Multiprotocol Label Switching (MPLS)


