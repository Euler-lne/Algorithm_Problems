## Problem Description
Hakase has n numbers in a line. At first, they are all equal to 1. Besides, Hakase is interested in primes. She will choose a continuous subsequence [l,r] and a prime parameter x each time and for every l≤i≤r, she will change ai into ai×x. To simplify the problem, x will be 2 or 3. After m operations, Hakase wants to know what is the greatest common divisor of all the numbers.
 

## Input
The first line contains an integer T(1≤T≤10) representing the number of test cases.

For each test case, the first line contains two integers
n(1≤n≤100000) and m(1≤m≤100000), where n refers to the length of the whole sequence and m means there are m operations.

The following m lines, each line contains three integers li(1≤li≤n),ri(1≤ri≤n),xi(xi∈2,3), which are referred above.
 

## Output
For each test case, print an integer in one line, representing the greatest common divisor of the sequence. Due to the answer might be very large, print the answer modulo 998244353.
 

## Sample Input
```
2
5 3
1 3 2
3 5 2
1 5 3
6 3
1 2 2
5 6 2
1 6 2
 ```

## Sample Output
```
6
2
 ```

### Hint
For the first test case, after all operations, the numbers will be [6,6,12,6,6]. So the greatest common divisor is 6.