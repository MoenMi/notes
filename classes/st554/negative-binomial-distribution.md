# Negative Binomial Distribution

The negative binomial distribution models the probability distribution of the number of independent Bernoulli trials required to observe a predetermined number of failures, where each trial has only two possible outcomes (success or failure) and the probability of success remains constant across all trials.

A negative binomial random variable is denoted as followed:

$$ X \sim \text{Negative Binomial}(r, p) $$

where
- $r$ = number of sucessess
- $p$ = probability of success in a Bernoulli trial

## Probability Mass Function (PMF)

The pmf of the negative binomial distribution is as follows:

$$
p_X(x) =
\begin{cases}
\binom{x-1}{r-1}p^r(1-p)^{x-r}, & \text{if } x=r, r+1, r+2, \dots \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

To derive the expected value of the negative binomial distribution, we must first note the following:

$$ X = W_1 + W_2 + \dots + W_r = \sum_{i=1}^rW_i $$

where

$$ W_1, W_2, \dots, W_r \sim \text{Geometric}(p) $$

Because we know that the expected value of the geometric distribution is $\frac{1}{p}$, we can use this to evaluate the expected value of the negative binomial distribution:

$$
\begin{align}
EX &= E \left( \sum_{i=1}^r W_i \right) \\
&= \frac{r}{p}
\end{align}
$$

## Variance

We can similarly evaluate the variance of the negative binomial distribution:

$$ Var(X) = \frac{r(1-p)}{p^2} $$