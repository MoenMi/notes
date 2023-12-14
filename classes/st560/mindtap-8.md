# MindTap 8 - Interval Estimation

A **point estimator** is a sample statistic used to estimate a population parameter. For examples, the sample mean $\bar{x}$ is a point estimator for the population mean $\mu$ and the sample proportion $\bar{p}$ is a point estimator of the population proportion $p$.

Because a point estimator cannot be expected to provide the exact value of a population parameter, an **interval estimate** is often computed by adding and subtracting the **margin of error** to and from the point estimate:

$$ \text{Point estimate } \pm \text{ Margin of error}  $$

Using this, we can calculate interval estimates for the population mean $\mu$ and the population proportion $p$:

$$ \bar{x} \ \pm \text{ Margin of error} \\
\bar{p} \ \pm \text{ Margin of error} $$

## 8.1 Population Mean: $\sigma$ Known

In order to develop an interval estimate of a population mean, either the population standard deviation $\sigma$ or the sample standard deviation $s$ must be known. However, in some applications, the population standard deviation $\sigma$ can be estimated from large amounts of historical data, or it can be assumed to be operating correctly in some quality control processes. These cases are called **$\sigma$ known** cases.

### Margin of Error and the Interval Estimate

The standard error of the sampling mean can be calculated as follows given the population standard deviation $\sigma$ is known:

$$ \sigma_{\bar{x}} = \frac{\sigma}{\sqrt{n}} $$

We can then use this to develop a 95% confidence interval about the mean by first calculating the margin of error using the knowledge that 95% of values fall within 1.96 standard deviations of a normal distribution:

$$ \text{Margin of error } = \ 1.96 \sigma_{\bar{x}} $$

Which gives us this 95% confidence interval:

$$ \bar{x} \ \pm \text{ Margin of error} $$

Note that in this process, we consider the 95% to be the **confidence level** and the value 0.95 to be the **confidence coefficient**.

The **level of signifance $\alpha$** is also used to describe the confidence:

$$ \alpha = 1- \text{Confidence coefficient} $$

All of this information can be generalized to find the interval estimate of a population mean for a case in which the population standard deviation $\sigma$ is known:

$$ \bar{x} \pm z_{\alpha/2} \frac{\sigma}{\sqrt{n}} $$

Note that these values are commonly used as confidence levels:

| Confidence Level | $\alpha$ | $\alpha/2$ | $z_{\alpha/2}$ |
| - | - | - | - |
| 90% | .10 | .05 | 1.645 |
| 95% | .05 | .025 | 1.960 |
| 99% | .01 | .005 | 2.576 |

## 8.2 Population Mean: $\sigma$ Unknown

In most cases, we will not have a good estimate of the population standard deviation $\sigma$. In these cases, we must use the sample to estimate both $\mu$ and $\sigma$. In this case, the interval estimate is based on the **$t$ distribution**.

The $t$ distibution depends on the **degrees of freedom**. Note that as the degrees of freedom approach infinity, the $t$ distribution approaches the normal distribution. The $t$ distribution used in interval estimation is $t_{\alpha/2}$, where the upper area of the $t$ distribution is equal to $\alpha/2$.

### Margin of Error and the Interval Estimate

The interval estimate of a population mean where the population standard deviation $\sigma$ is unknown is as follows:

$$ \bar{x} \ \pm \ t_{\alpha/2} \frac{s}{\sqrt{n}} $$

where
- $s$ is the sample standard deviation
- $t_{\alpha/2}$ has $n-1$ degrees of freedom

Recall that the sample standard deviation $s$ is

$$ s = \sqrt{\frac{\sum (x_i - \bar{x})^2}{n-1}} $$

## 8.3 Determining the Sample Size

Suppose we have a desired margin of error $E$ that we wish to achieve. We could then determine the size of our sample to satisfy that margin of error:

$$ 
\begin{align}
E &= z_{\alpha/2} \frac{\sigma}{\sqrt{n}} \\
n &= \frac{(z_{\alpha/2})^2 \sigma^2}{E^2}
\end{align}
$$

Note that this requires us to know the population standard deviation $\sigma$. However, we can still follow this method if we have a preliminary/planning value for $\sigma$.

## 8.4 Population Proportion

Recall that the interval estimate for the population proportion $p$ is given by:

$$ \bar{p} \ \pm \text{ Margin of error} $$

The mean of the sampling distribution of $\bar{p}$ is the population proportion $p$, and the standard error is:

$$ \sigma_{\bar{p}} = \sqrt{\frac{p(1-p)}{n}} $$

Because the sampling distribution of $\bar{p}$ is normally distributed, we can find the margin of error:

$$ \text{Margin of error } = z_{\alpha/2} \sigma_{\bar{p}} = z_{\alpha/2} \sqrt{\frac{\bar{p}(1-\bar{p})}{n}} $$

Brining this all together, we get the interval estimate:

$$ \bar{p} \ \pm \ z_{\alpha/2} \sqrt{\frac{\bar{p}(1-\bar{p})}{n}} $$

### Determining the Sample Size

We can solve for the required sample size for a desired margin of error like in the population mean case:

$$
\begin{align}
E &= z_{\alpha/2} \sqrt{\frac{\bar{p}(1-\bar{p})}{n}} \\
n &= \frac{(z_{\alpha/2})^2 \bar{p}(1-\bar{p})}{E^2} 
\end{align}
$$

However, since $\bar{p}$ won't be known until after the sample is collected, we must use an estimate $p^*$:

$$
\begin{align}
E &= z_{\alpha/2} \sqrt{\frac{p^*(1-p^*)}{n}} \\
n &= \frac{(z_{\alpha/2})^2 p^*(1-p^*)}{E^2} 
\end{align}
$$