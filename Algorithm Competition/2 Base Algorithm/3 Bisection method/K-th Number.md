## Problem Description
Alice are given an array A[1..N] with N numbers.

Now Alice want to build an array B by a parameter K as following rules:

Initially, the array B is empty. Consider each interval in array A. If the length of this interval is less than K, then ignore this interval. Otherwise, find the K-th largest number in this interval and add this number into array B.

In fact Alice doesn't care each element in the array B. She only wants to know the M-th largest element in the array B. Please help her to find this number.
 

## Input
The first line is the number of test cases.

For each test case, the first line contains three positive numbers N(1≤N≤105),K(1≤K≤N),M. The second line contains N numbers Ai(1≤Ai≤109).

It's guaranteed that M is not greater than the length of the array B.
 

## Output
For each test case, output a single line containing the M-th largest element in the array B.
 

## Sample Input
```
2
5 3 2
2 3 1 5 4
3 3 1
5 8 2
```

## Sample Output
```
3
2
```