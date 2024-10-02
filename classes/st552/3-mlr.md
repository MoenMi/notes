# 3 - MLR

Interpretation of slopes in MLR:
- Type I SS (sequential SS)
  ```
  Price ~ Food + Decor + Service + Speed
    SS(Food)
    SS(Decor | Food)
    SS(Service | Food + Decor)
    SS(Speed | Food + Decor + Service)
  ```
  - ANOVA analyzes Type I SS
- Type II SS (conditional/marginal effect)
  ```
  Price ~ Food + Decor + Service + Speed
    SS(Food | Decor + Service + Speed)
    SS(Decor | Food + Service + Speed)
    SS(Service | Food + Decor + Speed)
    SS(Speed | Food + Decor + Service)
  ```
  - Can be retrieved via R's `summary()`

Interpretation of $\beta_j$ (the slope of $x_j$):
- Change in the response $y$ with 1 unit increase in the predictor $x_j$, while the rest of the predictors remain unchanged

Multiple and adjusted $R^2$:

$$ R^2_{adj} = 1 - \frac{\text{SSE} / (n - p - 1)}{\text{SST} / (n - 1)} $$

- Adjusts for both sample size $n$ and model size $p$

## 3.1 - MLR Model

A standard multiple linear regression model:

$$ y_i = \beta_0 + \beta_1 x_{1i} + \beta_2 x_{2i} + \dots + \beta_p x_{pi} + \epsilon_i $$

- $(y_i, x_{1i}, x_{2i}, \dots, x_{pi})$ is the $i$th observation from a random sample $\{ (y_i, x_{1i}, x_{2i}, \dots, x_{pi}), i = 1, \dots, n \}$.
- $\beta_0$ is the intercept, and $\beta_1, \beta_2, \dots, \beta_p$ are the slopes.
- $\epsilon_i$ is the random error.

Random error $\epsilon_i$:
- Unexplained variation of the response $y$.
- $\epsilon_i$ is independent of $x_i$.
- $E(\epsilon_i | x_{1i}, x_{2i}, \dots, x_{pi}) = 0$.
- $Var(\epsilon_i | x_{1i}, x_{2i}, \dots, x_{pi}) = \sigma^2$.
- $\epsilon_i$ and $\epsilon_j$ are uncorrelated for $i \ne j$, for all $i, j = 1, \dots, n$.

$$ E(y_i | x_{1i}, x_{2i}, \dots, x_{pi}) = \beta_0 + \beta_1 x_{1i} + \beta_2 x_{2i} + \dots + \beta_p x_{pi} $$

$$ y_i = E(y_i | x_i) + \epsilon_i = \beta_0 + \beta_1 x_{1i} + \beta_2 x_{2i} + \dots + \beta_p x_{pi} + \epsilon_i $$

## 3.2 - Parameter Estimation

- Parameters: $\beta_0$ and $\beta_1, \beta_2, \dots, \beta_p$
- Sample estimates: $b_0$ and $b_1, b_2, \dots, b_p$
- Estimated model: $\hat y_i = b_0 + b_1 x_{1i} + b_2 x_{2i} + \dots + b_p x_{pi}$
- Residuals: $\hat\epsilon_i = y_i - \hat y_i$

### Least Squares

The least squares estimates of $\beta_0, \beta_1, \beta_2, \dots, \beta_p$ are the values of $b_0, b_1, b_2, \dots, b_p$ for which the sum of the squared residuals,

$$ RSS = \sum^n_{i=1} \hat\epsilon_i^2 = \sum^n_{i=1} (y_i - \hat y_i)^2 = \sum^n_{i=1} (y_i - b_0 - b_1 x_{1i} - b_2 x_{2i} - \dots - b_p x_{pi})^2 $$

is a minimum. For RSS to be a minimum with respect to $b_0, b_1, b_2, \dots, b_p$, we require

$$ \frac{\delta RSS}{\delta b_0} = -2 \sum^n_{i=1} (y_i - b_0 - b_1 x_{1i} - b_2 x_{2i} - \dots - b_p x_{pi}) = 0 $$

$$ \frac{\delta RSS}{\delta b_1} = -2 \sum^n_{i=1} x_{1i} (y_i - b_0 - b_1 x_{1i} - b_2 x_{2i} - \dots - b_p x_{pi}) = 0 $$

$$ \frac{\delta RSS}{\delta b_p} = -2 \sum^n_{i=1} x_{pi} (y_i - b_0 - b_1 x_{1i} - b_2 x_{2i} - \dots - b_p x_{pi}) = 0 $$

### Matrix Formulation of Least Squares

A convenient way to study the properties of the least squares estimates $\hat\beta_0, \hat\beta_1, \hat\beta_2, \dots, \hat\beta_p$ is to use matrix and vector notation. Define the $n \times 1$ vector $\textbf{Y}$, the $n \times (p + 1)$ matrix $\textbf{X}$, the $(p + 1) \times 1$ vector $\beta$ of unknown regression parameters and the $n \times 1$ vector $\textbf{e}$ of random errors by

$$
\textbf{Y} = \begin{pmatrix}
    y_1 \\ y_2 \\ \vdots \\ y_n
\end{pmatrix},

\textbf{X} = \begin{pmatrix}
    1 & x_{11} & \dots & x_{1p} \\
    1 & x_{21} & \dots & x_{2p} \\
    \vdots & \vdots & \ddots & \vdots \\
    1 & x_{n1} & \dots & x_{np}
\end{pmatrix},

\beta = \begin{pmatrix}
    \beta_0 \\ \beta_1 \\ \vdots \\ \beta_p
\end{pmatrix}

\textbf{e} = \begin{pmatrix}
    \epsilon_1 \\ \epsilon_2 \\ \vdots \\ \epsilon_n
\end{pmatrix}
$$

We can write the multiple linear regression model in matrix notation as

$$ \textbf{Y} = \textbf{X} \beta + \textbf{e} $$

The residual sum of squares as a function of $\beta$ can be written in matrix form as

$$ RSS(\beta) = (\textbf{Y} - \textbf{X}\beta)'(\textbf{Y} - \textbf{X}\beta) $$

Noting that $(\textbf{A} \textbf{B})' = \textbf{B}' \textbf{A}'$ and that $\textbf{B}' \textbf{A} = \textbf{A}' \textbf{B}$ when the result is $1 \times 1$, expanding this last equation gives

$$
\begin{align*}
    RSS(\beta) &= \textbf{Y}' \textbf{Y} + (\textbf{X} \beta)' \textbf{X} \beta - \textbf{Y}' \textbf{X} \beta - (\textbf{X} \beta)' \textbf{Y} \\
    &= \textbf{Y}' \textbf{Y} + \beta' (\textbf{X}' \textbf{X}) \beta - 2 \textbf{Y}' \textbf{X} \beta
\end{align*}
$$

To find the least squares estimates, we differentiate this equation with respect to $\beta$, equate the result to zero, then cancel out the 2 common to both sides. This gives the following matrix form of the normal equations:

$$ (\textbf{X}' \textbf{X}) \beta = \textbf{X}' \textbf{Y} $$

Assuming that the inverse of the matrix $(\textbf{X}' \textbf{X})$ exists, the least squares estimates are given by

$$ \hat\beta = (\textbf{X}' \textbf{X})^{-1} \textbf{X}' \textbf{Y} $$

The fitted or predicted values are given by

$$ \hat{\textbf{Y}} = \textbf{X} \hat\beta $$

and the residuals are given by

$$ \hat{\textbf{e}} = \textbf{Y} - \hat{\textbf{Y}} = \textbf{Y} - \textbf{X} \hat\beta $$

### Estimating the Error Variance

It can be shown that

$$ S^2 = \frac{RSS}{n-p-1} = \frac{1}{n - p - 1} \sum^n_{i=1} \hat\epsilon^2_i $$

is an unbiased estimator of $\sigma^2$.

## 3.3 - Model Inference



## 3.4 - ANOVA Table



## 3.5 - Regression Diagnostics



## 3.6 - Multicollinearity


