# 33 - Computational Geometry

## 33.1 - Line-Segment Properties

### Vector Rotation Problem

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

This results in the following cases:
- If $p_1 \times p_2 > 0$, then $p_1$ is clockwise from $p_2$ with respect to the origin.
- If $p_1 \times p_2 < 0$, then $p_1$ is counterclockwise from $p_2$ with respect to the origin.
- If $p_1 \times p_2 = 0$, then $p_1$ and $p_2$ are **colinear**, meaning that they point in either the same or opposite directions.

### Left/Right Turn Problem

Given two consecutive line segments $\overline{p_0p_1}$ and $\overline{p_1p_2}$. If we traverse $p_1$ and then $p_2$, do we make a left or right turn?

This can be solved using the cross product, as shown in the previous example. In this case, we merely examine the vectors $\overrightarrow{p_0p_1}$ and $\overrightarrow{p_0p_2}$.
- If $\overrightarrow{p_0p_2}$ is counterclockwise from $\overrightarrow{p_0p_1}$, then it is a left turn.
- If $\overrightarrow{p_0p_2}$ is clockwise from $\overrightarrow{p_0p_1}$, then it is a right turn.

### Line Segment Intersection Problem

Do line segments $\overline{p_1 p_2}$ and $\overline{p_3 p_4}$ intersect?

This can be solved using algebra, but it requires using division, which is costly and imprecise when done computationally. This can cause issues especially when the segments are nearly parallel.

Consider the walks from $p_1$ to $p_2$ to $p_3$, from $p_1$ to $p_2$ to $p_4$, from $p_3$ to $p_4$ to $p_1$, and from $p_3$ to $p_4$ to $p_2$. If both of these pairs of walks "straddle" the line (each turn in the pair has opposite directions), then the line segments intersect.
- If the line segments overlap, then we consider the segments to intersect. This must be handled separately.

ADD PSEUDOCODE FROM TEXTBOOK

## 33.2 - Determining Whether Any Pair of Segments Intersect

Consider the problem above, but we have a collection of line segments rather than just one pair.

To solve this, we utilize a vertical **sweep line**.
- This algorithm runs in $O(n \lg n)$ time, where $n$ is the number of line segments.
- This algorithm does not find all the intersections, it only finds whether one exists in the set.
- Imagine that this sweep line moves left to right through the space with the line segments.
- Whenever we hit the the beginning or end of a line segment, we find the vertical order of the line segments going through that point (or rather, we add/delete the new/old point and check whether the order of the pairs have changed).
- 

## Finding the Convex Hull

The **convex hull** is a set $Q$ of points, denoted by $\text{CH}(Q)$, is the smallest convex polygon $P$ for which each point in $Q$ is either on the boundary of $P$ or in its interior.
