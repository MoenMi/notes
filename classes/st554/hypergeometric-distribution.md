# Hypergeometric Distribution

The hypergeometric distribution models the probability of obtaining a specified number of successes in a fixed number of draws without replacement from a finite population containing a known number of successes and failures.

A hypergeometric random variable is denoted:

$$ X \sim \text{Hypergeometric}(N, M, n) $$

where
- $N$ = total number of objects available
- $M$ = total number of possible successes
- $n$ = sample size
- $x$ = number of successes in the sample

## Probability Mass Function (PMF)

The pmf of the hypergeometric distribution is as follows:

$$
p_X(x) = 
\begin{cases}
\frac{\binom{M}{x} \binom{N-M}{n-x}}{\binom{N}{n}} & x=0,1,...,n \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

The expectation of the hypergeometric distribution is derived as follows.

$$
\begin{align}
EX &= \sum_{x=0}^n x \ p_X(x) \\
&= \sum_{x=0}^n x\frac{\binom{M}{x} \binom{N-M}{n-x}}{\binom{N}{n}} \\
&= \sum_{x=1}^n x \frac{\frac{M}{x} \binom{M-1}{x-1} \binom{N-M}{n-x}}{\frac{N}{n} \binom{N-1}{n-1}} \\
&= \frac{nM}{N} \sum_{x=0}^n \frac{\binom{M-1}{x-1} \binom{N-M}{n-x}}{\binom{N-1}{n-1}} \\
&= \frac{nM}{N} \sum_{y=0}^{n-1} \frac{\binom{M-1}{y} \binom{N-1-(M-1)}{n-1-y}}{\binom{N-1}{n-1}} \\
&= \frac{nM}{N} \sum_{y=0}^{n-1} p_Y(y) \\
&= \frac{nM}{N}
\end{align}
$$

Note the following:
- In line (3), we the following: $\binom{M}{x} = \frac{M}{x} \binom{M-1}{x-1}$.
- In line (5), the variable $x$ is substituted for $y=x-1$
- When going from line (5) to line (6), we recognize that the summation is equal to $1$ since $Y \sim \text{Hypergeometric}(N-1,M-1,n-1)$

## Variance

Here is the variance of the hypergeometric distribution:

$$ Var(X) = n \frac{M}{N}(1 - \frac{M}{N})(\frac{N-n}{N-1}) $$