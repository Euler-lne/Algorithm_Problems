## 原文

**Aaronson**  
*Time Limit*: 4000/2000 MS (Java/Others)  
*Memory Limit*: 131072/131072 K (Java/Others)  

**Problem Description**  
Recently, Peter saw the equation  
\[
x_0 + 2x_1 + 4x_2 + \dots + 2^m x_m = n.
\]  
He wants to find a solution \((x_0, x_1, x_2, \dots, x_m)\) in such a manner that \(\sum_{i=0}^m x_i\) is minimum and every \(x_i\) \((0 \le i \le m)\) is non‑negative.

**Input**  
There are multiple test cases. The first line of input contains an integer \(T\) (\(1 \le T \le 10^5\)), indicating the number of test cases. For each test case:  

The first line contains two integers \(n\) and \(m\) (\(0 \le n, m \le 10^9\)).

**Output**  
For each test case, output the minimum value of \(\sum_{i=0}^m x_i\).

**Sample Input**  
```
10
1 2
3 2
5 2
10 2
10 3
10 4
13 5
20 4
11 11
12 3
```

**Sample Output**  
```
1
2
2
3
2
2
3
2
3
2
```

---

## 中文翻译

**题目：Aaronson**  

**问题描述**  
最近，Peter 看到了方程  
\[
x_0 + 2x_1 + 4x_2 + \dots + 2^m x_m = n.
\]  
他想找到一组解 \((x_0, x_1, x_2, \dots, x_m)\)，使得 \(\sum_{i=0}^m x_i\) 最小，并且每个 \(x_i\)（\(0 \le i \le m\)）都是非负整数。

**输入**  
输入包含多组测试用例。第一行是一个整数 \(T\)（\(1 \le T \le 10^5\)），表示测试用例的数量。对于每个测试用例：  

第一行包含两个整数 \(n\) 和 \(m\)（\(0 \le n, m \le 10^9\)）。

**输出**  
对于每个测试用例，输出最小的 \(\sum_{i=0}^m x_i\)。

**样例输入**  
```
10
1 2
3 2
5 2
10 2
10 3
10 4
13 5
20 4
11 11
12 3
```

**样例输出**  
```
1
2
2
3
2
2
3
2
3
2
```