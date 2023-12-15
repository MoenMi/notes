# 11 - Inferences About Population Variances

## 11.1 Inferences About a Population Variance

The point estimator of the population variance $\sigma^2$ is the sample variance $s^2$:

$$ s^2 = \frac{\sum (x_i - \bar{x})^2}{n-1} $$

When making inferences about the population variance, the sampling distribution of

$$\frac{(n-1)s^2}{\sigma^2}$$

is helpful. This distribution can be modeled by a **chi-square** distribution with $n-1$ degrees of freedom. A chi-square distribution results from sampling from a normal distribution

### Interval Estimation

For a level of significance $\alpha$, we will consider the right tail of the chi-square distribution, denoted $\chi_\alpha^2$. We can recognize that an interval estimation for the population standard deviation would require both upper and lower bounds:

$$ \chi_{1-\alpha/2}^2 \leq \frac{(n-1)s^2}{\sigma^2} \leq \chi_{\alpha/2}^2 $$

Solving for the population variance $\sigma^2$ yields:

$$ \frac{(n-1)s^2}{\chi_{\alpha/2}^2} \leq \sigma^2 \leq \frac{(n-1)s^2}{\chi_{1-\alpha/2}^2} $$

### Hypothesis Testing

To calculate the test statistic for hypothesis tests about a population variance:

$$ \chi^2 = \frac{(n-1)s^2}{\sigma_0^2} $$

where $s_0^2$ is the hypothesized population variance and $\chi^2$ has $n-1$ degrees of freedom.

Using this test statistic, we can calculate the $p$-value for the hypothesis testing to decide whether to accept or reject $H_0$.

## 11.2 Inferences About Two Population Variances

Some times we wish to compare the variances of two populations. When making these inferences, we will typically assume that the variance of each population is equal. Whenever this is the case, the sampling distribution of 

$$ \frac{s_1^2}{s_2^2} $$

has an $F$ distribution with $n_1 - 1$ degrees of freedom in the numerator and $n_2 - 1$ degrees of freedom in the denominator. This value is also denoted as the test statistic $F$. Note that the sample size in sample $1$ must be greater than that of sample $2$ and that only the right tail of the $F$ distribution is considered when calculating the $p$-value.

