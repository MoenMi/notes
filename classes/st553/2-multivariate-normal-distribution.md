# 2 - Multivariate Normal Distribution

## 2.1 - Review of the Univariate Normal Distribution

A **normal probability distribution**, also known as a **Gaussian probability distribution**, expresses the probabilities of outcomes for a continuous random variable $x$ with a particular symmetric and unimodal distribution. This density function is given by

$$ f(x) = \frac{1}{\sqrt{2 \pi} \sigma} e^{\frac{-(x - \mu)^2}{2 \sigma^2}} $$

where
- $\mu$ = mean
- $\sigma$ = standard deviation

Characteristics of the normal probability distribution:
- There are an infinite number of normal distributions, each defined by their own unique combination of the mean $\mu$ and the standard deviation $\sigma$.
- $\mu$ determines the central location and $\sigma$ determines the spread or width.
- The distribution is symmetric about $\mu$.
- It is unimodal.
- $\mu$ = $M_d$ = $M_o$
- It is asymptotic with respect to the horizontal axis.
- The area under the curve is $1$.
- It is neither platykrurtic nor leptokurtic.
- It follows the empirical rule:

$$ \begin{align*}
    P(\mu - 1\sigma \leq x \leq \mu + 1\sigma) &\approx 0.68 \\
    P(\mu - 2\sigma \leq x \leq \mu + 2\sigma) &\approx 0.95 \\
    P(\mu - 3\sigma \leq x \leq \mu + 3\sigma) &\approx 0.997
\end{align*} $$

- The shape of the curve is entirely determined by $\sigma$.

### Standard Normal Distribution

The **standard normal distribution** is the probability distribution associated with any normal random variable (usually denoted $z$) that has $\mu = 0$ and $\sigma = 1$.

## 2.2 - The Multivariate Normal Distribution

The univariate normal distribution has a generalized form in $p$ dimensions. The $p$-dimensional normal density function is

$$ f(\bm{x}) = \frac{1}{(2\pi)^{p/2} |\Sigma|^{1/2}} e^{[-(\bm{x} - \bm{\mu})' \Sigma^{-1} (\bm{x} - \bm{\mu})]/2} $$

where $-\infty \leq x_i \leq \infty, i = 1, \dots, p$.

This $p$-dimensional normal density function is denoted by $N_p (\bm{\mu}, \bm{\Sigma})$ where

$$ \bm{\mu} = \begin{bmatrix} \mu_1 \\ \mu_2 \\ \vdots \\ \mu_p \end{bmatrix}, \bm{\Sigma} = \begin{bmatrix}
    \sigma_{11} & \sigma_{12} & \dots & \sigma_{1p} \\
    \sigma_{21} & \sigma_{22} & \dots & \sigma_{2p} \\
    \vdots & \vdots & \ddots & \vdots \\
    \sigma_{p1} & \sigma_{p2} & \dots & \sigma_{pp}
\end{bmatrix} $$

### Bivariate Normal Distribution

The simplest multivariate normal distribution is the **bivariate (2 dimensional) normal distribution**, which has the density function

$$ f(\bm{x}) = \frac{1}{(2\pi) |\bm{\Sigma}|} e^{[-(\bm{x} - \bm{\mu})' \Sigma^{-1} (\bm{x} - \bm{\mu})]/2} $$

where$-\infty \leq x_i \leq \infty, i = 1, 2$.

This $2$-dimensional normal density function is denoted by $N_2 (\bm{\mu}, \bm{\Sigma})$ where

$$ \bm{\mu} = \begin{bmatrix} \mu_1 \\ \mu_2 \end{bmatrix}, \bm{\Sigma} = \begin{bmatrix}
    \sigma_{11} & \sigma_{12} \\
    \sigma_{21} & \sigma_{22}
\end{bmatrix} $$

and we can write $\bm{X} \sim N_2 (\bm{\mu}, \bm{\Sigma})$

We can easily find the inverse of the covariance matrix:

$$ \bm{\Sigma}^{-1} = \frac{1}{\sigma_{11} \sigma_{22} - \sigma_{12}^2} \begin{bmatrix}
    \sigma_{22} & -\sigma_{12} \\
    -\sigma_{21} & \sigma_{11}
\end{bmatrix} $$

We can use the relationship

$$ \sigma_{12} = \rho_{12} \sqrt{\sigma_{11}} \sqrt{\sigma_{22}} $$

to establish that

$$ \sigma_{11} \sigma{22} - \sigma_{12}^2 = \sigma_{11} \sigma_{22} (1 - \rho_{12}^2) $$



## 2.3 - Properties of the Multivariate Normal Distribution

For any multivariate normal random vector $\bm{X}$:
1. The density

   $$ f(\bm{x}) = \frac{1}{(2\pi)^{p/2} |\Sigma|^{1/2}} e^{[-(\bm{x} - \bm{\mu})' \Sigma^{-1} (\bm{x} - \bm{\mu})]/2} $$

   has a maximum value at

   $$ \bm{\mu} = \begin{bmatrix} \mu_1 \\ \mu_2 \\ \vdots \\ \mu_p \end{bmatrix} $$

   i.e., the mean is equal to the mode

2. The density 
   
   $$ f(\bm{x}) = \frac{1}{(2\pi)^{p/2} |\Sigma|^{1/2}} e^{[-(\bm{x} - \bm{\mu})' \Sigma^{-1} (\bm{x} - \bm{\mu})]/2} $$

   is symmetric along its constant density contours and is centered at $\bm{\mu}$, i.e., the mean is equal to the median.
3. All linear combinations of the components of $\bm{X}$ are normally distributed.
4. All subsets of the components of $\bm{X}$ have a (multivariate) normal distribution.
5. Zero covariance implies that the corresponding components of $\bm{X}$ are independently distributed.
6. All conditional distributions of the components of $\bm{X}$ are (multivariate) normal.

## 2.4 - Some Important Results Regarding the Multivariate Normal Distribution

1. If $\bm{X} \sim N_p(\bm{\mu}, \bm{\Sigma})$, then any linear combination
   
   $$ \bm{a'X} = \sum^p_{i=1} a_i X_i \sim N_p (\bm{a'\mu}, \bm{a'\Sigma a}) $$

   Furthermore, if $\bm{a'X} \sim N_p(\bm{\mu}, \bm{\Sigma})$ for every $\bm{a}$, then $\bm{X} \sim N_p(\bm{\mu}, \bm{\Sigma})$

2. 

## 2.5 - Sampling from a Multivariate Normal Distribution and Maximum Likelihood Estimation

Let $\bm{X}_j \sim N_p (\bm{\mu}, \bm{\Sigma}), j = 1, \dots, n$ represent a random sample.

Since the $\bm{X}_j$'s are mutually independent and each have distribution $N_p (\bm{\mu}, \bm{\Sigma})$, their joint density is the product of the marginal densities, i.e.,

$$ \begin{align*} \{ \text{joint density of } \bm{X}_1, \bm{X}_2, \dots, \bm{X}_n \}
&= \prod^n_{j=1} \frac{1}{(2\pi)^{p/2} |\bm{\Sigma}|^{1/2}} e^{[-(\bm{x}_j - \bm{\mu})' \bm{\Sigma}^{-1}(\bm{x}_j - \bm{\mu})]/2}  \\
&= \frac{1}{(2\pi)^{np/2} |\bm{\Sigma}|^{n/2}} e^{- \sum^n_{j=1}[(\bm{x}_j - \bm{\mu})' \bm{\Sigma}^{-1}(\bm{x}_j - \bm{\mu})]/2}
\end{align*} $$

**Maximum likelihood estimation**: Estimation of parameter values by finding estimates that maximize the likelihood of the sample data on which they are based (select estimated values for parameters that best explain the sample data collected).

**Maximum likelihood estimates**: The estimates of parameter values that maximize the likelihood of the sample data on which they are based.

We would like to obtain the maximum likelihood estimates of the parameters $\bm{\mu}$ and $\bm{\Sigma}$ given the sample data $\bm{X}$ we have collected. To simplify our efforts we will need to utilize some properties of the trace to rewrite the likelihood function in another form.



## 2.6 - The Sampling Distributions of $\bm{\bar{X}}$ and $\bm{S}$

For the multivariate case where $\bm{X} \sim N_p(\bm{\mu}, \bm{\Sigma})$, the sample mean is distributed as such

$$ \bar{\bm{X}} \sim N_p(\bm{\mu}, \frac{1}{n} \bm{\Sigma}) $$

## 2.7 - Large Sample Behavior of $\bar{\bm{X}}$ and $\bm{S}$



## 2.8 - Assessing the Assumption of Normality



## 2.9 - Outlier Detection



## 2.10 - Transformations to Near Normality


