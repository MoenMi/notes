# Formulas

## Discrete Distributions

### Discrete Uniform $(1, N)$

$$
p_X(x) =
\begin{cases}
    \frac{1}{N} & \text{if } x = 1, 2, ..., N \\
    0 & \text{otherwise}
\end{cases}
$$

$$ E(X) = \frac{N+1}{2} $$

$$ Var(X) = \frac{N^2-1}{12} $$

### Discrete Uniform $(N_0, N_1)$

$$
p_X(x) =
\begin{cases}
    \frac{1}{N_1 - N_0 + 1} & \text{if } x = N_0, N_0 + 1, ..., N_1 - 1, N_1 \\
    0 & \text{otherwise}
\end{cases}
$$

$$ E(X) = \frac{N_1 + N_0}{2} $$

$$ Var(X) = \frac{(N_1 - N_0)(N_1 - N_0 + 2)}{12} $$

### Hypergeometric $(N, M, n)$

$$
p_X(x) = 
\begin{cases}
\frac{\binom{M}{x} \binom{N-M}{n-x}}{\binom{N}{n}} & x=0,1,...,n \\
0, & \text{otherwise}
\end{cases}
$$

$$ E(X) = \frac{nM}{N} $$

$$ Var(X) = n \frac{M}{N}(1 - \frac{M}{N})(\frac{N-n}{N-1}) $$


## Continuous Distributions

## Summations

### Sum of Arithmetic Series

$$ \sum_{x=1}^N x = \frac{N(N+1)}{2} $$

### Pascal's Rule

$$ \binom{n}{r} = \frac{n}{r} \binom{n-1}{r-1} $$
