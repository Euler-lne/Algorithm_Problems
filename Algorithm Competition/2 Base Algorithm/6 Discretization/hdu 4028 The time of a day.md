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