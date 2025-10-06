# 2 - Probability: Univariate Models

## 2.1 - Introduction

There are two different interpretations of probability:
1. In the **frequentist** interpretation, probabilities represent the long run frequencies of events that can happen multiple times.
2. In the **Bayesian** interpretation, probability is used to quantify our uncertainty about something.

Uncertainty in predictions can arise for two different reasons:
1. **Epistemic uncertainty** (or **model uncertainty**) is due to ignorance in the underlying hidden causes or mechanism generating our data.
2. **Aleatoric uncertainty** (or **data uncertainty**) arises from intrinsic uncertainty, which cannot be reduced even by collecting new data.

## 2.2 - Random Variables

### 2.2.1 - Discrete random variables



### 2.2.2 - Continuous random variables



### 2.2.3 - Sets of related random variables



### 2.2.4 - Independence and conditional independence



### 2.2.5 - Moments of a distribution



### 2.2.6 - Limitations of summary statistics *



## 2.3 Bayes’ rule

### 2.3.1 - Example: Testing for COVID-19



### 2.3.2 - Example: The Monty Hall problem



### 2.3.3 - Inverse problems *



## 2.4 - Bernoulli and binomial distributions

### 2.4.1 - Definition



### 2.4.2 - Sigmoid (logistic) function

A **sigmoid** is an S-shaped function that is used to predict a binary variable.

$$ \sigma(a) \triangleq \frac{1}{1 + e^{-a}} $$

This forces the output of the function $a$ to be lie between 0 and 1.

### 2.4.3 - Binary logistic regression



## 2.5 - Categorical and multinomial distributions

### 2.5.1 - Definition

The **categorical distribution** generalizes the Bernoulli distribution to $C > 2$ values. It is a discrete distribution with one parameter per class:

$$ \text{Cat}(y | \boldsymbol{\theta}) \triangleq \prod^C_{c=1} \theta_c^{\mathbb{I}(y=c)} $$

### 2.5.2 - Softmax function

The **softmax function** takes a vector of real numbers and converts it into a probability distribution (nonnegative values that sum to 1).

For a vector $\boldsymbol{z} = (z_1, z_2, \dots, z_K)$, the softmax is:

$$ \text{softmax}(z_i) = \frac{e^{z_i}}{\sum^K_{j=1} e^{z_j}} \text{ for } i = 1, \dots, K $$

This is kind of like the multinomial version of the sigmoid function.

### 2.5.3 - Multiclass logistic regression



### 2.5.4 - Log-sum-exp trick



## 2.6 - Univariate Gaussian (normal) distribution

### 2.6.1 - Cumulative distribution function



### 2.6.2 - Probability density function



### 2.6.3 - Regression



### 2.6.4 - Why is the Gaussian distribution so widely used?



### 2.6.5 - Dirac delta function as a limiting case

As the variance of the Gaussian distribution approaches 0, the distribution approaches an infinitely narrow and infinitely tall spike:

$$ \lim_{\sigma \rightarrow 0} \mathcal{N}(y|\mu, \sigma^2) \rightarrow \delta(y - \mu) $$

where $\delta$ is the **Dirac delta function**, defined by

$$ \delta(x) = \begin{cases}
    +\infty & \text{if } x = 0 \\
    0 & \text{if } x \ne 0
\end{cases} $$

## 2.7 - Some other common univariate distributions *



### 2.7.1 - Student t distribution



### 2.7.2 - Cauchy distribution



### 2.7.3 - Laplace distribution



### 2.7.4 - Beta distribution



### 2.7.5 - Gamma distribution



### 2.7.6 - Empirical distribution



## 2.8 - Transformations of random variables *



### 2.8.1 - Discrete case



### 2.8.2 - Continuous case



### 2.8.3 - Invertible transformations (bijections)



### 2.8.4 - Moments of a linear transformation



### 2.8.5 - The convolution theorem



### 2.8.6 - Central limit theorem



### 2.8.7 - Monte Carlo approximation



## 2.9 Exercises

