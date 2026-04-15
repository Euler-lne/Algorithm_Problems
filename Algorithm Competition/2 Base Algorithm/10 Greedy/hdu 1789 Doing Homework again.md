以下是您要求的题目 **Doing Homework again** 的 Markdown 格式，包含英文原版和中文翻译。

---

# Doing Homework again

## English Version

**Time Limit**: 1000/1000 MS (Java/Others)  
**Memory Limit**: 32768/32768 K (Java/Others)  
**Total Submission(s)**: 30249  
**Accepted Submission(s)**: 17287  

### Problem Description

Ignatius has just come back school from the 30th ACM/ICPC. Now he has a lot of homework to do. Every teacher gives him a deadline of handing in the homework. If Ignatius hands in the homework after the deadline, the teacher will reduce his score of the final test. And now we assume that doing everyone homework always takes one day. So Ignatius wants you to help him to arrange the order of doing homework to minimize the reduced score.

### Input

The input contains several test cases. The first line of the input is a single integer T that is the number of test cases. T test cases follow.  
Each test case start with a positive integer N (1 ≤ N ≤ 1000) which indicates the number of homework. Then 2 lines follow. The first line contains N integers that indicate the deadlines of the subjects, and the next line contains N integers that indicate the reduced scores.

### Output

For each test case, you should output the smallest total reduced score, one line per test case.

### Sample Input

```
3
3
3 3 3
10 5 1
3
1 3 1
6 2 3
7
1 4 6 4 2 4 3
3 2 1 7 6 5 4
```

### Sample Output

```
0
3
5
```

---

## 中文翻译

### 问题描述

Ignatius 刚从第 30 届 ACM/ICPC 回到学校。现在他有很多作业要做。每位老师都给了他一个交作业的截止日期。如果 Ignatius 在截止日期之后才交作业，老师就会在期末考试成绩中扣掉一定的分数。我们假设每门作业都恰好需要一天时间完成。Ignatius 希望你帮他安排做作业的顺序，使得被扣掉的总分数最小。

### 输入

输入包含多个测试用例。第一行是一个整数 T，表示测试用例的数量。接下来有 T 个测试用例。  
每个测试用例的第一行是一个正整数 N（1 ≤ N ≤ 1000），表示作业的数量。  
随后两行：  
- 第一行包含 N 个整数，表示每门作业的截止日期；  
- 第二行包含 N 个整数，表示每门作业如果逾期会被扣掉的分数。

### 输出

对于每个测试用例，输出一行，包含最小的总扣分数。

### 样例输入

```
3
3
3 3 3
10 5 1
3
1 3 1
6 2 3
7
1 4 6 4 2 4 3
3 2 1 7 6 5 4
```

### 样例输出

```
0
3
5
```