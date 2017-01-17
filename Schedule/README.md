# **Schedule**

## **Description**

A HPS cluster is equipped with a unique task scheduler. To be simple, it is assumed that this cluster doesn’t support multiple tasks running at the same time, such that only one task is allowed to be in running state at any moment. Initially, the priority of ever task is denoted by an integer which is called priority number. **The smaller priority number stands for high priority. If two tasks have same task number, the priority is decided in the ASCII order of task name.** Following this policy, resources, such as CPU, are always occupied by the task with minimum priority number. When one task is finished, the one with minimum priority number in the rest tasks is picked to execute. The finished task won’t quit immediately. The priority number is doubled and put back to the task set. Once the priority number is greater or equal to 2^32, this task is deleted from the task set.

Given initial priority setting of every task, your job is to predict the running order of a batch of tasks. 

## **Input**

First line contains two integers, says n and m. n stands for the number of tasks in initial state. m stands for the length of predicted sequence. Every line is ended by a line break symbol. In each one of the following n lines, an integer and a string are included. This string is shorter than 8, which only contains lowercase letters and numbers. The integer is priority number and the string is the task name. The integer and string is separated by space. 

## **Output**

At most m lines, each one contains a string. Output the name of tasks according to the order that tasks are executed. If the number of executed tasks is less than m, then output all the executed tasks.

## **Example**

Input

>3 3<br>
>1 hello<br>
>2 world<br>
>10 test<br>

Output

>hello<br>
>hello<br>
>world<br>

## **Restrictions**

0 <= n <= 4,000,000

0 <= m <= 2,000,000

0 < Priority number < 2^32

No tasks have same name

Time: 2 sec

Memory: 512 MB

## **Result**

|Case No.	|Result|	Time(ms)|	Memory(KB)|
|:---|:-----|:----|:----|
|1|	Correct|	10|	14604|
|2|	Correct|	11|	14604|
|3|	Correct|	8|	14604|
|4|	Correct|	8|	14604|
|5|	Correct|	9|	14604|
|6|	Correct|	8|	14604|
|7|	Correct|	7|	14604|
|8|	Correct|	17|	14604|
|9|	Correct|	261|	22420|
|10|	Correct|	359|	27108|
|11|	Correct|	551|	30232|
|12|	Correct|	741|	38044|
|13|	Correct|	862|	45856|
|14|	Correct|	1321|	61480|
|15|	Correct|	1150|	45856|
|16|	Correct|	949|	48980|
|17|	Correct|	1305|	53668|
|18|	Correct|	1216|	61480|
|19|	Correct|	1626|	69292|
|20|	Correct|	1531|	69292|

