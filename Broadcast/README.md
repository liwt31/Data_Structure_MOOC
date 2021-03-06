# **Broadcast**

## **Description**

某广播公司要在一个地区架设无线广播发射装置。该地区共有n个小镇，每个小镇都要安装一台发射机并播放各自的节目。

不过，该公司只获得了FM104.2和FM98.6两个波段的授权，而使用同一波段的发射机会互相干扰。已知每台发射机的信号覆盖范围是以它为圆心，20km为半径的圆形区域，因此，如果距离小于20km的两个小镇使用同样的波段，那么它们就会由于波段干扰而无法正常收听节目。现在给出这些距离小于20km的小镇列表，试判断该公司能否使得整个地区的居民正常听到广播节目。

## **Input**

第一行为两个整数n，m，分别为小镇的个数以及接下来小于20km的小镇对的数目。 接下来的m行，每行2个整数，表示两个小镇的距离小于20km（编号从1开始）。

## **Output**

如果能够满足要求，输出1，否则输出-1。

## **Example**

Input

>4 3<br>
>1 2<br>
>1 3<br>
>2 4<br>

Output

>1<br>

## **Restrictions**

1 ≤ n ≤ 10000

1 ≤ m ≤ 30000

不需要考虑给定的20km小镇列表的空间特性，比如是否满足三角不等式，是否利用传递性可以推出更多的信息等等。

时间：2 sec

空间：256MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1|	Correct|	17|	12552|
|2|	Correct|	10|	12552|
|3|	Correct|	11|	12564|
|4|	Correct|	10|	12564|
|5|	Correct|	10|	12564|
|6|	Correct|	42|	14560|
|7|	Correct|	39|	14560|
|8|	Correct|	36|	14560|
|9|	Correct|	35|	14560|
|10|	Correct|	37|	14560|

