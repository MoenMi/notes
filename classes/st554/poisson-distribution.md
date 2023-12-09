# Poisson Distribution

A Poisson distribution is a discrete probability distribution that describes the number of events that occur within a fixed interval of time or space, with the events being rare and independent, and it is characterized by a single parameter, the average rate of occurrence.

A Poisson random variable is denoted as follows:

$$ X \sim \text{Poisson}(\lambda) $$

where $\lambda$ is the average rate of occurrence.

## Probability Mass Function (PMF)

The pmf of the poisson distribtuion is as follows:

$$
p_X(x) =
\begin{cases}
\frac{e^{-\lambda} \lambda^x}{x!}, & \text{if } x = 0, 1, 2, \dots \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

To derive the expected value, the following will come in handy:

$$
\begin{align}
\sum_{x=0}^\infty p_X(x) = 1 \\
\sum_{x=0}^\infty \frac{e^{-\lambda} \lambda^x}{x!} = 1 \\
\sum_{x=0}^\infty \frac{\lambda^x}{x!} = e^{\lambda} \\
\end{align}
$$

The expected value of the Poisson distribution can be derived as follows:

$$
\begin{align}
EX &= \sum_{x=0}^\infty x p_X(x) \\
&= \sum_{x=0}^\infty x \frac{e^{-\lambda} \lambda^x}{x!} \\
&= \sum_{x=1}^\infty \frac{e^{-\lambda} \lambda^x}{(x-1)!} \\
&= e^{-\lambda} \sum_{x=1}^\infty \frac{\lambda^x}{(x-1)!} \\
&= e^{-\lambda} \sum_{y=0}^\infty \frac{\lambda^{y+1}}{y!} \\
&= \lambda e^{-\lambda} \sum_{y=0}^\infty \frac{\lambda^y}{y!} \\
&= \lambda e^{-\lambda} e^{\lambda} \\
&= \lambda
\end{align}
$$

Note:
- In line (5), we substitute in $y=x-1$

## Variance

To derive the variance of the Poisson distribution, we perform a similar method to that of the expected value. We will consider the following:

$$ Var(X) = EX^2 - (EX)^2 = EX(X-1) + EX - (EX)^2 $$

Since we already calculated $EX$, we only need to find $EX(X-1)$:

$$
\begin{align}
EX(X-1) &= \sum_{x=0}^\infty x(x-1) \frac{e^{-\lambda} \lambda^x}{x!} \\
&= e^{-\lambda} \sum_{x=2}^\infty \frac{\lambda^2}{(x-2)!} \\
&= e^{-\lambda} \lambda^2 \sum_{x=2}^\infty \frac{\lambda^{x-2}}{(x-2)!} \\
&= e^{-\lambda} \lambda^2 \sum_{y=0}^\infty \frac{\lambda^y}{y!} \\
&= e^{-\lambda} \lambda^2 e^\lambda \\
&= \lambda^2 \\
\end{align}
$$

Note:
- In line (4), we substitute in $y=x-2$
- In line (5), we recognize apply the equation derived in the Expectation section

Now, we can use this to solve for the variance:

$$ Var(X) = EX(X-1) + EX - (EX)^2 = \lambda^2 + \lambda - \lambda^2 = \lambda $$