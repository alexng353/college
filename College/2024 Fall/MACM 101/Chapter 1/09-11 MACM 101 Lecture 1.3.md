$\neg q\implies\neg p$

| $p$ | $q$ | $\neg p$ | $\neg q$ | $p \implies q$ | $\neg q \implies \neg p$ |
| --- | --- | -------- | -------- | -------------- | ------------------------ |
| 0   | 0   | 1        | 1        | 1              | 1                        |
| 0   | 1   | 1        | 1        | 1              | 1                        |
| 1   | 0   | 0        | 1        | 0              |                          |
| 1   | 1   | 0        | 0        | 1              | 1                        |

$p \to q \text{ is logically equivalent to } \neg q \to \neg p$ 

So, $\neg q\to \neg p$ is the **contrapositive** of $p\to q$ 

$p \implies q$ **material implication**

$q \implies p$ is called the **converse** of material implication

$(\neg q \implies \neg p)$ is alled the **contrapositive** of material implication, and

$(\neg p \implies \neg q)$ is called the **inverse** of material implication

# First Identity
$p \implies q$ means $p \therefore q$ 

if the argument is valid and $p$ is true, then $q$ is also true.

If the argument is valid and $p$ is false, then we can conclude nothing about $q$.

thus, $p \implies q$ is logically equivalent to $\neg p \lor q$

| $p$ | $q$ | $\neg p$ | $p \implies q$ | $\neg p \lor q$ |
| --- | --- | -------- | -------------- | --------------- |
| 0   | 0   | 1        | 1              | 1               |
| 0   | 1   | 1        | 1              | 1               |
| 1   | 0   | 0        | 0              | 0               |
| 1   | 1   | 0        | 1              | 1               |

This is known as **implication reduction**

> this is important because we *always* want to remove implication from our logical statements

# De Morgan's Laws
$\neg(p\land q) \equiv \neg p\lor \neg q$

$\neg(p\lor q) \equiv \neg p \land \neg q$

***Many of the Axiomatic Laws come in pairs (principle of duality)***

> show the truth table (exercise)

**Propositional Identities are given on the exam**

# Principle of Duality

(exercise for the reader (???))

