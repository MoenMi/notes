# 5 - The Network Layer: Control Plane

## 5.1 - Introduction

This chapter is concerned with how forwarding and flow tables are computed, maintained, and installed. There are 2 approaches to this:
- *Per-router control:* Each router has a routing component that communicates with the routing components in other routers to compute the values in its forwarding table. This is what the Internet has used for decades, and the OSPF and BGP protocols are based on this approach.
- *Logically centralized control:* A logically centralized controller computes and distributes the forwarding tables to be used by each and every router.

## 5.2 - Routing Algorithms

Routing algorithms are graph algorithms that try to find good paths between two destinations.

A **centralized routing algorithm** computes the least-cost path between a source and destination using complete, global knowledge about the network. Algorithms with global state information are often referred to as **link-state (LS) algorithms**, since the algorithm must be aware of the cost of each link in the network.

In a **decentralized routing algorithm**, the calculation of the least-cost path is carried out in an iterative, distributed manner by the routers.

In **static routing algorithms**, routes change very slowly over time, often as a result of human intervention. **Dynamic routing algorithms** change the routing paths as the network traffic loads or topology change.

In a **load-sensitive algorithm**, link costs vary dynamically to reflect the current level of congestion in the underlying link. Today's Internet routing algorithms are **load-insensitive**, as a link's cost does not explicitly reflect its current, or recent past, level of congestion.

### 5.2.1 - The Link-State (LS) Routing Algorithm

A **link-state broadcast** algorithm involves sending link-state packets to all other nodes on a network, with each link-state packet containing the identities and costs of its attached links. Each node can then run the LS algorithm on the same set of least-cost paths as every other node.

The link-state algorithm that we'll use is Dijkstra's algorithm, which ensures that after $k$ iterations of the algorithm, the least-cost paths are known to $k$ destination nodes. Dijkstra's algorithm is $O(N^2)$.

### 5.2.2 - The Distance-Vector (DV) Routing Algorithm

The **distance-vector (DV)** algorithm does not rely on global knowledge of the network being available to each router. Instead, each node receives information from one or more of its directly attached neighbors, performs a calculation, and then distributes the results back to its neighbors. This continues until no more information is exchanged between neighbors.

To run this algorithm, each node computes the cost of reaching each of its direct neighbors. Then, it sends this data those neighbors, who see if they use alternative routes to reach their destination.

One issue with DV routing is that neighbors don't instantly become aware of when one node goes down. This can lead to **routing loops**, where two nodes both think that the downed node can be reach through the other, so they can data between the each other endlessly.

#### Distance-Vector Algorithm: Adding Poisoned Reverse

A **poisoned reverse** is a method to avoid routing loops. When a node routes through another node to reach its destination, it falsely advertises to the intermediate node that its distance to the destination is infinite, so that the intermediate node will never try to send the packet back.

Note that this technique only works on loops involving two nodes.

#### A Comparison of LS and DV Routing Algorithms

Here is a quick comparison of some of the attributes:
- *Message complexity:* LS requires each node to know the cost of each link in the network, requiring $O(NE)$ messages to be sent. Whenever a link cost changes, this new cost must be sent to all nodes. The DV algorithm only requires messages to be exchanged between directly connected nodes.
- *Speed of convergence:* LS is $O(N^2)$ requiring $O(NE)$ messages to be sent. DV can converge slowly, have routing loops, and suffer from the count-to-infinity problem.
- *Robustness:* Both algorithms can suffer significantly from the failure of a router, but LS is a little more robust.

## 5.3 - Intra-AS Routing in the Internet: OSPF

What we have looked at so far ignores the scale of the Internet and the administrative autonomy desired by the ISPs. These problems can be solved by organizing routers into **autonomous systems (ASs)**, with each AS consisting of a group of routers that are under the same administrative control. An autonomous system is identified by a unique autonomous system number (ASN), which is assigned by ICANN.

Routers within the same AS run the same routing algorithm and have information about each other. The routing algorithm running within an AS is called an **intra-autonomous system routing protocol**.

#### Open Shortest Path First (OSPF)

OSPF is a link-state protocol that uses flooding of link-state information and a Dijkstra's least-cost path algorithm. With OSPF, each router constructs a complete topological map of the entire AS. Each router then locally runs Dijkstra's algorithm to determine a shortest-path tree to all subnets. The network administrator decides how to configure the link costs.

Under OSPF, a router broadcasts routing information to all other routers in the AS, not just to the neighboring routers. It also broadcasts a link's state periodically, even if it has not changed.

Some of the advances embodied in OSPF include the following:
- *Security:* Exchanges between OSPF routers can be authenticated
- *Multiple same-cost paths:* When multiple paths to the same destination have the same cost, OSPF allows multiple paths to be used.
- *Integrated support for unicast and multicast routing*
- *Support for hierarchy within a single AS:* An OSPF AS can be configured hierarchically into areas.

## 5.4 - Routing Among the ISPs: BGP

All ASs in the Internet run the same inter-autonomous system routing protocol, which is known as the **Border Gateway Protocol (BGP)**.

### 5.4.1 - The Role of BGP

In BGP, packets are not routed to a specific destination address, but to CIDRized prefixes that represent subnets or collections of subnets.

BGP provides each router a means to:
- *Obtain prefix reachability information from neighboring ASs:* BGP allows each subnet to advertise its existence to the rest of the Internet.
- *Determine the "best" routes to the prefixes:* A router may learn about multiple different routes to a specific prefix. To determine the best route, the router will locally run a BGP route-selection procedure.

### 5.4.2 - Advertising BGP Route Information

For each AS, each router is either a **gateway router** or a **internal router**.

A **BGP connection** is a semi-permanent TCP connection over port 179 that routers use to exchange routing information. A BGP connection that spans two ASs is called an **external BGP (eBGP)** connection, and a BGP connection between two routers on the same AS is called an **internal BGP (iBGP)** connection.

Both eBGP and iBGP are used when advertising the existence of a prefix across different ASs.

### 5.4.3 - Determining the Best Routes

When a router advertises a prefix across a BGP connection, it includes with the prefix several **BGP attributes**. A prefix along with its attributes is called a **route**. Two of the more important attributes are AS-PATH, which contains a list of the ASs through which the advertisement has passed, and NEXT-HOP, which is the IP address of the router interface that begins the AS-PATH. The AS-PATH attribute can be used to identify loops.

#### Hot Potato Routing

Using **hot potato routing**, the route chosen is the one with the least cost to NEXT-HOP. This is a selfish algorithm, since it only considers the cost to the router's own AS.

#### Route-Selection Algorithm

In reality, BGP uses a route selection algorithm more complex than hot potato routing. If there are 2 or more routes to the same prefix, the following elimination rules are used sequentially until one route remains:
1. A route is assigned a **local preference** value as one of its attributes, and the routes with the highest local preference values are selected.
2. From the remaining routes, the route with the shortest AS-PATH is selected.
3. From the remaining routes, hot potato routing is used.
4. If more than one route remains, the router uses BGP identifiers to select the route.

### 5.4.4 - IP-Anycast



### 5.4.5 - Routing Policy



### 5.4.6 - Putting the Pieces Together: Obtaining Internet Presence



## 5.6 - ICMP: The Internet Control Message Protocol


