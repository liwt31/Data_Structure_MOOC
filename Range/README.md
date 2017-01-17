# **Range**

## **Description**

Let S be a set of n integral points on the x-axis. For each given interval [a, b], you are asked to count the points lying inside.

## **Input**

The first line contains two integers: n (size of S) and m (the number of queries).

The second line enumerates all the n points in S.

Each of the following m lines consists of two integers a and b and defines an query interval [a, b].

## **Output**

The number of points in S lying inside each of the m query intervals.

## **Example**

Input

>5 2<br>
>1 3 7 9 11<br>
>4 6<br>
>7 12<br>

Output

>0<br>
>3<br>


## **Restrictions**

0 <= n, m <= 5 * 10^5

For each query interval [a, b], it is guaranteed that a <= b.

Points in S are distinct from each other.

Coordinates of each point as well as the query interval boundaries a and b are non-negative integers not greater than 10^7.

Time: 2 sec

Memory: 256 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1	|Correct|	18	|12552|
|2	|Correct|	11	|12552|
|3	|Wrong answer|	10	|12552|
|4	|Wrong answer|	11	|12552|
|5	|Correct|	10	|12552|
|6	|Correct|	9	|12552|
|7	|Correct|	10	|12552|
|8	|Correct|	9	|12552|
|9	|Correct|	10	|12552|
|10|Correct|	10	|12552|
|11|Correct|	9	|12552|
|12|Correct	|152	|12788|
|13|Correct	|150	|13024|
|14|Correct	|115	|13024|
|15|Correct	|260	|13136|
|16|Correct	|311	|13576|
|17|Correct	|473	|13776|
|18|Correct	|458	|13916|
|19|Wrong answer	|787	|15972|
|20|Correct	|1157	|15972|

