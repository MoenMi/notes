# 1 - Computer Networks and the Internet

## 1.1 - What is the Internet?

### 1.1.1 - A "Nuts and Bolts" Description

The **Internet** is a computer network that connects billions of devices across the world.

The devices, including computer, phones, TVs, gaming consoles, thermostats, and others, that are connected to the Internet are called **hosts** or **end systems/nodes**.

The end systems in the network are connected together through a network of **communication links** and packet switches. Different links transmit data at different rates, with the **transmission rate** of each link measured in bits/second. The packages of information exchanged are known as **packets**.
- A **packet switch** takes a packet arriving on one of its incoming communication links and forwards that packet on one of its outgoing communication links.
  - The most prominent type of packet switches are **routers** and **link-layer switches**.
- The sequence of communication links and packet switches traversed by a packet from the sending end system to the receiving end system is known as its **route** or **path** through a network.

End systems access the Internet through **Internet Service Providers (ISPs)**. Each ISP is itself a network of packet switches and communication links.

End systems, packet switches, and other pieces of the Internet run protocols that control the sending and receiving of information within the Internet.
- The **Transmission Control Protocol (TCP)** and the **Internet Protocol (IP)** are two of the most important protocols in the Internet. The IP protocol specifies the format of the packets that are sent and received amoung routers and end systems. These two protocols are collectively known as **TCP/IP**.
- The **Internet standards** that define these protocols are developed by the **Internet Engineering Task Force (IETF)** in documents called **requests for comments (RFCs)**. 

### 1.1.2 - A "Services" Description

- Infrastructure that provides services to applications
  - Web, streaming video, multimedia teleconferencing, email, games, e-commerce, social media, interconnected appliances, etc.
- Provides programming interface to distributed applications:
  - "Hooks" allowing sending/receiving apps to "connect" to, use Internet transport service
  - Provides service options, analogous to postal service

### 1.1.3 - What is a Protocol?

**Protocols** define the format, order of messages sent and received among network entities, and actions taken on message transmission and receipt.

## 1.2 - The Network Edge

End systems, which are the network edges in the Internet, are commonly divided into two categories:
- Hosts: desktops, smartphones, laptops, etc.
- Servers: often in large **data centers**

Access networks, physical media:
- Wired, wireless communications links

Network core:
- Interconnected routers
- Network of networks

### 1.2.1 - Access Networks

How to connect end systems to edge router?
- Residential access nets
- Institutional access networks (school, company)
- Mobile access networks (WiFi, 4G,/5G)

#### Digital Subscriber Line (DSL)

**Digital subscriber line (DSL)** uses an existing phone line, where data goes to the Internet and voice goes to the telephone network. For DSL, the ISP is typically the local telephone company (telco).

A residence that is  connected to DSL will have the telephone and Internet run through the same wire, and the telephone and Internet data is separated with a **DSL access multiplexer (DSLAM)** located in the telco's local central office (CO).

The DSL standards define multiple transmission rates:
- 24 or 52 Mbps dedicated downstream transmission rate
- 3.5 or 16 Mbps dedicated upstream transmission rate

DSL is designed for residences to be within 5-10 miles of their CO. Residences outside of this range typically must resort to other means of Internet access.

#### Cable-Based Access

**Cable internet access** makes use of existing cable infrastructure from television companies. Both fiber obtic and coaxial cables are used in the development of these networks, so the system is called **hybrid fiber coax (HFC)**.

**Frequency division multiplexing (FDM)**: Different channels transmitted in different frequency bands.
- 40 Mbps - 1.2 Gbps downstream transmission rate
- 30-100 Mbps upstream transmission rate

#### Wireless Access Networks

Shared **wireless access network** connects end system to router via base station
- **Wireless local area networks (WLAN)**
  - Typically within or around a building (~100 ft)
  - 802.11b/g/n (WiFi): 11, 54, 450 Mbps transmission rate
- **Wide-area cellular access networks**
  - Provided by mobile, cellular network operator (10s of kilometers)
  - 10s of Mbps
  - 4G/5G cellular networks

#### Wide-Area Access Networks

Telecommunications companies manage fourth-generation (4G) wireless networks, which provide real-world download speeds of up to 60 Mbps.

#### Enterprise Networks

Mix of wired, wireless link technologies, connecting a mix of switches and routers.
- Ethernet: wired access at 100Mbps, 1Gbps, 10Gbps
- WiFi: wireless access points at 11, 54, 450 Mbps

#### Data Center Networks

High-bandwidth links (10s to 100s Gbps) connect hundreds to thousands of servers together and to the Internet.

### 1.2.2 - Physical Media

#### Hosts

Hosts send packets of data:
- Takes application message
- Breaks into smaller chunks, known as packets, of length $L$ bits
- Transmits packet into access network at transmission rate $R$
  - Link transmission rate, aka capacity, aka link bandwidth

$$ \text{Packet transmission delay} = \text{Time needed to transmit } L \text{-bit packet into link} = \frac{L}{R} $$

#### Links

- **Bit**: Propagates between transmitter/receiver pairs
- **Physical link**: What lies between transmitter and receiver
- **Guided media**: Signals propagate in solid media (copper, fiber, coax)
- **Undguided media**: Signal propagate freely (radio, etc.)

**Twisted Pair (TP)**: Two insulated copper wires
- Category 5: 100 Mbps, 1 Gbps Ethernet
- Category 6: 10Gbps Ethernet

**Coaxial cable**:
- Two concentric copper conductors
- Bidirectional
- Broadband
  - Multiple frequency channels on cable
  - 100s of Mbps per channel

**Fiber optic cable**:
- Glass fiber carrying light pulses, each pulse a bit
- High-speed operation:
  - High-speed point-to-point transmission (10s-100s of Gbps)
- Low error rate:
  - Repeaters spaced far apart
  - Immune to electromagnetic noise

**Wireless radio**:
- Signal carried in various bands in electromagnetic spectrum
- No physical "wire"
- Broadcast, "half-duplex" (sender to receiver)
- Propagation environment effects:
  - Reflection
  - Obstruction by objects
  - Interference/noise

**Radio link type**:
- **Wireless LAN** (WiFi): 10-100s of Mbps, 10s of meters
- **Wide-area** (e.g. 4G cellular): 10s of Mbps over ~10 km
- **Bluetooth**: short distances, limited rates
- **Terrestrial microwave**: Point-to-point, 45 Mbps channels
- **Satellite**: Up to 45 Mbps per channel (270 msec end-to-end delay)

## 1.3 - The Network Core

The **network core** is a mesh of interconnected routers.

**Packet-switching** is when hosts break application-layer messages into packets.
- Network forwards packets from one router to the next, across links on path from source to destination

Two key network-core functions:
- **Forwarding** (switching): A local action that moves arriving packets from the router's input link to appropriate router output link.
- **Routing**: A global action that determines source-destination paths taken by packets.

### 1.3.1 - Packet Switching

#### Store-and-Forward

- **Packet transmission delay**: takes $L/R$ seconds to transmit (push out) $L$-bit packet into link at $R$ bps
- **Store and forward**: Entire packet must arrive at router before it can be transmitted on the next link. This makes the transmission rate $2L/R$ when there is one packet switch that employs store-and-forward transmission.

If we consider there to be $N$ routers between source and destination:

$$ d_{\text{end-to-end}} = (N + 1) \frac{L}{R} $$

#### Queueing

**Queueing** occurs when work arrives faster than it can be serviced. Each packet switch has an **output buffer** or **output queue**, which stores packets that the

If the arrival rate (in bps) to link exceeds transmission rate (bps) of link for some period of time:
- There will be a **queueing delay**, since packets will wait to be serviced
- **Packet loss** will occur if memory (buffer) in router fills up

### 1.3.2 - Circuit Switching

End-to-end resources are allocated to and reserved for "call" between source and destination.
- Commonly used in traditional telephone networks
- Dedicated resources provide guaranteed performance
- Circuit segment sits idle if unused by call

**Frequency Division Multiplexing (FDM)**:
- Optical, electromagnetic frequencies divided into narrow frequency bands.
- Each call allocated at its own band, can transmit at max rate of that narrow band.

**Time Division Multiplexing (TDM)**:
- Time divided into slots.
- Each call allocated periodic slots, can transmit at maximum rate of wider frequency band during its time slot.

#### Packet Switching vs. Circuit Switching

Consider a system with 10 users with a total capacity of 1 Gb/s for its link. Each user uses 100 Mb/s when active, and each user is active 10% of the time. How many users can use this network under circuit-switching and packet-switching?

- Circuit-switching: 10 users
- Packet-switching: With 35 users, the probability that more than 10 users are active at the same time is less than 0.0004.

Packet-switching is great for "bursty" data, because it is better at resource sharing and simpler, with no call setup.
- Excessive congestion possible: packet delay and loss due to buffer overflow
- Protocols are needed for reliable data transfer
- There are ways of providing circuit-like behavior with packet-switching that will be covered later in the course

### 1.3.3 - A Network of Networks

End systems connect to the Internet via access ISPs, which can be a telco, cable company, university, or company among others. To connect every end system to each other, these access ISPs must also be connected, which is called the **network of networks**.

A naive approach to connect ISPs would be to have a mesh, i.e., to connect every ISP to each other through a physical connection.

In *Network Structure 1*, a single global transit ISP is constructed that connects all ISPs to each other. Each access ISP would then pay the global transit ISP based on the amount of traffic it exchanges with the global ISP.

In *Network Structure 2*, there are multiple global transit ISPs that compete with each other on price. Note that the global transit ISPs must also connect with each other.

*Network Structure 4*: In any given city, there is typically one **regional ISP** to which the access ISPs connect. These regional ISPs then connect to **tier-1 ISPs**, of which there are about a dozen in the world including AT&T, Sprint, and others. To more accurately approximate today's Internet, we must consider the following:
- A **point of presence (PoP)** is a group of one or more routers in the provider's network where customer ISPs can connect to the provider ISP.
- Any ISP can choose to **multi-home**, i.e., to connect to two or more provider ISPs. This allows the ISP to send and receive packets even if one of the provider ISPs fails.
- Two ISPs of the same tier can **peer** with each other. This means that they directly connect their networks and can access each other's resources without paying a fee. Note that tier-1 ISPs peer with each other.
  - An **Internet Exchange Point (IXP)** is a meeting point where multiple ISPs peer with each other.

*Network Structure 5* describes today's Internet. It works similarly to Network Structure 4, but includes **content-provider networks**. For example, Google has 19 major data centers (and many more smaller data centers) around the world that connect to each other through a private TCP/IP network that is separate from the Internet. Google can then peer with lower-tier ISPs, typically at IXPs, allowing them to pay fewer fees to higher-tier ISPs and gain more control over the way they send data to end systems.

## 1.4 - Delay, Loss, and Throughput in Packet-Switched Networks

### 1.4.1 - Overview of Delay in Packet-Switched Networks

As a packet travels from its source to its destination, it suffers several types of delays at each node along the path.

$$ d_{\text{nodal}} = d_{\text{proc}} + d_{\text{queue}} + d_{\text{trans}} + d_{\text{prop}} $$

- The time required to examine the packet's header and determine where to direct it is part of the **processing delay**. It can also include the time needed to check for bit-level errors in the packet. These delays are typically microseconds or less.
- A packet experiences **queuing delay** as it waits to be transmitted onto the link. The queuing delay depends on the number of items in the queue when the packet arrives, and is zero if it is empty.
- Denote the length of the packet (in bits) as $L$ and the transmission rate (in bits/second) $R$. The **transmission delay** is the amount time it takes to push the packet's contents to the link, and is $L/R$.
- The time required to travel across the physical links is called the **propagation delay**, which is equal to or just a little more than the distance between the nodes divided by the speed of light. This can be expressed as $d/s$, where $d$ is the distance between the links and $s$ is the speed of light.

### 1.4.2 - Queueing Delay and Packet Loss

The most interesting component of nodal delay is the queuing delay.

If a packet arrives to a router with a full queue, the router will **drop** the packet, resulting in **packet loss**.

### 1.4.3 - End-to-End Delay

End-to-end delay considers the full delay of a packet as it travels from its source to its destination, rather than just at a node.

Suppose there are $N-1$ routers on the packet's path. If we suppose that there are no queuing delays, we can say

$$ d_{\text{end-to-end} = N (d_{\text{proc}} + d_{\text{trans}} + d_{\text{prop}})} $$

Note that Traceroute is a program that sends a message back to the source with the name and address of each router it encounters.

It can be run in Windows with:

```sh
tracert mtmoen.com
```

Or in Linux with

```bash
traceroute mtmoen.com
```

### 1.4.4 - Throughput in Computer Networks

**Throughput** is the rate (bits/time) at which bits are being sent from sender to receiver.
- **Instantaneous**: Rate at given point in time
- **Average**: Rate over long period of time

Note that the throughput is determined by the link with the smallest transmission rate along the entire path. This link is called the **bottleneck link**. Note that this bottleneck link may be due to a shared link.

## 1.5 - Protocol Layers and Their Service Models

### 1.5.1 - Layered Architecture

**Layers** are actions taken at a certain step, which rely on previous steps.

Layered Internet protocol stack:

1. **Application Layer**: supporting network applications
   - HTTP, IMAP, SMTP, DNS
2. **Transport Layer**: process-process data transfer
    - TCP, UDP
3. **Network Layer**: routing of datagrams from source to destination
    - IP, routing protocols
4. **Link Layer**: data transfer between neighboring network elements
    - Ethernet, 802.11 (WiFi), PPP
5. **Physical Layer**: bits "on the wire"

### 1.5.2 - Encapsulation



## 1.6 - Networks Under Attack

The Internet was not originally designed with much security in mind.
- Original vision: "A group of mutually trusting users attached to a transparent network"

## 1.7 - History of Computer Networking and the Internet

### 1.7.1 - The Development of Packet Switching: 1961-1972



### 1.7.2 - Proprietary Networks and Internetworking: 1972-1980



### 1.7.3 - A Proliferation of Networks: 1980-1990



### 1.7.4 - The Internet Explosion: The 1990s



### 1.7.5 - The New Millenium


