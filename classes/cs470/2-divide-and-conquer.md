# 2 - Divide-and-Conquer

Format of Divide-and-Conquer algorithms:
- Divide: Split the array or list into smaller problems

Master Recurrence Theorem:

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

### Polynomial Multiplication Problem

Given two polynomials:

$P = 5x^3 + 7x^2 + 6x + 2 = (5x + 7)x^2 + (6x + 2) = Ax^2 + B$
$Q = x^3 - 8x^2$