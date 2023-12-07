# Discrete Distributions

## Discrete Uniform (1, N)

The discrete uniform distribution has the following pmf:

$$
p_X(x) =
\begin{cases}
    \frac{1}{N} & \text{if } x = 1, 2, ..., N \\
    0 & \text{otherwise}
\end{cases}
$$

From this, we can derive $E(X)$:

$$
\begin{align}
EX &= \sum_{x=1}^{N} \frac{1}{N} * x \\
&= \frac{1}{N} * \frac{N(N+1)}{2} \\
&= \frac{N+1}{2}
\end{align}
$$

We can also derive the variance $Var(X)$:

$$ Var(X) = EX^2 - (EX)^2 $$

Since we've already found $E(X)$, we only need to find $E(X^2)$:

$$
\begin{align}
EX^2 &= \sum_{x=1}^N \frac{1}{N} * x^2 \\
&= \frac{1}{N} * \frac{N(N+1)(2N+1)}{6} \\
&= \frac{(N+1)(2N+1)}{6}
\end{align}
$$