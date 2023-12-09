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

### Bernoulli Distribution $(p)$

$$
p_X(x) =
\begin{cases}
p, & \text{if } x = 1 \\
1-p, & \text{if } x = 0 \\
0, & \text{otherwise}
\end{cases}
=\begin{cases}
p^x(1-p)^{1-x}, & \text{if } x = 0, 1 \\
0, & \text{otherwise}
\end{cases}
$$

$$ EX = p $$

$$ Var(X) = p(1-P) $$

### Binomial Distribution $(n, p)$

$$
p_X(x) = 
\begin{cases}
\binom{n}{x}p^x(1-p)^{n-x}, & \text{if } x=0,1,...,n \\
0, & \text{otherwise}
\end{cases}
$$

$$ E(X) = np $$

$$ Var(X) = np(1-p) $$

### Geometric Distribution $(p)$

$$
p_X(x) =
\begin{cases}
p(1-p)^{x-1}, & \text{if } x=1,2,\dots \\
0, & \text{otherwise}
\end{cases}
$$

$$ E(X) = \frac{1}{p} $$

$$ Var(X) = \frac{1-p}{p^2} $$

### Negative Binomial Distribution $(r,p)$

$$
p_X(x) =
\begin{cases}
\binom{x-1}{r-1}p^r(1-p)^{x-r}, & \text{if } x=r, r+1, r+2, \dots \\
0, & \text{otherwise}
\end{cases}
$$

$$ X = W_1 + W_2 + \dots + W_r = \sum_{i=1}^rW_i $$
$$ W_1, W_2, \dots, W_r \sim \text{Geometric}(p) $$

$$ EX = \frac{r}{p} $$

$$ Var(X) = \frac{r(1-p)}{p^2} $$

### Poisson Distribution $(\lambda)$

$$
p_X(x) =
\begin{cases}
\frac{e^{-\lambda} \lambda^x}{x!}, & \text{if } x = 0, 1, 2, \dots \\
0, & \text{otherwise}
\end{cases}
$$

$$ E(X) = \lambda $$

$$ Var(X) = \lambda $$

## Continuous Distributions



## Summations

### Sum of Arithmetic Series

$$ \sum_{x=1}^N x = \frac{N(N+1)}{2} $$

### Sum of Geometric Series

$$ \sum_{n=0}^\infty ar^n = \frac{a}{1-r} $$

### Pascal's Rule

$$ \binom{n}{r} = \frac{n}{r} \binom{n-1}{r-1} $$
