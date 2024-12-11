# 34 - NP-Completeness

The **class P** consists of problems that are solvable in polynomial time.

The **class NP** consists of problems that are verifiable in polynomial time. If a problem is in class P, then it is also in class NP.

A problem is **NP-complete** if it is in NP and is as hard as any problem in NP. If any NP-complete problem can be solved in polynomial time, then every NP-complete problem can be solved in polynomial time.

We rely on 3 key concepts in showing a problem to be NP-complete:
1. **_Decision problems vs. optimization problems_**: If we can provide evidence that a decision problem is hard (e.g. finding shortest path), then we also provide evidence that its related optimization problem is hard as well (path minimization).
2. **_Reductions_**: A **reduction algorithm** transforms an instance of a problem into an instance of another problem that can be solved in polynomial time in polynomial time in order to find a solution. This same principle can be used to reduce a problem into another for which there is no known polynomial-time solution to show that such a problem is NP-complete.
3. **_The first NP-complete problem_**: The circuit-satifiability problem considers a set of AND, OR, and NOT gates where we wish to know whether the circuit's output given a set of boolean inputs is 0 or 1.

## 34.1 - Polynomial Time



## 34.2 - Polynomial-Time Verification

A **hamiltonian cycle** of an undirected graph is a simple cycle that contains each vertex in the graph. A graph that contains a hamiltonian cycle is said to be **hamiltonian**, otherwise it is **nonhamiltonian**.

To solve the hamiltonian cycle problem, one would need to check all permutations of the vertices in the graph, and check if each is a hamiltonian cycle. This runs in $\Omega(2^{\sqrt{n}})$, which is not polynomial time. This can be verified in polynomial time.

## 34.3 - NP-Completeness and Reducibility

The **circuit-satisfiability (SAT) problem** seeks to find whether there exists a boolean output of 1 for a given circuit made up of AND, OR, and NOT gates. In order to do this, we would have to check all $2^k$ inputs in the worst case, meaning that it would run in $\Omega(2^k)$.

## 34.4 - NP-Completeness Proofs

A boolean formula is in **conjunctive normal form (CNF)** if it is expressed as an AND of clauses, each of which is the OR of one or more literals. A boolean formula is in **3-conjunctive normal form (3-CNF)** if each clause has 3 distinct literals.

## 34.5 - NP-Complete Problems

A **clique** in an undirected graph is a subset of vertices, each pair of which is connected by an edge. The size of a clique is the number of vertices it contains. The **clique problem** asks us to check is a clique of size $k$ exists in a graph.

A **vertex cover** of an undirected graph is a subset of vertices that cover all edges (i.e. a subset for which every edge in the original graph is connected to one of the vertices in the new graph). The **vertex cover problem** is to find a vertex cover of minimum size in a given graph. The decision problem is to determine whether a graph has a vertex cover of a given size $k$.

In the **traveling-salesman problem**, a salesman must visit $n$ cities. Modeling the problem as a complete graph with $n$ vertices, we can say that the salesman wishes to make a tour, visiting each node exactly once and finishing at the city he starts from.

In the **subset-sum problem**, we are given a finite set of positive integers and an integer **target** $t > 0$.
