## Problem Description
In Land waterless, water is a very limited resource. People always fight for the biggest source of water. Given a sequence of water sources with a1,a2,a3,...,an representing the size of the water source. Given a set of queries each containing 2 integers l and r, please find out the biggest water source between al and ar.
 

## Input
First you are given an integer T(T≤10) indicating the number of test cases. For each test case, there is a number n(0≤n≤1000) on a line representing the number of water sources. n integers follow, respectively a1,a2,a3,...,an, and each integer is in {1,...,106}. On the next line, there is a number q(0≤q≤1000) representing the number of queries. After that, there will be q lines with two integers l and r(1≤l≤r≤n) indicating the range of which you should find out the biggest water source.
 

## Output
For each query, output an integer representing the size of the biggest water source.
 

## Sample Input
```
3
1
100
1
1 1
5
1 2 3 4 5
5
1 2
1 3
2 4
3 4
3 5
3
1 999999 1
4
1 1
1 2
2 3
3 3
```

## Sample Output
```
100
2
3
4
4
5
1
999999
999999
1
```