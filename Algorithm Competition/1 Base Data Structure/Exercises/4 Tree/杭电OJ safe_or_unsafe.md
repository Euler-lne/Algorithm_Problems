## Problem Description
Javac++ 一天在看计算机的书籍的时候，看到了一个有趣的东西！每一串字符都可以被编码成一些数字来储存信息，但是不同的编码方式得到的储存空间是不一样的！并且当储存空间大于一定的值的时候是不安全的！所以Javac++ 就想是否有一种方式是可以得到字符编码最小的空间值！显然这是可以的，因为书上有这一块内容--哈夫曼编码(Huffman Coding)；一个字母的权值等于该字母在字符串中出现的频率。所以Javac++ 想让你帮忙，给你安全数值和一串字符串，并让你判断这个字符串是否是安全的？
 

## Input
输入有多组case，首先是一个数字n表示有n组数据，然后每一组数据是有一个数值m(integer)，和一串字符串没有空格只有包含小写字母组成！
 

## Output
如果字符串的编码值小于等于给定的值则输出yes，否则输出no。
 

## Sample Input
2
12
helloworld
66
ithinkyoucandoit
 

## Sample Output
no
yes
 

## Source
HDU 2008-10 Programming Contest