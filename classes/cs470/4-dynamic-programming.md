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

## Matrix Chain Product (MCP)

Multiply chain of compatible matrices $M_1 M_2 M_3 \dots M_n$. Each matrix $M_j$ has $\text{D}[j-1]$ rows and $\text{D}[j]$ columns.

For example, $M_1 M_2 M_3$ where $\text{D}[0 \dots 3] = \{ 10, 20, 5, 30 \}$. $M_1$ is $10 \times 20$, $M_2$ is $20 \times 5$, and $M_3$ is $5 \times 30$.
- $(M_1 M_2) M_3$ takes $10*20*5 + 10*5*30 = 2500$ scalar products.
- $M_1 (M_2 M_3)$ takes $20*5*30 + 10*20*30 = 9000$ scalar products.

The goal is to compute $M_1 M_2 M_3 \dots M_n$ using the fewest scalar products.

Let $\text{Cost}[i][j]$ be the fewest scalar products to compute $M_i \dots M_j$. Note that $\text{Cost}[i][j] = 0$ when $i = j$.
- $\text{Cost}[i][j] = \min \{ \text{Cost}[i][k] + \text{Cost}[k+1][j] + \text{D}[i-1]*\text{D}[k]*\text{D}[j] | i \leq k \leq j-1 \}$ when $i < j$

### Dynamic Programming Algorithm

```
MATRIX-CHAIN-PRODUCT(D)
    Allocate arrays Cost[1..n][1..n] and Bestk[1..n][1..n]
    for i = 1 to n
        Cost[i][j] = 0
    for L = 2 to n
        for i = 1 to n-L+1
            j = i + L - 1
            Cost[i][j] = infinity
            for k = i to j-1
                t = Cost[i][k] + Cost[k+1][j] + D[i-1]*D[k]*D[j]
                if (t < Cost[i][j])
                    Cost[i][j] = t
                    Bestk[i][j] = k
```

The runtime of this algorithm is $\Theta(n^3)$
