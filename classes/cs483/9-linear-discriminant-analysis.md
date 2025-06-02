# 9 - Linear Discriminant Analysis

## 9.1 - Introduction

In this chapter, we consider models of the following form:

$$ p(y = c | \boldsymbol{x}, \boldsymbol{\theta}) = \frac{p(\boldsymbol{x} | y = c, \boldsymbol{\theta})p(y = c | \boldsymbol{\theta})}{\sum_{c'} p(\boldsymbol{x} | y = c', \boldsymbol{\theta}) p(y = c' | \boldsymbol{\theta})} $$

The term $p(y = c | \boldsymbol{\theta})$ is the prior over class labels, and the term $p(\boldsymbol{x} | y = c, \boldsymbol{\theta})$ is called the **class conditional density** for class $c$.

## 9.2 - Gaussian discriminant analysis

### 9.2.1 - Quadratic decision boundaries



### 9.2.2 - Linear decision boundaries



### 9.2.3 - The connection between LDA and logistic regression



### 9.2.4 - Model fitting



### 9.2.5 - Nearest centroid classifier



### 9.2.6 - Fisher’s linear discriminant analysis *



## 9.3 - Naive Bayes classifiers

### 9.3.1 - Example models



### 9.3.2 - Model fitting



### 9.3.3 - Bayesian naive Bayes



### 9.3.4 - The connection between naive Bayes and logistic regression



## 9.4 - Generative vs discriminative classifiers

### 9.4.1 - Advantages of discriminative classifiers



### 9.4.2 - Advantages of generative classifiers



### 9.4.3 - Handling missing features



### 9.5 Exercises -


