# 1 - Computer Networks and the Internet

## 1.1 - What is the Internet?

### 1.1.1 - A "Nuts and Bolts" Description

- Billions of connected computing devices:
  - Hosts = end systems/nodes
  - Running network apps Internet's edge
- Packet switches: forward packets (chunks of data)
  - Routers, switches
- Communication links
  - Fiber, copper, radio, satellite
  - Transmission rate: bandwidth
- Networks
  - Collection of devices, routers, and links managed by an organization
- The **Internet** is a network of networks
  - Interconnected ISPs
- Protocols are everywhere
  - Control sending and receiving of messages
  - e.g., HTTP, streaming video, Skype, TCP, IP, WiFi, 4G, Ethernet
- Internet Standards
  - RFC: Request for Comments
  - IETF: Internet Engineering Task Fore

### 1.1.2 - A "Services" Description

- Infrastructure that provides services to applications
  - Web, streaming video, multimedia teleconferencing, email, games, e-commerce, social media, interconnected appliances, etc.
- Provides programming interface to distributed applications:
  - "Hooks" allowing sending/receiving apps to "connect" to, use Internet transport service
  - Provides service options, analogous to postal service

### 1.1.3 - What is a Protocol?

**Protocols** define the format, order of messages sent and received among network entities, and actions taken on message transmission and receipt.

## 1.2 - The Network Edge

Network edge:
- Hosts: clients and servers
- Servers often in data centers

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

#### Cable-Based Access

**Frequency division multiplexing (FDM)**: Different channels transmitted in different frequency bands.

- **Hybrid fiber coax (HFC)** is asymmetric:
  - 40 Mbps - 1.2 Gbps downstream transmission rate
  - 30-100 Mbps upstream transmission rate

- Network of cable and fiber attaches homes to ISP router
  - Homes share access network to cable headend

#### Digital Subscriber Line (DSL)

DSL uses an existing phone line, where data goes to the Internet and voice goes to the telephone network.
- 24-52 Mbps dedicated downstream transmission rate
- 3.5-16 Mbps dedicated upstream transmission rate

#### Wireless Access Networks

Shared **wireless access network** connects end system to router via base station
- **Wireless local area networks (WLAN)**
  - Typically within or around a building (~100 ft)
  - 802.11b/g/n (WiFi): 11, 54, 450 Mbps transmission rate
- **Wide-area cellular access networks**
  - Provided by mobile, cellular network operator (10s of kilometers)
  - 10s of Mbps
  - 4G/5G cellular networks

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

- **Packet transmission delay**: takes $L$/$R$ seconds to transmit (push out) $L$-bit packet into link at $R$ bps
- **Store and forward**: Entire packet must arrive at router before it can be transmitted on the next link

#### Queueing

**Queueing** occurs when work arrives faster than it can be serviced.

If the arrival rate (in bps) to link exceeds transmission rate (bps) of link for some period of time:
- Packets will queue, waiting to be transmitted on output link
- Packets can be dropped (lost) if memory (buffer) in router fills up

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



## 1.4 - Delay, Loss, and Throughput in Packet-Switched Networks

### 1.4.1 - Overview of Delay in Packet-Switched Networks

How do packets delay and loss occur?
- Packets queue in router buffers, waiting for turn in transmission
  - Queue length grows when arrival rate to link (temporarily) exceeds output link capacity
- Packet loss occurs when memory to hold queued packets fills up

### 1.4.2 - Queueing Delay and Packet Loss

Four sources of packet delay:

$$ d_{\text{nodal}} = d_{\text{proc}} + d_{\text{queue}} + d_{\text{trans}} + d_{\text{prop}} $$

- $d_{\text{proc}}$: **Nodal processing**
  - Check bit errors
  - Determine output link
  - Typically fewer than microseconds
- $d_{\text{queue}}$: **Queueing delay**
  - Time waiting at output link for transmission
  - Depends on congestion level of router
- $d_{\text{trans}}$: **Transmission delay**
  - $L$: packet length (bits)
  - $R$: link transmission rate (bps)
  - $d_{\text{trans}} = L/R$
- $d_{\text{prop}}$: **Propagation delay**
  - $d$: length of physical link
  - $s$: propagation speed (about $2 \times 10^8$ m/s)

#### Packet Loss

- Queue (aka buffer) preceding link in buffer has finite capacity.
- Packet arriving to full queue dropped (aka lost).
- Lost packet may be retransmitted by previous node, by source end system, or not at all.

### 1.4.3 - End-to-End Delay



### 1.4.4 - Throughput in Computer Networks

**Throughput** is the rate (bits/time) at which bits are being sent from sender to receiver.
- **Instantaneous**: Rate at given point in time
- **Average**: Rate over long period of time

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


