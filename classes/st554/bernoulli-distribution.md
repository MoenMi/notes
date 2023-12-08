# Bernoulli Distribution

The Bernoulli distribution models the probability distribution of a random variable that takes the value $1$ with probability $p$ (success) and the value $0$ with probability $1-p$ (failure) in a single independent Bernoulli trial.

A Bernoulli random variable is denoted as the following:

$$ X \sim \text{Bernoulli}(p) $$

## Probability Mass Function (PMF)

The pmf of a Bernoulli random variable can be denoted as the following:

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

## Expectation

The expectation for a Bernoulli random variable can be derived as follows:

$$
\begin{align}
EX &= \sum_{x=0}^1 x \ p_X(x) \\
&= 0p^0(1-p)^1 + 1p^1(1-p)^0 \\
&= p
\end{align}
$$

## Variance

The variance for a Bernoulli random variable can be calculated:

$$ Var(X) = EX^2 - (EX)^2 $$

We must first find $EX^2$:

$$
\begin{align}
EX^2 &= \sum_{x=0}^1 x^2 p_X(x) \\
&= 0^2p^0(1-p)^1 + 1^2 p^1(1-p)^0 \\
&= p
\end{align}
$$

With this, we can find $Var(X)$:

$$
\begin{align}
Var(X) &= EX^2 - (EX)^2 \\
&= p - p^2 = p(1-p)
\end{align}
$$