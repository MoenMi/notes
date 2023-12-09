# Normal Distribution

The normal distribution, also known as the Gaussian distribution, is a continuous probability distribution characterized by a bell-shaped curve, where data clusters symmetrically around its mean, with a majority falling within one standard deviation, making it a fundamental concept in statistics and probability theory.

A normal random variable is denoted:

$$ X \sim \text{Normal}(\mu, \sigma) $$

A standard normal distribution has a mean ($\mu$) of $0$ and standard deviation ($\sigma$) of $1$.

$$ Z \sim \text{Normal}(0,1) $$

## Probability Distribution Function (PDF)

The pdf of the standard normal distribution is given as followed:

$$ f_Z(z) = \frac{1}{\sqrt{2\pi}} e^{-\frac{x^2}{2}} \text{ if } z \in \real $$

The pdf of the normal distribution is:

$$ f_X(x) = \frac{1}{\sigma\sqrt{2\pi}} e^{-\frac{1}{2} \left(\frac{x-\mu}{\sigma} \right)^2} \text{ if } x \in \real $$

## Expectation

The expected value of the standard normal distribution is clearly $0$, bet we can derive it here:

$$
\begin{align}
EZ &= \int_\infty^\infty z f_Z(z) dz \\
&= \frac{1}{\sqrt{2\pi}} \int_\infty^\infty z e^{-\frac{z^2}{2}} dz \\
\end{align}
$$

Note that $ z e^{-\frac{z^2}{2}} $ is an odd function, so it is symmetrical and the mean is $0$.