# 2 - SLR

What is **regression**?

- The term "regression" was coined by Francis Galton in the nineteenth century to describe a biological phenomenon. The phenomenon was that the heights of descendents of tall ancestors tend to regress down towards a normal average (a phenomenon also known as regression toward the mean).
- Supervised learning with continuous responses is called Simple/Multiple Linear Regression (SLR/MLR)
- Supervised learning with binary responses is called Logistic Regression
- Estimation, inference, and prediction

## 2.1 - SLR Models

A standard simple linear regression model:

$$ y_i = \beta_0 + \beta_1 x_i + e_i $$

- $(y_i, x_i)$ is the $i$th observation from a random sample $\{(y_i, x_i), i = 1, \dots, n\}$
- $\beta_0$ and $\beta_1$ are the regression coefficients: intercept and slope, respectively
- $e_i$ is the random error

Random error $e_i$:
- Unexplained variation in the response $y$
- $e_i$ is independent of $x_i$
- Mean $E(e_i | x_i) = 0$, and variance $\text{Var}(e_i | x_i) = \sigma^2$
- $e_i$ and $e_j$ are uncorrelated for $i \ne j$
- For all $i, j = 1, \dots, n$

$E(y_i | x_i) = \beta_0 + \beta_1 x_i$

$y_i = E(y_i | x_i) + e_i = \beta_0 + \beta_1 x_i + e_i$

## 2.2 - Parameter Estimation

- Parameters: $\beta_0$ and $\beta_1$
- Sample estimates: $b_0$ and $b_1$
- Estimated model: $\hat{y}_i = b_0 + b_1 x_i$
- Residuals: $\hat{e}_i = y_i - \hat{y}_i$

### Least Squares

**Residual Sum of Squares (RSS)**, or **Sum of Squared Residuals (SSR)**:

$$ RSS = \sum^n_{i=1} \hat{e}_i^2 = \sum^n_{i=1} (y_i - \hat{y}_i)^2 = \sum^n_{i=1} (y_i - b_0 - b_1 x_i)^2 $$

For RSS to be a minimum with respect to $b_0$ and $b_1$, we require

$$ \frac{\delta RSS}{\delta b_0} = -2 \sum^n_{i-1} (y_i - b_0 - b_1 x_i) = 0 $$

and

$$ \frac{\delta RSS}{\delta b_1} = -2 \sum^n_{i=1} x_i (y_i - b_0 - b_1 x_i) = 0 $$

Rearranging terms in these two equations gives

$$ \sum^n_{i=1} y_i = b_0 n + b_1 \sum^n_{i=1} x_i $$

and

$$ \sum^n_{i=1} x_i y_i = b_0 \sum^n_{i=1} x_i + b_1 \sum^n_{i=1} x_i^2 $$

These last two equations are called the **normal equations**. Solving these equations for $b_0$ and $b_1$ gives the so-called **least squares estimate (LSE)** of the intercept:

$$ \hat\beta_0 = \bar y - \hat \beta_1 \bar x $$

and the slope:

$$ \hat\beta_1 = \frac{\sum^n_{i=1} x_i y_i - n \overline{xy}}{\sum^n_{i=1} x_i^2 - n \bar x^2} = \frac{\sum^n_{i=1} (x_i - \bar x)(y_i - \bar y)}{\sum^n_{i=1} (x_i - \bar x)^2} = \frac{SXY}{SXX} $$

### Residual Variance

The residual variance $\sigma^2$ can be estimated by

$$ s^2 = \frac{RSS}{n -2} = \frac{\sum^n_{i=1} \hat e_i^2}{n-2} $$

## 2.3 - Model Inference

### Assumptions for Inference

- $y$ is related to $x$ by the simple linear regression model
  
  $$ y_i = \beta_0 + \beta_1 x_i + e_i $$

- Errors $\{ e_i, i=1, \dots, n \}$ are independent of each other
- Constant variance $\text{Var}(e_i | x_i) = \sigma^2$
- The errors are normally distributed with mean 0 and variance $\sigma^2$, $e \sim N(0, \sigma^2)$

### Inference on the Slope $\beta_1$

Tests concerning the slope $\beta_1$ are often of interest, particularly

$$ H_0 : \beta_1 = 0 $$

$$ H_1 : \beta_1 \ne 0 $$

The null hypothesis $(y_i = \beta_0 + (0) x_i + e_i)$ implies that there is no linear relationship between $y$ and $x$, meaning that all the $y_i$'s are equal at all levels of $x_i$.

Recall that the least squares estimate of the $\beta_1$ is

$$ \hat\beta_1 = \frac{\sum^n_{i=1} x_i y_i - n \overline{xy}}{\sum^n_{i=1} x_i^2 - n \bar x^2} = \frac{\sum^n_{i=1} (x_i - \bar x)(y_i - \bar y)}{\sum^n_{i=1} (x_i - \bar x)^2} = \frac{SXY}{SXX} $$

Under the given assumptions,
- $E(\hat\beta_1 | X) = \beta_1$
- $\text{Var}(\hat\beta_1 | X) = \frac{\sigma^2}{SXX}$
- $\hat\beta_1 | X \sim N \left(\beta_1, \frac{\sigma^2}{SXX} \right)$

Standardizing the final result gives

$$ Z = \frac{\hat\beta_1 - \beta_1}{\frac{\sigma}{\sqrt{SXX}}} \sim N(0,1) $$

If $\sigma$ were known, then we could use a $Z$ to test hypotheses and find confidence intervals for $\beta_1$. When $\sigma$ is unknown (as is usually the case), replacing $\sigma$ by $S$, the standard deviation of the residuals results in

$$ T = \frac{\hat\beta_1 - \beta_1}{\frac{\sigma}{\sqrt{SXX}}} = \frac{\hat\beta_1 - \beta_1}{\text{se}(\hat\beta_1)} $$

where $\text{se}(\hat\beta_1) = \frac{S}{\sqrt{SXX}}$ is the estimated standard error ($\text{se}$) of $\hat\beta_1$.

It can be shown that under the above assumptions that $T$ has a $t$-distribution with $n-2$ degrees of freedom, that is

$$ T = \frac{\hat\beta_1 - \beta_1}{\text{se}(\hat\beta_1)} \sim t_{n-2} $$

For testing the hypothesis $H_0: \beta_1 = \beta_1^0$, the test statistic is

$$ T = \frac{\hat\beta_1 - \beta_1^0}{\text{se}(\hat\beta_1)} \sim t_{n-2} \text{ when } H_0 \text{ is true} $$

A $100(1-\alpha)\%$ confidence interval for $\beta_1$, the slope of the regression line is given by

$$ (\hat\beta_1 - t(\frac{\alpha}{2}, n-2) \text{se}(\hat\beta_1), \hat\beta_1 + t(\frac{\alpha}{2}, n-2) \text{se}(\hat\beta_1)) $$

where $t(\alpha/2, n-2)$ is the $100(1-\alpha/2)$th quantile of the $t$-distribution with $n-2$ degrees of freedom.

## 2.4 - Model Prediction

- Estimation $E(y^*)$ at $x = x^*$
- Prediction $y^*$

### Confidence Interval for $E(y^*)$

A $100(1-alpha)\%$ confidence interval for $E(Y | X = x^*) = \beta_0 + \beta_1 x^*$, the population regression line at $X = x^*$, is given by

$$
\hat y^* \pm t(\frac{\alpha}{2}, n-2) S \sqrt{\frac{1}{n} + \frac{(x^* - \bar x)^2}{SXX}} \\
= \hat\beta_0 + \hat\beta_1 x^* \pm t(\frac{\alpha}{2}, n-2) S \sqrt{\frac{1}{n} + \frac{(x^* - \bar x)^2}{SXX}}
$$

where $t(\alpha/2, n-1)$ is the $100(1-\alpha/2)$th quantile of the $t$-distribution with $n-2$ degrees of freedom.

### Prediction Interval for $y^*$

A $100(1-alpha)\%$ prediction interval for $Y^*$, the value of $Y$ at $X = x^*$, is given by

$$
\hat y^* \pm t(\frac{\alpha}{2}, n-2) S \sqrt{1 +\frac{1}{n} + \frac{(x^* - \bar x)^2}{SXX}} \\
= \hat\beta_0 + \hat\beta_1 x^* \pm t(\frac{\alpha}{2}, n-2) S \sqrt{1 + \frac{1}{n} + \frac{(x^* - \bar x)^2}{SXX}}
$$

where $t(\alpha/2, n-1)$ is the $100(1-\alpha/2)$th quantile of the $t$-distribution with $n-2$ degrees of freedom.

## 2.5 - ANOVA Table



## 2.6 - Regression Diagnostics


