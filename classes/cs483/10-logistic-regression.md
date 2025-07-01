# 10 - Logistic Regression

## 10.1 - Introduction

**Logistic regression** is a discriminative classification model $p(y|\boldsymbol{x};\boldsymbol{\theta})$, where $\boldsymbol{x}$ is a fixed-dimensional input vector, $y \in \{ 1, \dots, C \}$ is the class label, and $\boldsymbol{\theta}$ are the parameters. If $C = 2$, this is known as **binary logistic regression**. If $C > 2$, it is known as **multinomial logistic regression** or **multiclass logistic regression**.

## 10.2 - Binary logistic regression

Binary logistic regression corresponds to the following model:

$$ p(y|\boldsymbol{x};\boldsymbol{\theta}) = \text{Ber}(y|\sigma(\boldsymbol{\omega^T x} + b)) $$

where $\sigma$ is the sigmoid function, $\boldsymbol{\omega}$ are the weights, $b$ is the bias, and $\boldsymbol{\theta} = (\boldsymbol{\omega}, b)$ are all the parameters. In other words,

$$ p(y = 1 | \boldsymbol{x}; \boldsymbol{\theta}) = \sigma(a) = \frac{1}{1 + e^{-a}} $$

where $a = \boldsymbol{\omega^T x} + b = \log(\frac{p}{1-p})$ is the log-odds, and $p = p(y=1|\boldsymbol{x};\boldsymbol{\theta})$. In ML, the quantity $a$ is usually called the **logit** or the **pre-activation**.

### 10.2.1 - Linear classifiers



### 10.2.2 - Nonlinear classifiers



### 10.2.3 - Maximum likelihood estimation



### 10.2.4 - Stochastic gradient descent



### 10.2.5 - Perceptron algorithm



### 10.2.6 - Iteratively reweighted least squares



### 10.2.7 - MAP estimation



### 10.2.8 - Standardization



## 10.3 - Multinomial logistic regression



### 10.3.1 - Linear and nonlinear classifiers



### 10.3.2 - Maximum likelihood estimation



### 10.3.3 - Gradient-based optimization



### 10.3.4 - Bound optimization



### 10.3.5 - MAP estimation



### 10.3.6 - Maximum entropy classifiers



### 10.3.7 - Hierarchical classification



### 10.3.8 - Handling large numbers of classes



## 10.4 - Robust logistic regression *



### 10.4.1 - Mixture model for the likelihood



### 10.4.2 - Bi-tempered loss



## 10.5 - Bayesian logistic regression *



### 10.5.1 - Laplace approximation



### 10.5.2 - Approximating the posterior predictive
