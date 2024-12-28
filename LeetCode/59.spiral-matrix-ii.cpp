// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 边界条件一致性的问题
        int i = 0, j = 0, startx = 0, starty = 0, offset = 1, count = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        for (int k = 0; k < n / 2; k++)
        {
            // 注意循环次数，这里奇数情况比较特殊，最后要特殊处理
            for (j = starty; j < n - offset; j++)
                ans[startx][j] = count++;
            for (i = startx; i < n - offset; i++)
                ans[i][j] = count++;
            for (j = n - offset; j > starty; j--)
                ans[i][j] = count++;
            for (i = n - offset; i > startx; i--)
                ans[i][j] = count++;
            startx++;
            starty++;
            offset++;
        }
        if (n % 2) // 为奇数
            ans[n / 2][n / 2] = count;
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
