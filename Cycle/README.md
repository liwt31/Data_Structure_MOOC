# **Cycle**

## **Description**

Cycle shifting refers to following operation on the sting. Moving first letter to the end and keeping rest part of the string. For example, apply cycle shifting on ABCD will generate BCDA. Given any two strings, to judge if arbitrary times of cycle shifting on one string can generate the other one. 

## **Input**

There m lines in the input, while each one consists of two strings separated by space. Each string only contains uppercase letter 'A'~'Z'. 

## **Output**

For each line in input, output YES in case one string can be transformed into the other by cycle shifting, otherwise output NO.

## **Example**

Input

>AACD CDAA<br>
>ABCDEFG EFGABCD<br>
>ABCD ACBD<br>
>ABCDEFEG ABCDEE<br>

Output

>YES<br>
>YES<br>
>NO<br>
>NO<br>


## **Restrictions**

0 <= m <= 5000

1 <= |S1|, |S2| <= 10^5

Time: 2 sec

Memory: 256 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1|	Correct|	11|	14696|
|2|	Correct|	8|	14696|
|3|	Correct|	10|	14696|
|4|	Correct|	8|	14696|
|5|	Correct|	9|	14696|
|6|	Correct|	6|	14696|
|7|	Correct|	9|	14696|
|8|	Correct|	64|	14696|
|9|	Correct|	86|	14696|
|10|	Correct|	203|	14696|

