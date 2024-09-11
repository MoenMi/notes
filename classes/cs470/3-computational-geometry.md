# 3 - Computational Geometry

## Vector Rotation Problem

Given two vectors $p_1$ and $p_2$, how can we determine whether it is quicker to rotate clockwise or counterclockwise to make the direction of $p_1$ match that of $p_2$.

The **cross product** $p_1 \times p_2$ can be interpreted as the signed area of the parallelogram formed by the points $(0,0), p_1, p_2,$ and $p_1 + p_2 = (x_1 + x_2, y_1 + y_2)$. An equivalent, but more useful definition, gives the cross product as the determinant of a matrix:

$$
\begin{align*}
    p_1 \times p_2 &= \det \begin{pmatrix}
        x_1 & x_2 \\
        y_1 & y_2
    \end{pmatrix} \\
    &= x_1 y_2 - x_2 y_1 \\
    &= -p_2 \times p_1
\end{align*}
$$

ADD MORE DETAIL FROM BOOK HERE

## Left/Right Turn Problem

Given two vectors $p_1$ and $p_2$, if we traverse $p_1$ and then $p_2$, do we make a left or right turn?



## Line Segment Intersection Problem

Do line segments $\overline{p_1 p_2}$ and $\overline{p_3 p_4}$ intersect?

This can be solved using linear algebra, but it requires using division, which is costly and imprecise when done computationally. This can cause issues especially when the segments are nearly parallel.

Consider the walks from $p_1$ to $p_2$ to $p_3$, from $p_1$ to $p_2$ to $p_4$, from $p_3$ to $p_4$ to $p_1$, and from $p_3$ to $p_4$ to $p_2$. If both of these pairs of walks "straddle" the line (each turn in the pair has opposite directions), then the line segments intersect.
- If the line segments overlap, then we consider the segments to intersect. This must be handled separately.

## Determining Whether Any Pair of Segments Intersect

Consider the problem above, but we have a collection of line segments rather than just one pair.

To solve this, we utilize a vertical **sweep line**.
- Imagine that this sweep line moves left to right through the space with the line segments.
- Whenever we hit the the beginning or end of a line segment, we find the vertical order of the line segments going through that point (or rather, we add/delete the new/old point and check whether the order of the pairs have changed).
- 

## Finding the Convex Hull

The **convex hull** is a set $Q$ of points, denoted by $\text{CH}(Q)$, is the smallest convex polygon $P$ for which each point in $Q$ is either on the boundary of $P$ or in its interior.
