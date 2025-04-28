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

Time-division multiplexing (TDM) can be used to fairly divide a broadcast channel's bandwidth among all nodes. However, it can be wasteful when there is only one broadcasting node. Frequency-division multiplexing (FDM) shares the same downsides.

A third channel partitioning protocol is **code division multiple access (CDMA)**. CDMA assigns a code to each node, which the node uses to encode the messages it sends. If the codes are chosen carefully, CDMA networks can have different nodes that transmit simultaneously and yet have their respective receivers receive a sender's encoded data bits.

### 6.3.2 - Random Access Protocols

In a random access protocol, nodes always transmit at the full rate of the channel. When there is a collision, each node involved in the collision repeatedly retransmits its frame until it gets through without collision. The transmitter waits a random delay before retransmitting the frame.

#### Slotted ALOHA

We assume the following:
- All frames consist of exactly $L$ bits.
- Time is divided into slots of size $L/R$ seconds (a slot is the time to transmit one frame).
- Nodes start to transmit frames only at the beginnings of slots.
- The nodes are synchronized so that each node knows when the slots begin.
- If two or more frames collide in a slot, then all nodes detect the collision event before the slot ends.

A probability $p$ is selected to determine the chance that a frame is retransmitted in each slot.

Slotted ALOHA allows nodes to transmit at their full rate, is highly decentralized, and is also very simple. However, it does require synchronization of all the nodes.

The **efficiency** of a slotted multiple access protocol is defined to be the long-run fraction of successful slots in the case when there are a large number of active nodes, each always having a large number of frames to send. The maximum efficiency of slotted ALOHA works itself out to be about 37%.

#### ALOHA

The unslotted version of ALOHA does not require synchronization. Instead, the transmitting node will immediately retransmit in the case of a collision, and then retransmits after a frame time with probability $p$.

The efficiency of unslotted ALOHA is half that of slotted ALOHA.

#### Carrier Sense Multiple Access (CSMA)

In both versions of ALOHA, the nodes' decisions to transmit is made independently of other nodes.

The following two rules are considered in the family of **carrier sense multiple access (CSMA)** and **CSMA with collision detection (CSMA/CD)** protocols:
- **Carrier sensing** is when a node listens to the channel before transmitting, waiting for any current transmissions to stop.
- **Collision detection** is when a transmitting node listens to the channel while it is transmitting. If it detects that another node is transmitting, it stops and waits a random amount of time before repeating.

**Channel propagation delay** is the time it takes for a signal to propogate from one of the nodes to another. This plays an important role in determining the performance of a broadcast channel.

#### Carrier Sense Multiple Access with Collision Detection (CSMA/CD)

Here is the operation of the CSMA/CD protocol from the perspective of an adapter attached to a broadcast channel:
1. The adapter obtains a datagram from the network layer, prepares a link-layer frame, and puts the frame adapter buffer.
2. If the adapter senses that the channel is idle, it starts to transmit the frame. If the channel is busy, it instead waits.
3. While transmitting, the adapter monitors for the presence of signal energy coming from other adapters.
4. If the adapter transmits the entire frame, it is finished with the frame. If it detects a collision, it aborts the transmission.
5. After aborting, the adapter waits a random amount of time and then returns to step 2.

The **binary exponential backoff** algorithm, used in Ethernet and DOCSIS, tells a node has exerienced $n$ collisions to wait somewhere from $\{ 0, 1, 2, \dots, 2^n - 1 \}$.

#### CSMA/CD Efficiency

The efficiency of CSMA/CD is given as follows:

$$ \text{Efficiency} = \frac{1}{1 + 5d_\text{prop}/d_\text{trans}} $$

### 6.3.3 - Taking-Turns Protocols

The **polling protocol** requires one of the nodes to be designated as the master node. The master node **polls** each of the nodes in a round-robin fashion. It tells each node that it can transmit, and then moves on to the next node when it is done transmitting.

The polling protocol introduces polling delay and has the initial drawback that the master node going down takes the whole systm down. Bluetooth uses the polling protocol.

The **token-passing protocol** has no master node. Instead, a **token** is passed between the nodes in a fixed order. This protocol is decentralized, but the failure of any node can break the system.

### 6.3.4 - DOCSIS: The Link-Layer Protocol for Cable Internet Access



## 6.4 - Switched Local Area Networks

### 6.4.1 - Link-Layer Addressing and ARP



### 6.4.2 - Ethernet



### 6.4.3 - Link-Layer Switches



### 6.4.4 - Virtual Local Area Networks (VLANs)



## 6.5 - Link Virtualization: A Network as a Link Layer

### 6.5.1 - Multiprotocol Label Switching (MPLS)


