# Binomial Distribution

The binomial distribution models the probability distribution of the number of successes in a fixed number of independent Bernoulli trials, where each trial has only two possible outcomes (success or failure) and the probability of success remains constant across all trials.

A binomial random variable is denoted as follows:

$$ X \sim \text{Binomial}(n, p) $$

## Probability Mass Function (PMF)

The pmf of the binomial distribution is as follows:

$$
p_X(x) = 
\begin{cases}
\binom{n}{x}p^x(1-p)^{n-x}, & \text{if } x=0,1,...,n \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

The expectation of the binomial distribution can be derived as follows:

$$
\begin{align}
EX &= \sum_{x=0}^n x p_X(x) \\
&= \sum_{x=0}^n x \binom{n}{x}p^x(1-p)^{n-x} \\
&= n \sum_{x=1}^n \binom{n-1}{x-1}p^x(1-p)^{n-x} \\
&= np \sum_{x=1}^n \binom{n-1}{x-1}p^{x-1}(1-p)^{n-x} \\
&= np \sum_{y=0}^n \binom{n-1}{y}p^{y-1}(1-p)^{n-1-y} \\
&= np \sum_{y=0}^n p_Y(y) \\
&= np
\end{align}
$$

Notes:
- In line (5), we substitute in $y=x-1$
- In line (6), we recognize that $Y \sim \text{Hypergeometric}(n-1, p)$, whose summation must be equal to $1$

## Variance

A similar process can be used to derive the variance of the binomial distribution:

$$ Var(X) = np(1-p) $$
