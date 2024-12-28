// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 * @lcpr version=21913
 *
 * [2596] 检查骑士巡视方案
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        int route[8][2] = {{2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}};
        int n = grid[0].size();
        int x = 0, y = 0;
        int isEqule = 1;
        if(grid[0][0])
            return false;
        for (int key = 0; key < n * n - 1; key++)
        {
            isEqule = 1;
            for (int i = 0; i < 8; i++)
            {
                int x_ = (route[i][0] + x >= 0 && route[i][0] + x <= n - 1) ? route[i][0] + x : x;
                int y_ = (route[i][1] + y >= 0 && route[i][1] + y <= n - 1) ? route[i][1] + y : y;
                if (x_ == x || y_ == y)
                {
                    //边界条件判断
                    if (i == 7)
                        isEqule = 0;
                    continue;
                }
                else if (grid[x_][y_] == key + 1)
                {
                    x = x_;
                    y = y_;
                    break;
                }
                //只有在边界的时候才置为0
                else if (i == 7)
                    isEqule = 0;
            }
            if (isEqule == 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=checkValidGrid
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,3,6],[5,8,1],[2,7,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[8,3,6],[5,0,1],[2,7,4]]\n
// @lcpr case=end

 */
