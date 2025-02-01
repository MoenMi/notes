# 1 - Sample Geometry and Random Sampling

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
