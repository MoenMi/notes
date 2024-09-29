# 3 - MLR

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

## 3.3 - Model Inference



## 3.4 - ANOVA Table



## 3.5 - Regression Diagnostics



## 3.6 - Multicollinearity


