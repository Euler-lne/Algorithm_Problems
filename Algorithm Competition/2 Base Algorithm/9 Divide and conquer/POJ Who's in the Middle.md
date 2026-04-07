# Who's in the Middle

## Description

FJ is surveying his herd to find the most average cow. He wants to know how much milk this 'median' cow gives: half of the cows give as much or more than the median; half give as much or less.

Given an odd number of cows N (1 <= N < 10,000) and their milk output (1..1,000,000), find the median amount of milk given such that at least half the cows give the same amount of milk or more and at least half give the same or less.
## Input

* Line 1: A single integer N

* Lines 2..N+1: Each line contains a single integer that is the milk output of one cow.
## Output

* Line 1: A single integer that is the median milk output.
## Sample Input
```
5
2
4
1
3
5
```
## Sample Output
```
3
```

**题目描述**

FJ 正在调查他的牛群，以找出最「平均」的那头奶牛。他想知道这头「中位数」奶牛的产奶量：一半的奶牛产奶量大于等于中位数，另一半的产奶量小于等于中位数。

给定奇数 N（1 ≤ N < 10,000）和每头奶牛的产奶量（1 ≤ 产奶量 ≤ 1,000,000），请找出中位数，使得至少一半的奶牛产奶量大于等于该值，且至少一半的奶牛产奶量小于等于该值。

**输入格式**

* 第 1 行：一个整数 N
* 第 2 至 N+1 行：每行一个整数，表示一头奶牛的产奶量

**输出格式**

* 第 1 行：一个整数，即中位产奶量

**样例输入**

```
5
2
4
1
3
5
```

**样例输出**

```
3
```