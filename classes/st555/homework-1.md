# Homework 1

## Section 3.5 (14-17, 22)

### Problem 14

$$ P(X_1 > X_2 + X_3 + 2) = P(X_1 - X_2 - X_3) $$

$$ Y = X_1 - X_2 - X_3 $$

$$
Y = aX =
\begin{bmatrix}
1 & -1 & -1
\end{bmatrix}
\begin{bmatrix}
X_1 \\ X_2 \\ X_3
\end{bmatrix}
$$

Therefore, we see that $Y \sim \text{Normal}(a \mu, a \Sigma a^T)$.

$$
a \mu =
\begin{bmatrix}
1 & -1 & -1
\end{bmatrix}
\begin{bmatrix}
0 \\ 0 \\ 0
\end{bmatrix}
= 0
$$

$$
\begin{align*}
    a \Sigma a^T &=
    \begin{bmatrix}
        1 & -1 & -1
    \end{bmatrix}
    \begin{bmatrix}
        1 & 0 & 0 \\
        0 & 2 & 1 \\
        0 & 1 & 2
    \end{bmatrix}
    \begin{bmatrix}
        1 \\ -1 \\ -1
    \end{bmatrix} \\

    &=
    \begin{bmatrix}
        1 & -3 & -3
    \end{bmatrix}
    \begin{bmatrix}
        1 \\ -1 \\ -1
    \end{bmatrix} \\

    &= 1 + 3 + 3 \\
    &= 7
\end{align*}
$$

Therefore, $Y \sim \text{Normal}(0, 7)$, and so

$$
\begin{align*}
    P(Y > 2) &= 1 - P(Y \leq 2) \\
    &= 1 - P(Z \leq \frac{2-0}{\sqrt{7}}), & Z \sim \text{Normal}(0,1) \\
    &\approx 1 - 0.775 \\
    &\approx 0.225 
\end{align*}
$$

### Problem 16

$$ Y = aX =
\begin{bmatrix}
    1 & 1 \\
    1 & -1
\end{bmatrix}
\begin{bmatrix}
    X_1 \\ X_2
\end{bmatrix}
=
\begin{bmatrix}
    X_1 + X_2 \\
    X_1 - X_2
\end{bmatrix}
$$

Therefore, $Y \sim \text{Normal}(a\mu, a\Sigma a^T)$.

To show that $X_1 + X_2$ and $X_1 - X_2$ are independent when $Var(X_1) = Var(X_2)$, we will show that their covariance is $0$.

$$
\begin{align*}
    Var(Y) = a \Sigma a^T &=
    \begin{bmatrix}
        1 & 1 \\
        1 & -1
    \end{bmatrix}
    \begin{bmatrix}
        \sigma_1^2 & \sigma_{1,2} \\
        \sigma_{1,2} & \sigma_2^2
    \end{bmatrix}
    \begin{bmatrix}
        1 & 1 \\
        1 & -1
    \end{bmatrix} \\
    &=
    \begin{bmatrix}
        \sigma_1^2 + \sigma_{1,2} & \sigma_{1,2} + \sigma_2^2 \\
        \sigma_1^2 - \sigma_{1,2} & \sigma_{1,2} - \sigma_2^2
    \end{bmatrix}
    \begin{bmatrix}
        1 & 1 \\
        1 & -1
    \end{bmatrix} \\
    &=
    \begin{bmatrix}
        \sigma_1^2 + 2\sigma_{1,2} + \sigma_2^2 & \sigma_1^2 - \sigma_2^2 \\
        \sigma_1^2 - \sigma_2^2 & \sigma_1^2 - 2\sigma_{1,2} + \sigma_2^2
    \end{bmatrix}
\end{align*}
$$

It follows from here that if $Var(X_1) = Var(X_2)$, then $Cov(X_1 + X_2, X_1 - X_2) = 0$ and, therefore, $X_1 + X_2$ and $X_1 - X_2$ are independent.
