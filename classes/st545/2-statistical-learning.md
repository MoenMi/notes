# 2 - Statistical Learning

Consider the following model to predict Sales:

$$ \text{Sales} \approx f(\text{TV}, \text{Radio}, \text{Newspaper}) $$

- $\text{Sales}$ is the **response** or **target** that we wish to predict. We generally refer to the response as $Y$.
- $\text{TV}$ is a **feature**, **input**, or **predictor**; we name it $X_1$.
- Similarly, we name $\text{Radio}$ as $X_2$ and so on.

We can refer to the input vector as:

$$ X = \begin{pmatrix} X_1 \\ X_2 \\ X_3 \end{pmatrix} $$

Now we write our model as

$$ Y = f(X) + \epsilon $$

where $\epsilon$ captures measurement errors and other discrepancies.
