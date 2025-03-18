# 4 - The Network Layer: Data Plane

## 4.1 - Overview of Network Layer

### 4.1.1 - Forwarding and Routing: The Data and Control Planes

The primary role of the network layer is to move packets from a sending host to a receiving host. This involves two network-layer functions:
1. **Forwarding** is the router-local action of transferring a packet from an input link interface to the appropriate output link interface. It takes place in nanoseconds and is typically implemented in hardware.
2. **Routing** is the network-wide process that determines the end-to-end paths that packets take from source to destination.

Every network router has a **forwarding table** which manages the forwarding using lookups.

### 4.1.2 - Network Service Model



## 4.2 - What's Inside a Router?

### 4.2.1 - Input Port Processing and Destination-Based Forwarding



### 4.2.2 - Switching



### 4.2.3 - Output Port Processing



### 4.2.4 - Where Does Queuing Occur?



### 4.2.5 - Packet Scheduling



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


