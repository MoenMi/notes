# MindTap 9 - Hypothesis Tests

In hypothesis testing, we make an assumption about a population parameter. This assumption is called the **null hypothesis ($H_0$)**. In turn, we define the opposite of the null hypothesis as the **alternative hypothesis ($H_a$)**.

## 9.2 Type I and Type II Errors

Since the null and alternative hypotheses are conflicting statements, either one can be true or both can be true.

A **Type I error** occurs when the null hypothesis is true but rejected.

A **Type II error** occurs when the alternative hypothesis is true, but we fail to reject it.

Note that the level of significance $\alpha$ indicates the probability of making a Type I error when the null hypothesis is true.

## 9.3 Population Mean: $\sigma$ Known

When the standard population deviation $\sigma$ is known or there is enough historical data available to reasonably estimate it, we do not have to estimate this value.

### One-Tailed Test

**One-tailed tests** about a population mean $\mu$ take one of the two following forms:

$$
\begin{align}
&\text{Lower Tail Test} & \text{Upper Tail Test} \\
& H_0: \mu \geq \mu_0 & H_0: \mu \leq \mu_0 \\
& H_a: \mu < \mu_0 & H_a: \mu > \mu_0
\end{align}
$$

#### Test Statistic

The test statistic for hypothesis tests when $\sigma$ is known is given as follows:

$$ z = \frac{\bar{x}-\mu_0}{\sigma/\sqrt{n}} $$

Once we have calculated the test statistic, we must decide whether to reject or accept the null hypothesis based on one of the two following approaches: the $p$-value approach and the critical value approach.

#### The $p$-Value Approach

The $p$-value approach uses the test statistic $z$ to compute a probability called a $p$-value.

The **$p$-value** indicates the probability that a result at least as extreme as the actual result occurs given that null hypothesis is true. The $p$-value can be calculated from the standard normal distribution, where the test statistic is the upper or lower bound depending on the hypothesis test.

After calculating the $p$-value, we reject $H_0$ if the $p$-value is less than or equal to $\alpha$. Otherwise, we fail to to reject $H_0$.

#### Critical Value Approach

The critical value approach requires us to calculate the **critical value** for the test statistic. This critical value is compared to the test statistic to determine whether the test statistic is large/small enough to reject $H_0$.

The critical value is calculated based on the level of significance $\alpha$ (ex. 1.96 for $\alpha = .05$).

### Two-Tailed Test

**Two-tailed tests** about the population mean follow the form:

$$
H_0: \mu = \mu_0 \\
H_a: \mu \ne \mu_0
$$

The test statistic can be calculated in the same manner as the one-tailed test.

#### $p$-Value Approach

In a two-tailed test, values of the test statistic in either tail provide evidence against the null hypothesis. To find this $p$-value, we find the area of one tail and double it. Comparing this doubled value to the level of significance $\alpha$ tells us whether or not to reject $H_0$.

#### Critical Value Approach

Compare the test statistic with $\pm z_{\alpha/2}$. If the test statistic is outside these bounds, reject $H_0$. Otherwise, you fail to reject $H_0$.

## 9.4 Population Mean: $\sigma$ Unknown

To conduct a hypothesis test about a population mean for the $\sigma$ unknown case, the sample mean $\bar{x}$ is used as an estimate of $\mu$ and the sample standard deviation $s$ is used as an estimate of $\sigma$. However, since we are using an estimate for the population standard deviation $\sigma$, we must use a $t$ distribution to model the sampling distribution of the test statistic.

This test statistic can be calculated as follows:

$$ t = \frac{\bar{x} - \mu_0}{s/ \sqrt{n}} $$

This test statistic has a $t$ distribution with $n-1$ degrees of freedom.

Note that the same processes can be used to determine whether to reject or accept $H_0$ as in the $\sigma$ known case, but the only difference is the test statistic.

## 9.5 Population Proportion

Hypothesis tests on the population proportion are based on the difference between the sample population proportion $\bar{p}$ and the hypothesized population proportion $p_0$. Note that the methods to conduct the hypothesis test are the same as those used when working with the population mean, but the difference lies in how the test statistic is calculated.

When $H_0$ is true, the mean of $\bar{p}$ is $p_0$. However, we must first calculate the standard deviation of $\bar{p}$:

$$ \sigma_{\bar{p}} = \sqrt{\frac{p_0(1-p_0)}{n}} $$

If $np \geq 5$ and $n(1-p) \geq 5$, then the sampling distribution of $\bar{p}$ can be approximated by a normal distribution. Under these circumstances:

$$ z = \frac{\bar{p} - p_0}{\sigma_{\bar{p}}} $$

We can combine these equations to create a complete formula for our test statistic:

$$ z = \frac{\bar{p} - p_0}{\sqrt{\frac{p_0(1-p_0)}{n}}} $$
