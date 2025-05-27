# 1 - Introduction

## 1.1 - What is machine learning?

A popular definition of **machine learning (ML)** is as follows: A computer program is said to learn from experience E with respect to some class of tasks T, and performance measure P, if its performance at tasks in T, as measured by P, improves with experience E.

This book examines ML from a **probabilistic perspective**, meaning that we treat all unknown quantities as random variables that have probability distributions.

We adopt the probabilistic approach for the following two reasons:
1. It is the optimal approach for decision making under uncertainty.
2. Probabilitic modeling is used by most other areas of science and engineering.

## 1.2 - Supervised learning

In **supervised learning**, the most common form of ML, the task is to learn a mapping $f$ from inputs $\bf{x} \in \mathcal{X}$ to outputs $\bf{y} \in \mathcal{Y}$.
- The inputs $\bf{x}$ are called the **features**, **covariates**, or **inputs**. In this case, $\mathcal{X} = \mathbb{R}^D$, where $D$ is the dimensionality of the vector.
- The output $\bf{y}$ is also known as the **label**, **target**, or **response**.

The experience E, also known as the **sample size** is given in the form of the set of $N$ input-output pairs $\mathcal{D} = \{(\bf{x}_n, \bf{y}_n)\}^N_{n=1}$, known as the **training set**. The performance measure P depends on the type of output we are predicting.

### 1.2.1 - Classification

In **classification** problems, the output space is a set of $C$ unordered and mutually exclusive labels known as **classes**, $\mathcal{Y} = \{ 1,2,\dots,C \}$. The problem of predicting the class label given in an output is also called **pattern recognition**. If there are just two classes, this problem is called **binary classification**.

#### Classifying Iris flowers

**Image classification** problems can be solved using **convolutional neural networks (CNNs)**.

When we have small datasets of features, it is common to store them in an $N \times D$ matrix, in which each row is a trial and each column is a feature. This is known as a **design matrix**.

#### Exploratory data analysis

Before tackling a problem with ML, it is wise to perform an **exploratory data analysis** to find any trends in the data. For datasets with high dimensionality, it is common to perform **dimensionality reduction**.

#### Learning a classifier

A **decision rule** can be created to classify things into different classes, which may involve a **decision boundary**. Multiple decision rules can be chained together to form a **decision tree**.

#### Empirical risk minimization

A common way to measure the performance of a decision tree model is in terms of the **misclassification rate** on the training set:

$$ \mathcal{L}(\theta) \triangleq \frac{1}{N} \sum^N_{n=1} \mathbb{I} (y_n \neq f(\bf{x}_n; \bf{\theta})) $$

where $\mathbb{I}(e)$ is the binary **indicator function**, which returns $1$ iff the condition $e$ is true, and $0$ if it is false.

$$ \mathbb{I} = \begin{cases} 1 & \text{if } e \text{ is true} \\ 0 & \text{if } e \text{ is false} \end{cases} $$

Note that this assumes that all errors are equal. In cases where some errors are more costly than others, we might use a **loss function** $\mathbb{\ell(y, \hat y)}$. We can then define **empirical risk**:

$$ \mathcal{L}(\theta) \triangleq \frac{1}{N} \sum^N_{n=1} \ell (y_n \neq f(\bf{x}_n; \bf{\theta})) $$

In general, our goal is to minimize this empirical risk function on the training set while keeping it generalizable for future data.

#### Uncertainty

There are two times of uncertainty that prevent us from being able to perfectly predict an output based on an input:
- **Epistemic uncertainty** (or **model uncertainty**) is due to lack of knowledge of the input-output mapping.
- **Aleatoric uncertainty** (or **data uncertainty**) is due to intrinsic stochasticity in the mapping.

#### Maximum likelihood estimation

When fitting probabilistic models, it is common to use the negative log probability as the loss function:

$$ \ell(y, f(\textbf{x}; \boldsymbol{\theta})) = -\log p(y | f(\textbf{x}; \boldsymbol{\theta})) $$

The average **negative log likelihood** is given as

$$ \text{NLL}(\boldsymbol{\theta}) = - \frac{1}{N} \sum^N_{n=1} \log p(y_n | f(\textbf{x}_n; \boldsymbol{\theta})) $$

This can be minimized to compute the **maximum likelihood estimate (MLE)**.

### 1.2.2 - Regression



### 1.2.3 - Overfitting and generalization



### 1.2.4 - No free lunch theorem

The **no free lunch theorem** describes that there is no one general model that works best for all situations. Instead, the best model must be carefully selected for the situtation.

## 1.3 - Unsupervised learning

### 1.3.1 - Clustering



### 1.3.2 - Discovering latent "factors of variation"



### 1.3.3 - Self-supervised learning



### 1.3.4 - Evaluating unsupervised learning



## 1.4 - Reinforcement learning



## 1.5 - Data

### 1.5.1 - Some common image datasets



### 1.5.2 - Some common text datasets



### 1.5.3 - Preprocessing discrete input data



### 1.5.4 - Preprocessing text data



### 1.5.5 - Handling missing data



## 1.6 - Discussion

### 1.6.1 - The relationship between ML and other fields

The field of **predictive analytics** is similar to supervised learning, but focuses more on business applications. **Data mining** covers both supervised and unsupervised machine learning, but focuses more on structured data. **Data science** uses techniques from machine learning and statistics, but also focuses on other topics.

Machine learning is related to the field of **artificial intelligence (AI)**, as it is the way that AI systems often obtain knowledge.

### 1.6.3 - Caveats

It is hard to design a loss function that correctly specifies our preferences, resulting in **reward hacking**, where the machine optimizes the reward function we give it. This is part of the larger **alignment problem** , which is the potential discrepancy between what we ask our algorithms to optimize and what we actually want them to do.

The two main views of AI are as **artificial general intelligence (AGI)**, which makes decisions on its own without a human in the loop, and **augmented intelligence (IA)**, which views AI as a process for creating smart tools.
