# Continuous Uniform Distribution

The continuous uniform distribution represents a probability distribution where any interval of a specified length within the range of possible values has an equal probability of occurring, and outside this range, the probability is zero.

A continuous uniform random variable is denoted as followed:

$$ X \sim \text{Uniform}(a,b) $$

where
- $a$ represents the lower bound
- $b$ represents the upper bound

## Probability Distribution Function (PDF)

The pdf for a continuous random distribution is given as followed:

$$
f_X(x) =
\begin{cases}
\frac{1}{b-a}, & \text{if } a < x < b \\
0, & \text{otherwise}
\end{cases}
$$

## Expectation

The expected value of a continuous uniform can be derived as such:

$$
\begin{align}
EX &= \int_a^b x f_X(x) dx \\
&= \int_a^b \frac{x}{b-a} dx \\
&= \frac{1}{b-a} \int_a^b {x} dx \\
&= \frac{1}{b-a} \left[ \frac{x^2}{2} \right]_a^b \\
&= \frac{1}{b-a} \left[ \frac{b^2 - a^2}{2} \right] \\
&= \frac{b^2 - a^2}{2(b-a)} \\
&= \frac{(b-a)(b+a)}{2(b-a)} \\
&= \frac{b+a}{2} \\
\end{align}
$$

## Variance

To find the variance, we'll use the following equation:

$$ Var(X) = EX^2 - (EX)^2 $$

First, we'll find $EX^2$:

$$
\begin{align}
EX^2 &= \int_a^b x^2 f_X(x) dx \\
&= \int_a^b \frac{x^2}{b-a} dx \\
&= \frac{1}{b-a} \int_a^b x^2 dx \\
&= \frac{1}{b-a} \left[ \frac{x^3}{3} \right]_a^b \\
&= \frac{b^3 - a^3}{3(b-a)} \\
&= \frac{(b-a)(b^2 + ab + a^2)}{3(b-a)} \\
&= \frac{b^2 + ab + a^2}{3} \\
\end{align}
$$

Now, we can find $Var(X)$:

$$
\begin{align}
Var(X) &= EX^2 - (EX)^2 \\
&= \frac{b^2 + ab + a^2}{3} - \left( \frac{b+a}{2} \right)^2 \\
&= \frac{b^2 + ab + a^2}{3} - \left( \frac{b^2 + 2ab + a^2}{4}  \right) \\
&= \frac{4b^2 - 3b^2 + 4ab -6ab + 4a^2 - 3a^2}{12} \\
&= \frac{b^2 - 2ab + a^2}{12} \\
&= \frac{(b-a)^2}{12} \\
\end{align}
$$