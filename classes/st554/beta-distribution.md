# Beta Distribution

The beta distribution is a continuous probability distribution defined on the interval $\left[0, 1\right]$, characterized by two shape parameters, and is often used to model random variables representing proportions or probabilities.

A beta random variable is denoted as followed:

$$ X \sim \text{Beta}(\alpha, \beta) $$

## Beta Function

The beta distribution is based on the beta function:

$$ B(\alpha, \beta) = \frac{\Gamma(\alpha) \Gamma(\beta)}{\Gamma(\alpha + \beta)} = \int_0^1 x^{\alpha-1} (1-x)^{\beta-1} dx $$

## Probability Distribution Function (PDF)

The pdf for the beta distribution is given as followed:

$$
f_X(x) =
\begin{cases}
\frac{1}{\Beta(\alpha, \beta)} x^{\alpha-1} (1-x)^{\beta-1}, & \text{if } x \in (0,1) \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

The expected value of the beta distribution can be derived as followed:

$$
\begin{align}
EX &= \int_0^1 x f_X(x) dx \\
&= \frac{1}{\Beta(\alpha, \beta)} \int_0^1 x^\alpha (1-x)^{\beta-1} dx \\
&= \frac{1}{\Beta(\alpha, \beta)} \int_0^1 x^{(\alpha+1)-1} (1-x)^{\beta-1} dx \\
&= \frac{\Beta(\alpha+1,\beta)}{\Beta(\alpha, \beta)} \\
&= \frac{\Gamma(\alpha+1) \Gamma(\beta) \Gamma(\alpha + \beta)}{\Gamma(\alpha + \beta + 1) \Gamma(\alpha) \Gamma(\beta)} \\
&= \frac{\alpha \Gamma(\alpha) \Gamma(\alpha + \beta)}{(\alpha + \beta) \Gamma(\alpha + \beta) \Gamma(\alpha)} \\
&= \frac{\alpha}{\alpha + \beta} \\
\end{align}
$$

This can be generalized to solve for any moment:

$$
\begin{align}
EX^r &= \int_0^1 x^r f_X(x) dx \\
&= \frac{1}{\Beta(\alpha, \beta)} \int_0^1 x^{\alpha - 1 + r} (1-x)^{\beta-1} dx \\
&= \frac{1}{\Beta(\alpha, \beta)} \int_0^1 x^{(\alpha+r)-1} (1-x)^{\beta-1} dx \\
&= \frac{\Beta(\alpha+r,\beta)}{\Beta(\alpha, \beta)} \\
&= \frac{\Gamma(\alpha+r) \Gamma(\beta) \Gamma(\alpha + \beta)}{\Gamma(\alpha + \beta + r) \Gamma(\alpha) \Gamma(\beta)} \\
&= \frac{\Gamma(\alpha+r) \Gamma(\alpha + \beta)}{\Gamma(\alpha + \beta + r) \Gamma(\alpha)} \\
\end{align}
$$

## Variance

Using our generalized moment formula, we can easily find $Var(X)$:

$$ Var(X) = \frac{\alpha \beta}{(\alpha + \beta)^2 (\alpha + \beta + 1)} $$