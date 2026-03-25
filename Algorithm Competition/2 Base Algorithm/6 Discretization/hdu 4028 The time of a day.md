# The time of a day



## Problem Description
There are no days and nights on byte island, so the residents here can hardly determine the length of a single day. Fortunately, they have invented a clock with several pointers. They have N pointers which can move round the clock. Every pointer ticks once per second, and the i-th pointer move to the starting position after i times of ticks. The wise of the byte island decide to define a day as the time interval between the initial time and the first time when all the pointers moves to the position exactly the same as the initial time.
The wise of the island decide to choose some of the N pointers to make the length of the day greater or equal to M. They want to know how many different ways there are to make it possible.
 

## Input
There are a lot of test cases. The first line of input contains exactly one integer, indicating the number of test cases.
  For each test cases, there are only one line contains two integers N and M, indicating the number of pointers and the lower bound for seconds of a day M. (1 <= N <= 40, 1 <= M <= 263-1)
 

## Output
For each test case, output a single integer denoting the number of ways.
 

## Sample Input
```
3
5 5
10 1
10 128
```

## Sample Output
```
Case #1: 22
Case #2: 1023
Case #3: 586
```

## 一天的时间

### 问题描述
字节岛上没有白天和黑夜，因此这里的居民很难确定一天的长度。幸运的是，他们发明了一种带有若干指针的时钟。他们拥有 N 个可以绕钟面转动的指针。每个指针每秒跳动一次，第 i 个指针经过 i 次跳动后回到起始位置。岛上的智者决定将一天定义为从初始时刻到所有指针首次同时回到初始位置所经过的时间间隔。

岛上的智者希望选择其中一些指针，使得一天的长度大于或等于 M。他们想知道有多少种不同的选择方式可以实现这一点。

### 输入
有多组测试数据。输入的第一行包含一个整数，表示测试用例的数量。  
对于每个测试用例，仅有一行包含两个整数 N 和 M，分别表示指针的数量和一天长度的下界（以秒为单位）。(1 ≤ N ≤ 40, 1 ≤ M ≤ 2^63 - 1)

### 输出
对于每个测试用例，输出一个整数，表示满足条件的选择方式的数量。

### 样例输入
```
3
5 5
10 1
10 128
```

### 样例输出
```
Case #1: 22
Case #2: 1023
Case #3: 586
```