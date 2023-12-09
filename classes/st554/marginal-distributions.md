# Marginal Distributions

A **joint distribution** for $X$ and $Y$ must determine all necessary information about distributions of $X$ and $Y$.

For discrete and continous cases, we can get marginal information (one-dimensional distribution for $X$ or $Y$) from the joint pmf/pdf.

For discrete cases:

$$ p_X(x) = \sum_y p_{X,Y}(x,y) $$

$$ p_Y(y) = \sum_x p_{X,Y}(x,y) $$

For continuous cases:

$$ f_X(x) = \int_{-\infty}^\infty f_{X,Y}(x,y) \ dy $$

$$ f_Y(y) = \int_{-\infty}^\infty f_{X,Y}(x,y) \ dx $$