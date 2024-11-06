# TB6 - Diagnostics and Transformations for MLR

## 6.4 - Multicollinearity

Important issues arise when strong correlations exist among the predictor variables (often referred to as **multicollinearity**). In particular, many regression coefficients can have the wrong sign and/or many of the predictor variables are not statistically significant when the overall F-test is highly significant.

Consider a multiple regression model with two predictors

$$ Y = \beta_0 + \beta_1 x_1 + \beta_2 x_2 + \epsilon $$

Let $r_{12}$ denote the correlation between $x_1$ and $x_2$ and $S_{x_j}$ denote the standard deviation of $x_j$. Then it can be shown that

$$ \text{Var}(\hat\beta_j) = \frac{1}{1 - r^2_{12}} \times \frac{\sigma^2}{(n-1) S^2_{x_j}}, j = 1, 2 $$

Note how the variance of $\hat\beta_j$ gets larger as the absolute value of $r_{12}$ increases. Thus, the correlation amongst the predictors increases the variance of the estimated regression coefficients.

The term $\frac{1}{1 - r^2_{12}}$ is the **variance inflation factor (VIF)**. VIF values above 10 are a typical cutoff for multicollinearity. Any values above this indicate that the associated regression coefficients are poorly estimated.

```r
vif(model)
```
