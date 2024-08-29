# 1 - Growth of Functions

## Big-O Notation

**Big-O Notation** describes the tight upper bound:

$$
O(g(n)) = 
\begin{cases}
	f(n): \exists \text{ positive constants } c, n_0 \text{ s.t. } 0 \leq f(n) \leq c g(n), \forall n \geq n_0
\end{cases}
$$

$f(n)$ is $O(g(n))$ iff $\exists$ positive constants $c$, $n_0$ such that $f(n) \leq cg(n) \ \forall n \geq n_0$.
- This just means that $27n^2 + 10n - 5$ is $O(n^2)$

Note that **Little-o Notation** describes the loose upper bound.

## Big-Omega Notation

**Big-Omega Notation** describes the tight lower bound:

$$
\Omega(g(n)) = 
\begin{cases}
	f(n) : \exists \text{ positive constants } c, n_0 \text{ s.t. } 0 \leq cg(n) \leq f(n), \forall n \geq n_0
\end{cases}
$$

$$
\begin{align*}
	27n^2 + 10n - 5 &\leq cn^2 \\
	27 + \frac{10}{n} - \frac{5}{n^2} &\leq c, \text{ for } n \geq 10, \frac{10}{n} \leq 1 \\
	28 &\leq c
\end{align*}
$$

Note that **Little-omega Notation** describes the loose lower bound.

$27n^2 + 10n - 5$ is $\Omega(n^2)$

$$
\begin{align*}
	27n^2 + 10n - 5 &\geq cn^2 \\
	27 + \frac{10}{n} - \frac{5}{n^2} &\geq c, \text{ for } n \geq 1, \frac{5}{n^2} \leq 5 \\
	22 &\geq c
\end{align*}
$$

$13n + 8$ is $O(n^2)$

$$
\begin{align*}
	13n + 8 &\leq cn^2 \\
	\frac{13}{n} + \frac{8}{n^2} &\leq c
\end{align*}
$$

$13n + 8$ is $\Omega(n^2)$

$$
\begin{align*}
	13n + 8 &\geq cn^2 \\
	13 + \frac{8}{n} &\geq cn
\end{align*}
$$

This is not true, hence why it is important to care about both the upper and lower bounds.

$$
\begin{align*}
	an^2 + bn + c \text{ is }& \Theta(n^2) \\
	c_1n^2 \leq an^2 + bn + c &\leq c_2n^2 \\
	c_1 \leq a + \frac{b}{n} + \frac{c}{n^2} &\leq c_2, \text{ let } c_1 = \frac{a}{4}, c_2 = \frac{7a}{4}, n_0 = 2 \max\left(\frac{|b|}{a}, \sqrt{\frac{|c|}{a}}\right) \\
	c_1 \leq a + \frac{b}{2\frac{|b|}{a}} + \frac{c}{4 \frac{|c|}{a}} &\leq c_2 \\
	c_1 \leq a \pm \frac{a}{2} \pm \frac{a}{4} &\leq c_2 \\
\end{align*}
$$