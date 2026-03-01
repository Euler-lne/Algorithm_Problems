# Color the Ball

## Problem Description
There are infinite (无限的) balls in a line (numbered 1 2 3 ....), and initially (最初) all of them are paint black. Now Jim use a brush paint the balls, every time give two integers a b and follow by a char 'w' or 'b', 'w' denotes the ball from a to b are painted white, 'b' denotes that be painted black. You are ask to find the longest white ball sequence.
 

## Input
First line is an integer N (<=2000), the times Jim paint, next N line contain a b c, c can be 'w' and 'b'.

There are multiple cases, process to the end of file.
 

## Output
Two integers the left end of the longest white ball sequence and the right end of longest white ball sequence (If more than one output the small number one). All the input are less than 2^31-1. If no such sequence exists, output "Oh, my god".
 

## Sample Input
```
3
1 4 w
8 11 w
3 5 b
``` 

## Sample Output
```
8 11
```