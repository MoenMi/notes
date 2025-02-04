# 1 - Sample Geometry and Random Sampling

## 1.1 - The Geometry of the Random Sample

Our sample data in matrix form looks like this

$$ \bm{X}_{n \times p} = \begin{bmatrix}
    x_{11} & x_{12} & \dots & x_{1p} \\
    x_{21} & x_{22} & \dots & x_{2p} \\
    \vdots & \vdots & \ddots & \vdots \\
    x_{n1} & x_{n2} & \dots & x_{np}
\end{bmatrix} = \begin{bmatrix}
    \bm{x_1'} \\
    \bm{x_2'} \\
    \vdots \\
    \bm{x_n'}
\end{bmatrix} $$

Just as the point where the population means of all $p$ variables lies is the **centroid of the population**, the point where the sample means of all $p$ variables lies is the **centroid of the sample**. For a sample with two variables and three observations:

$$ \bm{X}_{3 \times 2} = \begin{bmatrix}
    x_{11} & x_{12} \\
    x_{21} & x_{22} \\
    x_{31} & x_{32}
\end{bmatrix} $$

## 1.2 - Random Samples and the Expected Values of $\bm{\mu}$ and $\bm{\Sigma}$

Suppose we intend to collect $n$ sets of measurements (or observations) on $p$ variables. At this point we can consider each of the $n \times p$ values to be observed to be random variables $X_{jk}$. This leads to interpretation of each set of measurements $\bm{X}_j$ on the $p$ variables to be a random vector, i.e.,

$$ \bm{X}_{n \times p} = \begin{bmatrix}
    x_{11} & x_{12} & \dots & x_{1p} \\
    x_{21} & x_{22} & \dots & x_{2p} \\
    \vdots & \vdots & \ddots & \vdots \\
    x_{n1} & x_{n2} & \dots & x_{np}
\end{bmatrix} = \begin{bmatrix}
    \bm{x_1'} \\
    \bm{x_2'} \\
    \vdots \\
    \bm{x_n'}
\end{bmatrix} $$

Note that the row vectors $\bm{x'}_1, \bm{x'}_2, \dots, \bm{x'}_n$ represent independent observations concepts will be used to define a **random sample**.

## 1.3 - Generalizing Variance over $p$ Dimensions

For a given variance-covariance matrix,

$$ S_{n \times p} = \begin{bmatrix}
    s_{11} & s_{12} & \dots & s_{1p} \\
    s_{21} & s_{22} & \dots & s_{2p} \\
    \vdots & \vdots & \ddots & \vdots \\
    s_{n1} & s_{n2} & \dots & s_{np}
\end{bmatrix} = \left\{
    s_{ik} = \frac{1}{n-1} \sum^n_{j = 1} (x_{ji} - \bar{x_i}) (x_{jk} - \bar{x}_k)'
\right\} $$

The **generalized sample variance** is $|\bm{S}|$.

### Example

Consider the previous matrix of three observations in 3D space:

$$ \bm{X} = \begin{bmatrix} 
    2 & 4 & 6 \\
    1 & 7 & 1 \\
    -6 & 1 & 8
\end{bmatrix} $$

Since the sample covariance matrix is

$$ \bm{S} = \begin{bmatrix}
    \frac{38}{2} & \frac{21}{2} & -\frac{20}{2} \\
    \frac{21}{2} & \frac{18}{2} & -\frac{21}{2} \\
    -\frac{20}{2} & -\frac{21}{2} & \frac{26}{2}
\end{bmatrix} $$

The generalized sample variance is

$$
\begin{align*}
|\bm{S}| &= \left|\begin{bmatrix}
    \frac{38}{2} & \frac{21}{2} & -\frac{20}{2} \\
    \frac{21}{2} & \frac{18}{2} & -\frac{21}{2} \\
    -\frac{20}{2} & -\frac{21}{2} & \frac{26}{2}
\end{bmatrix}\right| \\
&= \frac{38}{2} \begin{vmatrix} 
    \frac{18}{2} & -\frac{21}{2} \\
    -\frac{21}{2} & \frac{26}{2}
\end{vmatrix}
- \frac{21}{2} \begin{vmatrix}
    \frac{21}{2}
\end{vmatrix}
\end{align*}
$$

## 1.4 - Matrix Operations for Calculating Sample Means, Covariances, and Correlations

For a given matrix $\bm{X}$, we have that

$$ \bm{\bar x} = \begin{bmatrix}
    \bm{x'}_1 \bm{1} / n \\
    \bm{x'}_2 \bm{1} / n \\
    \vdots \\
    \bm{x'}_p \bm{1} / n
\end{bmatrix} = \frac{1}{n} \begin{bmatrix}
    x_{11} & x_{12} & \dots & x_{1p} \\
    x_{21} & x_{22} & \dots & x_{2p} \\
    \vdots & \vdots & \ddots & \vdots \\
    x_{n1} & x_{n2} & \dots & x_{np}
\end{bmatrix} \begin{bmatrix} 
    1 \\ 1 \\ \dots \\ 1
\end{bmatrix} = \frac{1}{n} \bm{x' 1} $$

## 1.5 - Sample Values of Linear Combinations of Variables


