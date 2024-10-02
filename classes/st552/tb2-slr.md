# TB2 - SLR

## 2.1 - Introduction and Least Squares Estimates

In this chapter, we consider problems modeling the relationship between two variables as a straight line. Note that a scatter plot should always be drawn before building a model to get an idea about the relationship between two variables.

### 2.1.1 - Simple Linear Regression Models

The regression of $Y$ on $X$ is linear if and only if

$$ E(Y | X = x) = \beta_0 + \beta_1 x $$

where the unknown parameters $\beta_0$ and $\beta_1$ determine the intercept and slope of a specific straight line.

Suppose that $Y_1, Y_2, \dots, Y_n$ are independent realizations of the random variable $Y$ that are observed at the values $x_1, x_2, \dots, x_n$ of a random variable $X$. If the regression of $Y$ on $X$ is linear, then for $i = 1, 2, \dots, n$

$$ Y_i = E(Y | X = x) + \epsilon_i = \beta_0 + \beta_1 x + \epsilon_i $$

where $\epsilon_i$ is the random error in $Y_i$ and is such that $E(\epsilon | X) = 0$.

We will begin by assuming that

$$ \text{Var}(Y | X=x) = \sigma^2 $$

#### Estimating the Population Slope and Intercept

Since the population intercept $\beta_0$ and slope $\beta_1$ are unknown, we must find $b_0$ and $b_1$ such that $\hat y_i = b_0 + b_1 x_i$ is as close as possible to $y_i$.

#### Residuals

In practice, we want to minimize the difference between the actual value of $y$ ($y_i$) and the predicted value of $y$ ($\hat y_i$). This difference is called the residual $\hat\epsilon_i$, that is

$$ \hat\epsilon_i = y_i - \hat y_i $$

#### Least Squares Line of Best Fit

A very popular method of choosing $b_0$ and $b_1$ is called the method of least squares. With this method, $b_0$ and $b_1$ are chosen to minimize the sum of squared residuals.

$$ \text{RSS} = \sum^n_{i=1} \hat\epsilon_i^2 = \sum^n_{i=1} (y_i - \hat y_i)^2 = \sum^n_{i=1} (y_i - b_0 - b_1 x_i)^2 $$

We can solve the following **normal equations**

$$ \sum^n_{i=1} y_i = b_0 n + b_1 \sum^n_{i=1} x_i $$

$$ \sum^n_{i=1} x_i y_i = b_0 \sum^n_{i=1} x_i + b_1 \sum^n_{i=1} x_i^2 $$

to get the **least squares estimates** of the intercept and the slope:

$$ \hat\beta_0 = \bar y - \hat\beta_1 \bar x $$

$$ \hat\beta_1 = \frac{\sum^n_{i=1} x_i y_i - n \overline{xy}}{\sum^n_{i=1} x_i^2 - n \bar x^2} = \frac{\sum^n_{i=1} (x_i - \bar x)(y_i - \bar y)}{\sum^n_{i=1}(x_i - \bar x)^2} = \frac{SXY}{SXX} $$

#### Estimating the Variance of the Random Error Term

Consider the linear regression model with constant variance:

$$ Y_i = \beta_0 + \beta_1 x_i + \epsilon_i \ \ \ \ (i = 1, 2, \dots, n) $$

where the random error $\epsilon_i$ has mean $0$ and variance $\sigma^2$. We wish to examine $\sigma^2 = \text{Var}(\epsilon)$. Notice that

$$ \epsilon_i = Y_i - (\beta_0 + \beta_1 x_i) = Y_i - \text{unknown regression line at } x_i $$

The residuals can be used to estimate $\sigma^2$. It can be shown that

$$ S^2 = \frac{\text{RSS}}{n-2} = \frac{1}{n-2} \sum^n_{i=1} \hat\epsilon_i^2 $$

is an unbiased estimate of $\sigma^2$. Note:
- $\bar{\hat\epsilon} = 0$
- The divisor in $S^2$ is $n-2$ since we have estimated two parameters ($\beta_0$ and $\beta_1$)

## 2.2 - Inferences About the Slope and Intercept

### 2.2.1 - Assumptions Necessary to Make Inferences About the Regression Model

1. $Y$ is related to $x$ by the simple linear regression model.
2. The errors $\epsilon_1, \dots, \epsilon_n$ are independent of each other.
3. The errors $\epsilon_1, \dots, \epsilon_n$ have a common variance $\sigma^2$.
4. The errors are normally distributed with a mean of 0 and variance $\sigma^2$.

### 2.2.2 - Inferences About the Slope of the Regression Line

$$ \hat\beta_1 = \sum^n_{i=1} c_i y_i \text{ where } c_i = \frac{x_i - \bar x}{SXX} $$

$$ E(\hat\beta_1 | X) = \beta_1 $$

$$ \text{Var}(\hat\beta_1 | X) = \frac{\sigma^2}{SXX} $$

$$ \hat\beta_1 | X \sim N \left(\beta_1, \frac{\sigma^2}{SXX} \right) $$

To construct a hypothesis test for $\beta_1$, we can use the following $t$-distribution:

$$ T = \frac{\hat\beta_1 - \beta_1}{\frac{S}{\sqrt{SXX}}} = \frac{\hat\beta_1 - \beta_1}{ \text{se}(\hat\beta_1)} \sim t_{n-2} $$

Note that $\text{se}(\hat\beta_1)$ is given directly by R.

### 2.2.3 - Inferences About the Intercept of the Regression Line

$$ E(\hat\beta_0 | X) = \beta_0 $$

$$ \text{Var}(\hat\beta_0 | X) = \sigma^2 \left( \frac{1}{n} + \frac{\bar x^2}{SXX} \right) $$

$$ \hat\beta_0 | X \sim N \left( \beta_0, \sigma^2 \left( \frac{1}{n} + \frac{\bar x^2}{SXX} \right) \right) $$

To construct a hypothesis test and confidence interval for $\beta_0$, we can use the following $t$-distribution:

$$ T = \frac{\hat\beta_0 - \beta_0}{S \sqrt{\frac{1}{n} + \frac{\bar x^2}{SXX}}} = \frac{\hat\beta_0 - \beta_0}{\text{se}(\hat\beta_0)} \sim t_{n-2} $$

## 2.3 - Confidence Intervals for the Population Regression Line



## 2.4 - Prediction Intervals for the Actual Values of $Y$


