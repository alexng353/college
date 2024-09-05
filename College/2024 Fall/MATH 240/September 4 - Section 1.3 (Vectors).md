Vectors in $\mathbb{R}^n$ (vectors in n-dimensional space)
-  Let $\mathbb{R}$ denote the set of real numbers
- Let $\mathbb{R}^n$ denote n-dimensional space
- Let $(x_{1}, x_{2} \dots, x_{n})$ denote a point in $\mathbb{R}^n$
- Let $[x_{1}, x_{2}, \dots, x_{n}]$ denote a vector in $\mathbb{R}^n$. We will also use vertical brackets.
- Definition. Let u, v be vectors in R^n and let $S\in\mathbb{R}$ (a scalar)

# Definitions:
Equality:

Two vectors are equal **if and only if** their corresponding entries are equal. len(v) = len(u) and each element at each index is equal
$$
\begin{pmatrix}
4 \\ 7
\end{pmatrix}
\ne
\begin{pmatrix}
7 \\ 4
\end{pmatrix}
$$

Vector addition:

$u+v = [u_{1}+v_{1}, u_{2}+v_{2}, \dots, u_{n}+v_{n}]$

Vector subtraction:

$u-v = [u_{1}-v_{1}, u_{2}-v_{2}, \dots, u_{n}-v_{n}]$

Vector multiplication:

$s\times u = [s \cdot u_{1}, s\cdot u_{2}, \dots s\cdot u_{n}]$

** Multiplying a vector by a scalar does not change the direction (negative can flip it)**

The *magnitude* or *length* of a vector $u$ in $\mathbb{R}^n$ is the distance from $(0, 0,\dots, 0)$ to $(u_{1}, u_{2}, \dots, u_{n})$, which is $\sqrt{ u_{1}^2 + u_{2}^2 + \dots +u_{n}^2 }$ (by Pythagoras theorem). **It is denoted by $||u||$.**

**The length of u+v is not the same as the length of u + the length of v**
$||u+v|| \ne ||u|| + ||v||$, but $||2u|| = 2||u||$

## Properties of vector addition, subtraction and scalar multiplication

Let $u, v, w$ be vectors in $\mathbb{R}^n$ and $c, d, \in \mathbb{R}$ be scalars.
Let $\mathbb{0} = [0, 0, \dots, 0] \to \text{The Zero Vector}$
1. $u+v = v+u$                          -> Addition is Commutative
2. $u + (v+w) = (u+v) + w$     -> Addition is Associative
3. $u+\mathbb{0} = u$                                -> The Additive Identity
4. $u+ -1\cdot u = \mathbb{0}$                        -> Inverse Additive Identity
5.  $c \cdot  (u + v) = c \cdot  u + c \cdot  v$      -> The Distributive Law
6. $(c+d) \cdot  u=c\cdot u+d\cdot u$      -> Also the Distributive Law
7. $(c\cdot d)u = c\cdot (du)$                  -> Grouping Law
8.  $1\cdot u=u$                                -> Multiplicative Identity
9. $u-v=u+ -1\cdot v$                 -> No name (??? prof???)
### Proofs of properties
> You **MUST** use a property of real numbers in the proof (that *is* the proof.)

Property 1 $\to$ Addition is Commutative

$$
\begin{align}
u+v &= [u_{1},u_{2},\dots,u_{n}] + [v_{1},v_{2},\dots,u_{n}] \\
&= [u_{1}+v_{1},u_{2}+v_{2},\dots,u_{n}+v_{n}] \to \text{by the definition of vector addition}\\
&= [v_{1}+u_{1}, v_{2}+u_{2},\dots,v_{n} + u_{n}] \to \textbf{addition in } \mathbb{R} \textbf{ is commutative} \\
&=[v_{1},v_{2},\dots,v_{n}] + [u_{1},u_{2},\dots,u_{n}] \to \text{by the definition of vector addition} \\
&= v + u
\end{align}
$$

Property 6 -> The Distributive Law.

$$
\begin{align*}
(c+d) \cdot u &= (c+d) \cdot [u_{1},u_{2},\dots,u_{n}] \\
&= [(c+d)\cdot u_{1}, (c+d) \cdot u_{2}, \dots, (c+d)\cdot u_{n}] \to \text{by definition of vec mul.}\\
&= [(c+d)\cdot u_{1}, (c+d) \cdot u_{2}, \dots, (c+d)\cdot u_{n}] \to \textbf{distributive law in } \mathbb{R} \\
&=[cu_{1},cu_{2},\dots,cu_{n}] + [du_{1},du_{2},\dots,du_{n}] \to \text{by the definition of vector addition}\\
&=c[u_{1},u_{2},\dots u_{n}]+ d[u_{1},u_{2},\dots u_{n}] \to \text{by definition of vector scalar multiplication}\\
&=cu+du
\end{align*}
$$

