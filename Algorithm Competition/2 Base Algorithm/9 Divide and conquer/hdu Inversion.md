# Inversion

## Problem Description
bobo has a sequence a1,a2,…,an. He is allowed to swap two adjacent numbers for no more than k times.

Find the minimum number of inversions after his swaps.

Note: The number of inversions is the number of pair (i,j) where 1≤i<j≤n and ai>aj.
 

## Input
The input consists of several tests. For each tests:

The first line contains 2 integers n,k (1≤n≤105,0≤k≤109). The second line contains n integers a1,a2,…,an (0≤ai≤109).
 

## Output
For each tests:

A single integer denotes the minimum number of inversions.
 

## Sample Input
```
3 1
2 2 1
3 0
2 2 1
``` 

## Sample Output
```
1
2
```

**题目描述**

bobo 有一个序列 a₁, a₂, …, aₙ。他可以进行不超过 k 次操作，每次操作可以交换两个相邻的元素。

求经过最多 k 次交换后，序列的逆序对数量最少可以是多少。

注：逆序对定义为满足 1 ≤ i < j ≤ n 且 aᵢ > aⱼ 的数对 (i, j) 的数量。

**输入格式**

输入包含多个测试用例。对于每个测试用例：

- 第一行包含两个整数 n, k（1 ≤ n ≤ 10⁵，0 ≤ k ≤ 10⁹）。
- 第二行包含 n 个整数 a₁, a₂, …, aₙ（0 ≤ aᵢ ≤ 10⁹）。

**输出格式**

对于每个测试用例，输出一行一个整数，表示经过最多 k 次交换后，能得到的最小的逆序对数量。

**样例输入**

```
3 1
2 2 1
3 0
2 2 1
```

**样例输出**

```
1
2
```