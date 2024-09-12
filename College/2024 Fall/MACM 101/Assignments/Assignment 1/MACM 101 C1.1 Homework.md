### Question 22
a) Inclusive or, the requirement is experience with one or the other, and having both would still satisfy the requirement.

b) Exclusive or, Lunch will come with either soup or salad, not both.

c) Inclusive or, having both documents will not get you turned away.

d) Exclusive or, publishing prevents perishing

### Question 24
a) If you get promoted, then you have washed the Boss's car

b) If there are winds from the south, then there is a spring thaw.

c) If you bought the computer less than a year ago, then the warranty is good.

d) If Willy cheats, then he gets caught.

e) If you can access the website, then you have paid a subscription fee.

f) If you know the right people, then you get elected

g) If Carol is on a boat, then she gets seasick.

### Question 26
a) If you send me an e-mail message, then I will remember to send you the address.

b) If you were born in the United States, then you are a citizen of this country.

c) If you keep your textbook, then it will be a useful reference in your future courses.

d) If their goalie plays well, then the Red Wings will win the Stanley Cup.

e) If you get the job, then you had the best credentials.

f) If there is a storm, then the beach erodes.

g) If you log on to the server, then you have a valid password.

h) If you do not begin your climb too late, then you will reach the summit. 

i) If you are among the first 100 customers tomorrow, then you will get a free ice cream cone.

### Question 38

a) $(p\lor q)\lor r$

| $p$ | $q$ | $r$ | $a\lor q$ | $(a\lor q)\lor r$ |
| --- | --- | --- | --------- | ----------------- |
| 0   | 0   | 0   | 0         | ０                 |
| 0   | 0   | 1   | 0         | １                 |
| 0   | 1   | 0   | 1         | 1                 |
| 0   | 1   | 1   | 1         | 1                 |
| 1   | 0   | 0   | 1         | 1                 |
| 1   | 0   | 1   | 1         | 1                 |
| 1   | 1   | 0   | 1         | 1                 |
| 1   | 1   | 1   | 1         | 1                 |

b) $(p\lor q)\land r$

| $p$ | $q$ | $r$ | $p\lor q$ | $(p\lor q)\land r$ |
| --- | --- | --- | --------- | ------------------ |
| 0   | 0   | 0   | 0         | 0                  |
| 0   | 0   | 1   | 0         | 0                  |
| 0   | 1   | 0   | 1         | 0                  |
| 0   | 1   | 1   | 1         | 1                  |
| 1   | 0   | 0   | 1         | 0                  |
| 1   | 0   | 1   | 1         | 1                  |
| 1   | 1   | 0   | 1         | 0                  |
| 1   | 1   | 1   | 1         | 1                  |

c) $(p\land q)\lor r$

| $p$ | $q$ | $r$ | $p\land q$ | $(p\land q)\lor r$ |
| --- | --- | --- | ---------- | ------------------ |
| 0   | 0   | 0   | 0          | 0                  |
| 0   | 0   | 1   | 0          | 1                  |
| 0   | 1   | 0   | 0          | 0                  |
| 0   | 1   | 1   | 0          | 1                  |
| 1   | 0   | 0   | 0          | 0                  |
| 1   | 0   | 1   | 0          | 1                  |
| 1   | 1   | 0   | 1          | 1                  |
| 1   | 1   | 1   | 1          | 1                  |

d) $(p\land q)\lor r$

| $p$ | $q$ | $r$ | $p\land q$ | $(p\land q)\lor r$ |
| --- | --- | --- | ---------- | ------------------ |
| 0   | 0   | 0   | 0          | 0                  |
| 0   | 0   | 1   | 0          | 1                  |
| 0   | 1   | 0   | 0          | 0                  |
| 0   | 1   | 1   | 0          | 1                  |
| 1   | 0   | 0   | 0          | 0                  |
| 1   | 0   | 1   | 0          | 1                  |
| 1   | 1   | 0   | 1          | 1                  |
| 1   | 1   | 1   | 1          | 1                  |

e) $(p\lor q)\land \neg r$

| $p$ | $q$ | $r$ | $\neg r$ | $(p\lor q)$ | $(p\lor q)\land \neg r$ |
| --- | --- | --- | -------- | ----------- | ----------------------- |
| 0   | 0   | 0   | 1        | 0           | 0                       |
| 0   | 0   | 1   | 0        | 0           | 0                       |
| 0   | 1   | 0   | 1        | 1           | 1                       |
| 0   | 1   | 1   | 0        | 1           | 0                       |
| 1   | 0   | 0   | 1        | 1           | 1                       |
| 1   | 0   | 1   | 0        | 1           | 0                       |
| 1   | 1   | 0   | 1        | 1           | 1                       |
| 1   | 1   | 1   | 0        | 1           | 0                       |

f) $(p\land q)\lor \neg r$

| $p$ | $q$ | $r$ | $\neg r$ | $(p\land q)$ | $(p\land q)\lor \neg r$ |
| --- | --- | --- | -------- | ------------ | ----------------------- |
| 0   | 0   | 0   | 1        | 0            | 1                       |
| 0   | 0   | 1   | 0        | 0            | 0                       |
| 0   | 1   | 0   | 1        | 0            | 1                       |
| 0   | 1   | 1   | 0        | 0            | 0                       |
| 1   | 0   | 0   | 1        | 0            | 1                       |
| 1   | 0   | 1   | 0        | 0            | 0                       |
| 1   | 1   | 0   | 1        | 1            | 1                       |
| 1   | 1   | 1   | 0        | 1            | 1                       |

### Question 42

![[Pasted image 20240910155311.png]]

Given $(p\lor \neg q) \land (q\lor \neg r)\land(r\lor \neg p)$

If $p \lor \neg q$ is $true$, then $p$ is $true$ or $q$ is $false$. 
If $q\lor \neg r$ is $true$, then $q$ is $true$ or $r$ is $false$. 
If $r \lor \neg p$ is $true$, then $r$ is $true$ or $p$ is $false$. 

If $p$ is $false$, then in order for $p \lor \neg q$ to be $true$, $q$ must be $false$. Otherwise, $p\lor \neg q$ will be $false$, and therefore $(p\lor \neg q) \land \dots$ must be $false$. This shows that if one value of $p$, $q$, or $r$ is $false$, all other values must be false in order for the entire statement to be $true$.

Similarly, if $p$ is $true$, then $p\lor \neg q$ must be true. This does not constrain the value of $q$. However, if $p$ is $true$, in order for $r\lor \neg p$ to be $true$, $r$ must be $true$. This reasoning can be extended to show that if $r$ is $true$, in order for $q \lor \neg r$ to be true, $q$ must also be true. In any other case where one of $p$, $q$ or $r$ does not have the same truth value as the others, $(p\lor \neg q)\land\dots$ must be $false$.

