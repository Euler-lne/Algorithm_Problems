## Problem Description
Yellowstar is writing an article that contains N words and 1 picture, and the i-th word contains ai characters.
The page width is fixed to W characters. In order to make the article look more beautiful, Yellowstar has made some rules:

1. The fixed width of the picture is pw. The distance from the left side of the page to the left side of the photo fixed to dw, in other words, the left margin is dw, and the right margin is W - pw - dw.
2. The photo and words can't overlap, but can exist in same line.
3. The relative order of words cannot be changed.
4. Individual words need to be placed in a line.
5. If two words are placed in a continuous position on the same line, then there is a space between them.
6. Minimize the number of rows occupied by the article according to the location and height of the image.

![alt text](img/image.png)

However, Yellowstar has not yet determined the location of the picture and the height of the picture, he would like to try Q different locations and different heights to get the best look. Yellowstar tries too many times, he wants to quickly know the number of rows each time, so he asked for your help. It should be noted that when a row contains characters or pictures, the line was considered to be occupied.

 

## Input
The first line of the input gives the number of test cases T; T test cases follow.
Each case begins with one line with four integers N, W, pw, dw : the number of words, page width, picture width and left margin.
The next line contains N integers ai, indicates i-th word consists of ai characters.
The third line contains one integer Q.
Then Q lines follow, each line contains the values of xi and hi, indicates the starting line and the image height of the image.

### Limits
T≤10
1≤N,W,Q≤105
1≤pw,ai≤W
0≤dw≤W−pw
 

## Output
For each query, output one integer denotes the minimum number of rows.
 

## Sample Input
```
2
2 7 4 3
1 3
3
1 2
2 2
5 2
3 8 2 3
1 1 3
1
1 1
```

## Sample Output
```
2
3
3
1
```