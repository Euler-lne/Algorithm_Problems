# Monitor


## Problem Description
Xiaoteng has a large area of land for growing crops, and the land can be seen as a rectangle of n×m.

But recently Xiaoteng found that his crops were often stolen by a group of people, so he decided to install some monitors to find all the people and then negotiate (谈判；协商；磋商；商定) with them.

However, Xiao Teng bought bad monitors, each monitor can only monitor the crops inside a rectangle. There are p monitors installed by Xiaoteng, and the rectangle monitored by each monitor is known.

Xiao Teng guess that the thieves would also steal q times of crops. he also guessed the range they were going to steal, which was also a rectangle. Xiao Teng wants to know if his monitors can see all the thieves at a time.
 

## Input
There are mutiple test cases.

Each case starts with a line containing two integers n,m(1≤n,1≤m,n×m≤107) which represent the area of the land.

And the secend line contain a integer p(1≤p≤106) which represent the number of the monitor Xiaoteng has installed. This is followed by p lines each describing a rectangle. Each of these lines contains four intergers x1,y1,x2 and y2(1≤x1≤x2≤n,1≤y1≤y2≤m) ,meaning the lower left corner and upper right corner of the rectangle.

Next line contain a integer q(1≤q≤106) which represent the number of times that thieves will steal the crops.This is followed by q lines each describing a rectangle. Each of these lines contains four intergers x1,y1,x2 and y2(1≤x1≤x2≤n,1≤y1≤y2≤m),meaning the lower left corner and upper right corner of the rectangle.
 

## Output
For each case you should print q lines.

Each line containing YES or NO mean the all thieves whether can be seen.
 

## Sample Input
```
6 6
3
2 2 4 4
3 3 5 6
5 1 6 2
2
3 2 5 4
1 5 6 5
```

## Sample Output
```
YES
NO
```
 

## Hint
In the picture,the red solid rectangles mean the monitor Xiaoteng installed, and the blue dotted rectangles mean the area will be stolen.
![alt text](<img/hdu 6514 Monitor.png>)
