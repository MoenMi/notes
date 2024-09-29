# 4 - Dynamic Programming

## All-Pairs Shortest Paths

Given a weighted (undirected or directed) graph, find a minimum-distance path from each start vertex to each destination vertex.
- Restriction: We allow edges with negative weights, but not any cycle with negative total weight.



## World Series Problem

- Teams A and B compete in a series of games.
- The winner is the first team to win $n$ games.
- The series ends as soon as the winner is decided.
- At most, $2n-1$ games are played.
- For $1 \leq k \leq 2n-1$, let `p[k]` be the probability that team A wins the $k$th game (These are the input values).
- For $0 \leq i \leq n$ and $0 \leq j \leq n$, let `X(i, j)` be the probability that the series reaches a situation where team A wins exactly $i$ games and team B wins exactly $j$ games (These are the output values).

First, we develop a recursive formula:

```
X(0, 0) = 1
X(n, n) = 0
X(i, 0) = X(i-1, 0) * p[i], for i>0
X(0, j) = X(0, j-1) * (1 - p[j]), for j>0
X(n, j) = X(n-1, j) * p[n+j], for j<n
X(i, n) = X(i, n-1) * (1 - p[i+n]), for i<n
X(i, j) = X(i-1, j) * p[i+j] + X(i, j-1) * (1 - p[i+j]), for 0<i<n and 0<j<n
```
