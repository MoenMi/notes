# 5 - Graph Algorithms

These graph algorithms are covered in Chapters 22-24 of the textbook.

A **graph** is a set of vertices and edges.
- Edges may be directed or undirected.
- Edges may have weight.

There are 2 main ways to represent a graph:
- An **adjacency-list representation** is an array of size $n$, where $n$ is the number of vertices in the graph. Each item in the array is a list of the vertices connected to that vertex by an edge.
- An **adjacency matrix** represents the connections between vertices in a graph.

## 22.2 - Breadth-first Search

**Breadth-first search (BFS)** searches for a vertex from a starting vertex by systematically visiting every vertex in order of closeness to the source vertex.

```
BFS(G, s)
    for each vertex u in G.V - {s}
        u.color = WHITE
        u.d = infinity
        u.pi = NIL
    s.color = GRAY
    s.d = 0
    Q = {}
    ENQUEUE(Q, s)
    while Q != {}
        u = DEQUEUE(Q)
        for each v in G.Adj[u]
            if v.color == WHITE
                v.color = GRAY
                v.d = u.d + 1
                v.pi = u
                ENQUEUE(Q, v)
        u.color = BLACK
```

Runtime: $O(V + E)$

## 22.3 - Depth-first Search

Unlike BFS, which creates one tree of the nodes visited, DFS creates a set of trees, or a **depth-first forest** composed of several **depth-first trees**.

```
DFS(G)
    for each vertex u in G.V
        u.color = WHITE
        u.pi = NIL
    time = 0
    for each vertex u in G.V
        if u.color == WHITE
            DFS-VISIT(G, u)

DFS-Visit(G, u)
    time = time + 1
    u.d = time
    u.color = GRAY
    for each v in G.Adj[u]
        if v.color == WHITE
            v.pi = u
            DFS-VISIT(G, v)
    u.color = BLACK
    time = time + 1
    u.f = time
```

Runtime: $O(V + E)$

### Classification of Edges

1. **Tree edges** are edges in the depth-first forest. $\text{Edge}(u, v)$ is a tree edge if $v$ was first discovered by exploring edge $(u, v)$.
2. **Back edges** are edges that connect back to an ancestor in a depth-first tree. We conider self-loops to be back edges.
3. **Forward edges** are nontree edges connecting a vertex to a descendant in a depth-first tree.
4. **Cross edges** are all other edges. They can connect depth-first trees or go between non-ancestor/descendant nodes in a depth-first tree.

The DFS algorithm has enough information to classify some edges as it encounters them. The key idea is that when we first explore an edge $(u, v)$, the color of the vertex $v$ tells us sosmething about the edge:
1. $\text{WHITE}$ indicates a tree edge
2. $\text{GRAY}$ indicates a back edge
3. $\text{BLACK}$ indicates a forward or cross edge

Note that it can be proven that a graph is acyclic if its DFS does not produce a black edge.

## 22.4 - Topological Sort

A **directed acyclic graph (dag)** is a graph with directed edges and no cycles, as the name implies.

A **topological sort** of a dag $G = (V, E)$ is a linear ordering of all its vertices such that if $G$ contains an edge $(u, v)$, then $u$ appears before $v$ in the ordering. We can view a topological sort of a graph as an ordering of its vertices along a horizontal line so that all directed edges go from left to right.

The following algorithm topologically sorts a dag:

```
TOPOLOGICAL-SORT(G)
    call DFS(G) to compute finishing times v.f for each vertex V
    as each vertex is finished, insert it into the front of a linked list
    return the linked list of vertices
```

Runtime: $\Theta(V + E)$

## 23 - Minimum Spanning Trees

Both Kruskal's algorithm and Prim's algorithm are greedy algorithms that run in $O(E \lg V)$ using binary heaps, or $O(E + V \lg V)$ using Fibonacci heaps.

### Kruskal's Algorithm

Kruskal's algorithm grows its minimum spanning tree by starting with the edge of the least weight.

```
MST-KRUSKAL(G, w)
    A = {}
    for each vertex v in G.V
        MAKE-SET(v)
    sort the edges of G.E into nondecreasing order by weight w
    for each edge (u, v) in G.E, taken in nondecreasing order by weight
        if FIND-SET(u) != FIND-SET(v)
            add {(u, v)} to A
            UNION(u, v)
    return A
```

### Prim's Algorithm

Prim's algorithm starts with one vertex in the graph, and greedily adds the best edge on its frontier to the MST.

```
MST-PRIM(G, w, r)
    for each u in G.V
        u.key = infinity
        u.pi = NIL
    r.key = 0
    Q = G.V
    while Q != {}
        u = EXTRACT-MIN(Q)
        for each v in G.Adj[u]
            if v in Q and w(u, v) < v.key
                v.pi = u
                v.key = w(u, v)
```

## 24 - Single-Source Shortest Paths

The algorithms in this chapter use a technique called **relaxation**. For each vertex $v \in V$, we maintain a **shortest-path estimate** $v.d$. We initialize all shortest-path estimates to infinity.

The process of relaxing an edge $(u, v)$ consists of checking whether we can improve the shortest path to $v$ by going through $u$. If so, we update $v.\pi$ and $v.d$.

### 24.1 - Bellman-Ford Algorithm

The **Bellman-Ford algorithm** returns a boolean value indicating that there are negative cycles if there is one, and a single-source shortest-path tree if there isn't. The algorithm relaxes edges until it achieves the actual shortest-path weight for each vertex.

```
BELLMAN-FORD(G, w, s)
    INITIALIZE-SINGLE-SOURCE(G, s)
    for i = 1 to |G.V| - 1
        for each edge (u, v) in G.E
            RELAX(u, v, w)
    for each edge (u, v) in G.E
        if v.d > u.d + w(u, v)
            return False
    return True
```

Runtime: $\Theta(VE)$

### 24.3 - Dijkstra's Algorithm

Dijkstra's algorithm is just Prim's algorithm but you relax edges.

## 26 - Maximum Flow
