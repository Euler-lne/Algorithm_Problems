// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 * @lcpr version=30204
 *
 * [1139] 最大的以 1 为边界的正方形
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
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] += (get(i - 1, j, grid) + get(i, j - 1, grid) - get(i - 1, j - 1, grid));
            }
        }
        if (get_sum(grid, 0, 0, m - 1, n - 1) == 0)
            return 0;
        // 边边减去中间，如果值为周长那么就是对的
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                // 得到右下角的坐标，k代表当前要处理的边长 k = c - a + 1
                for (int c = a + ans, d = b + ans, k = ans + 1; c < m && d < n; c++, d++, k++) {
                    if (get_sum(grid, a, b, c, d) - get_sum(grid, a + 1, b + 1, c - 1, d - 1) == (k - 1) << 2)
                        ans = k;
                }
            }
        }
        return ans * ans;
    }

    int get(int i, int j, vector<vector<int>> &grid)
    {
        return i < 0 || j < 0 ? 0 : grid[i][j];
    }

    int get_sum(vector<vector<int>> &grid, int a, int b, int c, int d)
    {
        if (a > c || b > d)
            return 0;
        return get(c, d, grid) - get(c, b - 1, grid) - get(a - 1, d, grid) + get(a - 1, b - 1, grid);
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=largest1BorderedSquare
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,0,0]]\n
// @lcpr case=end

// @lcpr case=start
//[[0,0],[0,1]]\n
// @lcpr case=end

 */
