# 0 - Matrix Algebra Primer

**Matrix algebra** is a means of efficiently expressing large numbers of calculations to be made upon ordered sets of numbers. 
- It overlaps substantially with linear algebra.
- It is primarily used to facilitate mathematical expression and computation.
- Many mathematical expressions would be extremely difficult to write if scalar mathematics had to be used. It is also important to note that the scalar algebra is embedded in matrix algebra.

## Vectors

A **scalar** is a single value (i.e., a number).

A **vector** is an array (single row or column) of real numbers.
- Each individual number is called an **element**.
- Vectors are denoted with bold small lowercase letters.
- Row vector:

$$ \boldsymbol{a} = \begin{bmatrix} 1 & 2 & 3 & 4 \end{bmatrix} $$

- Column vector:

$$ \boldsymbol{a} = \begin{bmatrix} 1 \\ 2 \\ 3 \\ 4 \end{bmatrix} $$

### Geometry of Vectors

A vector $\boldsymbol{x}$ can be represented geometrically as a directed line in $n$ dimensions with $x_1$ along the first axis, $x_2$ along the second axis, and so on.
- A vector can be expanded or contracted through multiplication of the vector by a constant $c$.
- A vector $\boldsymbol{x}$ can start at any point in $n$-space. A vector $\overrightarrow{pq}$ starts at point $p$ and terminates at point $q$.
- A vector $\boldsymbol{x}$ has two characteristics: **magnitude** and **direction**.

## Matrices

A **matrix** is a rectangular array of numbers (called **elements**) arranged in orderly rows and columns:

$$ \boldsymbol{A} = \begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \end{bmatrix} $$

All matrices (and vectors) have an **order of dimensions** (the number of rows $\times$ the number of columns). Thus, $\boldsymbol{A}$ is referred to as a $2 \times 3$ matrix. A matrix of dimension $n \times m$ is often denoted $\boldsymbol{A}_{n \times m}$.

A **null matrix** is a matrix for which all the elements are 0.

A **square matrix** is a matrix for which the number of rows is equal to the number of columns.

A **symmetric matrix** is a matrix for which $a_{ij} = a_{ji} \forall i, j$.
- If a matrix is symmetric, it must also be square

**Diagonal elements** are the elements of a square matrix for which the row and column locations equal.

An **upper triangular matrix** is a matrix for which all elements below the diagonal are zero. A **lower triangular matrix** is a matrix for which all elements above the diagonal are zero.

Two matrices are equal iff all of their elements are identical.

### Transpose

The **transpose** $\boldsymbol{A}'$ of a matrix $\boldsymbol{A}$ is the matrix such that the i$^{th}$ row of $\boldsymbol{A}$ is the j$^{th}$ column of $\boldsymbol{A}'$.

$$ \boldsymbol{A} = \begin{bmatrix} 1 & 4 \\ 2 & 5 \\ 3 & 6 \end{bmatrix}, \boldsymbol{A}' = \begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \end{bmatrix} $$

### Sums and Differences of Matrices

Two matrices can be added or subtracted iff they are the same order.

### Matrix Multiplication

We write the multiplication of two matrices $\boldsymbol{A}$ and $\boldsymbol{B}$ as $\boldsymbol{AB}$. This is referred to as either **pre-multiplying** $\boldsymbol{B}$ by $\boldsymbol{A}$ or **post-multiplying** $\boldsymbol{A}$ by $\boldsymbol{B}$.
- In other words, $\boldsymbol{A}$ is referred to as the **premultiplier** and $\boldsymbol{B}$ is referred to as the **postmultiplier**.

In order to multiply matrices, they must be **conformable** (i.e., the number of columns in the premultiplier must equal the number of rows in the postmultiplier).
- If an $m \times n$ matrix is multiplied by an $n \times p$ matrix, the product is an $m \times p$ matrix.
- An $m \times n$ matrix cannot be multiplied by an $p \times n$ matrix if $n \ne p$.

$$ \boldsymbol{AB} =
\begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \end{bmatrix}
\begin{bmatrix} b_{11} & b_{12} \\ b_{21} & b_{22} \\ b_{31} & b_{32} \end{bmatrix} =
\begin{bmatrix}
    a_{11}b_{11} + a_{12}b_{21} + a_{13}b_{31} & a_{11}b_{11} + a_{12}b_{22} + a_{13}b_{32} \\
    a_{21}b_{11} + a_{22}b_{21} + a_{23}b_{31} & a_{21}b_{11} + a_{22}b_{22} + a_{23}b_{32}
\end{bmatrix}
$$

Note that the transpose of a product is equal to the product of the transposes in reverse order: $(\boldsymbol{ABC})' = \boldsymbol{C'B'A'}$.
- If $\boldsymbol{AA'} = \boldsymbol{A}$ then $\boldsymbol{A'}$ is idempotent (and $\boldsymbol{A'} = \boldsymbol{A}$).

## Special Uses for Matrix Multiplication

### Sum Column Elements

This is useful when taking the average for an observation in a dataset.

Premultiply a matrix $\boldsymbol{A}$ by a conformable row vector of 1s.

$$ \boldsymbol{1A} =
\begin{bmatrix} 1 & 1 & 1 \end{bmatrix}
\begin{bmatrix} 1 & 4 & 7 \\ 2 & 5 & 8 \\ 3 & 6 & 9 \end{bmatrix}
= \begin{bmatrix} 6 & 15 & 24 \end{bmatrix}
$$

### Sum Row Elements

Postmultiply a matrix $\boldsymbol{A}$ by a conformable row vector of 1s.

$$ \boldsymbol{A1} =
\begin{bmatrix} 1 & 4 & 7 \\ 2 & 5 & 8 \\ 3 & 6 & 9 \end{bmatrix}
\begin{bmatrix} 1 & 1 & 1 \end{bmatrix}
= \begin{bmatrix} 12 \\ 15 \\ 18 \end{bmatrix}
$$

### The Dot (or Inner) Product of Two Vectors

Premultiplication of a column vector $\boldsymbol{a}$ by conformable row vector $\boldsymbol{b}$ yields a single value called the **dot product** or **inner product**.

$$ \boldsymbol{a} \cdot \boldsymbol{b} = \begin{bmatrix} 3 & 4 & 6 \end{bmatrix} \begin{bmatrix} 5 \\ 2 \\ 8 \end{bmatrix} = 3(5) + 4(2) + 6(8) = 71 $$

### The Outer Product of Two Vectors

Postmultiplication of a column vector $\boldsymbol{a}$ by a conformable row vector $\boldsymbol{b}$ yields a matrix containing the products of each pair of elements from the two matrices, called the **outer product**.

$$ \boldsymbol{ba} = \begin{bmatrix} 5 \\ 2 \\ 8 \end{bmatrix} \begin{bmatrix} 3 & 4 & 6 \end{bmatrix} = \begin{bmatrix} 15 & 20 & 30 \\ 6 & 8 & 12 \\ 24 & 32 & 48 \end{bmatrix} $$

### Determining If Two Vectors are Orthogonal

Two conformable vectors $\boldsymbol{a}$ and $\boldsymbol{b}$ are **orthogonal** iff

$$ \boldsymbol{a'b} = 0 $$

### Representing Systems of Simultaneous Equations

Suppose we have the following system of simultaneous equations:

$$ \begin{align*}
px_1 + qx_2 + rx_3 = M \\
dx_1 + ex_2 + fx_3 = N
\end{align*} $$

If we let

$$
\boldsymbol{A} = \begin{bmatrix} p & q & r \\ d & e & f \end{bmatrix},
\boldsymbol{x} = \begin{bmatrix} x_1 \\ x_2 \\ x_3 \end{bmatrix},
\boldsymbol{b} = \begin{bmatrix} M \\ N \end{bmatrix}
$$

then we can represent the system as $\boldsymbol{Ax} = \boldsymbol{b}$.

### Linear Independence and Rank

Any subset of columns (or rows) of a matrix $\boldsymbol{A}$ are said to be **linearly independent** if no column (or row) in the subset can be expressed as a linear combination of other columns (or rows) in the subset. If such a combination does exist, then the columns (rows) are said to be **linearly dependent**.

The **rank** of a matrix is defined to be the number of linearly independent columns (or rows) of the matrix.

A **nonsingular matrix**, or a **full rank matrix**, is any matrix that has no linear dependencies among its columns (or rows). For a square matrix $\boldsymbol{A}$ this implies that $\boldsymbol{Ax} = \boldsymbol{0}$ iff $\boldsymbol{x} = \boldsymbol{0}$.

A **singular matrix**, or a **matrix not of full rank**, is any matrix that has at least one linear dependency among its columns (or rows).

#### Examples

The following matrix $\boldsymbol{A}$ is singular because the third column is equal to three times the first column:

$$ \boldsymbol{A} = \begin{bmatrix} 1 & 2 & 3 \\ 3 & 4 & 9 \\ 6 & 5 & 18 \end{bmatrix} $$

This result implies that there is either no unique solution or no existing solution to the system of equations $\boldsymbol{Ax} = \boldsymbol{0}$.

The following matrix is singular because the third column is equal to the first column plus two times the second column.

$$ \boldsymbol{A} = \begin{bmatrix} 1 & 2 & 5 \\ 3 & 4 & 11 \\ 6 & 5 & 16 \end{bmatrix} $$

Note that the number of linearly independent rows will always be equal to the number of linearly independent columns in a matrix.

## More Vector Geometry

Vectors have geometric properties of length and direction.

$$ \boldsymbol{x} = \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} $$

Consider that the length is

$$ L_x = \sqrt{x_1^2 + x_2^2 + \dots + x_p^2} = \sqrt{\boldsymbol{x'x}} $$

## Vector Spaces

The space of all real $m$-tuples, with scalar multiplication and vector addition as we have defined, is called **vector space**.

The vector

$$ \boldsymbol{y} = a_1 \boldsymbol{x}_1 + a_2 \boldsymbol{x}_2 + \dots + a_k \boldsymbol{x}_k $$

is a **linear combination** of the vectors $\boldsymbol{x}_1, \boldsymbol{x}_2, \dots, \boldsymbol{x}_k$.

The set of all linear combinations of the vectors $\boldsymbol{x}_1, \boldsymbol{x}_2, \dots, \boldsymbol{x}_k$ is called their **linear span**.

A set of vectors $\boldsymbol{x}_1, \boldsymbol{x}_2, \dots, \boldsymbol{x}_k$ is said to be **linearly dependent** if there exist $k$ numbers $a_1, a_2, \dots, a_k$, at least one of which is nonzero, such that

$$ a_1 \boldsymbol{x}_1 + a_2 \boldsymbol{x}_2 + \dots + a_k \boldsymbol{x}_k = 0 $$

Otherwise, the set of vectors $\boldsymbol{x}_1, \boldsymbol{x}_2, \dots, \boldsymbol{x}_k$ is said to be **linearly independent**.
