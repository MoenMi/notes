# 1 - Introduction

## Starting Example

Consider the following scenario:

You are a bakery that can produce cake and pies using flour and suger.

|  | flour | sugar | profit |
| - | - | - | - |
| cake | 3 cups | 1 cup | $10 |
| pie | 1 cup | 2 cups | $12 |
| inventory | 30 cups | 20 cups |  |

How many cakes and how many pies should you produce to maximize profit? Consider $x_1$ to be the number of cakes, and $x_2$ to be the number of pies.

$$ \text{Profit} = 10x_1 + 12x_2 $$

This is subject to the following constraints:

$$ 
\begin{align*}
    3x_1 + x_2 &\leq 30 \\
    x_1 + 2x_2 &\leq 20 \\
    x_1 &\geq 0 \\
    x_2 &\geq 0
\end{align*}
$$

## General Form of these Problems

The **objective function**, $z = f(x)$, is what we aim to maximize or minimize.

This can be subject to **equality constraints** (e.g. $h(x)=0$), **inequality constraints** (e.g. $g(x) \leq 0$), or **set constraints** (e.g. $x \in S \leq \mathbb{R}^n$).

### Example

$$ x = \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} $$

$$ f(x) = 10x_1 + 12x_2 $$

$$ h(x) = 0 $$

$$ g(x) = \begin{bmatrix}
    3x_1 + x_2 - 30 \\
    x_1 + 2x_2 - 20
\end{bmatrix} $$

## Standard Linear Programming (LP)

The following is the **standard form** of an LP problem:

```text
min z=c^T x
s.t. Ax = b
     x >= 0
```

Here, $A = A_{m \times n}$, $b = b_{m \times 1}$, and $x = x_{1 \times n}$.

$x^*$ is an **optimal solution** if
1. Feasibility: $Ax^*=b, x^* \geq 0$
2. Optimality: For any $x$ s.t. $Ax = b, x \geq 0$ we have $c^T x^* \subseteq c^T x$

To **solve the LP**, we must find the optimal solution $x^*$ and the corresponding $z^* = c^T x^*$.

Any LP can be equivalently written as a standard LP. Consider the following example LP1:

```text
max w = c^T x
s.t. Ax = b
     x >= 0
```

This can be rewritten as LP2:

```text
min z = -w = -c^T x
s.t. Ax = b
     x >= 0
```

### Example using Slack Variables

In this scenario, $s$ is a **slack variable**.

$Ax \leq b$

```text
LP1: min z = c^T x
     s.t. Ax <= b
          x >= 0
```

This is equivalent to

```text
min z = c^T x
s.t. Ax + s = b
     x >= 0
     s >= 0
```

which is equivalent to

```text
min z^~ = c^~^T x^~
s.t. A^~ x^~ = b^~
     x^~ >= 0
```

$$ \tilde{x} = \begin{bmatrix} x \\ s \end{bmatrix} $$

$$ \tilde{A} = \begin{bmatrix} A & I \end{bmatrix} $$

$$ \tilde{b} = b = \begin{bmatrix} x \\ s \end{bmatrix} $$

$$ \tilde{c} = \begin{bmatrix} c \\ 0 \end{bmatrix} $$

### Example using Surplus Variables

In this scenario, $s$ is a **surplus variable**.

$Ax \geq b$

```text
LP1: min z = c^T x
     s.t. Ax >= b
          x >= 0
```

This is equivalent to

```text
min z = c^T x
s.t. Ax - s = b
     x >= 0
     s >= 0
```

which is equivalent to

```text
min z^~ = c^~^T x^~
s.t. A^~ x^~ = b^~
     x^~ >= 0
```

$$ \tilde{x} = \begin{bmatrix} x \\ s \end{bmatrix} $$

$$ \tilde{A} = \begin{bmatrix} A & -I \end{bmatrix} $$

$$ \tilde{b} = b = \begin{bmatrix} x \\ s \end{bmatrix} $$

$$ \tilde{c} = \begin{bmatrix} c \\ 0 \end{bmatrix} $$

### Example (upper bound: $0 \leq x \leq d$)

```text
LP1: min z = c^T x
     s.t. Ax = b
          0 <= x <= d
```

```text
min z = c^T x
s.t. Ax = b
     x + s = d
     x >= 0
     s >= 0
```

```text
min z^~ = c^~^T x^~
s.t. A^~ x^~ = b^~
     x^~ >= 0
```

$\tilde{A} = \begin{bmatrix} A & 0 \\ I & I \end{bmatrix}$
