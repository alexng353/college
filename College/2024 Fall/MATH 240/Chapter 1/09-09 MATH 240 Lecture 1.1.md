(1) $x_{1}+x_{2}+x_{3}=1$
(2) $x_{1}+2x_{2}+3x_{3}=4$
(3) $2x_{1}+3x_{2}+5x_{3} = 3$

This is a linear system of 3 equations in 3 unknowns, $x_{1}, x_{2},x_{3}$.

One way to solve the system is called "Gaussian Elimination."

# Gaussian Elimination (examples)
1. Subtract (1) from (2) and subtract 2(1) from (3).
$$
\begin{align}
x_{1}+x_{2}+x_{3}&=1 \\
0+x_{2}+2x_{3}&= 3 \\
0+x_{2}+3x_{3}&= 1
\end{align}
$$
2. Subtract (2) from (3)
$$
\begin{align}
x_{1}+x_{2}+x_{3} &=  1 \\
0+x_{2}+2x_{3}&= 3 \\
0+0+x_{3}&= -2
\end{align}
$$
3. The forward elimination is done.
   Start back elimination.
4. Subtract 2(3) from (2) and (3) from (1)
$$
\begin{align}
x_{1}+x_{2}+0 &= 3 \\
0+x_{2}+0 &= 7 \\
0+0+x_{3}&= -2
\end{align}
$$
5. Subtract (2) from (1)
$$
\begin{align}
x_{1}&=3 \\
x_{2}&= 7 \\
x_{3}&= -2
\end{align}
$$
The system has 1 solution.

Fin.

## Gaussian Elimination with Matrices

> We will write the linear system as a matrix (augmented matrix) of the form $[A|b]$ (this notation reads "The matrix $A$ augmented with $b$)

Take the following linear system
$$
\begin{align}
1x_{1}+1x_{2}+1x_{3}&= 1 \\
1x_{1}+2x_{2}+3x_{3}&= 4 \\
2x_{1}+3x_{2}+5x_{3}&= 3
\end{align}
$$

The augmented matrix corresponding to this system is
$$
\begin{bmatrix}
1 & 1 & 1 & 1 \\
1 & 2 & 3 & 4 \\
2 & 3 & 5 & 3
\end{bmatrix}
$$
We do the same operations on the rows of $[A|b]$.

1. $R_{2}:=R_{2}-R_{1}$
   $R_{3}:=R_{3}-2R_{1}$
$$
\begin{bmatrix}
1 & 1 & 1 & 1 \\
0 & 1 & 2 & 3 \\
0 & 1 & 3 & 1
\end{bmatrix}
$$

2. $R_{3}:=R_{3}-R_{2}$d
$$
\begin{bmatrix}
1 & 1 & 1 & 1 \\
0 & 1 & 2 & 3 \\
0 & 0 & 1 & -2
\end{bmatrix}
$$
3. $R_{1}:=R_{1}-R_{3}$
   $R_{2}:=R_{2}-2R_{3}$
$$
\begin{bmatrix}
1 & 1 & 0 & 3 \\
0 & 1 & 0 & 7 \\
0 & 0 & 1 & -2
\end{bmatrix}
$$
4. $R_{1}:=R_{1}-R_{2}$
$$
\begin{bmatrix}
1 & 0 & 0 & -4\\
0 & 1 & 0 & 7\\
0 & 0 & 1 & -2\\
\end{bmatrix}
$$

$$
\begin{align}
\therefore\text{ }
x_{1}&= -4 \\
x_{2}&= 7 \\
x_{3}&= -2

\end{align}
$$
Fin. 

**Pivots** are the first nonzero element in each row of the matrix.
**If** you come to a **contradiction** ($0=b$), there are **No Solutions** to that particular linear system. 
A linear system with no solution is **inconsistent**. Otherwise, it is **consistent**.

In the Lecture, he does it again, but I don't feel like typing it out again so I'm not going to. Read the lecture notes if you really want to.

## Example 3
$$
\begin{align}
x-z&= 0 \\
x+z&= 1 \\
x+y&= 1
\end{align}
$$
$$
\begin{bmatrix}
1 & 0 & -1 & 0 \\
0 & 1 & 1 & 1 \\
1 & 1 & 0 & 1
\end{bmatrix}
$$
1. $R_{3}:=R_{3}-R_{1}$
$$
\begin{bmatrix}
1 & 0 & -1 & 0 \\
0 & 1 & 1 & 1 \\
0 & 1 & 1 & 1
\end{bmatrix}
$$
Notice how $R_{2}$ and $R_{3}$ are equal.
2. $R_{3}:=R_{3}-R_{2}$
$$
\begin{bmatrix}
1 & 0 & -1 & 0 \\
0 & 1 & 1 & 1 \\
0 & 0 & 0 & 0
\end{bmatrix}
$$
$$
\begin{align}
x-z &= 0 \\
y+z  &= 1
\end{align}
$$
$$
\begin{align}
x &= z \\
y &= 1-z \\
z & \text{ is free (can be anything)}
\end{align}
$$

In general, a linear system has 0, 1 or $\infty$ real solutions.

How should we describe $\infty$ solutions?

$x=z$

$y=1-z$

$\text{let } z=t\in \mathbb{R}\text{ (a parameter)}$

We can represent these solutions

1. as a set of points in $\mathbb{R}^{n}$

$\{(x,y,z) = (t, 1-t, t)\text{ where } t \in \mathbb{R}\}$

2. as a parametric vector

$$
\begin{bmatrix}
x \\y \\z
\end{bmatrix}
= \begin{bmatrix}
t\\1-t\\t
\end{bmatrix}
= \begin{bmatrix}
0\\1\\0
\end{bmatrix}
+ t\cdot\begin{bmatrix}
1\\-1\\1
\end{bmatrix}
$$

This parametric vector can be represented as a line, going through the point $v$ in 3d space .

For one free variable (one parameter) we get a line in $\mathbb{R}^{n}$. 

For two free variables, we get a plane in $\mathbb{R}^{n}$.

# Elementary Row Operations

> There are 3 elementary row operations we can do without altering the solution set of the original system

1. $R_{i} := R_{i} + S \cdot R_{j}\text{ for } S\in \mathbb{R}\text{ and }i\ne j$
2. $R_{i}:= S\cdot R_{i}\text{ for } S\ne 0$
3. $R_{i} \leftrightarrow R_{j}\text{ (interchange two rows)}$

Notice that these operations are reversible. 

**Theory:** These row operations do not change the solutions of the Linear System

If a matrix $B$ is obtained from a matrix $A$ by doing a row operation, we say $B$ is **row equivalent** to $A$ and we write $B \sim A$. 

Since row operations are reversible, we if $B \sim A$, then $A \sim B$. 

Exercise: Write Gaussian elimination in code

### Another Example:
$$
\begin{align}
c &= 1 \\
a+b+c &= 3 \\
a-b+c &= 1
\end{align}
$$

Augmented matrix:
$$
\begin{bmatrix}
0 & 0 & 1 & 1 \\
1 & 1 & 1 & 3 \\
1 & -1 & 1 & 1
\end{bmatrix}
$$
1. $R_{1} \leftrightarrow R_{3}$

$$
\begin{bmatrix}
1 & -1 & 1 & 1 \\
1 & 1 & 1 & 3 \\
0 & 0 & 1 & 1
\end{bmatrix}
$$

2. $R_{2}:=R_{2}-R_{1}$

$$
\begin{bmatrix}
1 & -1 & 1 & 1 \\
0 & 2 & 0 & 2 \\
0 & 0 & 1 & 1
\end{bmatrix}
$$

3. $R_{2}:=\frac{1}{2}R_{2}$

$$
\begin{bmatrix}
1 & -1 & 1 & 1 \\
0 & 1 & 0 & 1 \\
0 & 0 & 1 & 1
\end{bmatrix}
$$

4. $R_{1}:=R_{1}-R_{3}$

$$
\begin{bmatrix}
1 & -1 & 0 & 0 \\
0 & 1 & 0 & 1 \\
0 & 0 & 1 & 1
\end{bmatrix}
$$

5. $R_{1}:=R_{1}+R_{2}$

$$
\begin{bmatrix}
1 & 0 & 0 & 1 \\
0 & 1 & 0 & 1 \\
0 & 0 & 1 & 1
\end{bmatrix}
$$

This corresponds to

$$
\begin{align}
\therefore\text{ }
a &= 1 \\
b &= 1 \\
c &= 1
\end{align}
$$

This is special because this matrix corresponds to the 3 basis vectors of $R^3$ space.