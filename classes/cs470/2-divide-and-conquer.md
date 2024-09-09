# 2 - Divide-and-Conquer

Format of **divide-and-conquer algorithms**:
- **Divide** the problem into a number of subproblems that are smaller instances of the same problem.
- **Conquer** the subproblems by solving them recursively. If the subproblem sizes are small enough, however, just solve the subproblems in a straightforward manner.
- **Combine** the solutions to the subproblems into the solution for the original problem.

When the subproblems are small enough that we do not need to solve them recursively, that is called the **base case**. When recursion is needed, it is called the **recursive case**.

## Recurrences

A **recurrence** is an equation or equality that describes a function in terms of its value on smaller inputs.

For example, the worst-case run-time $T(n)$ of the merge sort algorithm is given by:

$$
T(n) = \begin{cases}
	\Theta(1) & \text{if } n = 1, \\
	2T(\frac{n}{2}) + \Theta(n) & \text{if } n > 1
\end{cases}
$$

whose solution is $T(n) = \Theta(n \lg n)$.

**Master Recurrence Theorem**:

If $T(n) = aT(\frac{n}{b}) + \theta(n^k)$, then the solution is:
- $T(n) = \theta(n^k)$, if $\log_b(a) < k$ (or $a < b^k$)
- $T(n) = \theta(n^k \log(n))$, if $\log_b(a) = k$ (or $a = b^k$)
- $T(n) = \theta(n^{\log_b(a)})$, if $\log_b(a) > k$ (or $a > b^k$)

The main example for a divide-and-conquer algorithm is merge sort. To find its runtime, we must solve recursively:

$$
\begin{align*}
	T(n) &= 2 T(\frac{n}{2}) + \theta(n) \\
	\log_2(2) &= 1
\end{align*}
$$
Therefore, the runtime of merge sort is $\Theta(n \log(n))$.

Binary search:
$$
\begin{align*}
	T(n) &= T(\frac{n}{2}) + \theta(1) \\
	a=1, & b=1,
\end{align*}
$$

Sometimes, we find things that don't fit the form of the master theorem (e.g. $T(n) = T(\frac{n}{2}) + T(\frac{n}{4}) + \Theta(n)$). To solve in this case, we can use a substitution method.

## Polynomial Multiplication Problem

Given two polynomials:

$P = 5x^3 + 7x^2 + 6x + 2 = (5x + 7)x^2 + (6x + 2) = Ax^2 + B$

$Q = x^3 - 8x^2 + 9x - 1 = (x-8)x^2 + (9x-1) = Cx^2 + D$

$$
\begin{align*}
	A &= 5x + 7 \Rightarrow [5, 7] \\
	B &= 6x + 2 \Rightarrow [6, 2] \\
	C &= x - 8 \Rightarrow [1, -8] \\
	D &= 9x - 1 \Rightarrow [9, -1]
\end{align*}
$$

This yields four recursive subproblems: $A*C, B*C, A*D, B*D$

Analysis of this matrix multiplication algorithm:

$$
T(n) = 4T(\frac{n}{2}) + \theta(n) \\
a = 4, b = 2, k = 1 \\
\log_2 4 = 2 > 1 \\
\text{So } T(n) = \theta(n^{\log_b a}) = \theta(n^2)
$$

### Karatsuba's Algorithm

As before,

$$ P*Q = (Ax^{n/2} + B)(Cx^{n/2} + D) = (AC)x^n + (BC + AD)x^{n/2} + (BD) $$

This time, we write

$$ (BC + AD) = (A + B)(C + D) - (AC) - (BD) $$

As such, we only need three recursive calls:
- $A*C$
- $B*D$
- $(A+B)(C+D)$

Again, stop the recursion when when $n=1$.

Analysis of Karratsuba's algorithm:

$$
T(n) = 3T(\frac{n}{2}) + \theta(n) \\
a=3, b=2, k=1 \\
\log_2 3 > 1 \\
\text{So } T(n) = \theta(n^{\log_b a}) = \theta(n^{\lg 3}) \approx \theta(n^{1.58})
$$

## Matrix Multiplication Problem

If matrices $A$, $B$ are $n \times n$ matrices, then product $C=A*B$ is also an $n \times n$ matrix.

Example with $n=3$:

$$
\begin{bmatrix}
	1 & 2 & 3 \\
	4 & 5 & 6 \\
	7 & 8 & 9 
\end{bmatrix}
\begin{bmatrix}
	10 & 11 & 12 \\
	13 & 14 & 15 \\
	16 & 17 & 18 
\end{bmatrix}
=
\begin{bmatrix}
	1*10 + 2*13 + 3*16 & \dots & \dots \\
	\dots & \dots & \dots \\
	\dots & \dots & 7*12 + 8*15 + 9*18 
\end{bmatrix}
$$

### Naive Algorithm

Each element $C[i][j] = \sum_{1 \leq k \leq n} A[i][k] * B[k][j]$

The above formula leads to the following naive algorithm for computing the matrix $C$ in $O(n^3)$ total time:

```
for i = 1 to n {
	for j = 1 to n {
		C[i][j] = 0;
		for k = 1 to n {
			C[i][j] += A[i][k] * B[k][j];
		}
	}
}
```

### Naive Divide-and-Conquer Algorithm

Assume $n$ is even. Otherwise, add an extra row and column of all 0s. Stop the recursion when $n=1$.

$$
A = \begin{bmatrix}
	a_{1,1} & \dots & a_{1, n} \\
	\vdots & \ddots & \vdots \\
	a_{n,1} & \dots & a_{n,n}
\end{bmatrix},

B = \begin{bmatrix}
	b_{1,1} & \dots & b_{1, n} \\
	\vdots & \ddots & \vdots \\
	b_{n,1} & \dots & b_{n,n}
\end{bmatrix}
$$

Then write $A = \begin{bmatrix} S & T \\ U & V \end{bmatrix}$ and $B = \begin{bmatrix} W & X \\ Y & Z \end{bmatrix}$ where each of $S, T, U, V, W, X, Y, Z$ is a $\frac{n}{2} \times \frac{n}{2}$ matrix.

For example,

$$
S = \begin{bmatrix}
	a_{1,1} & \dots & a_{1, n/2} \\
	\vdots & \ddots & \vdots \\
	a_{n/2,1} & \dots & a_{n/2,n/2}
\end{bmatrix}
$$

$$
C = A*B = \begin{bmatrix}
	S & T \\
	U & V
\end{bmatrix}
\begin{bmatrix}
	W & X \\
	Y & Z
\end{bmatrix}
= \begin{bmatrix}
	S*W + T*Y & S*X + T*Z \\
	U*W + V*Y & U*X + V*Z
\end{bmatrix}
$$

This requires 8 recursive calls:
- $S*W$
- $S*X$
- $U*W$
- $U*X$
- $T*Y$
- $T*Z$
- $V*Y$
- $V*Z$

Analysis of the algorithm:

$$
T(n) = 8T(\frac{n}{2}) + \theta(n^2) \\
a=8, b=2, k=2 \\
\log_2 8 = 3 > 2 \\
\text{So } T(n) = \theta(n^3)
$$

Note that this is the same runtime as the naive algorithm.

### Strassen's Algorithm

Again, we write $A =\begin{bmatrix} S & T \\ U & V \end{bmatrix}$ and $B =\begin{bmatrix} W & X \\ Y & Z \end{bmatrix}$.

This requires 7 recursive calls:
- $P_1 = S * (X - Z)$
- $P_2 = (S + T) * Z$
- $P_3 = (U + V) * W$
- $P_4 = V * (Y - W)$
- $P_5 = (S + V) * (W + Z)$
- $P_6 = (T - V) * (Y + Z)$
- $P_7 = (U - S) * (W + X)$

$$
C = \begin{bmatrix}
	P_5 + P_4 - P_2 + P_6 & P_1 + P_2 \\
	P_3 + P_4 & P_5 + P_1 - P_3 + P_7
\end{bmatrix}
$$

Analysis of Strassen's algorithm:

$$
T(n) = 7 T(\frac{n}{2}) + \theta(n^2) \\
a = 7, b = 2, k = 2 \\
\log_2 7 > 2 \\
\text{So } T(n) = \theta(n^{\lg 7}) \approx \theta(n^{2.81})
$$

The current best known algorithm for matrix multiplication is about $\theta(n^{2.37})$ time. This is achieved by further extending the this divide-and-conquer approach, but the formulas are very complex.

## Majority Element Problem

Given an array $A$ of size $n$, does there exist any value $M$ that appears more than $\frac{n}{2}$ times in array $A$?

Majority element algorithm:
1. Use divide-and-conquer to find candidate value $M$.
2. Check if $M$ really is a majority element, $\theta(n)$ time, simple loop.

Phase 1 details:
- Divide:
  - Group the elements of $A$ into $\frac{n}{2}$ pairs
  - If $n$ is odd, there is one unpaired element $x$
    - Check if this $x$ is the majority element of $A$
    - If so, return $x$, but otherwise, discard $x$
  - Compare each pair $(y, z)$
    - If $y=z$, keep $y$ and discard $z$
    - If $y \ne z$, discard both $y$ and $z$
- Conquer: One recursive call on subarray of size $\leq \frac{n}{2}$
- Combine: Nothing remains to be done, so omit this step

Example:

```
A = [7, 7, 5, 2, 5, 5, 4, 5, 5, 5, 7]
	(7, 7) (5, 2) (5, 5) (4, 5) (5, 5) (7)
A = [7, 5, 5]
	(7, 5) (5)
# Return 5 (candidate, also majority)
```

```
A = [1, 2, 3, 1, 2, 3, 1, 2, 9, 9]
	(1, 2) (3, 1) (2, 3) (1, 2) (9, 9)
A = [9] ⇒ return 9 (candidate, but not majority)
```

Analysis of the algorithm:

Let $T(n) =$ running time of Phase 1 on array of size $n$:

$T(n) = T(\frac{n}{2}) + \theta(n)$
- Number of recursive subproblems = 1
- Size of each subproblem = $\frac{n}{2}$ [worst-case]
- Time for all the non-recursive steps = $\theta(n)$

$$
T(n) = T(\frac{n}{2}) + \theta(n) \\
a=1, b=2, k=1 \\
\log_2 1 = 0 < 1 \\
\text{So } T(n) = \theta(n^k) = \theta(n)
$$

## Selection Problem

Given an array `A[1...n]` and value $k$ where $1 \leq k \leq n$, find and return the $k$th smallest element in `A`.
- If $k=1$, minimum element
- If $k=n$, maximum element
- If $k=\frac{1+n}{2}$, median element

### Algorithm 1

- Sort `A` into ascending order
- return `A[k]`

This algorithm takes $\theta(n \lg n)$ time using mergre sort or heap sort.

This can be improved by not sorting the entire array.

### Algorithm 2

- Choose pivot element that is hopefully near the median of `A`
  - Can be anything, but random is generally the best to avoid the worst case scenario

```
Select(A, k) {
	pivot = ...;
	create 3 empty lists: L, E, G;
	for each x in A:
		if (x < pivot)
			add x to L;
		else if (x == pivot)
			add x to E;
		else
			add x to G;
		if (k <= L.size)
			return Select(L, k);
		else if (k <= L.size + E.size)
			return pivot
		else
			return Select(G, k - L.size - E.size)
}
```

Analysis of Algorithm 2:
- Best case: $\theta(n)$, if pivot happens to be the $k$th smallest element
- Worst case: $\theta(n^2)$, if pivot is always near the maximum or minimum value
- Average case: $\theta(n)$, if sometimes pivot yields a good split and sometimes a bad split, based on probabilities

Recurrence for worst case: $T(n) = T(n-1) + \theta(n)$ or $T(n) = T(n-2) + \theta(n)$

Recurrence for average case (assuming no duplicates):

$$ T(n) = \frac{1}{n} \sum_{1 \leq k \leq n} \left[\frac{k-1}{n}T(k-1) + \frac{n-k}{n}T(n-k) \right] + \theta(n) $$

Since this doesn't conform to the Master Recurrence Theorem, it is difficult to solve.

Note: If we could be very lucky to always guess the median element as the pivot, then

$$ T(n) = T(\frac{n}{2}) + \theta(n) \Rightarrow T(n) = \theta(n) $$

### Algorithm 3

- Same as Algorithm 2, except for a new pivot strategy:
  - Choose an odd number $g$ (later we'll see that $g=5$ is best)
  - Partition the $n$ elements into groups of size $g$ each (so the number of groups is $\frac{n}{g}$)
  - Find the median of each group (Note that we can sort each group in $\theta(g^2) = \theta(1)$ time)
  - Let $M$ be a list of all these group medians, so size of $M$ is $\frac{n}{g}$
  - Find the median of $M$ by calling Algorithm 3 recursively (Note: because we can't sort $M$ in $\theta(n)$ time)
  - Let pivot be the median of $M=\text{Select}(M, \frac{1 + \frac{n}{g}}{2})$

Stop the recursion when $n$ is below some threshold (such as $n < 3g$ or $n < g^2$), and solve using Algorithm 1 or 2.

Analysis of Algorithm 3:

Two recursive calls:
- Pivot - $\text{Select}(M, \frac{1 + \frac{n}{g}}{2})$
- Only one of $\text{Select}(L, k)$ or $\text{Select}(G, k - L.size - E.size)$

$$ T(n) = T(M.\text{size}) + T(\max(L.\text{size}, G.\text{size})) + \theta(n) $$
