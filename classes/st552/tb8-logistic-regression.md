# TB8 - Logistic Regression

Logistic regression is used in cases where the response variable is binary.

## 8.1 - Logistic Regression Based on a Single Predictor

In this section, we consider the case of predicting a binomial random variable $Y$ based on a single preditor variable $x$ via logistic regression.

### The Logistic Function and Odds

The logistic function is an S-shaped curve that is defined as follows

$$ \theta(x) = \frac{\exp(\beta_0 + \beta_1 x)}{1 + \exp(\beta_0 + \beta_1 x)} = \frac{1}{1 + \exp(- \{ \beta_0 + \beta_1 x \})} $$

Solving this function for $\beta_0 + \beta_1 x$ gives

$$ \beta_0 + \beta_1 x = \log \left( \frac{\theta(x)}{1 - \theta(x)} \right) $$

If the chosen function is correct, a plot of $\log \left( \frac{\theta(x)}{1 - \theta(x)} \right)$ against $x$ will produce a straight line. The quantity $\log \left( \frac{\theta(x)}{1 - \theta(x)} \right)$ is called a **logit**.

The quantity $\frac{\theta(x)}{1 - \theta(x)}$ is known as **odds**. Note that the odds represent a ratio (e.g. odds of a horse winning a race are 20:1, so the horse has a 1/21 chance to win).

### Likelihood for Logistic Regression with a Single Predictor



## 8.2 - Binary Logistic Regression


