# Joint Distributions

A **joint distribution** for $X$ and $Y$ must determine all necessary information about distributions of $X$ and $Y$.

## Cumulative Distribution Functions (CDFs)

If $(X,Y)$ is a random vector and $F$ is its cdf, then

1. $F$ is a non-decreasing function, meaning $x \leq x'$ and $y \leq y' \Rightarrow F(x,y) \leq F(x',y')$
2. $F$ is 'right-continuous'
3. If $(x_n, y_n)$ is such that $ \text{min}(x_n, y_n) \rightarrow - \infty $, then $ F(x_n, y_n) \rightarrow 0 $
4. If $(x_n, y_n)$ is such that $ \text{min} (x_n, y_n) \rightarrow + \infty $, then $ F(x_n, y_n) \rightarrow 1 $
5. If $x \leq x'$ and $y \leq y'$, then $F(x',y') - F(x',y) - F(x, y') + F(x, y) \geq 0$

## Marginal Distributions

For discrete and continous cases, we can get marginal information (one-dimensional distribution for $X$ or $Y$) from the joint pmf/pdf.

### Discrete Cases

$$ p_X(x) = \sum_y p_{X,Y}(x,y) $$

$$ p_Y(y) = \sum_x p_{X,Y}(x,y) $$

### Continuous Cases

$$ f_X(x) = \int_{-\infty}^\infty f_{X,Y}(x,y) \ dy $$

$$ f_Y(y) = \int_{-\infty}^\infty f_{X,Y}(x,y) \ dx $$

## Expectations with Multiple Random Variables

If $V=h(X,Y)$, where $ h(X,Y): \mathbb{R}^2 \rightarrow \mathbb{R}^1 $, we don't have to go through the pain of finding the distribution of $V$ just to find $E(V)$.

If $X$ and $Y$ are **jointly discrete** with pmf $p_{X,Y}(x,y)$, provided $ \sum_{(x,y)} h(x,y) p_{X,Y}(x,y) \lt \infty $, we define:

$$ Eh(X,Y) = \sum_{(x,y)} h(x,y) p_{X,Y}(x,y) $$

Likewise, if $X$ and $Y$ are **jointly continuous** with pdf $ f_{X,Y}(x,y) $, provided $ \iint_{\mathbb{R}^2} h(x,y) f_{X,Y}(x,y) dydx \lt \infty $, where:

$$ Eh(X,Y) = \iint_{\mathbb{R}^2} h(x,y) f_{X,Y}(x,y) dydx $$

Expectations of functions with more than one random variable have the same linearity properties as functions of a single random variable:

- $ E(ah(X,Y) + b) = a Eh(X,Y) + b $
- $ E(h(X,Y) + g(X,Y)) = Eh(X,Y) + Eg(X,Y) $