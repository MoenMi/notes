# Discrete Uniform Distributions

A discrete uniform distribution is a probability distribution where all distinct outcomes within a finite range have equal probability of occurring, and outcomes outside this range have zero probability.

## Discrete Uniform $(1, N)$

This form of the discrete uniform distribution has a lower bound of 1 and an upper bound of $N$.

### Probability Mass Function (PMF)

The discrete uniform distribution has the following pmf:

$$
p_X(x) =
\begin{cases}
    \frac{1}{N} & \text{if } x = 1, 2, ..., N \\
    0 & \text{otherwise}
\end{cases}
$$

### Expectation

From the pmf, we can derive $E(X)$:

$$
\begin{align}
EX &= \sum_{x=1}^{N} \frac{1}{N} \ x \\
&= \frac{1}{N} \ \frac{N(N+1)}{2} \\
&= \frac{N+1}{2}
\end{align}
$$

### Variance

We can also derive the variance $Var(X)$:

$$ Var(X) = EX^2 - (EX)^2 $$

Since we've already found $E(X)$, we only need to find $E(X^2)$:

$$
\begin{align}
EX^2 &= \sum_{x=1}^N \frac{1}{N} \ x^2 \\
&= \frac{1}{N} \ \frac{N(N+1)(2N+1)}{6} \\
&= \frac{(N+1)(2N+1)}{6}
\end{align}
$$

Now, we can solve for $Var(X)$:

$$
\begin{align}
Var(X) &= EX^2 - (EX)^2 \\
&= \frac{(N+1)(2N+1)}{6} - \left[\frac{N+1}{2}\right]^2 \\
&= \frac{2N^2+3N+1}{6} - \frac{N^2+2N+1}{4} \\
&= \frac{N^2-1}{12} \\
\end{align}
$$

## Discrete Uniform $(N_0, N_1)$

The discrete uniform distribution above can be generalized from $\text{Uniform}(1, N)$ to $\text{Uniform}(N_0, N_1)$.

$$
X \sim \text{Uniform}(1, N_1 - N_0 + 1) \\
Y = X + (N_0 - 1)\sim \text{Uniform}(N_0, N_1)
$$

### Probability Mass Function (PMF)

$$
p_X(x) =
\begin{cases}
    \frac{1}{N_1 - N_0 + 1} & \text{if } x = N_0, N_0 + 1, ..., N_1 - 1, N_1 \\
    0 & \text{otherwise}
\end{cases}
$$

### Expectation

We can use $Y$ to derive the expectation of the distribution:

$$
\begin{align}
EY = E(X + N_0 - 1) &= EX + N_0 - 1 \\
&= \frac{N_1 - N_0 + 1 + 1}{2} + N_0 - 1 \\
&= \frac{N_1 + N_0}{2}
\end{align}
$$

### Variance

Once again, we can use $Y$ to derive the variance of the distribution:

$$
\begin{align}
Var(Y) = Var(X+N_0-1) &= Var(X) + N_0 - 1 \\
&= \frac{(N_1 - N_0 + 1)^2 - 1}{12} + N_0 - 1 \\
&= \frac{(N_1 - N_0)(N_1 - N_0 + 2)}{12}
\end{align}
$$