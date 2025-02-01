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

$$ \bm{a} = \begin{bmatrix} 1 & 2 & 3 & 4 \end{bmatrix} $$

- Column vector:

$$ \bm{a} = \begin{bmatrix} 1 \\ 2 \\ 3 \\ 4 \end{bmatrix} $$

### Geometry of Vectors

A vector $\bm{x}$ can be represented geometrically as a directed line in $n$ dimensions with $x_1$ along the first axis, $x_2$ along the second axis, and so on.
- A vector can be expanded or contracted through multiplication of the vector by a constant $c$.
- A vector $\bm{x}$ can start at any point in $n$-space. A vector $\overrightarrow{pq}$ starts at point $p$ and terminates at point $q$.
- A vector $\bm{x}$ has two characteristics: **magnitude** and **direction**.

## Matrices

A **matrix** is a rectangular array of numbers (called **elements**) arranged in orderly rows and columns:

$$ \bm{A} = \begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \end{bmatrix} $$

All matrices (and vectors) have an **order of dimensions** (the number of rows $\times$ the number of columns). Thus, $\bm{A}$ is referred to as a $2 \times 3$ matrix. A matrix of dimension $n \times m$ is often denoted $\bm{A}_{n \times m}$.

A **null matrix** is a matrix for which all the elements are 0.

A **square matrix** is a matrix for which the number of rows is equal to the number of columns.

A **symmetric matrix** is a matrix for which $a_{ij} = a_{ji} \forall i, j$.
- If a matrix is symmetric, it must also be square

**Diagonal elements** are the elements of a square matrix for which the row and column locations equal.

An **upper triangular matrix** is a matrix for which all elements below the diagonal are zero. A **lower triangular matrix** is a matrix for which all elements above the diagonal are zero.

Two matrices are equal iff all of their elements are identical.

### Transpose

The **transpose** $\bm{A}'$ of a matrix $\bm{A}$ is the matrix such that the i$^{th}$ row of $\bm{A}$ is the j$^{th}$ column of $\bm{A}'$.

$$ \bm{A} = \begin{bmatrix} 1 & 4 \\ 2 & 5 \\ 3 & 6 \end{bmatrix}, \bm{A}' = \begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \end{bmatrix} $$

### Sums and Differences of Matrices

Two matrices can be added or subtracted iff they are the same order.

### Matrix Multiplication

We write the multiplication of two matrices $\bm{A}$ and $\bm{B}$ as $\bm{AB}$. This is referred to as either **pre-multiplying** $\bm{B}$ by $\bm{A}$ or **post-multiplying** $\bm{A}$ by $\bm{B}$.
- In other words, $\bm{A}$ is referred to as the **premultiplier** and $\bm{B}$ is referred to as the **postmultiplier**.

In order to multiply matrices, they must be **conformable** (i.e., the number of columns in the premultiplier must equal the number of rows in the postmultiplier).
- If an $m \times n$ matrix is multiplied by an $n \times p$ matrix, the product is an $m \times p$ matrix.
- An $m \times n$ matrix cannot be multiplied by an $p \times n$ matrix if $n \ne p$.

$$ \bm{AB} =
\begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \end{bmatrix}
\begin{bmatrix} b_{11} & b_{12} \\ b_{21} & b_{22} \\ b_{31} & b_{32} \end{bmatrix} =
\begin{bmatrix}
    a_{11}b_{11} + a_{12}b_{21} + a_{13}b_{31} & a_{11}b_{11} + a_{12}b_{22} + a_{13}b_{32} \\
    a_{21}b_{11} + a_{22}b_{21} + a_{23}b_{31} & a_{21}b_{11} + a_{22}b_{22} + a_{23}b_{32}
\end{bmatrix}
$$

Note that the transpose of a product is equal to the product of the transposes in reverse order: $(\bm{ABC})' = \bm{C'B'A'}$.
- If $\bm{AA'} = \bm{A}$ then $\bm{A'}$ is idempotent (and $\bm{A'} = \bm{A}$).

## Special Uses for Matrix Multiplication

### Sum Column Elements

This is useful when taking the average for an observation in a dataset.

Premultiply a matrix $\bm{A}$ by a conformable row vector of 1s.

$$ \bm{1A} =
\begin{bmatrix} 1 & 1 & 1 \end{bmatrix}
\begin{bmatrix} 1 & 4 & 7 \\ 2 & 5 & 8 \\ 3 & 6 & 9 \end{bmatrix}
= \begin{bmatrix} 6 & 15 & 24 \end{bmatrix}
$$

### Sum Row Elements

Postmultiply a matrix $\bm{A}$ by a conformable row vector of 1s.

$$ \bm{A1} =
\begin{bmatrix} 1 & 4 & 7 \\ 2 & 5 & 8 \\ 3 & 6 & 9 \end{bmatrix}
\begin{bmatrix} 1 & 1 & 1 \end{bmatrix}
= \begin{bmatrix} 12 \\ 15 \\ 18 \end{bmatrix}
$$

### The Dot (or Inner) Product of Two Vectors

Premultiplication of a column vector $\bm{a}$ by conformable row vector $\bm{b}$ yields a single value called the **dot product** or **inner product**.

$$ \bm{a} \cdot \bm{b} = \begin{bmatrix} 3 & 4 & 6 \end{bmatrix} \begin{bmatrix} 5 \\ 2 \\ 8 \end{bmatrix} = 3(5) + 4(2) + 6(8) = 71 $$

### The Outer Product of Two Vectors

Postmultiplication of a column vector $\bm{a}$ by a conformable row vector $\bm{b}$ yields a matrix containing the products of each pair of elements from the two matrices, called the **outer product**.

$$ \bm{ba} = \begin{bmatrix} 5 \\ 2 \\ 8 \end{bmatrix} \begin{bmatrix} 3 & 4 & 6 \end{bmatrix} = \begin{bmatrix} 15 & 20 & 30 \\ 6 & 8 & 12 \\ 24 & 32 & 48 \end{bmatrix} $$

### Determining If Two Vectors are Orthogonal

Two conformable vectors $\bm{a}$ and $\bm{b}$ are **orthogonal** iff

$$ \bm{a'b} = 0 $$

### Representing Systems of Simultaneous Equations

Suppose we have the following system of simultaneous equations:

$$ \begin{align*}
px_1 + qx_2 + rx_3 = M \\
dx_1 + ex_2 + fx_3 = N
\end{align*} $$

If we let

$$
\bm{A} = \begin{bmatrix} p & q & r \\ d & e & f \end{bmatrix},
\bm{x} = \begin{bmatrix} x_1 \\ x_2 \\ x_3 \end{bmatrix},
\bm{b} = \begin{bmatrix} M \\ N \end{bmatrix}
$$

then we can represent the system as $\bm{Ax} = \bm{b}$.

### Linear Independence and Rank

Any subset of columns (or rows) of a matrix $\bm{A}$ are said to be **linearly independent** if no column (or row) in the subset can be expressed as a linear combination of other columns (or rows) in the subset. If such a combination does exist, then the columns (rows) are said to be **linearly dependent**.

The **rank** of a matrix is defined to be the number of linearly independent columns (or rows) of the matrix.

A **nonsingular matrix**, or a **full rank matrix**, is any matrix that has no linear dependencies among its columns (or rows). For a square matrix $\bm{A}$ this implies that $\bm{Ax} = \bm{0}$ iff $\bm{x} = \bm{0}$.

A **singular matrix**, or a **matrix not of full rank**, is any matrix that has at least one linear dependency among its columns (or rows).

#### Examples

The following matrix $\bm{A}$ is singular because the third column is equal to three times the first column:

$$ \bm{A} = \begin{bmatrix} 1 & 2 & 3 \\ 3 & 4 & 9 \\ 6 & 5 & 18 \end{bmatrix} $$

This result implies that there is either no unique solution or no existing solution to the system of equations $\bm{Ax} = \bm{0}$.

The following matrix is singular because the third column is equal to the first column plus two times the second column.

$$ \bm{A} = \begin{bmatrix} 1 & 2 & 5 \\ 3 & 4 & 11 \\ 6 & 5 & 16 \end{bmatrix} $$

Note that the number of linearly independent rows will always be equal to the number of linearly independent columns in a matrix.

## More Vector Geometry

Vectors have geometric properties of length and direction.

$$ \bm{x} = \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} $$

Consider that the length is

$$ L_x = \sqrt{x_1^2 + x_2^2 + \dots + x_p^2} = \sqrt{\bm{x'x}} $$

### Vector Spaces

The space of all real $m$-tuples, with scalar multiplication and vector addition as we have defined, is called **vector space**.

### Linear Independence

The vector

$$ \bm{y} = a_1 \bm{x}_1 + a_2 \bm{x}_2 + \dots + a_k \bm{x}_k $$

is a **linear combination** of the vectors $\bm{x}_1, \bm{x}_2, \dots, \bm{x}_k$.

The set of all linear combinations of the vectors $\bm{x}_1, \bm{x}_2, \dots, \bm{x}_k$ is called their **linear span**.

A set of vectors $\bm{x}_1, \bm{x}_2, \dots, \bm{x}_k$ is said to be **linearly dependent** if there exist $k$ numbers $a_1, a_2, \dots, a_k$, at least one of which is nonzero, such that

$$ a_1 \bm{x}_1 + a_2 \bm{x}_2 + \dots + a_k \bm{x}_k = 0 $$

Otherwise, the set of vectors $\bm{x}_1, \bm{x}_2, \dots, \bm{x}_k$ is said to be **linearly independent**.

### Orthogonality

When $\bm{x}$ and $\bm{y}$ are perpendicular (or **orthogonal**), this is written as $\bm{x} \perp \bm{y}$.
- $\bm{x'y} = 0 \rightarrow \bm{x} \perp \bm{y}$
- $\bm{z}$ is perpendicular to every vector iff $\bm{z} = \bm{0}$
- If $\bm{z}$ is perpendicular to each vector $\bm{x_1}, \dots, \bm{x_k}$, then $\bm{z}$ is perpendicular to their linear span.

### Projection

The **projection** (or **shadow**) of a vector $\bm{x}$ on a vector $\bm{y}$ is given by:

$$ \frac{\bm{x'y}}{L^2_{\bm{y}}} \bm{y} $$

LOOK MORE AT GEOMETRY OF REGRESSION (SLIDE 89)

## The Gram-Schmidt (Orthogonalization) Process

For linearly independent vectors $\bm{x_1}, \dots, \bm{x_k}$, there exist mutually perpendicular vectors $\bm{u_1}, \dots, \bm{u_k}$ with the same linear span. These may be constructed by setting:

$$ \begin{align*}
    \bm{u_1} &= \bm{x_1} \\
    \bm{u_2} &= \bm{x_2} - \frac{\bm{x_2'u_1}}{\bm{u_1'u_1}} \bm{u_1} \\
    &\vdots \\
    \bm{u_k} &= \bm{x_k} - \frac{\bm{x_2'u_1}}{\bm{u_1'u_1}} \bm{u_1 x_1} - \dots - \frac{\bm{x_k'u_{k-1}}}{\bm{u_{k-1}'u_{k-1}}} \bm{u_{k-1}}
\end{align*} $$

We can normalize (set to unit length) the vectors by dividing by the distance.

## Special Matrices

- Diagonal Matrices
- Identity Matrices
- Null Matrices
- Commutative Matrices
- Anti-Commutative Matrices
- Periodic Matrices
- Idempotent Matrices
- Nilpodent Matrices
- Orthogonal Matrices

## The Determinant of a Matrix

The **determinant** of a matrix $\bm{A}$, commonly denoted $|\bm{A}|$ or $\det \bm{A}$, exist only for square matrices.

### Determinant of a $2 \times 2$ Matrix



### Determinant of a $3 \times 3$ Matrix



### Properties

- $|\bm{A}| = |\bm{A}'|$
- If each element of a row or column of $\bm{A}$ is 0, then $|\bm{A}| = 0$
- If every value in a row of a matrix $\bm{A}$ is multiplied by $k$, then the determinant becomes $k|\bm{A}|$
- If two rows (or columns) are interchanged, then the sign (but not value) of $|\bm{A}|$ changes
- If two rows (or columns) of $\bm{A}$ are identical, $|\bm{A}| = 0$
- $|\bm{A}|$ remains unchanged if each element of a row is multiplied by a constant and added to any other row
- If $\bm{A}$ is nonsingular, then $|\bm{A}| = \frac{1}{|\bm{A}^{-1}|}$, or $|\bm{A}||\bm{A}^{-1}| = 1$
- $|\bm{AB}| = |\bm{A}||\bm{B}|$
- For any scalar $c$, $|c\bm{A}| = c^k |\bm{A}|$ where $k$ is the order of $\bm{A}$
- The determinant of a diagonal matrix is simply the product of the diagonal elements
- If $\bm{A}$ is an orthogonal matrix, its determinants are $\pm 1$ (note that all matrices whose determinant is $\pm 1$ are not necessarily orthogonal)

### Why Are Determinants Important?



### Traces of Matrices

The **trace** of a square matrix, denoted $\text{tr}(\bm{A})$, is the sum of the diagonal elements.

## The Inverse of a Matrix

- The inverse of a matrix $\bm{A}$ is commonly denoted by $\bm{A}^{-1}$ or $\text{inv} \bm{A}$.
- The inverse of an $n \times n$ matrix $\bm{A}$ is the matrix $\bm{A}^{-1}$ such that $\bm{AA}^{-1} = \bm{I} = \bm{A^{-1}A}$.
- A matrix that has an inverse is called nonsingular, regular, or invertable.
- A matrix that does not have an inverse is called singular.
- For some $n \times n$ matrix $\bm{A}$ and inverse matrix $\bm{A}^{-1}$ may not exist.
- An inverse of an $n \times n$ matrix exists iff $|\bm{A}| \ne 0$

### Inverse by Simultaneous Equations



### Inverse by Gauss-Jordan Elimination



### Inverse by Determinants



## Eigenvalues and Eigenvectors

For a square matrix $\bm{A}$, let $\bm{I}$ be a conformable identity matrix. Then the scalars $\lambda$ satisfying the polynomial equation $|\bm{A} - \lambda \bm{I}| = 0$ are called the **eigenvalues** (or **characteristic roots**) of $\bm{A}$.

The equation $|\bm{A} - \lambda \bm{I}| = 0$ is called the **characteristic equation** or the **determinantal equation**.

### Properties

- The sum of the eigenvalues of a matrix $\bm{A}$ is equal to the trace of $\bm{A}$:
  $$ \sum\lambda_i = \text{tr}(\bm{A}) $$
- 