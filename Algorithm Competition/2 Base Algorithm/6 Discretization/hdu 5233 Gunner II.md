# Gunner II

## Problem Description
Long long ago, there was a gunner whose name is Jack. He likes to go hunting very much. One day he go to the grove. There are n birds and n trees. The i-th bird stands on the top of the i-th tree. The trees stand in straight line from left to the right. Every tree has its height. Jack stands on the left side of the left most tree. When Jack shots a bullet in height H to the right, the nearest bird which stands in the tree with height H will falls.

Jack will shot many times, he wants to know which bird will fall during each shot.
 

## Input
There are multiple test cases (about 5), every case gives n, m in the first line, n indicates there are n trees and n birds, m means Jack will shot m times.

In the second line, there are n numbers h[1],h[2],h[3],…,h[n] which describes the height of the trees.

In the third line, there are m numbers q[1],q[2],q[3],…,q[m] which describes the height of the Jack’s shots.

Please process to the end of file.

[Technical Specification]

All input items are integers.

1<=n,m<=100000(10^5)

1<=h[i],q[i]<=1000000000(10^9)
 

## Output
For each q[i], output an integer in a single line indicates the id of bird Jack shots down. If Jack can’t shot any bird, just output -1.

The id starts from 1.
 

## Sample Input
```
5 5
1 2 3 4 1
1 3 1 4 2
```

## Sample Output
```
1
3
5
4
2
```

## 枪手 II

### 问题描述
很久以前，有一个名叫杰克的枪手。他非常喜欢打猎。一天，他去了树林。有 n 只鸟和 n 棵树。第 i 只鸟站在第 i 棵树的树顶上。这些树从左到右排成一条直线。每棵树都有其高度。杰克站在最左边树的左侧。当杰克向右侧以高度 H 开枪时，会击中最近的那只站在高度为 H 的树上的鸟。

杰克会射击多次，他想知道每次射击中哪只鸟会掉下来。

### 输入
有多个测试用例（大约 5 个），每个测试用例的第一行给出 n 和 m，n 表示有 n 棵树和 n 只鸟，m 表示杰克将射击 m 次。

第二行有 n 个数 h[1], h[2], h[3], …, h[n]，表示树的高度。

第三行有 m 个数 q[1], q[2], q[3], …, q[m]，表示杰克每次射击的高度。

处理到文件结束。

[技术规格]
所有输入项均为整数。
1 ≤ n, m ≤ 100000 (10^5)
1 ≤ h[i], q[i] ≤ 1000000000 (10^9)

### 输出
对于每个 q[i]，输出一行一个整数，表示杰克击落的鸟的编号。如果杰克没有击中任何鸟，则输出 -1。

编号从 1 开始。

### 样例输入
```
5 5
1 2 3 4 1
1 3 1 4 2
```

### 样例输出
```
1
3
5
4
2
```