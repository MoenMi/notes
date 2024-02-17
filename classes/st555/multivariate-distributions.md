# Multivariate Distributions

Given a random vector $X = \begin{pmatrix} X_1 \\ \vdots \\ X_k \end{pmatrix}$, the expected value is

$$ EX = \begin{pmatrix} EX_1 \\ \vdots \\ EX_k \end{pmatrix} $$

The covariance of a multivariate distribution is given as the following matrix:

$$ 
\begin{align*}
    Cov(X) &= E[(X - EX)(X - EX)^T] \\
    &= \begin{bmatrix}
        Cov(X_1, X_1) & Cov(X_2, X_1) & \dots & Cov(X_k, X_1) \\
        Cov(X_1, X_2) & Cov(X_2, X_2) & \dots & Cov(X_k, X_2) \\
        \vdots & \vdots & \ddots & \vdots \\
        Cov(X_1, X_k) & Cov(X_2, X_k) & \dots & Cov(X_k, X_k)
       \end{bmatrix}
\end{align*}    
$$

Note that $Cov(X_1, X_1) = Var(X_1)$ and $Cov(X,Y) = E(X-EX)(Y-EY) = E(XY) - E(X)E(Y)$.

Note that if $D$ is a matrix of constants and $\underset{l \times 1}{Y} = \underset{l \times k}{D} * \underset{k \times 1}{X}$, then

$$ EY = D * EX $$

$$
\begin{align*}
    Cov(Y) &= E\left((Y-EY)(Y-EY)^T\right) \\
    &= E\left(D(X-EX)(X-EX)^T D^T\right) \\
    &= D * E\left((X-EX)(X-EX)^T\right) * D^T \\
    &= D * Cov(X) * D^T \\
\end{align*}
$$

The moment generating function of a $k \times 1$ random vector $X$ is a function of $k$ real variables $t_1, \dots, t_k$:

$$ M_X(t) = Ee^{tX}, $$

where $t^T = (t_1, \dots, t_k)$. Note that $Ee^{t^TX} = Ee^{\sum^k_{i=1} t_iX_i}$. 