# **TSP**

## **Description**

Shrek is a postman working in the mountain, whose routine work is sending mail to n villages. Unfortunately, road between villages is out of repair for long time, such that some road is one-way road. There are even some villages that can’t be reached from any other village. In such a case, we only hope as many villages can receive mails as possible.

Shrek hopes to choose a village A as starting point (He will be air-dropped to this location), then pass by as many villages as possible. Finally, Shrek will arrived at village B. In the travelling process, each villages is only passed by once. You should help Shrek to design the travel route.

## **Input**

There are 2 integers, n and m, in first line. Stand for number of village and number of road respectively.

In the following m line, m road is given by identity of villages on two terminals. From v1 to v2. The identity of village is in range [1, n].

## **Output**

Output maximum number of villages Shrek can pass by.

## **Example**

Input

>4 3<br>
>1 4<br>
>2 4<br>
>4 3<br>

Output

>3<br>

## **Restrictions**

1 <= n <= 1,000,000

0 <= m <= 1,000,000

These is no loop road in the input.

Time: 2 sec

Memory: 256 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1|	Correct|	9|	12552|
|2|	Correct|	7|	12552|
|3|	Correct|	10|	12552|
|4|	Correct|	9|	12552|
|5|	Correct|	9|	12552|
|6|	Correct|	8|	12552|
|7|	Correct|	9|	14896|
|8|	Correct|	8|	12572|
|9|	Correct|	9|	12572|
|10|	Correct|	14|	12932|
|11|	Correct|	37|	13712|
|12|	Correct|	81|	16760|
|13|	Correct|	550|	30004|
|14|	Correct|	106|	22496|
|15|	Correct|	379|	29300|
|16|	Correct|	581|	39844|
|17|	Correct|	781|	46048|
|18|	Correct|	406|	30472|
|19|	Correct|	669|	46048|
|20|	Correct|	100|	19372|
