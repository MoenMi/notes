# 13 - Experimental Design and Analysis of Variance (ANOVA)

## 13.1 An Introduction to Experimental Design and Analysis of Variance

A **factor** is an independent variable of interest (e.g. launch angle).

A **treatment** is a level of a factor (e.g. $140\degree$ ).

A **single-factor experiment** is an experiment involving only one factor.

A **response variable** is another word for the dependent variable of interest.

### Data Collection

After collecting data, find the sample mean, standard deviation, and variance of the response variable for each treatment.

If there are 3 treatments, then there will be 3 sample means:
- $\mu_1$ = mean of response variable for treatment 1
- $\mu_2$ = mean of response variable for treatment 2
- $\mu_3$ = mean of response variable for treatment 3

We can use these sample means to conduct a hypothesis test:

$$
H_0: \mu_1 = \mu_2 = \mu_3 \\
H_a: \text{Not all population means are equal}
$$

### Assumptions for Analysis of Variance

Three assumptions are required for ANOVA:
1. For each population, the response variable is normally distributed.
2. The variance of the response variable, denoted &sigma;<sup>2</sup>, is the same for all of the populations.
3. The observations must be independent.

### Analysis of Variance: A Conceptual Overview

If the means for the three populations are equal, we would expect the three sample means to be close together. In fact, the closer the three sample means are to one another, the weaker the evidence we have for the conclusion that the population means differ. In other words, if the variability among the sample means is small, it supports <em>H<sub>0</sub></em>, and if the variability is large, it supports <em>H<sub>a</sub></em>.

#### Example

$$ \bar{x}_{1} = 62 $$
$$ \bar{x}_{2} = 66 $$
$$ \bar{x}_{3} = 52 $$

We estimate the overall mean of the sample to be the average of the sample means:

$$ \mu_{\bar{x}} = \frac{62+66+52}{3} = 60 $$

The variance of the sampling distribution of $ \bar{x} $ is:

$$ s_{\bar{x}}^{2} = \frac{(62-60)^{2}+(66-60)^{2}+(52-60)^{2}}{3-1} = \frac{104}{2} = 52 $$

Because $ \sigma_{\bar{x}}^{2} = \frac{\sigma^{2}}{n} $, we can see that:

$$ \sigma^{2} = n\sigma_{\bar{x}}^{2} $$

Therefore,

$$ Estimate~of~\sigma^{2} = n(Estimate~of~\sigma_{\bar{x}}^{2}) = ns_{\bar{x}}^{2} = 5(52) = 260 $$

This result of $ ns_{\bar{x}}^{2} = 260 $ is called the **between-treatments estimate** of $ ns_{\bar{x}}^{2} $.

## 13.2 Analysis of Variance and the Completely Randomized Design

The general form of the hypotheses tested in ANOVA is:

$$
H_0: \mu_1 = \mu_2 = \dots = \mu_k \\
H_a: \text{Not all population means are equal}
$$

We assume that a random sample of size $n_j$ has been selected from each of the $k$ populations. For the resulting dataset, let
- $x_{ij}$ = value of observation $i$ for population $j$
- $n_j$ = number of observations for population $j$
- $\bar{x}_j$ = sample mean for population $j$
- $s_j^2$ = sample variance for population $j$
- $s_j$ = sample standard deviation for population $j$

These values can be calculated as follows:

$$ \bar{x}_j = \frac{\sum_{i=1}^{n_j}}{n_j} $$

$$ s_j^2 = \frac{\sum_{i=1}^{n_j} (x_{ij} - \bar{x}_j)^2}{n_j - 1} $$

The overall sample mean $\bar{x}$ is the sum of all observations divided by the total number of observations:

$$ \bar{x} = \frac{\sum_{j=1}^k \sum_{i=1}^{n_j} x_{ij}}{n_T} $$

### Between-Treatments Estimate of Population Variance

The **mean squares due to treatments ($MSTR$)** is computed as followed:

$$ MSTR = \frac{\sum_{j=1}^k n_j(\bar{x}_j - \bar{x})^2}{k-1} $$

The numerator of this equation is known as the **sum of squares due to treatments ($SSTR$)**.

### Within-Treatments Estimate of Population Variance

The general formula for computing the **mean square due to error ($MSE$)** is:

$$ MSE = \frac{\sum_{j=1}^k (n_j - 1)s_j^2}{n_T-k} $$

The numerator of this equation is called the **sum of squares due to errer ($SSE$)**.

### Comparing the Variance Estimates: The $F$ Test

If $H_0$ is true, $MSTR$ and $MSE$ provide independent and unbiased estimates of $\sigma^2$. We can then use an $F$ distribution to determine the $p$-value where the test statistic is:

$$ F = \frac{MSTR}{MSE} $$

where the $F$ distribution has $k-1$ degrees of freedom in the numerator and $n_T - k$ degrees of freedom in the denominator.

### ANOVA Table

The general form of an ANOVA table will take a form similar to:

| Source of Variation | Sum of Squares | Degrees of Freedom | Mean Squares | $F$ | $p$-value |
| - | - | - | - | - | - |
| Treatments | $SSTR$ | $k-1$ | $MSTR$ | $\frac{MSTR}{MSE}$ |  |
| Error | $SSE$ | $n_T-k$ | $MSE$ |  |  |
| Total | $SST$ | $n_T-1$ |  |  |  |

Note that:

$$ SST = SSTR + SSE $$

## 13.3 Multiple Comparison Procedures

The above example only allows to determine whether the population means are not all equal. Multiple comparison procedures allow us to conduct statistical comparisons between pairs of population means.

### Fisher's LSD

**Fisher's least significant difference (LSD) procedure** can be used to find whether a pair of population means differ. To perform this method, find a test statistic for each pair:

$$ t = \frac{\bar{x}_i - \bar{x}_j}{\sqrt{MSE \left( \frac{1}{n_i} + \frac{1}{n_j} \right)}} $$

where the $t$ distribution has $n_T-k$ degrees of freedom.

We can also use this method to create a confidence interval for the difference between two population means:

$$ \bar{x}_i - \bar{x}_j \pm LSD $$

where $LSD$ is defined:

$$ LSD = t_{\alpha/2} \sqrt{MSE \left( \frac{1}{n_i} + \frac{1}{n_j} \right)} $$

where the $t$ distribution has $n_T-k$ degrees of freedom.

### Type I Error Rates

The **comparisonwise Type I error rate** is the level of significance associated with a single pairwise comparison, which is equal to $\alpha$.

The **experimentwise Type I error rate** is the probability that we have a Type I error in at least one of the comparisons. This is denoted $\alpha_{EW}$, and is calculated as such:

$$ \alpha_{EW} = 1 - (1-\alpha)(1-\alpha)(1-\alpha) $$

in a case with three comparisons.

## 13.4 Randomized Block Design

A completely randomized experiment is useful when the experimental units are homogeneous. If the experimental units are heterogeneous, blocking can be used to form homogeneous groups.

### ANOVA Procedure

We need to partition SST into 3 groups: SSTR, SSE, and the **sum of squares due to blocks (SSBL)**. That is,

$$ SST = SSTR + SSE + SSBL $$

The ANOVA table can then be updated as follows:

| Source of Variation | Sum of Squares | Degrees of Freedom | Mean Squares | $F$ | $p$-value |
| - | - | - | - | - | - |
| Treatments | $SSTR$ | $k-1$ | $MSTR$ | $\frac{MSTR}{MSE}$ |  |
| Blocks | $SSBL$ | $b-1$ | $MSBL$ |  | ||
| Error | $SSE$ | $(k-1)(b-1)$ | $MSE$ |  |  |
| Total | $SST$ | $n_T-1$ |  |  |  |

where
- $k$ is the number of treatments
- $b$ is the number of blocks
- $MSBL = \frac{SSBL}{b-1}$
- $MSE = \frac{SSE}{(k-1)(b-1)}$

## 13.5 Factorial Experiment

A **factorial experiment** is an experiment that allows simultaneous conclusions about two or more factors.

The sample size for each combination of treatments is called the number of **replications**.

A factorial experiment will examine 3 effects:
- Main effect (factor A)
- Main effect (factor B)
- Interaction effect (factors A and B)

An **interaction** is an effect that can be studied from a combination of effects.

### ANOVA Procedure

The ANOVA table can then be updated as follows:

| Source of Variation | Sum of Squares | Degrees of Freedom | Mean Squares | $F$ | $p$-value |
| - | - | - | - | - | - |
| Factor A | $SSA$ | $a-1$ | $MSA$ | $\frac{MSA}{MSE}$ |  |
| Factor B | $SSB$ | $b-1$ | $MSB$ | $\frac{MSB}{MSE}$ |  |
| Interaction | $SSAB$ | $(a-1)(b-1)$ | $MSAB$ | $\frac{MSAB}{MSE}$ | ||
| Error | $SSE$ | $ab(r-1)$ | $MSE$ |  |  |
| Total | $SST$ | $n_T-1$ |  |  |  |

where
- $a$ is the number of levels of factor A
- $b$ is the number of levels of factor B
- $r$ is the number of replications
- $MSA = \frac{SSA}{a-1}$
- $MSB = \frac{SSB}{b-1}$
- $MSAB = \frac{SSAB}{(a-1)(b-1)}$
- $MSE = \frac{SSE}{ab(r-1)}$