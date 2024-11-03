# TB7 - Variable Selection

Variable selection is the process of choosing the "best" model from a class of multiple regression models.

This chapter assumes the following multiple regression model containing all $m$ potential predictor variables:

$$ Y = \beta_0 + \beta_1 x_1 + \dots + \beta_m x_m + \epsilon $$

In general, the more predictor variables included in a valid model, the lower the bias of the predictions, but the higher the variance. Including too many variables in a regression model is commonly called over-fitting, while opposite is called under-fitting.

The two key aspects of variable selection methods are:
1. Evaluating each potential subset of $p$ predictor variables
2. Deciding on the collection of potential subsets

## 7.1 - Evaluating Potential Subsets of Predictor Variables

### Criterion 1: $R^2$-Adjusted

Recall that $R^2$, the coefficient of determination of the regression model, is defined as the proportion of the total sample variability in the $Y$'s explained by the regression model:

$$ R^2 = \frac{\text{SSreg}}{\text{SST}} = 1 - \frac{\text{RSS}}{\text{SST}} $$

Adding irrelevant predictor variables to the regression equation often increases $R^2$. To compensate for this, we can define an adjusted coefficient of determination $R^2_{\text{adj}}$:

$$ R^2_{\text{adj}} = 1 - \frac{\text{RSS} / (n - p - 1)}{\text{SST} / (n - 1)} $$

where $p$ is the number of predictors in the current model.

The usual practice is to *choose the subset of the predictors that has the highest value of $R^2_{\text{adj}}$*. Note, however, that choosing the highest value of $R^2_{\text{adj}}$ tends toward over-fitting. If two models have a similar $R^2_{\text{adj}}$ but one has fewer predictors, the model with fewer predictors is preferable.

### Criterion 2: AIC, Akaike's Information Criterion

**Akaike's information criterion (AIC)** can be motivated in two ways. The most popular motivation appears to be based on balancing goodness of fit and a penalty for model complexity. AIC is defined such that *the smaller the value of AIC, the better the model*.

AIC is derived from likelihood theory, and is calculated as follows:

$$ \text{AIC} = n \log \left( \frac{\text{RSS}}{n} \right) + 2p $$

where $p$ is the number of predictors.

### Criterion 3: $\text{AIC}_C$, Corrected AIC

**Corrected AIC ($\text{AIC}_C$)** is a bias corrected version of AIC designed for use when the sample size is small, or when the number of parameters estimated is a moderate to large fraction of the sample size. It is recommended that $\text{AIC}_C$ be used instead of AIC unless $\frac{n}{K} > 40$, where $K = p + 2$. Furthermore, $\text{AIC}_C$ converges to AIC as $n$ gets large, so it is generally recommended to use $\text{AIC}_C$, which is given by:

$$ \text{AIC}_C = \text{AIC} + \frac{2K(K + 1)}{n - K - 1} = \text{AIC} + \frac{2(p+2)(p+3)}{n-p-1} $$

Note that the corrected AIC has a larger penalty for model complexity than regular AIC.

### Criterion 4: BIC, Bayesian Information Criterion

The **Bayesian information criterion (BIC)** is given as

$$ \text{BIC} = n \log \left( \frac{\text{RSS}}{n} \right) + K \log(n) $$

where $K = p + 2$, the number of parameters estimated in the model. BIC is defined such that *the smaller the value of BIC the better the model.* BIC penalizes complex models more heavily than AIC.

### Comparison of AIC, $\text{AIC}_C$, and BIC

A popular strategy for data analysis is to compate the models which minimize AIC, $\text{AIC}_C$, and BIC with the model that maximizes $R^2_{\text{adj}}$.

## 7.2 - Deciding on the Collection of Potential Subsets of Predictor Variables

There are two distinctly different approaches to choosing the potential subsets of predictor variables, namely,

1. All possible subsets
2. Stepwise methods

### All Possible Subsets

This approach is based on considering all $2^m$ possible regression equations and identifying the subset of the predictors of a given size that maximizes a measure of fit or minimizes an information criterion based on a monotone function of the residual sum of squares.

Note that with a fixed number of terms in the regression model, all for criteria for evaluating a subset of predictor variables agree that the best choice is the set of predictors that minimizes the RSS. Note however, when the comparison is across models with different numbers of predictors, the four methods produce different results.

### Stepwise Subsets


