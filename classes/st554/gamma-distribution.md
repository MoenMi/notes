# Gamma Distribution

The gamma distribution is a continuous probability distribution that generalizes the exponential distribution, modeling the time until a specified number of independent events occur, and is parameterized by a shape parameter $\alpha$ and a scale parameter $\beta$.

A gamma random variable is denoted as follows:

$$ X \sim \text{Gamma}(\alpha, \beta) $$

## The Gamma Function

The gamma distribution is based on the gamma function:

$$ \Gamma(\alpha) = \int_0^\infty t^{\alpha - 1} e^{-t} dt, \ \ \alpha > 0 $$

The gamma function can be evaluated as followed:

$$ 
\begin{align}
\Gamma(1) &= \int_0^\infty t^{1-1} e^{-t} dt \\
&= \int_0^\infty e^{-t} dt \\
&= \left[ -e^{-t} \right]_0^\infty \\
&= 0 - (-1) \\
&= 1 \\
\end{align}
$$

The gamma function has a special property:

$$
\begin{align}
\Gamma(\alpha + 1) &= \int_0^\infty t^{\alpha + 1-1} e^{-t} dt \\
&= \int_0^\infty t^\alpha e^{-t} dt \\
&= -t^\alpha e^{-t} \Big|_0^\infty + \alpha \int_0^\infty t^{\alpha-1} e^{-t} dt \\
&= \alpha \int_0^\infty t^\alpha e^{-t} dt \\
&= \alpha \Gamma({\alpha}) \\
\end{align}
$$

Note: 
- In line (3), we perform integration by parts where $u=t^\alpha$ and $dv=e^{-t} dt$

A special case in the gamma function is:

$$ \Gamma\left(\frac{1}{2}\right) = \sqrt{\pi} $$

## Probability Distribution Function (PDF)

The pdf for the gamma distribution is given as followed:

$$
f_X(x) =
\begin{cases}
\frac{1}{\Gamma(\alpha) \beta^\alpha} x^{\alpha-1} e^{-\frac{x}{\beta}} , & \text{if } x>0 \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

The expected value of the gamma distribution can be derived using by performing the following:

$$
\begin{align}
EX &= \int_0^\infty x f_X(x) dx \\
&= \int_0^\infty x \frac{1}{\Gamma(\alpha) \beta^\alpha} x^{\alpha-1} e^{-\frac{x}{\beta}} dx \\
&= \frac{1}{\Gamma(\alpha) \beta^\alpha} \int_0^\infty x^\alpha e^{-\frac{x}{\beta}} dx \\
&= \frac{1}{\Gamma(\alpha) \beta^\alpha} \int_0^\infty \beta (u \beta)^\alpha e^{-u} du \\
&= \frac{\beta}{\Gamma(\alpha)} \int_0^\infty x^\alpha e^{-u} du \\
&= \frac{\beta}{\Gamma(\alpha)} \int_0^\infty x^{(\alpha + 1) - 1} e^{-u} du \\
&= \frac{\beta \Gamma(\alpha + 1)}{\Gamma(\alpha)} \\
&= \frac{\alpha \beta \Gamma(\alpha)}{\Gamma(\alpha)} \\
&= \alpha \beta \\
\end{align}
$$

Note:
- In line (4), we substitute in $u = \frac{x}{\beta}$ or $x=\beta u$
- In line (7), we recognize that the integral is the definition of the gamma function with the argument $\alpha + 1$

## Variance

A similar argument reveals that the variance of the gamma distribution is as followed:

$$ Var(X) = \alpha \beta^2 $$