# MindTap 10 - Inference About Means and Proportions with Two Populations

## 10.1 Inferences About the Difference Between Two Population Means: $\sigma_1$ and $\sigma_2$ Known

Using $\mu_1$ and $\mu_2$ to denote the population means of two populations, we can make inferences about the difference between these means: $\mu_1 - \mu_2$. To make these inferences, we must take independent random samples with sizes of $n_1$ and $n_2$, respectively. In this section, we assume that the population standard deviations $\sigma_1$ and $\sigma_2$ are already known.

### Interval Estimation of $\mu_1 - \mu_2$

To find this interval, we must first establish the point estimator for the difference between these two population means as $\bar{x}_1 - \bar{x}_2$. We can then also calculate the standard error of $\bar{x}_1 - \bar{x}_2$ from the known population standard deviations:

$$ \sigma_{\bar{x}_1 - \bar{x}_2} = \sqrt{\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}} $$

Then, we must calculate the margin of error using this value:

$$ \text{Margin of error } = z_{\alpha/2} \sqrt{\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}} $$

Thus, the interval estimate for the difference between two population means where both population standard deviations are known is given by:

$$ \bar{x}_1 - \bar{x}_2 \pm z_{\alpha/2} \sqrt{\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}} $$

where $1-\alpha$ is the confidence coefficient.

### Hypothesis Tests About $\mu_1 - \mu_2$

The general process for hypothesis testing remains the same. However, the test statistic is calculated as such:

$$ z = \frac{(x_1 - x_2) - D_0}{\sqrt{\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}}} $$

where $D_0$ is the assumed difference in population means (typically $0$).

## 10.2 Inferences About the Difference Between Two Population Means: $\sigma_1$ and $\sigma_2$ Unknown

With the population standard deviations unknown, we must use the $t$ distribution rather than the normal distribution to estimate the difference in population means.

### Interval Estimate of $\mu_1 - \mu_2$

When creating an interval estimate of the difference between population means when the population standard deviation is unknown, we use a similar equation to when it is known:

$$ \bar{x}_1 - \bar{x}_2 \pm t_{\alpha/2} \sqrt{\frac{s_1^2}{n_1} + \frac{s_2^2}{n_2}} $$

where $1-\alpha$ is the confidence coefficient. The degrees of freedom are calculated using the following formula:

$$ df = \frac{\left( \frac{s_1^2}{n_1} + \frac{s_2^2}{n_2} \right)^2}{\frac{1}{n_1 - 1} \left( \frac{s_1^2}{n_1} \right)^2 + \frac{1}{n_2-1} \left( \frac{s_2^2}{n_2} \right)^2} $$

Note that this values is typically rounded down, since that is the more conservative estimate.

### Hypothesis Tests About $\mu_1 - \mu_2$

We can similarly adapt the previous equation for the test statistic to use the estimated standard deviation:

$$ t = \frac{(x_1 - x_2) - D_0}{\sqrt{\frac{s_1^2}{n_1} + \frac{s_2^2}{n_2}}} $$

We then calculate the degrees of freedom using the same formula from the previous section. Using this, we can calculate a $p$-value for the hypothesis test.

## 10.3 Inferences About the Difference Between Two Population Means: Matched Samples

An alternative to independent sampling is **matched sampling**, which uses the same sample for both treatments (ex. same employees performing two different methods). Since this method helps minimize sampling variability, it leads to a smaller sampling error.

When analyzing the difference in means, we must first calculate the sample mean and sample standard deviation of the differences $d$.

$$ \bar{d} = \frac{\sum d_i}{n} $$

$$ s_d = \sqrt{\frac{\sum (d_i - \bar{d})^2}{n-1}} $$

With this, we can calculate the test statistic for analyzing this difference in means:

$$ t = \frac{\bar{d} - \mu_d}{s_d / \sqrt{n}} $$

This test statistic has a $t$ distribution with $n-1$ degrees of freedom. This test statistic can then be used to create confidence intervals, calculate $p$-values, or otherwise perform a hypothesis test.

## 10.4 Inferences About the Difference Between Two Population Proportions

Let $p_1 - p_2$ denote the difference between the population proportions of two populations. We will then draw a sample of size $n_1$ from population $1$ and a sample of size $n_2$ from population $2$.

### Interval Estimation of $p_1 - p_2$

The point estimator for the difference in population proportions is $\bar{p}_1 - \bar{p}_2$. The standard error of this distribution can be calculated as such:

$$ \sigma_{\bar{p}_1 - \bar{p}_2} = \sqrt{\frac{p_1(1-n_1)}{n_1} + \frac{p_2(1-p_2)}{n_2}} $$

If the sample size is large enough such that $n_1 p_1$, $n_1 (1-p_1)$, $n_2 p_2$, and $n_2 (1-p_2)$ are all less than $5$, then the sampling distribution of $\bar{p}_1 - \bar{p}_2$ can be modeled by the normal distribution.

To perform an interval estimation, we must first calculate the margin of error:

$$ \text{Margin of error } = z_{\alpha/2} \sqrt{\frac{p_1(1-n_1)}{n_1} + \frac{p_2(1-p_2)}{n_2}} $$

It follows that an interval estimate would take the following form:

$$ \bar{p}_1 - \bar{p}_2 \pm z_{\alpha/2} \sqrt{\frac{p_1(1-n_1)}{n_1} + \frac{p_2(1-p_2)}{n_2}} $$

### Hypothesis Tests About $p_1 - p_2$

In a hypothesis test, we typically have the null hypothesis be an assumption that the difference of population proportions is related to $0$ in some way. Note that this is the same as saying that $p_1 = p_2$, so we can simplify our equation for the standard error $\sigma_{\bar{p}_1 - \bar{p}_2}$.

$$ \sigma_{\bar{p}_1 - \bar{p}_2} = \sqrt{p(1-p) \left( \frac{1}{n_1}+\frac{1}{n_2} \right)} $$

We then also establish a **pooled estimator of $p$**, which is a weighted average of $\bar{p}_1$ and $\bar{p}_2$:

$$ \bar{p} = \frac{n_1 \bar{p}_1 + n_2 \bar{p}_2}{n_1 + n_2} $$

With this, we can calculate the test statistic for this hypothesis test:

$$ z = \frac{\bar{p}_1 - \bar{p}_2}{\sqrt{p(1-p) \left( \frac{1}{n_1}+\frac{1}{n_2} \right)}} $$

This test statistic applies to large samples where $n_1 p_1$, $n1 (1-p_1)$, $n_2 p_2$, and $n_2 (1-p_2)$ are greater or equal to $5$.