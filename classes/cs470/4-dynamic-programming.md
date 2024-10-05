# 4 - Dynamic Programming

Format of dynamic programming algorithms:
- Use a recursive formula
- But recursion can be inefficient because it might repeat the same computations multiple times
- So use an array to store and lookup the subproblem results as needed

## Fibonacci Numbers

$$ 1, 1, 2, 3, 5, 8, 13, 21, 34, \dots $$

- $F(0) = 1$
- $F(1) = 1$
- $F(n) = F(n - 2) + F(n - 1)$, when $n \geq 2$

### Recursive (Naive) Approach

```
int F(int n) {
    if (n == 0 || n == 1)
        return 1
    else
        return F(n-2) + F(n-1)
}
```

Recursion as in the example above yields repeated subproblems, so its runtime is exponential.

### Bottom-Up Approach (Table, No Recursion)

```
Allocate array A[0..n]
for (k = 0; k <= n; k++)
    if (k == 0 || k == 1)
        A[k] = 1
    else
        A[k] = A[k-2] + A[k-1]
return A[n]
```

Runtime: $\Theta(n)$

### Top-Down Approach (Table and Recursion)

```
Allocate array A[0..n]
for (k = 0; k <= n; k++)
    A[k] = null
return F(n)

int F(int n) {
    if (A[n] != null)
        return A[n]
    if (n == 0 || n == 1)
        A[n] = 1
    else
        A[n] = F(n-2) + F(n-1)
    return A[n]
}
```

Runtime: $\Theta(n)$

## Combinations

$$ _nC_k = \binom{n}{k} = \frac{n!}{k! (n-k)!} $$

Pascal's recursive formula for combinations:

```
C(n, 0) = 1
C(n, n) = 1
C(n, k) = C(n-1, k-1) + C(n-1, k), when 0 < k < n
```

```
int C(int n, int k) {
    if (k == 0 || k == n)
        return 1
    else
        return C(n-1, k-1) + C(n-1, k)
}
```

Again, recursion yields repeated subproblems, so runtime is exponential.

### Pascal's Triangle (DP Approach)

```
Allocate array C[0..n][0..k]
for(m=0; m<=n; m++)
    for(j=0; j<=k; j++)
        if (j == 0 || j == m)
            C[m][j] = 1
        else
            C[m][j] = C[m-1][j-1] + C[m-1][j]
return C[n][k]
```

Runtime: $\Theta(nk) = \Theta(n^2)$, because $k \leq n$

## 0-1 Knapsack Problem

- Objects $\{ 1 \dots n \}$
- Profits $P[ 1 \dots n ]$
- Weights $W[ 1 \dots n ]$
- Maximum weight capacity $M$

0-1 Constraint: Must take none (0) or all (1) of each of object.

Goal: Determine the amounts $X[1 \dots n]$ for each object so that $\sum_{1 \leq k \leq n} X[k] * W[k] \leq M$, and $\sum_{1 \leq k \leq n} X[k] * P[k]$ is as large as possible. Each $X[j]$ must be either $0$ or $1$.

### Recursive Function

- $T(n, M)$ is the max possible total profit such that we choose any subset of objects $\{ 1 \dots n \}$ and maximum weight capacity is $M$.
- $T(j, k)$ is the max possible total profit such that we can only choose from objects $\{ 1 \dots j \}$ and maximum weight capacity is $k$.
  - $(0 \leq j \leq n, 0 \leq k \leq M)$

Formulation:
- $T(j, k) = 0$, if $j == 0$
- $T(j, k) = T(j-1, k)$, if $j > 0$ and $k < W[j]$
- $T(j, k) = \max \{ T(j-1, k), T(j-1, k-W[j]) + P[j] \}$ if $j > 0$ and $k \geq W[j]$

```
int T(int j, int k) {
    if (j == 0)
        return 0
    if (k < W[j])
        return T(j-1, k)
    return max{T(j-1, k), T(j-1, k-W[j]) + P[j]}
}
```

### Dynamic Programming Algorithm

```
Allocate array T[0..n][0..M]
for j = 0 to n
    for k = 0 to M
        if (j == 0)
            T[j][k] = 0
        else if (k < W[j])
            T[j][k] = T[j-1][k]
        else
            T[j][k] = max{T[j-1][k], T[j-1][k-W[j]] + P[j]}
```

Runtime: $\Theta(nM)$

### Example

- $n = 4$
- $M = 8$

|  | 1 | 2 | 3 | 4 |
| - | - | - | - | - |
| P | 12 | 15 | 16 | 18 |
| W | 2 | 3 | 4 | 6 |

| T | k=0 | k=1 | k=2 | k=3 | k=4 | k=5 | k=6 | k=7 | k=8 |
| - | - | - | - | - | - | - | - | - | - |
| $j=0$ | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| $j=1$ | 0 | 0 | 12 | 12 | 12 | 12 | 12 | 12 | 12 |
| $j=2$ | 0 | 0 | 12 | 15 | 15 | 27 | 27 | 27 | 27 |
| $j=3$ | 0 | 0 | 12 | 15 | 16 | 27 | 28 | 31 | 31 |
| $j=4$ | 0 | 0 | 12 | 15 | 16 | 27 | 28 | 31 | 31 |

So the max total profit is 31, but which objects do we need to choose? We still need to assign each $X[j]$ with either 0 or 1.

```
k = M
for (j=n; j>0; j--)
    if (T[j-1][k] == T[j][k])
        X[j] = 0
    else
        { X[j] = 1 }
        { k -= W[j] }
```

This takes $\Theta(n)$ additional time.

## Longest Common Subsequence (LCS)

Given two strings:
- $X[1 \dots m]$
- $Y[1 \dots n]$

Goal: Find a string that is a subsequence of both $X$ and $Y$, and that has the largest possible length.

Example:
- $X=$ "bdacbea", $m=7$
- $Y=$ "dcbaecba", $n=8$
- $\text{LCS}(X, Y) =$ "dacba"

### Recursive Function for LCS

- $\text{L}(m, n) =$ length of the LCS of $X[1 \dots m]$ and $Y[1 \dots n]$
- $\text{L}(j, k) =$ length of the LCS of $X[1 \dots j]$ and $Y[1 \dots k] (0  \leq j \leq m, 0 \leq k \leq n)$

Formulation:
- $\text{L}(m, n) = 0$ if $j = 0$ or $k = 0$
- $\text{L}(m, n) = \text{L}(j-1, k-1) + 1$ if $j > 0, k > 0,$ and $X[j] = Y[k]$
- $\text{L}(m, n) = \max \{ \text{L}(j-1, k), \text{L}(j, k-1) \}$ if $j > 0, k > 0,$ and $X[j] \ne Y[k]$

```
int L(int j, int k) {
    if (j == 0 || k == 0)
        return 0
    if (X[j] == Y[k])
        return L(j-1, k-1) + 1
    return max{L(j-1, k), L(j, k-1)}
}
```

The runtime of this function is exponential due to repeated subproblems.

### Dynamic Programming Algorithm

```
Allocate array L[0..m][0..n]
for j = 0 to m
    for k = 0 to n
        if (j == 0 || k == 0)
            L[j][k] = 0
        else if (X[j] == Y[k])
            L[j][k] = L[j-1][k-1] + 1
        else
            L[j][k] = max{L[j-1][k], L[j][k-1]}
```

Runtime: $\Theta(mn)$

### Example

- $X=$ "bdacbea", $m=7$
- $Y=$ "dcbaecba", $n=8$

| L | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| - | - | - | - | - | - | - | - | - | - |
| **0** | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| **1** | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 |
| **2** | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| **3** | 0 | 1 | 1 | 1 | 2 | 2 | 2 | 2 | 2 |
| **4** | 0 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 3 |
| **5** | 0 | 1 | 2 | 3 | 3 | 3 | 3 | 4 | 4 |
| **6** | 0 | 1 | 2 | 3 | 3 | 4 | 4 | 4 | 4 |
| **7** | 0 | 1 | 2 | 3 | 4 | 4 | 4 | 4 | 5 |

How can we find an LCS that has length 5?

```
string buildLCS(j, k) {
    if (L[j][k] == 0)
        return ""
    else if (X[j] == Y[k])
        return buildLCS(j-1, k-1) + X[j]
    else if (L[j][k-1] == L[j][k])
        return buildLCS(j, k-1)
    else
        return buildLCS(j-1, k)
}
```

Runtime: $\Theta(m+n)$
- Assumes we append characters in $\Theta(1)$ time.
- This is possible because we know the final string length $\text{L}(m, n)$ in advance.
- Can allocate an array of size $\text{L}(m, n)$ chars in advance, or replace recursion by iteration.

## Optimal Binary Search Tree (BST)

Construct a BST with Key$_1$ < Key$_2$ < Key$_3$ < $\dots$ < Key$_n$. The frequency of searching for each Key$_i$ is $\text{F}[i]$.

Example: Key$[1..3] = \{ a, b, c \}$ and $\text{F}[1..3] = \{ 0.3, 0.5, 0.2 \}$.

Goal: Construct the BST with the minimum expected search cost.

Let $\text{Cost}[i][j]$ be the minimum expected search cost for a BST with Key$[i..j]$.
1. Find the best choice Key$[r]$ for the root node.
2. Left subtree has Key$[i..r-1]$.
3. Right subtree has Key$[r+1..j]$

Formulation:
- $\text{Cost}[i][j] = 0$ when $i > j$
- $\text{Cost}[i][j] = \text{F}[i]$ when $i = j$
- $\text{Cost}[i][j] = \min \{ \text{Cost}[i][r-1] + \text{Cost}[r+1][j] + \sum_{i \leq k \leq j} \text{F}[k] \ \ | \ \ i \leq r \leq j \}$ when $i < j$

For efficiency, define $\text{W}[i][j] = \sum_{i \leq k \leq j} \text{F}[k]$
- $\text{Cost}[i][j] = \min \{ \text{Cost}[i][r-1] + \text{Cost}[r+1][j] + \text{W}[i][j] \ \ | \ \ i \leq r \leq j \}$ when $i < j$

### Dynamic Programming Algorithm

```
Allocate arrays Cost[1..n+1][0..n], W[1..n+1][0..n], and Root[1..n+1][0..n]

for i = 0 to n
    Cost[i+1][i] = 0
    W[i+1][i] = 0
for L = 1 to n
    for i = 1 to n-L+1
        j = i+L-1
        Cost[i][j] = infinity
        W[i][j] = W[i][j-1] F[j]
        for r = i to j
            t = Cost[i][r-1] + Cost[r+1][j] + W[i][j]
            if (t < Cost[i][j])
                Cost[i][j] = t
                Root[i][j] = r
```

Runtime: $\Theta(n^3)$

Example: $n=3, \text{F}[1..3] = \{ 0.3, 0.5, 0.2 \}$

Next build the BST to achieve the minimum expected search cost.

```
BuildBST(i, j) {
    if (i > j)
        return null
    r = Root[i][j]
    left = BuildBST(i, r-1)
    right = BuildBST(r+1, j)
    return new Node(Key[r], left, right)
}

tree = BuildBST(1, n)
```

## All-Pairs Shortest Paths

Given a weighted (undirected or directed) graph, find a minimum-distance path from each start vertex to each destination vertex.
- Restriction: We allow edges with negative weights, but not any cycle with negative total weight.

### Floyd's Algorithm

```
// initialize D0 = weighted adjacency matrix
for X = 1 to n
    for Y = 1 to n
        if (X == Y)
            D0[X, Y] = 0
        else if (edge (X, Y) exists)
            D0[X, Y] = weight(X, Y)
        else
            D0[X, Y] = infinity

// compute each Dz matrix values in the D_{z-1} matrix
for Z = 1 to n
    for X = 1 to n
        for Y = 1 to n
            if (D_{z-1}[X, Z] + D_{z-1}[Z, Y] < D_{z-1} matrix)
                Dz[X, Y] = D_{z-1}[X, Z] + D_{z-1}[Z, Y]
            else
                Dz[X, Y] = D_{z-1}[X, Y]
```

Runtime: $\Theta(n^3)$

Memory usage: $\Theta(n^3)$
- The memory usage can be improved to $\Theta(n^2)$ by letting $D$ be a 2-D array

```
for X = 1 to n
    for Y = 1 to n
        if (X == Y)
            D[X, Y] = 0
        else if (edge (X, Y) exists)
            D[X, Y] = weight(X, Y)
        else
            D[X, Y] = infinity

for Z = 1 to n
    for X = 1 to n
        for Y = 1 to n
            if (D[X, Z] + D[Z, Y] < D[X, Y])
                D[X, Y] = D[X, Z] + D[Z, Y]
```

To determine if the graph has a negative cycle:

```
boolean hasNegativeCycle() {
    for X = 1 to n
        if (D[X, Y] < 0)
            return true
    return false
}
```

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

### Dynamic Programming Algorithm

```
Allocate array X[0..n][0..n]
for (i=0; i<=n; i++)
    for (j=0; j<=n; j++)
        if (i == 0 && j == 0)
            X[i][j] = 1
        else if (i == n && j == n)
            X[i][j] = 0
        else if ((i > 0 && j == 0) || (i == n && j < n))
            X[i][j] = X[i-1][j] * p[i+j]
        else if ((i == 0 && j > 0) || (i < n && j == n))
            X[i][j] = X[i][j-1] * (1 - p[i+j])
        else
            X[i][j] = X[i-1][j] * p[i+j] + X[i][j-1] * (1 - p[i+j])
```

Runtime: $\Theta(n^2)$

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
