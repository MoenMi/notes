# 5 - Probabilistic Study of Qualitative Behavior

We can use the probability transition graph to classify the states of a Markov chain and decompose the Markov chain.

## 5.1 - Classification of States

*This covers section 1.3 in the textbook.*

A **transition probability graph** is a second way to represent a Markov chain where nodes represent the states of the chain and the edges represent possible transitions.

## 5.2 - Definition of Transient and Recurrent States

### 5.2.1 - Definition 1

Let $N(y)$ be the number of visits to $y$ at times $n \geq 1$ (i.e., being there at time $0$ does not count). Also let $P_y$ be the notation for taking the probability conditioned on the initial state being $y$. So $P_y(A) = P(A|X_0 = y)$.

There are 2 cases:
1. The states $y$ such that $P_y(N(y) \geq 1) < 1$, i.e. $y$ is not sure to ever return to $y$.
2. The states $y$ such that $P_y(N(y) \geq 1) = 1$, i.e. $y$ is bound to return to $y$.

We can use the following notation:

$$ \begin{align*}
    \rho_{xy} &:= P_x(N(y) \geq 1) = P(N(y) \geq 1 | X_0 = x) \\
    &= P(\text{the chain will ever visit state } y \text{ when it starts at } x)
\end{align*} $$

So the above cases can be rewritten as:

$$ \begin{cases}
    \rho_{yy} < 1 \Longleftrightarrow y \text{ transient}, \\
    \rho_{yy} = 1 \Longleftrightarrow y \text{ recurrent}
\end{cases} $$

### 5.2.2 - Definition 2

Let's consider this notation: $T_y$ is the first positive time that the chain visits state $y$ (i.e., being there at time $0$ does not count).

With this, we can rewrite the definition as

$$ \rho_{xy} = P_x(T_y < \infty) $$

### 5.2.3 - Using the Notion $T_y$ to Do the Computation of $\rho$

Consider gambler's ruin with $p=0.4$ and $N=4$.

Let's compute $\rho_{00}$:

$$ \begin{align*}
    \rho_{00} &= P_0(T_{\{0\}} < \infty) = P(T_{\{0\}} < \infty | X_0 = 0) \geq P(X_1 = 0 | X_0 = 0) \\
    &= P(T_{\{0\}} = 1, \text{ or } 2, \text{ or } 3, \dots | X_0 = 0) \\
    &\geq P(T_{\{0\}} = 1 | X_0 = 0) \\
    &\geq P(X_1 = 0 | X_0 = 0) = p(0, 0) = 1
\end{align*} $$

These states where $p(x,x)=1$ are called **absorbing states**, which must be recurrent.

Finding the classification of state 1 is more difficult.

#### Method 1

We have

$$ P_1 (T_1 = \infty) \geq P(X_1 = 0 | X_0 = 1) = p(1, 0) = 0.6 $$

Thus

$$ \rho_{11} = P_1(T_1 < \infty) = 1 - P_1(T_1 = \infty) \leq 1 -0.6 = 0.4 <1 $$

Since $\rho_{11} < 1$, state 1 is transient.

#### Method 2

$$ P_1(N(1) = 0) = P(\text{the chain will never return to state 1 if it starts at 1}) \geq p(1,0) = 0.6 $$

$$ P_1(N(1) \geq 1) = 1 - P_1(N(1) < 1) \leq 1 - 0.6 = 0.4 < 1 $$


