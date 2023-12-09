# Exponential Distribution

The exponential distribution models the probability distribution of the time until an independent and identically distributed continuous random event occurs, with a constant hazard rate, often associated with the waiting time between Poisson-distributed events.

An exponential random variable is denoted as followed:

$$ X \sim \text{Exponential}(\beta) $$

Note that the exponential distribution is a gamma distribution  that can be modeled as such:

$$ X \sim \text{Gamma}(1, \beta) $$

## Probability Distribution Function (PDF)

Since the exponential distribution is modeled after the gamma distribution, we see that its pdf is:

$$
f_X(x) =
\begin{cases}
\frac{1}{\beta^\alpha} e^{-\frac{x}{\beta}} , & \text{if } x>0 \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

We can find the expected value of the exponential distribution from its gamma distribution origins:

$$ EX = \beta $$

## Variance

We can similarly find the variance of the exponential distribution:

$$ Var(X) = \beta^2 $$