# Negative Binomial Distribution

The negative binomial distribution models the probability distribution of the number of independent Bernoulli trials required to observe a predetermined number of failures, where each trial has only two possible outcomes (success or failure) and the probability of success remains constant across all trials.

A negative binomial random variable is denoted as followed:

$$ X \sim \text{Negative Binomial}(r, p) $$

where
- $r$ = number of sucessess
- $p$ = probability of success in a Bernoulli trial

## Probability Mass Function (PMF)

$$
p_X(x) =
\begin{cases}
\binom{x-1}{r-1}p^r(1-p)^{x-r}, & \text{if } x=r, r+1, r+2, \dots \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation



## Variance