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



## 5.4 - Routing Among the ISPs: BGP

### 5.4.1 - The Role of BGP



### 5.4.2 - Advertising BGP Route Information



### 5.4.3 - Determining the Best Routes



### 5.4.4 - IP-Anycast



### 5.4.5 - Routing Policy



### 5.4.6 - Putting the Pieces Together: Obtaining Internet Presence



## 5.6 - ICMP: The Internet Control Message Protocol


