Let $u$,$v$ be two vectors in $\mathbb{R}^{n}$ and $s\in \mathbb{R}$ (a scalar).

So, $u = [u_{1}, u_{2}, ..., u_{n}]$ and $v=[v_{1}, v_{2}, ..., v_{n}]$,

 $u+v = [u_{1}+v_{1}, u_{2}+v_{2}, ..., u_{n} + v_{n}]$ 

 $u-v = [u_{1} - v_{1}, u_{2} - u_{2}, ..., u_{n} - u_{n}]$

 $s\cdot u = [s\cdot u_{1}, s \cdot u_{2}, ..., s \cdot u_{n}]$
 
example:

$u=\begin{pmatrix}2,1\end{pmatrix}$

$v=\begin{pmatrix}1,2\end{pmatrix}$

$u=vt$

# Dot Product
$u \cdot v = [u_{1}\cdot v_{1} + u_{2} \cdot v_{2}, \dots + u_{n} \cdot v_{n}] \in \mathbb{R}$

Example:
$$
\begin{bmatrix}
2 \\
1
\end{bmatrix}
\cdot
\begin{bmatrix}
1 \\
2
\end{bmatrix}
= 2 \cdot 1 + 1 \cdot 2 = 4
$$
# Linear Combination
Let $v_{1}, v_{2}, ..., v_{n}$ be vectors in $\mathbb{R}^{n}$ and $c_{1},c_{2},\dots,c_{n}$ be scalars in $\mathbb{R}$. The vector $c_{1}\cdot v_{1}+c_{2}*v_{2},\dots +c_{m}\cdot v_{M}$ is called a linear combination of $v_{1},v_{2},\dots,v_{m}$

Given $v_{1}=\begin{bmatrix}1\\1\\1\end{bmatrix}$ and $v_{2} = \begin{bmatrix}1\\2\\3\end{bmatrix}$ and $b=\begin{bmatrix}2\\3\\5\end{bmatrix}$, is $b$ a linear combination of $v_{1}$ and $v_{2}$?

Is $b=c_{1}\cdot v_{1} + c_{2} \cdot v_{2}$ for some scalars $c_{1}, c_{2} \in \mathbb{R}$?

Is $\begin{bmatrix}2\\3\\5\end{bmatrix} = c_{1}\begin{bmatrix}1\\1\\1\end{bmatrix} + c_{2}\begin{bmatrix}1\\2\\3\end{bmatrix} = \begin{bmatrix}c_{1}\\c_{1}\\c_{1}\end{bmatrix} + \begin{bmatrix}c_{2}\\2c_{2}\\3c_{2}\end{bmatrix} = \begin{bmatrix}c_{1}+c_{2}\\c_{1}+2c_{2}\\c_{1}+3c_{2}\end{bmatrix}$

(1): $2=c_{1}+c_{2}$

(2): $3=c_{1}+2c_{2}$

(3): $5=c_{1}+3c_{2}$

> This is a system of 3 linear equations in two unknowns, $c_{1}$ and $c_{2}$

We have 3 linear equations and two unknowns, and now we need to solve them.

$(2)-(1) \to 1 = 0 + c_{2} \implies c_{2}=1$

$(3)-(2) \to 2 = 0 +c_{2} \implies c_{2}=2$

Because there is a contradiction ($c_{2} = 1 \text{ and } c_{2}=2$) this system has no solutions

The equation $b=c_{1}v_{1}+c_{2}v_{2}$ is called a vector equation, which corresponds to a linear system.

> Every linear system has a corresponding (*can be written as a*) vector equation 

## Example
$x+2y+z =3$

$2x=3y = 4$

$y+z = 5$

We can use this transformation to prove a linear system

$$
\begin{bmatrix}
3 \\
4 \\
5
\end{bmatrix}
=
\begin{bmatrix}
x+2y+z \\
2x-3y+0 \\
0+y+z
\end{bmatrix}
=
\begin{bmatrix}
x \\
2x \\
0
\end{bmatrix}
+
\begin{bmatrix}
2y \\
-3y \\
y
\end{bmatrix}
+
\begin{bmatrix}
z \\
0 \\
z
\end{bmatrix}
=
x\begin{bmatrix}
1 \\
2 \\
0
\end{bmatrix}
y\begin{bmatrix}
2 \\
-3 \\
1
\end{bmatrix}
+
z\begin{bmatrix}
1 \\
0 \\
1
\end{bmatrix}
$$
## Definition
If $v_{1},v_{2},\dots,v_{m} \in \mathbb{R}^{n}$ , then the set of all linear combinations of the vectors $v_{1},v_{2},\dots,v_{m}$ is denoted by $Span(v_{1},v_{2},\dots,v_{m})$

> $Span$ means the **set of all linear combinations** of it's arguments

That is, $Span(v_{1},v_{2},\dots,v_{m}) = \{c_{1}v_{1} + c_{2}v_{2} + \dots + c_{m}v_{m} : c_{1},c_{2},\dots c_{m} \in \mathbb{R}\}$ 

(Read as Span(...) is equal to the set of c1v1... such that c1... is a member of $\mathbb{R}$ (the real number set))

What does $Span(v_{1},v_{2},\dots,v_{m})$ ? (???)

#### Example

$v_{1}=\begin{bmatrix}1\\0\\0\end{bmatrix}$ and $v_{2}=\begin{bmatrix}0\\1\\0\end{bmatrix}$ in $\mathbb{R}^3$

$Span(v_{1}, v_{2})=\{c_{1}\begin{bmatrix}1\\0\\0\end{bmatrix} + c_{2}\begin{bmatrix}0\\1\\0\end{bmatrix}: c_{1},c_{2}\in \mathbb{R}\}$

$={\begin{bmatrix}c_{1}\\c_{2}\\0\end{bmatrix}: c_{1},c_{2} \in \mathbb{R}}$

*First entry is the "$x$ co-ordinate", second is $y$, third is $z$*

Because the $z$ coordinate is 0, we can't have any vector with a nonzero $z$ coordinate. 

So, this is equal to the set of all vectors in $R^3$ with $z=0$. This is the $x-y$ plane.

> Span is saying we can get every linear combination in the plane

# Question
Consider $S = Span(\begin{bmatrix}1\\0\\0\end{bmatrix}, \begin{bmatrix}0\\1\\0\end{bmatrix}, \begin{bmatrix}1\\1\\0\end{bmatrix})$

Because $z=0$ still, $S=Span(v_{1},v_{2})$

> The vector, v3, is redundant

**Theorem.** 

Let $S=Span(v_{1},v_{2},\dots,v_{R})$ in $\mathbb{R}^{n}$.

if $V_{R} = c_{1}v_{1}+c_{2}v_{2}+\dots+c_{R-1}v_{R-1}$ for some $c_{1},c_{2},\dots,c_{R-1} \in \mathbb{R}$.

then $S=Span(v_{1},v_{2},\dots,v_{R-1})$ (i.e. $v_{R}$ is redundant)

Prove that $Span(v_{1},v_{2},v_{1}+v_{2}) = Span(v_{1},v_{2})$

Prove that $S_{1} = S_{2}$?

**Proof Method**: Show that every vector in $S_{1}$ is in $S_{2}$, and show that every vector in $S_{2}$ is in $S_{1}$. 

Show that $(S_{1} \subset S_{2} )$.

Let $w \in S_{1}$.

So,
$$
\begin{align}
w&= d_{1}v_{1} + d_{2}v_{2} +d_{3}v_{3} \text{ where } d_{1},d_{2},d_{3} \in \mathbb{R}.\\
&= d_{1}v_{1}+d_{2}v_{2} + (d_{3}v_{1}+d_{3}v_{2}) \to \text{ This is Property 5.}\\
& \text{We can re-order the vectors using property 1 and 2}\\
&= (d_{1}v_{1}+d_{3}v_{1})+(d_{2}v_{2}+d_{3}v_{2})\\
&= (d_{1}+d_{3})v_{1} + (d_{2}+d_{3})v_{2} \to \text{ Property 6.} \\
&= c_{1}v_{1} + c_{2}v_{2} \in S_{2} = Span(v_{1},v_{2})
\end{align}
$$

Show that ($S_{2}\subset S_{2}$)
$$
\begin{align}
\text{Let } u\in S_{2} &= Span(v_{1},v_{2}) \\
u &= c_{1}v_{1} + c_{2}v_{2} \text{ for some } c_{1},c_{2} \in \mathbb{R} \\
& \implies

\end{align}

$$

Elementary vector 1

$e_{1} = \begin{bmatrix}1\\0\\0\end{bmatrix}$ describes the $x$ vector (in an $xyz$ coordinate system)

$e_{2}=\begin{bmatrix}0\\1\\0\end{bmatrix}$ descibres the $y$ vector

$e_{3}=\begin{bmatrix}0\\0\\1\end{bmatrix}$ likewise describes the $z$ vector
