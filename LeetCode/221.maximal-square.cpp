/*
 * @lc app=leetcode.cn id=221 lang=cpp
 * @lcpr version=30204
 *
 * [221] 最大正方形
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
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 1;
        vector<vector<int>> sum(m + 2, vector(n + 2, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] -
                             sum[i - 1][j - 1] + (matrix[i - 1][j - 1] == '0' ? 0 : 1));
            }
        }
        if (sum[m][n] == 0)
            return 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int ei = i + ans, ej = j + ans; ei <= m && ej <= n; ei++, ej++) {
                    int l = ei - i + 1;
                    if (sum[ei][ej] - sum[ei][j - 1] - sum[i - 1][ej] + sum[i - 1][j - 1] == l * l) {
                        ans = l;
                    }
                }
            }
        }
        return ans * ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","1"],["1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

 */
