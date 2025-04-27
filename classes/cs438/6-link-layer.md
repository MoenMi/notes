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

### 6.2.1 - Parity Checks



### 6.2.2 - Checksumming Methods



### 6.2.3 - Cyclic Redundancy Checks (CRC)



## 6.3 - Multiple Access Links and Protocols

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


