# **Zuma**

## **Description**

Let's play the game Zuma!

There are a sequence of beads on a track at the right beginning. All the beads are colored but no three adjacent ones are allowed to be with a same color. You can then insert beads one by one into the sequence. Once three (or more) beads with a same color become adjacent due to an insertion, they will vanish immediately.

![Zuma](https://dsa.cs.tsinghua.edu.cn/oj/attachment/39d0/39d0c6d89d99f25f06b6217f2bba86ea4747dd49.png)

Note that it is possible for such a case to happen for more than once for a single insertion. You can't insert the next bead until all the eliminations have been done.

Given both the initial sequence and the insertion series, you are now asked by the fans to provide a playback tool for replaying their games. In other words, the sequence of beads after all possible eliminations as a result of each insertion should be calculated.

## **Input**

The first line gives the initial bead sequence. Namely, it is a string of capital letters from 'A' to 'Z', where different letters correspond to beads with different colors.

The second line just consists of a single interger n, i.e., the number of insertions.

The following n lines tell all the insertions in turn. Each contains an integer k and a capital letter Σ, giving the rank and the color of the next bead to be inserted respectively. Specifically, k ranges from 0 to m when there are currently m beads on the track.

## **Output**

n lines of capital letters, i.e., the evolutionary history of the bead sequence.

Specially, "-" stands for an empty sequence.

## **Example**

Input

>ACCBA<br>
>5<br>
>1 B<br>
>0 A<br>
>2 B<br>
>4 C<br>
>0 A<br>

Output

>ABCCBA<br>
>AABCCBA<br>
>AABBCCBA<br>
>-<br>
>A<br>


## **Restrictions**

0 <= n <= 10^4

0 <= length of the initial sequence <= 10^4

Time: 2 sec

Memory: 256 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1	|Correct	|10	|14600|
|2	|Correct	|10	|14600|
|3	|Correct	|9	|14600|
|4	|Correct	|8	|14600|
|5	|Correct	|9	|14600|
|6	|Correct	|10	|14600|
|7	|Correct	|8	|14600|
|8	|Correct	|8	|14600|
|9	|Correct	|10	|14600|
|10|	Correct|	11	|14600|
|11|	Correct|	15	|14600|
|12|	Correct|	12	|14600|
|13|	Correct|	6	|14600|
|14|	Correct|	118	|14600|
|15|	Correct|	12	|14732|
|16|	Correct|	184	|14732|
|17|	Correct|	137	|14864|
|18|	Correct|	148	|14732|
|19|	Correct|	155	|14864|
|20|	Exceed time limit|	≥2408	|15128|

