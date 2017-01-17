# **Proper Rebuild**

## **Description**

In general, given the preorder traversal sequence and postorder traversal sequence of a binary tree, we cannot determine the binary tree.

![Fig1](https://dsa.cs.tsinghua.edu.cn/oj/attachment/7c7a/7c7a319cffe20865fa728afcdfccbccac25eeb46.png)

Figure 1

In Figure 1 for example, although they are two different binary tree, their preorder traversal sequence and postorder traversal sequence are both of the same.

But for one proper binary tree, in which each internal node has two sons, we can uniquely determine it through its given preorder traversal sequence and postorder traversal sequence.

Label n nodes in one binary tree using the integers in [1, n], we would like to output the inorder traversal sequence of a binary tree through its preorder and postorder traversal sequence. 

## **Input**

The 1st line is an integer n, i.e., the number of nodes in one given binary tree,

The 2nd and 3rd lines are the given preorder and postorder traversal sequence respectively.

## **Output**

The inorder traversal sequence of the given binary tree in one line.

## **Example**

Input

>5<br>
>1 2 4 5 3<br>
>4 5 2 3 1<br>

Output

>4 2 5 1 3<br>

## **Restrictions**

For 95% of the estimation, 1 <= n <= 1,000,00

For 100% of the estimation, 1 <= n <= 4,000,000

The input sequence is a permutation of {1,2...n}, corresponding to a legal binary tree.

Time: 2 sec

Memory: 256 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1|	Correct|	10|	14604|
|2|	Correct|	7|	14604|
|3|	Correct|	6|	14604|
|4|	Correct|	6|	14604|
|5|	Correct|	5|	14604|
|6|	Correct|	5|	14604|
|7|	Correct|	8|	14604|
|8|	Correct|	5|	14604|
|9|	Correct|	9|	14604|
|10|	Correct|	10|	14604|
|11|	Correct|	10|	14604|
|12|	Correct|	72|	16568|
|13|	Correct|	132|	18008|
|14|	Correct|	235|	21752|
|15|	Correct|	247|	22136|
|16|	Correct|	415|	28344|
|17|	Correct|	411|	28120|
|18|	Correct|	313|	24632|
|19|	Correct|	457|	28776|
|20|	Correct|	1280|	64440|
