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

If we want to predict a real-valued quantity $y \in \mathbb{R}$ instead of a class label $y \in \{ 1, \dots, C \}$, this is known as **regression**.

Regression is very similar to classification, but we need to use a different loss function. The most common choice is to use quadratic loss:

$$ \ell_2(y, \hat{y}) = (y - \hat{y})^2 $$

The empirical risk when using quadratic loss is equal to the **mean squared error (MSE)**:

$$ \text{MSE}(\boldsymbol{\theta}) = \frac{1}{N} \sum^N_{n=1} (y_n - f(\boldsymbol{x}_n; \boldsymbol{\theta}))^2 $$

In regression problems, we typically assume that the output distribution is normal.

#### Linear Regression

A **simple linear regression (SLR)** model model takes the following form:

$$ f(x; \boldsymbol{\theta}) = \beta_0 + \beta_1 x $$

We can adjust $\beta_0$ and $\beta_1$ to find the values that minimize the squared errors.

If we have multiple input features, we can use a **multiple linear regression (MLR)** model:

$$ f(x; \boldsymbol{\theta}) = \beta_0 + \beta_1 x_1 + \dots + \beta_n x_n $$

#### Polynomial Regression

A **polynomial regression** model of degree $D$ has the form $f(x;\boldsymbol{\omega}) = \omega^T \phi(x)$, where $\phi(x)$ is a feature vector derived from the input, which has the following form:

$$ \phi(x) = [1, x, x^2, \dots, x^D] $$

Note that we can have multi-dimensional inputs and interaction terms in polynomial regression models.

#### Deep Neural Networks

We can create powerful models by having the feature extraction be performed automatically. This is the key idea behind deep neural networks (DNNs), convolutional neural networks (CNNs), and recurrent neural networks (RNNs).

### 1.2.3 - Overfitting and generalization



### 1.2.4 - No free lunch theorem

The **no free lunch theorem** describes that there is no one general model that works best for all situations. Instead, the best model must be carefully selected for the situtation.

## 1.3 - Unsupervised learning

**Unsupervised learning** has no output targets and seeks to make sense of data.

### 1.3.1 - Clustering

The goal of clustering is to partition the inputs into regions that contain similar points. Note that the number of clusters is determined by balancing model complexity and fit to the data.

### 1.3.2 - Discovering latent "factors of variation"

When dealing with high-dimensional data, it is often useful to reduce the dimensionality by projecting it to a lower dimensional subspace that captures the essence of the data.

One approach to this problem is to assume that each observed high-dimensional output $\boldsymbol{x}_n \in \mathbb{R}^D$ was generated by a set of hidden or unobserved low-dimensional **latent factors** $\boldsymbol{z}_n \in \mathbb{R}^K$.

### 1.3.3 - Self-supervised learning



### 1.3.4 - Evaluating unsupervised learning



## 1.4 - Reinforcement learning

**Reinforcement learning (RL)** is a third type of ML that in which the agent has to learn how to interact with its environment. It differs from supervised learning in that the system does not receive a response for each input, but rather an intermittent reward/punishment.

## 1.5 - Data

### 1.5.1 - Some common image datasets

The following are some common small image datasets:
- **MNIST** is a dataset of 60k training images and 10k test images, each of size 28 x 28 (grayscale), illustrating handwritten digits.
- **EMNIST** (extended MNIST) is MNIST, but but with lower and upper case letters as well.
- **Fashion-MNIST** has the same size as MNIST, but each picture represents an article of clothing.
- **CIFAR** is a dataset of 60k images, each of size 32 x 32 x 3, representing everyday objects from 10 or 100 classes.

**ImageNet** is a dataset of about 14 million images of size 256 x 256 x 3 illustrating images from 20000 different classes.

### 1.5.2 - Some common text datasets

When machine learning is applied to text to solve tasks, it is known as **natural language processing (NLP)**.

A simple NLP task is text classification, which can be used for spam classification, sentiment analysis, and much more. A common dataset for evaluating such methods is the **IMDB movie review dataset**.

A more difficult NLP task is map a sentence $\boldsymbol{x}$ in one language to a semantically equivalent sentence $\boldsymbol{y}$ in another language, which is called **machine translation**.

A **seq2seq model** is a mapping of one sequence $\boldsymbol{x}$ to another sequence $\boldsymbol{y}$. This can include document summarization, question summarization, and more.

### 1.5.3 - Preprocessing discrete input data

When we have categorical features, we need to convert them to a numerical scale so that computing weighted combinations of inputs makes sense. The standard way to preprocess such categorical variables is to use a **one-hot encoding** (or a **dummy encoding**). If a variable $x$ has $K$ values, we denote its dummy encoding as follows: $\text{one-hot}(x) = [\mathbb{I}(x = 1), \dots, \mathbb{I}(x = K)]$.

A linear model using dummy encoding for each categorical variable can capture the main effects, but not the interaction effects between them. We can fix this by computing **feature crosses**, which contain each combination of multiple categories. Note that the use of feature crosses converts the dataset into a wide format with many more columns.

### 1.5.4 - Preprocessing text data

Words that were not encountered in the training data are called **out-of-vocabulary (OOV)** words.

#### Bag of words model

On approach to parsing variable-length text documents is to interpret them as a **bag of words**, in which we ignore word order. To convert this to a vector, we first map each word to a token from some vocabulary.

To reduce the number of tokens, we often use various preprocessing techniques, such as dropping punctuation, converting everything to lower case, dropping common but uninformative words (called **stop word removal**), and replacing words with their base form (called **word stemming**).

Let $x_{nt}$ be the token at location $t$ in the $n$th document. If there are $D$ unique tokens in the vocabulary We can represent the $n$th document as a $D$-dimensional vector $\boldsymbol{x}_n$, where $\boldsymbol{x}_{nv}$ is the number of times that word $v$ occurs in document $n$:

$$ \boldsymbol{x}_{nv} = \sum^T_{t=1} \mathbb{I}(x_{nt} = v) $$

where $T$ is the length of document $n$. This is called the **vector space model** of text.

We typically store input data in an $N \times D$ matrix denoted by $\textbf{X}$, where $D$ is the number of features. In the context of vector space models, it is more common to represent the input data as a $D \times N$ **term frequency matrix**, where $\text{TF}_{ij}$ is the frequenct of term $i$ in document $j$.

#### TF-IDF

To reduce the impact of words that appear many times in general, we compute a quantity called the **inverse document frequency**, defined as $\text{IDF}_i \triangleq \log\frac{N}{1 + \text{DF}_i}$, where $\text{DF}_i$ is the number of documents with term $i$. We can combine these transformations to compute the **TF-IDF** matrix as follows:

$$ \text{TFIDF}_{ij} = \log(\text{TF}_{ij} + 1) \times \text{IDF}_i $$

#### Word embeddings

**Word embeddings** map each sparse one-hot vector, $\boldsymbol{x}_{nt} \in \{0, 1\}^V$, to a lower-dimensional dense vector, $\boldsymbol{e}_{nt} \in \mathbb{R}^K$ using $\boldsymbol{e}_{nt} = \textbf{E} \boldsymbol{x}_{nt}$, where $\textbf{E} \in \mathbb{R}^{K \times V}$ is learned such that semantically similar words are placed close by. Once we have an embedding matrix, we can represent a variable-length text document as a **bag of word embeddings**. We can then convert this to a fixed length vector by summing the embeddings

$$ \bar{\boldsymbol{e}}_n = \sum^T_{t=1} \boldsymbol{e}_{nt} = \textbf{E} \tilde{\boldsymbol{x}}_n $$

where $\tilde{\boldsymbol{x}}_n$ is the bag of words representation. We can use this inside of a logistic regression classifier. The overall model has the form

$$ p(y = c | \boldsymbol{x}_n, \boldsymbol{\theta}) = \text{softmax}_c(\textbf{WE} \tilde{\boldsymbol{x}}_n) $$

We often use a **pre-trained word embedding** matrix $\textbf{E}$, in which case the model is linear in $\textbf{W}$, which simplifies parameter estimation.

#### Dealing with novel words

If the model encounters a novel word at test time, it is known as **out of vocabulary (OOV)**. A standard heuristic to solve this problem is to replace all novel words with the special symbol **UNK**. This loses information, since we may be able to deduce info from suffixes/root words. To address this, we can break the words down into their substructure, and then take **subword units** or **wordpieces**. These are often created using a method called **byte-pair encoding**, which is a form of data compression that creates new symbols to represent common substrings.

### 1.5.5 - Handling missing data



## 1.6 - Discussion

The field of **predictive analytics** is similar to supervised learning, but focuses more on business applications. **Data mining** covers both supervised and unsupervised machine learning, but focuses more on structured data. **Data science** uses techniques from machine learning and statistics, but also focuses on other topics.

Machine learning is related to the field of **artificial intelligence (AI)**, as it is the way that AI systems often obtain knowledge.

It is hard to design a loss function that correctly specifies our preferences, resulting in **reward hacking**, where the machine optimizes the reward function we give it. This is part of the larger **alignment problem** , which is the potential discrepancy between what we ask our algorithms to optimize and what we actually want them to do.

The two main views of AI are as **artificial general intelligence (AGI)**, which makes decisions on its own without a human in the loop, and **augmented intelligence (IA)**, which views AI as a process for creating smart tools.
