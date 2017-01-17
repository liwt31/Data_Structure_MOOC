# **Train**

## **Description**

Figure 1 shows the structure of a station for train dispatching.

![Fig1](https://dsa.cs.tsinghua.edu.cn/oj/attachment/03bc/03bc70595803464554b5f6b69a21962beb038264.png)
Figure 1

In this station, A is the entrance for each train and B is the exit. S is the transfer end. All single tracks are one-way, which means that the train can enter the station from A to S, and pull out from S to B. Note that the overtaking is not allowed. Because the compartments can reside in S, the order that they pull out at B may differ from that they enter at A. However, because of the limited capacity of S, no more that m compartments can reside at S simultaneously.

Assume that a train consist of n compartments labeled {1, 2, …, n}. A dispatcher wants to know whether these compartments can pull out at B in the order of {a1, a2, …, an} (a sequence). If can, in what order he should operate it?

## **Input**

Two lines:

1st line: two integers n and m;

2nd line: n integers separated by spaces, which is a permutation of {1, 2, …, n}. This is a compartment sequence that is to be judged regarding the feasibility. 

## **Output**

If the sequence is feasible, output the sequence. “Push” means one compartment goes from A to S, while “pop” means one compartment goes from S to B. Each operation takes up one line.

If the sequence is infeasible, output a “no”. 

## **Example1**

Input

>5 2<br>
>1 2 3 5 4<br>

Output

>push<br>
>pop<br>
>push<br>
>pop<br>
>push<br>
>pop<br>
>push<br>
>push<br>
>pop<br>
>pop<br>

## **Example2**

Input

>5 5<br>
>3 1 2 4 5<br>

Output

>No<br>

## **Restrictions**

1 <= n <= 1,600,000

0 <= m <= 1,600,000

Time: 2 sec

Memory: 256 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1|	Correct|	8|	31308|
|2|	Correct|	9|	31308|
|3|	Correct|	7|	31308|
|4|	Correct|	7|	31308|
|5|	Correct|	6|	31308|
|6|	Correct|	8|	31308|
|7|	Correct|	8|	31308|
|8|	Correct|	10|	31308|
|9|	Correct|	8|	31308|
|10|	Correct|	9|	31308|
|11|	Correct|	16|	31560|
|12|	Correct|	23|	32072|
|13|	Correct|	46|	32840|
|14|	Correct|	100|	34376|
|15|	Correct|	95|	32072|
|16|	Correct|	37|	32072|
|17|	Correct|	324|	31812|
|18|	Correct|	438|	55880|
|19|	Correct|	440|	55880|
|20|	Correct|	791|	55880|

