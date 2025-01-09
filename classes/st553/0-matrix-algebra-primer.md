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

**Diagonal elements** are the elements of a square matrix for which the row and column locations equal.

An **upper triangular matrix** is a matrix for which all elements below the diagonal are zero. A **lower triangular matrix** is a matrix for which all elements above the diagonal are zero.

Two matrices are equal iff all of their elements are identical.

### Transpose

The **transpose** $\boldsymbol{A}'$ of a matrix $\boldsymbol{A}$ is the matrix such that the i$^{th}$ row of $\boldsymbol{A}$ is the j$^{th}$ column of $\boldsymbol{A}'$.

$$ \boldsymbol{A} = \begin{bmatrix} 1 & 4 \\ 2 & 5 \\ 3 & 6 \end{bmatrix}, \boldsymbol{A}' = \begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \end{bmatrix} $$

### Sums and Differences of Matrices

Two matrices can be added or subtracted iff they are the same order.

### Products of Matrices


