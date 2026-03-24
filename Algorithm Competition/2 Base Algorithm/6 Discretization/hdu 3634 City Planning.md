# City Planning


## Problem Description
After many years, the buildings in HDU has become very old. It need to rebuild the buildings now. So Mr dragon (the president of HDU's logistics department ) ask Mr Wan (a very famous engineer) for help.
Mr Wan only draw one building on a construction design drawings(all the buildings are rectangle and each edge of buildings' is paraller or perpendicular to others buildings' edge 建筑物的每一边都与其他建筑物的边平行或垂直 ). And total draw n drawings (all the drawings have same width and length . And bottomleft point is (0, 0)). Due to possible overlap of conditions, so when they build a new building, they should to remove all the overlapping part of it. And for each building, HDU have a jury evaluate the value per unit area. Now Mr dragon want to know how to arrange the order of build these buildings can make the highest value.
 

## Input
The first line of input is a number T which indicate the number of cases . (1 < T < 3000);
Each test case will begin with a single line containing a single integer n (where 1 <= n <= 20).
Next n line will contain five integers x1, y1, x2, y2 ,value . x1,y1 is bottomleft point and x2,y2 is topright point , value is the value of the buildings' unit area.(0 <= x1, y1, x2, y2 <= 10000) (x1 < x2, && y1 < y2) (1 <= value <= 22)
 

## Output
For each case. You just ouput the highest value in one line.
 

## Sample Input
```
1
3
1 1 10 10 4
4 4 15 5 5
7 8 20 30 6
 ```

## Sample Output
```
Case 1: 2047
```