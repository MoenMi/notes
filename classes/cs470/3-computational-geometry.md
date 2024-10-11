# 3 - Computational Geometry

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

```
SEGMENTS-INTERSECT(p1, p2, p3, p4)
    d1 = DIRECTION(p3, p4, p1)
    d2 = DIRECTION(p3, p4, p2)
    d3 = DIRECTION(p1, p2, p3)
    d4 = DIRECTION(p1, p2, p4)
    if ((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and
       ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0))
        return TRUE
    elseif d1 == 0 and ON-SEGMENT(p3, p4, p1)
        return True
    elseif d2 == 0 and ON-SEGMENT(p3, p4, p2)
        return True
    elseif d3 == 0 and ON-SEGMENT(p1, p2, p3)
        return True
    elseif d4 == 0 and ON-SEGMENT(p1, p2, p4)
        return True
    else
        return FALSE

DIRECTION(pi, pj, pk)
    return (pk - pi) * (pj - pi)

ON-SEGMENT(pi, pj, pk)
    if min(xi, xj) <= xk <= max(xi, xj) and
       min(yi, yj) <= yk <= max(yi, yj)
        return TRUE
    else
        return FALSE
```

## 33.2 - Determining Whether Any Pair of Segments Intersect

Consider the problem above, but we have a collection of line segments rather than just one pair.

To solve this, we utilize a vertical **sweep line**.
- This algorithm runs in $O(n \lg n)$ time, where $n$ is the number of line segments.
- This algorithm does not find all the intersections, it only finds whether one exists in the set.
- The algorithm assumes that the set contains no vertical line segments, and that no intersection contains three line segments.
- Imagine that this sweep line moves left to right through the space with the line segments.
- Whenever we hit an endpoint of a line segment, we find the vertical order of the line segments going through that point (or rather, we add/delete the new/old point and check whether the order of the pairs have changed).

Sweeping algorithms typically manage two sets of data:
1. The **sweep-line status** gives the relationships among the objects that the sweep line intersects.
2. The **event-point schedule** is a sequence of points, called **event points**, which we order from left to right according to their $x$-coordinates. Whenever the sweep line reaches an event point, the sweep halts to process the event point, and then it resumes.

The sweep-line algorithm:
1. Sort the endpoints of all line segments by $x$-coordinate.
   - If two endpoints are **covertical** (they have the same $x$-coordinate) we break the tie by putting all the covertical left endpoints before all the covertical right endpoints.
   - If there is still a tie, we sort by increasing $y$-coordinates.
2. Whenever an event point is encountered, we perform a sweep.
   - When we encounter a left endpoint in a sweep, we insert the segment into the sweep-line status.
   - When we encounter a right endpoint in a sweep, we delete the segment from the sweep-line status.
   - When two segments first become consecutive in the total preorder, we check whether they intersect.

The sweep-line status is a total preorder $T$, for which the following operations are required:
- $\text{INSERT}(T, s):$ insert segment $s$ into $T$.
- $\text{DELETE}(T, s):$ delete segment $s$ from $T$.
- $\text{ABOVE}(T, s):$ return the segment immediately above segment $s$ in $T$.
- $\text{BELOW}(T, s):$ return the segment immediately below segment $s$ in $T$.

If the input contains $n$ segments, we can perform each of the above operations in $O(\lg n)$ using red-black trees.

### Pseudocode

The following algorithm takes as input a set $S$ of $n$ line segments, returning $\text{TRUE}$ if any pair of segments in $S$ intersects, and $\text{FALSE}$ otherwise. A red-black tree maintains the total preorder $T$.

```
ANY-SEGMENTS-INTERSECT(S)
    T = {}
    sort the endpoints of the segments in S from left to right,
        breaking ties by putting left endpoints before right endpoints
        and breaking further ties by putting points with lower
        y-coordinates first
    for each point p in the sorted list of endpoints
        if p is the left endpoint of a segment x
            INSERT(T, s)
            if (ABOVE(T, s) exists and intersects s)
                or (BELOW(T, s) exists and intersects s)
                return TRUE
        if p is the right endpoint of a segment s
            if both ABOVE(T, s) and BELOW(T, s) exist
                and ABOVE(T, s) intersects BELOW(T, s)
                return TRUE
            DELETE(T, s)
    return FALSE
```

## 33.3 - Finding the Convex Hull

The **convex hull** of a set $Q$ of points, denoted by $\text{CH}(Q)$, is the smallest convex polygon $P$ for which each point in $Q$ is either on the boundary of $P$ or in its interior. If the set of points are nails hammered into a board, the convex hull is the rubber band that fits around that set.

This section covers Graham's scan and Jarvis's march as methods for computing the complex hull, which utilize a **rotational sweep**. Other methods include:
- In the **incremental method**, we first sort the points from left to right, yielding a sequence $\langle p_1, p_2, \dots, p_n \rangle$. At the $i$th stage, we update the convex hull of the $i-1$ leftmost point, $\text{CH}(\{ p_1, p_2, \dots, p_{i-1} \})$, according to the $i$th point from the left, thus forming $\text{CH}(\{ p_1, p_2, \dots, p_i \})$. This can be done in $O(n \lg n)$ time.
- In the **divide-and-conquer method**, we divide the set of $n$ points in $\Theta(n)$ time into two subsets, one containing the leftmost $[n/2]$ points and one containing the rightmost $[n/2]$ points, recursively compute the convex hulls of the subsets, and then, by means of a clever method, combine the hulls in $O(n)$ time. The running time is described by the familiar recurrence $T(n) = 2T(n/2) + O(n)$, and so the divide-and-conquer method runs in $O(n \lg n)$ time.
- The **prune-and-search method** is similar to the worst case linear-time median algorithm in Section 9.3. With this method, we find the upper portion (or upper chain) of the convex hull by repeatedly throwing out a constant fraction of the remaining points until only the upper chain of the convex hull remains. We then do the same for the lower chain. This method is asymptotically the fastest: if the convex hull contains $h$ vertices, it runs in only $O(n \lg h)$ time.

### Graham's Scan

**Graham's scan** solves the convex hull problem by maintaining a stack $S$ of candidate points. It pushes each point of the input set $Q$ onto the stack one time, and it eventually pops from the stack each point that is not a vertex $\text{CH}(Q)$. When the algorithm terminates, stack $S$ contains exactly the vertices $\text{CH}(Q)$, in counterclockwise order of their appearance on the boundary.

```
GRAHAM-SCAN(Q)
    let p0 be the point in Q with the minimum y-coordinate,
        or the leftmost such point in case of a tie
    let <p1, p2, ..., pm> be the remaining points in Q,
        sorted by polar angle in counterclockwise order around p0
        (if more than one point has the same angle, remove all but
        the one that is farthest from p0)
    let S be an empty stack
    PUSH(p0, S)
    PUSH(p1, S)
    PUSH(p2, S)
    for i = 3 to m
        while the angle formed by points NEXT-TO-TOP(S), TOP(S),
                and pi makes a nonleft turn
            POP(S)
        PUSH(pi, S)
    return S
```

Graham's scan runs in $O(n \lg n)$ time.

### Jarvis's March

**Jarvis's march** computes the convex hull of a set of $Q$ points by a technique known as **package wrapping** or **gift wrapping**. The algorithm runs in $O(nh)$ time, where $h$ is the number of vertices on the convex hull.

Intuitively, Jarvis's march simulates wrapping a taut piece of paper around the set $Q$. We start at the lowest point in the set $p_0$, the same as Graham's scan.

At each vertex visited in Jarvis's march, we compute the point which has the most rightward angle with respect to the current vertex. In doing so, we build the right chain until we find the uppermost vertex. From here, we do the same on the way down to find the left chain. Once this is completed, the convex hull is found.

## 33.4 - Finding the Closest Pair of Points

A brute force approach to finding the closest pair of points in a set $Q$ would examine every pair, taking $O(n^2)$.

In this section, we use a divide-and-conquer algorithm, whose runtime is given by the recurrence $T(n) = 2T(n/2) + O(n)$. Thus, this algorithm runs in $O(n \lg n)$ time.

### The Divide-and-Conquer Algorithm

Each recursive iteration takes as input a subset $P \subseteq Q$ and arrays $X$ and $Y$, each of which contains all the points of the input subset $P$. The points in array $X$ are sorted so that their $x$-coordinates are monotonically increasing. Similarly, array $Y$ is sorted by monotonically  increasing $y$-coordinate. Note that in order to attain the $O(n \lg n)$ time bound, we cannot afford to sort in each recursive call.

A given recursive invocation with inputs $P$, $X$, and $Y$ first checks whether $|P| \leq 3$. If so, the invocation simply performs the brute-force method. If $|P| > 3$, the recursive invocation carries out the divide-and-conquer paradigm:
- **Divide**: Find a vertical line $l$ that bisects the point set $P$ into two sets $P_L$ and $P_R$ such that $|P_L| = \lceil |P|/2 \rceil, |P_R| = \lfloor |P|/2 \rfloor$ all points in $P_R$ are on or to the right of $l$. Divide the array $X$ into $X_L$ and $X_R$, which contain the points of $P_L$ and $P_R$ respectively, sorted by monotonically increasing $x$-coordinate. Similarly, divide the array $Y$ into arrays $Y_L$ and $Y_R$, which contain the points of $P_L$ and $P_R$ respectively, sorted by monotonically increasing $y$-coordinate.
- **Conquer**: Having divided $P$ into $P_L$ and $P_R$, make two recursive calls, one to find the closest pair of points in $P_L$ and the other to find the closest pair of points in $P_R$. The inputs to the first call are the subset $P_L$ and arrays $X_L$ and $Y_L$; the second call receives the inputs $P_R$, $X_R$, and $Y_R$. Let the closest-pair distances returned for $P_L$ and $P_R$ be $\delta_L$ and $\delta_R$, respectively, and let $\delta = \min(\delta_L, \delta_R)$.
- **Combine**: The closest pair is either the pair with distance $\delta$ found by one of the recursive calls, or it is the pair of points with one point in $P_L$ and the other in $P_R$. The algorithm determines whether there is a pair with one point in $P_L$ and the other point in $P_R$ and whose distance is less than $\delta$. Observe that if a pair of points has distance less than $\delta$, both points of the pair must reside within $\delta$ units of line $l$. To find such a pair, if it exists, we do the following:
    1. Create an array $Y'$, which is the array $Y$ with all points not in the $2\delta$-wide vertical strip removed. The array $Y'$ is sorted by $y$-coordinate, just as $Y$ is .
    2. For each point $p$ in the array $Y'$, try to find points in $Y'$ that are within $\delta$ units of $p$. Only the 7 points in $Y'$ that follow $p$ need to be considered. Compute the distance from $p$ to each of these 7 points, and keep track of the closest-pair distance $\delta'$ found over all pairs in $Y'$.
    3. If $\delta' < \delta$, then the vertical strip does indeed contain a closer pair than the recursive calls found. Return this pair and its distance $\delta'$. Otherwise, return the closest pair and its distance $\delta$ found by the recursive calls.

When implemented correctly, the divide-and-conquer approach achieves $O(n \lg n)$ time complexity.
