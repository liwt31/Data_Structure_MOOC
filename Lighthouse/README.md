# **Lighthouse**

## **Description**

As shown in the following figure, If another lighthouse is in gray area, they can beacon each other. 

![Lighthouse1](https://dsa.cs.tsinghua.edu.cn/oj/attachment/c6c8/c6c8562b88ed7fd518cacf0264ae624f59598ed7.png)

For example, in following figure, (B, R) is a pair of lighthouse which can beacon each other, while (B, G), (R, G) are NOT. 

![Lighthouse2](https://dsa.cs.tsinghua.edu.cn/oj/attachment/9d7f/9d7f16b4bddbee9795e12ba22fd7f88af5438aa6.png)

## **Input**

1st line: N

2nd ~ (N + 1)th line: each line is X Y, means a lighthouse is on the point (X, Y).

## **Output**

How many pairs of lighthourses can beacon each other

( For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same )

## **Example**

Input

>3<br>
>2 2<br>
>4 3<br>
>5 1<br>

Output

>1<br>

## **Restrictions**

For 90% test cases: 1 <= n <= 3 * 105

For 95% test cases: 1 <= n <= 106

For all test cases: 1 <= n <= 4 * 106

For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same.

1 <= x, y <= 10^8

Time: 2 sec

Memory: 256 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1	|Correct|	11	|12556|
|2	|Correct|	8	|12556|
|3	|Correct|	9	|12556|
|4	|Correct|	9	|12556|
|5	|Correct|	8	|12556|
|6	|Correct|	8	|12556|
|7	|Correct|	8	|12556|
|8	|Correct|	8	|12556|
|9	|Correct|	10	|12568|
|10|	Correct|	87	|13260|
|11|	Correct|	126	|13652|
|12|	Correct|	131	|13920|
|13|	Correct|	155	|14056|
|14|	Correct|	163	|14196|
|15|	Correct|	184	|14468|
|16|	Correct|	210	|14744|
|17|	Correct|	245	|15012|
|18|	Correct|	396	|16652|
|19|	Correct|	862	|26228|
|20|	Exceed time limit|	≥2202	|43672|

