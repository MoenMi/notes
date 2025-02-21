# 4 - Qualitative Behavior of Chains

If we want to find $\lim_{n \rightarrow \infty} q P^m$, there are some special cases where this is easy to identify.

## 4.1 - Two Special Matrices that Can Be Computed by Hand

### Case 1

Assume we have the following one-step transition probability matrix:

$$ \begin{bmatrix} 
    0 & 1 & 0 \\
    1 - p & 0 & p \\
    0 & 1 & 0
\end{bmatrix} $$

We observe through matrix multiplication that $P = P^3$ and

$$ P^2 = P^4 = \begin{bmatrix}
    1 - p & 0 & p \\
    0 & 1 & 0 \\
    1 - p & 0 & p
\end{bmatrix} $$

Thus, we have $P^n = P$ when $P$ is odd, and $P^n = P^2$ when $P$ is even.

### Case 2

Assume the one-step transition probability matrix is

$$ P = \begin{bmatrix}
    0.6 & 0 & 0.4 \\
    0 & 1 & 0 \\
    0.6 & 0 & 0.4
\end{bmatrix} $$

We can see that $P = P^2 = \dots = P^n$ where $n$ is an integer.

## 4.2 - Long Term and Short Term Behavior of the Chain

It is difficult to determine the long-term behavior of a chain based on the matrix computation of $q_0 \times P^n$.
