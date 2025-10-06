# 3 - Probability: Multivariate Models

## 3.1 - Joint distributions for multiple random variables

### 3.1.1 - Covariance

The **covariance** between two random variables $X$ and $Y$ measures the degree to which $X$ and $Y$ are linearly related:

$$ \text{Cov}[X, Y] \triangleq E[(X - E[X])(Y - E[Y])] = E[XY] - E[X]E[Y] $$

### 3.1.2 - Correlation

The **Pearson correlation coefficient** between $X$ and $Y$ is defined as

$$ \rho \triangleq \text{corr}[X, Y] = \frac{\text{Cov}[X, Y]}{\sqrt{\text{Var}[X]\text{Var}[Y]}} $$

### 3.1.3 - Uncorrelated does not imply independent

Independence implies uncorrelated, but uncorrelated does not imply independent.

### 3.1.5 - Simpson’s paradox

Simpson's paradox says that a statistical trend can disappear or reverse signs when these groups are combined.

## 3.2 - The multivariate Gaussian (normal) distribution

### 3.2.1 - Definition



### 3.2.2 - Mahalanobis distance



### 3.2.3 - Marginals and conditionals of an MVN *



### 3.2.4 - Example: conditioning a 2d Gaussian



### 3.2.5 - Example: Imputing missing values *



## 3.3 - Linear Gaussian systems *

### 3.3.1 - Bayes rule for Gaussians



### 3.3.2 - Derivation *



### 3.3.3 - Example: Inferring an unknown scalar



### 3.3.4 - Example: inferring an unknown vector



### 3.3.5 - Example: sensor fusion



## 3.4 - The exponential family *

### 3.4.1 - Definition



### 3.4.2 - Example



### 3.4.3 - Log partition function is cumulant generating function



### 3.4.4 - Maximum entropy derivation of the exponential family



## 3.5 - Mixture models

### 3.5.1 - Gaussian mixture models



### 3.5.2 - Bernoulli mixture models



## 3.6 - Probabilistic graphical models *

### 3.6.1 - Representation



### 3.6.2 - Inference 



### 3.6.3 - Learning 



## 3.7 - Exercises
