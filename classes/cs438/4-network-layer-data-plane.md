# 4 - The Network Layer: Data Plane

## 4.1 - Overview of Network Layer

### 4.1.1 - Forwarding and Routing: The Data and Control Planes

The primary role of the network layer is to move packets from a sending host to a receiving host. This involves two network-layer functions:
1. **Forwarding** is the router-local action of transferring a packet from an input link interface to the appropriate output link interface. It takes place in nanoseconds and is typically implemented in hardware.
2. **Routing** is the network-wide process that determines the end-to-end paths that packets take from source to destination.

Every network router has a **forwarding table** which manages the forwarding using lookups.

**Software-defined networking (SDN)** describes when the controller that computes forwarding tables and interacts with routers is implemented in software.

### 4.1.2 - Network Service Model

The **network service model** defines the characteristics of end-to-end delivery of packets between sending and receiving hosts. Some services that the network layer could provide are
- Guaranteed delivery
- Guaranteed delivery with bounded delay (guarantee delivery with a set maximum delay)
- In-order packet delivery
- Guaranteed minimal bandwidth
- Security

The Internet's network layer provides a single service known as the **best-effort service**, under which packets are neither guaranteed to be received in the order they were nor are they guaranteed to be received at all. There is no guarantee in end-to-end delay and no guaranteed minimal bandwidth.

**Link-layer switches** are packet switches that base their forwarding decision on values in the fields of the link-layer frame.

**Routers** are packet switches that base their forwarding decisions on header field data available in the network-layer datagram. As such, routers are the only packet switches we will concern ourselves with when looking at the network layer.

## 4.2 - What's Inside a Router?

There are 4 general router components:
- **Input ports** perform several key functions. First, it terminates an incoming physical link at the router. It also performs link-layer functions to interoperate with the link layer at the other side of the link. Additionally, a lookup function is performed, which consults a forwarding table to determine which output port to switch the packet to.
- The **switching fabric** connects the router's input ports to its output ports.
- **Output ports** store packets received from the switching fabric and transmits these packets on an outgoing link via link-layer and physical-layer functions.
- The **routing processor** performs control-plane functions to execute routing protocols.

The input ports, output ports, and switching fabric are almost always implemented in hardware.

### 4.2.1 - Input Port Processing and Destination-Based Forwarding

The forwarding table in a router is either computed and updated by the routing processor or received from a remote SDN controller.

A forwarding table may be structured like we see below:

| Prefix | Link Interface |
| - | - |
| `11001000 00010111 00010` | 0 |
| `11001000 00010111 00011000` | 1 |
| `11001000 00010111 00011` | 2 |
| Otherwise | 3 |

As an example, if the router receives packet with the destination address `11001000 00010111 00010110 10100001`, it will forward the packet to link interface 0. Note that if we have `11001000 00010111 00011000 10101010`, this matches with link interface 1 and link interface 2. Using the **longest prefix matching rule**, we would forward the result to link address 1.

Packets may be blocked from entering the switching fabric if it is currently in use.

### 4.2.2 - Switching

The switching within the switching fabric can be accomplished in a number of ways:
- *Switching via memory:* The earliest routers were traditional computers that switched packets from the input port to the output port via the CPU (routing processor). An input port with an arriving packet would signal to the routing processor via a system interrupt.
- *Switching via a bus:* In this approach, the input port transfers the packet directly to the output port over a shared bus, without intervention by the routing processor. This is typically done by having the input port prepend a header to the packet indicating the local output port to which the packet is being transferred. All output ports receive the packet, but only the port that matches the label transmits it. This approach is limited because only one packet can be in the bus at a time, but it is often sufficient for small local area and enterprise networks.
- *Switching via an interconnection network:* Using a crossbar switch, we can connect $N$ input ports to $N$ output ports using $2N$ buses, allowing packets to be forwarded in parallel. This forwarding is non-blocking.

### 4.2.3 - Output Port Processing

Output port processing takes packets that have been stored in the output port's memory and transmits them over the output link.

### 4.2.4 - Where Does Queuing Occur?

When packet loss occurs, it is when the packets are dropped at a router in the nework layer, because the memory available for the router queue is exhausted.

#### Input Queuing

If the switch fabric is not fast enough to transfer all arriving packets through the switching fabric, packet queuing can occur at the input ports. Packets can be kept in the input port queue if there are multiple packets destined for the same output port.

**Head-of-the-line (HOL) blocking** describes when a queued packet in an input queue must wait for another packet at the head of the line to be unblocked in order to reach its destination, even though there is no conflict with its output ports.

#### Output Queuing

Imagine that is the transimission rate of the switch fabric is greater than the transmission rate of the output link. In this case, packets will queue up at the output port. Eventually, all available memory may be exhausted and packet loss will occur.

When there is not enough memory available for a new packet, the decision must be made whether to drop the arriving packet (a policy known as **drop-tail**) or remove one or more already-queued packets to make room for the new packet.

Several proactive packet-dropping and -marking techniques exist are known as **active queue management (AQM)** algorithms. One such algorithm is the **Random Early Detection (RED)** algorithm. Note that in these algorithms, a **packet scheduler** at the output port must select one packet among those queued.

#### How Much Buffering Is Enough?

For many years, the rule of thumb was that the amount of buffering ($B$) should be equal to an average round-trip time ($RTT$) times the link capacity ($C$). Thus, $B = RTT * C$. However, more recent developments suggest that when a large number of independent TCP flows pass ($N$) through a link, the amount of buffering needed is $B = RTT * C / \sqrt{N}$.

More buffering is not always better, since it can increase queuing delays.

**Bufferbloat** is when excessive buffering in a network causes high latency (delay) and jitter (delay variation), even when the network has plenty of bandwidth.

### 4.2.5 - Packet Scheduling

First-in-First-out (FIFO), priority queuing, and round robin and weighted fair queuing (WFQ) are strategies to determine which queued packet is sent to an outgoing link.

## 4.3 - The Internet Protocol (IP): IPv4, Addressing, IPv6, and More

### 4.3.1 - IPv4 Datagram Format



### 4.3.2 - IPv4 Addressing



### 4.3.3 - Network Address Translation (NAT)



### 4.3.4 - IPv6



## 4.4 - Generalized Forwarding and SDN

### 4.4.1 - Match



### 4.4.2 - Action



### 4.4.3 - OpenFlow Examples of Match-plus-action in Action



## 4.5 - Middleboxes


