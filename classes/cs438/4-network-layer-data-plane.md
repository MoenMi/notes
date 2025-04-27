# 4 - Network Layer: Data Plane

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

Network-layer packets in the Internet are called datagrams. The key fields of these datagrams in IPv4 include:
- *Version number:* 4 bits that determine the IP protocol version of the datagram.
- *Header length:* Gives the starting location of the payload, since the datagram can have a variable number of headers.
- *Type of service:* These bits allow different types of IPv4 datagrams to be distinguished from each other.
- *Datagram length:* Total length of the datagram.
- *Identifier, flags, fragmentation offset:* These fields have to do with IP fragmentation, where a large datagram is broken into several smaller datagrams that are then forwarded independently to their destination.
- *Time-to-live:* Ensures that datagrams do not circulate forever; it is decremented by one each time it encounters a router and terminated when it reaches zero.
- *Protocol:* Indicates TCP, UDP, or some other transport-layer protocol.
- *Header checksum:* Used for detecting bit errors in an IP datagram.
- *Source and destination IP addresses*
- *Options:* Meant to be used rarely and not included in IPv6.
- *Data (payload)*

### 4.3.2 - IPv4 Addressing

An **interface** is the connection between a host and the network. Each IP address is technically associated with an interface rather than the host or router containing that interface.

A network that connects multiple host interfaces with one router interface can be called a **subnet**. IP addressing assigns an address to a subnet, which may be denoted like the following: 223.1.1.0/24, which indicates that the first 24 bits are the subnet address and the /24, called the **subnet mask**, indicates that the first 24 bits are this subnet address.

The Internet's address assignment strategy is called **Classless Interdomain Routing (CIDR)** and uses the form $a.b.c.d/x$, where the first $x$ bits are often referred to as the **prefix** of the address. Only the $x$ first bits are considered by routers outside the address's network.

Before CIDR, the network portions of an IP address were constrained to 8, 16, or 24 bits in length, in an addressing scheme known as **classful addressing**. This meant that a class C (/24) subnet could only accomodate 254 hosts (2 of the addresses are reserved for special use).

The IP broadcast address 255.255.255.255 delivers a message to all hosts on a subnet.

#### Obtaining a Block of Addresses

An organization can obtain a block of IP addresses from their ISP. ICANN is responsible for providing blocks of IP addresses to the ISPs.

#### Obtaining a Host Address: The Dynamic Host Configuration Protocol

The **Dynamic Host Configuration Protocol (DHCP)** allows a host to be allocated an IP address dynamically. A network administrator can configure DHCP so that a host is given the same IP address each time it connects to a network, or a host can be given a **temporary IP address**.

DHCP is often called a **plug-and-play** or **zeroconf** (zero-configuration) protocol.

DHCP is a client-server protocol, whose client is typically a newly arriving host wanting to obtain network configuration information. In the simplest case, each subnet will have a DHCP server.

For a newly arriving host, the DHCP protocol is a 4-step process:
- *DHCP server discovery:* A **DHCP discover message**, which a client sends within a UDP packet to port 67, is used to find a DHCP server. This message is send with the destination IP address of 255.255.255.255 and a source IP address of 0.0.0.0.
- *DHCP server offer(s):* The DHCP server responds with a **DHCP offer message** that is broadcast to all nodes on the subnet using 255.255.255.255.
- *DHCP request:* The newly arriving client will choose from its server offers and respond to its selected offer with a **DHCP request message**, echoing the configuration parameters.
- *DHCP ACK:* The server responds to the DHCP request message with a **DHCP ACK message**, confirming the requested parameters.

### 4.3.3 - Network Address Translation (NAT)

**Network Adress Translation (NAT)** allows a router to behave as a single device with a single IP address to the outside world, while each device on its network has a private address.

Each NAT-enabled router has a **NAT translation table** that can be used to know which internal host to forward a program to, using port numbers to track the internal hosts. When the NAT-enabled router receives an outgoing request, it indexes the destination IP address, destination port, source IP address, and source port. Then, it rewrites the source IP address and port before sending the request out to the destination.

NAT has some issues, such as interfering with servers running on home networks.

### 4.3.4 - IPv6

The primary motivation for the development of IPv6 was the realization that the number of available IPv4 IP addresses would run low eventually.

#### IPv6 Datagram Format

The most important additions in the IPv6 format are as follows:
- *Expanded addressing capabilities:* IPv6 increases the size of the IP address from 32 bits to 128 bits. It also introduces **anycast addresses**, which allow a datagram to be delivered by any one of a group of hosts.
- *A stream-lined 40-byte header:* Smaller headers allow for faster processing by routers.
- *Flow labeling:* **Flow** is an elusive term without a clear definition.

#### Transitioning from IPv4 to IPv6

IPv6 compatible devices are backwards compatible with IPv4, but IPv4 devices cannot handle IPv6.

The approach that has been taking to handle the IPv4 to IPv6 transition is called **tunneling**, which involves putting an entire IPv6 message as the payload of an IPv4 message in order to get it through IPv4 devices.
