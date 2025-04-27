# 5 - The Network Layer: Control Plane

## 5.1 - Introduction

This chapter is concerned with how forwarding and flow tables are computed, maintained, and installed. There are 2 approaches to this:
- *Per-router control:* Each router has a routing component that communicates with the routing components in other routers to compute the values in its forwarding table. This is what the Internet has used for decades, and the OSPF and BGP protocols are based on this approach.
- *Logically centralized control:* A logically centralized controller computes and distributes the forwarding tables to be used by each and every router.

## 5.2 - Routing Algorithms



### 5.2.1 - The Link-State (LS) Routing Algorithm



### 5.2.2 - The Distance-Vector (DV) Routing Algorithm



## 5.3 - Intra-AS Routing in the Internet: OSPF



## 5.4 - Routing Among the ISPs: BGP



### 5.4.1 - The Role of BGP



### 5.4.2 - Advertising BGP Route Information



### 5.4.3 - Determining the Best Routes



### 5.4.4 - IP-Anycast



### 5.4.5 - Routing Policy



### 5.4.6 - Putting the Pieces Together: Obtaining Internet Presence



## 5.6 - ICMP: The Internet Control Message Protocol


