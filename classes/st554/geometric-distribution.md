# Geometric Distribution

The geometric distribution models the probability distribution of the number of independent Bernoulli trials needed to achieve the first success, where each trial has only two possible outcomes (success or failure) and the probability of success remains constant across all trials.

A geometric random variable is denoted as followed:

$$ X \sim \text{Geometric}(p) $$

## Probability Mass Function (PMF)

The pmf of the geometric distribution is as follows:

$$
p_X(x) =
\begin{cases}
p(1-p)^{x-1}, & \text{if } x=1,2,\dots \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

The expected value of the geometric distribution is derived as follows:

$$
\begin{align}
EX &= \sum_{x=1}^\infty xp_X(x) \\
&= \sum_{x=1}^\infty xp(1-p)^{x-1} \\
&= p \sum_{x=0}^\infty x(1-p)^{x-1} \\
&= p \sum_{x=0}^\infty - \frac{d}{dp} (1-p)^{x} \\
&= - p \frac{d}{dp} \sum_{x=0}^\infty (1-p)^{x} \\
&= - p \frac{d}{dp} \frac{1}{1-(1-p)} \\
&= - p \frac{d}{dp} \frac{1}{p} \\
&= - p (-\frac{1}{p^2}) \\
&= \frac{1}{p}
\end{align}
$$

Notes:
- In line (6), we apply the sum of geometric series formula: $\sum_{n=0}^\infin ar^n = \frac{a}{1-r}$ 

## Variance

To find the variance of the geometric distribution, we'll use the following equation:

$$ Var(X) = EX^2 - (EX)^2 = EX(X-1) + EX -(EX)^2 $$

First, we must find $EX(X-1)$:

$$
\begin{align}
EX(X-1) &= \sum_{x=1}^\infty x(x-1)p_X(x) \\
&= \sum_{x=1}^\infty x(x-1)p(1-p)^{x-1} \\
&= p(1-p) \sum_{x=0}^\infty x(x-1)(1-p)^{x-2} \\
&= p(1-p) \sum_{x=0}^\infty \frac{d^2}{dx^2} (1-p)^x \\
&= p(1-p) \frac{d^2}{dx^2} \sum_{x=0}^\infty (1-p)^x \\
&= p(1-p) \frac{d^2}{dx^2} \frac{1}{1-(1-p)} \\
&= p(1-p) \frac{d^2}{dx^2} \frac{1}{p} \\
&= p(1-p) (\frac{2}{p^3}) \\
&= \frac{2(1-p)}{p^2} \\
\end{align}
$$

With this, we can solve for $Var(X)$:

$$
\begin{align}
Var(X) &= EX(X-1) + EX -(EX)^2 \\
&= \frac{2(1-p)}{p^2} + \frac{1}{p} - \frac{1}{p^2} \\
&= \frac{2 - 2p + p - 1}{p^2} \\
&= \frac{1 - p}{p^2} \\
\end{align}
$$