# 16 - Exemplar-based Methods

## 16.1 - K nearest neighbor (KNN) classification

**K nearest neighbor (KNN)** is a non-parametric classification algorithm that classifies a new input $\boldsymbol{x}$ based on the $K$ closest examples to $\boldsymbol{x}$ in the training set, denoted $N_K(\boldsymbol{x}, \mathcal{D})$. We compute

$$ p(y=c | \boldsymbol{x}, \mathcal{D}) = \frac{1}{K} \sum_{n \in N_K (\boldsymbol{x}, \mathcal{D})} \mathbb{I}(y_n = c) $$

From this, we can determine the distribution or the majority label.

KNN requires two parameters:
1. The size of the neighborhood $K$
2. The distance metric $d(\boldsymbol{x}, \boldsymbol{x'})$

For the distance metric, it is common to use the **Mahalanobis distance**, defined:

$$ d_\textbf{M}(\boldsymbol{x}, \boldsymbol{\mu}) = \sqrt{(\boldsymbol{x} - \boldsymbol{\mu})^T \textbf{M}(\boldsymbol{x} - \boldsymbol{\mu})} $$

where $\textbf{M}$ is a positive definite matrix.

### 16.1.1 - Example

If we use $K = 1$, then we create a **Voronoi tesselation** of the points, which is a space wherein each new point is assigned to its closed neighbor.

### 16.1.2 - The curse of dimensionality

Due to the curse of dimensionality, KNN classifiers do not work well with high dimensional inputs. There are two main ways to address the curse:
1. Make assumptions about the form of the function (use a parametric model)
2. Use a metric that only cares about a small subset of the dimensions

### 16.1.3 - Reducing the speed and memory requirements

KNN classifiers require storing all of the training data, which is a waste of space. Various methods exist to remove points that do not affect the decision boundaries.

Once the number of dimensions exceeds 10, it is computationally infeasible to find the $K$ nearest neighbors, so most methods focus on finding the approximate nearest neighbors. These techniques will typically require either partition the space into regions or hashing.
- A **k-d tree** divides space into axis-parallel regions or some kind of clustering method using anchor points. 
- For hashing methods, **locality sensitive hashing (LSH)** is widely used.

### 16.1.4 - Open set recognition

The **closed world assumption** describes the assumption that there is a fixed set of classes. However, many real world problems involve test samples that come from new categories. This is called **open set recognition**.

Consider a face recognition system trained to predict the identity of a person from a fixed set of face images. At test time, we may encounter an input from a new category. The ability to recognize that the input belongs to a new category and not an existing category is called **novelty detection**.

If we then assign a label to the newly discovered class and add it to the set of class is called **incremental learning**, **online learning**, **life-long learning**, or **continual learning**. Detecting that an input is from an entirely different kind of distribution (e.g. a picture of a dog to the face recognition system) is called **out-of-distribution (OOD)** detection.

Prediction in settings where we only have a few examples of each class is called **few-shot classification**. Novelty and OOD detection can be easily be implemented with KNN by checking the distance to see whether a new input is far enough from its neighbors to be a novel class or OOD.

A few other open world problems include:
- *Entity resolution*, or *entity linking*, determines whether different strings refer to the same entity.
- *Multi-object tracking*, such as determining whether a new blip on a radar system is an object being tracked or a new object.

## 16.2 - Learning distance metrics

### 16.2.1 - Linear and convex methods



### 16.2.2 - Deep metric learning



### 16.2.3 - Classification losses



### 16.2.4 - Ranking losses



### 16.2.5 - Speeding up ranking loss optimization



### 16.2.6 - Other training tricks for DML



## 16.3 - Kernel density estimation (KDE)

### 16.3.1 - Density kernels



### 16.3.2 - Parzen window density estimator



### 16.3.3 - How to choose the bandwidth parameter



### 16.3.4 - From KDE to KNN classification



### 16.3.5 - Kernel regression
