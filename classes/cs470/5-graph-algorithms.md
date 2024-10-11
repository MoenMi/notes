# 5 - Graph Algorithms

These graph algorithms are covered in Chapter 22 of the textbook.

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

Running DFS creates a forest, which is a collection of trees, which contain the vertices and edges.

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
4. **Cross edges** are all other edges. They can connect depth-first trees or go between non-ancestor/descendant vertices in a depth-first tree.
