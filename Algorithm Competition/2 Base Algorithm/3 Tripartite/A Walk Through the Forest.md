## Problem Description
Jimmy experiences a lot of stress at work these days, especially since his accident made working difficult. To relax after a hard day, he likes to walk home. To make things even nicer, his office is on one side of a forest, and his house is on the other. A nice walk through the forest, seeing the birds and chipmunks is quite enjoyable.
The forest is beautiful, and Jimmy wants to take a different route everyday. He also wants to get home before dark, so he always takes a path to make progress towards his house. He considers taking a path from A to B to be progress if there exists a route from B to his home that is shorter than any possible route from A. Calculate how many different routes through the forest Jimmy might take.
 

## Input
Input contains several test cases followed by a line containing 0. Jimmy has numbered each intersection or joining of paths starting with 1. His office is numbered 1, and his house is numbered 2. The first line of each test case gives the number of intersections N, 1 < N ≤ 1000, and the number of paths M. The following M lines each contain a pair of intersections a b and an integer distance 1 ≤ d ≤ 1000000 indicating a path of length d between intersection a and a different intersection b. Jimmy may walk a path any direction he chooses. There is at most one path between any pair of intersections.
 

## Output
For each test case, output a single integer indicating the number of different routes through the forest. You may assume that this number does not exceed 2147483647
 

## Sample Input
```
5 6
1 3 2
1 4 2
3 4 3
1 5 12
4 2 34
5 2 24
7 8
1 3 1
1 4 1
3 7 1
7 4 1
7 5 1
6 7 1
5 2 1
6 2 1
0
``` 

## Sample Output
```
2
4
```



题目大意：求最短路，不过有限制条件，英文题搞不太明白，最短路又不熟，，， 2 为终点，1 为起点，问题是求从 1 到 2 的路径的条数，但是有个要求就是要想走a到b这一条路，必须b到终点的最短路径小于a到终点的最短路，思路是先从终点 2 求单源最短路，之后从起点 1 开始DFS,进行记忆化搜索找路的条数，搜索的条件就是map[a][b]!=INF&&d[a]>d[b].因为得保证a b之间有路可走