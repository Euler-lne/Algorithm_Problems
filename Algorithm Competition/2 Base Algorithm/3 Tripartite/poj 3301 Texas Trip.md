# Description

After a day trip with his friend Dick, Harry noticed a strange pattern of tiny holes in the door of his SUV. The local American Tire store sells fiberglass patching material only in square sheets. What is the smallest patch that Harry needs to fix his door?

Assume that the holes are points on the integer lattice in the plane. Your job is to find the area of the smallest square that will cover all the holes.

在与朋友迪克进行了一天的旅行后，哈利注意到他的 SUV 车门上有一个奇怪的小孔图案。当地的美国轮胎商店只出售方形玻璃纤维修补材料。哈利需要修理的最小修补块是什么？

假设这些小孔是平面上整数格子上的点。你的任务是找到能够覆盖所有小孔的最小正方形面积。

# Input

The first line of input contains a single integer T expressed in decimal with no leading zeroes, denoting the number of test cases to follow. The subsequent lines of input describe the test cases.

Each test case begins with a single line, containing a single integer n expressed in decimal with no leading zeroes, the number of points to follow; each of the following n lines contains two integers x and y, both expressed in decimal with no leading zeroes, giving the coordinates of one of your points.

You are guaranteed that T ≤ 30 and that no data set contains more than 30 points. All points in each data set will be no more than 500 units away from (0,0).

输入的第一行包含一个单独的整数 T, 以十进制表示，前面没有零，表示接下来的测试用例数。后续输入行描述了测试用例。

每个测试用例都从一行开始，包含一个单独的整数 n, 用十进制表示，前面没有零，表示要跟随的点数；以下 n 行中的每一行都包含两个整数 x 和 y, 都用十进制表示，前面没有 0, 表示其中一个点的坐标。

保证 T≤30, 且数据集不包含超过 30 个点。每个数据集中的所有点距离 (0,0) 不超过 500 个单位。

# Output

Print, on a single line with two decimal places of precision, the area of the smallest square containing all of your points.

在一条带有两位小数精度的线上，打印出包含所有点的最小正方形的面积。

# Sample Input
```
2
4
-1 -1
1 -1
1 1
-1 1
4
10 1
10 -1
-10 1
-10 -1
```
# Sample Output
```
4.00
242.00
```