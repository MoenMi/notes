# 1 - Intro

A **stochastic process** is a collection of random variables indexed by time. When the time index is discrete, we say that it is a discrete-time stochastic process and we denote them as $X_0, X_1, X_2, \dots, X_n, \dots$. When the time is continuous, we say that it is a continuous-time stochastic process, and denote them as $X_t, t \geq 0$.

## 1.1 - Examples of Stochastic Processes

### 1.1.1 - Bernoulli Processes

The most basic stochastic process is a Bernoulli process $X_1, X_2, \dots$, where $X_1, X_2, \dots$ are Bernoulli random variables. We can use this to model a coin toss for $i = 1, 2, \dots$

$$ X_i = \begin{cases}
    1, & \text{the i-th coin toss is heads}, \\
    0, & \text{the i-th coin toss is tails}
\end{cases} $$

Suppose that $p = 0.4$, which is the probability that the coin is heads. Then, for $i = 1, 2, \dots$, we have

$$ X_i = \begin{cases}
    1, & \text{with probability } p, \\
    0, & \text{with probability } 1 - p
\end{cases} $$

### 1.1.2 - Gambler's Ruin

Consider a gambling game in which on any turn, you win \$1 with probability $p = 0.4$, and lose \$1 with probability $1 - p = 0.6$. We quit if we go broke or reach a fortune of \$100.

Let $Y_n$ be the accumulated amount of money we have after $n$ plays. Then, $Y_1, Y_2, \dots, Y_n, \dots$ is a stochastic process.

### 1.1.3 - Weather Chain

Let $X_n$ be the weather on day $n$ in Ithaca, NY, which we assume is either $1$ if it is rainy or $2$ if it is sunny.

This is a discrete-time stochastic process.

## 1.2 - Markovian Property

In general, we cannot assume that random variables $X_1, X_2, \dots$ in a discrete-time stochastic process are independent.

A stochastic process is **Markovian** if its future states depend only possibly on the present states.
