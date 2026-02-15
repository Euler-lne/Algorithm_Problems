// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2132 lang=cpp
 * @lcpr version=30204
 *
 * [2132] 用邮票贴满网格图
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
    // 1. 先贪心，拿到一个左上角的点能贴就贴，前缀和数组判断能不能贴
    // 2. 差分数组记录贴在哪里
    // 3. 差分累加之后，如果这个点的树为0说明没有被邮票覆盖
    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] += (get_arr(i, j - 1, grid) + get_arr(i - 1, j, grid) - get_arr(i - 1, j - 1, grid));
            }
        }
        if (grid[m - 1][n - 1] == m * n) // 没有空格子
            return true;
        if (grid[m - 1][n - 1] > m * n - stampHeight * stampWidth) // 都不够一个邮票
            return false;
        for (int i = 0, ei = i + stampHeight - 1; i < m && ei < m; i++, ei++) {
            for (int j = 0, ej = j + stampWidth - 1; j < n && ej < n; j++, ej++) {
                if (get_grid(i, j, ei, ej, grid) == 0) { // 能贴
                    set_diff(i + 1, j + 1, ei + 1, ej + 1, diff);
                }
            }
        }
        build_diff(diff, m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (diff[i + 1][j + 1] == 0 &&
                    get_grid(i, j, i, j, grid) == 0)
                    return false;
            }
        }
        return true;
    }

    int get_arr(int i, int j, vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;
        return g[i][j];
    }

    int get_grid(int i, int j, int ei, int ej, vector<vector<int>> &g)
    {
        // 注意是末减始
        return get_arr(ei, ej, g) - get_arr(ei, j - 1, g) - get_arr(i - 1, ej, g) + get_arr(i - 1, j - 1, g);
    }

    void set_diff(int a, int b, int c, int d, vector<vector<int>> &diff)
    {
        diff[a][b]++;
        diff[a][d + 1]--;
        diff[c + 1][b]--;
        diff[c + 1][d + 1]++;
    }

    void build_diff(vector<vector<int>> &diff, int m, int n)
    {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                diff[i][j] += (diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1]);
            }
        }
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=possibleToStamp
// paramTypes= ["number[][]","number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]\n2\n2\n
// @lcpr case=end

 */
