// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=85 lang=cpp
 * @lcpr version=30204
 *
 * [85] 最大矩形
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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
            }
        }
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int j = 0; j < n; j++) {
            // left[i][j] 每次i变j不变寻找该数组的最大面积
            for (int i = 0; i < m; i++) {
                while (stk.top() != -1 && left[i][j] < left[stk.top()][j]) {
                    int h = left[stk.top()][j];
                    stk.pop();
                    int id_left = stk.top();
                    int val = h * (i - id_left - 1);
                    ans = val > ans ? val : ans;
                }
                while (stk.top() != -1 && left[i][j] == left[stk.top()][j])
                    stk.pop(); //   保留最右边的
                stk.push(i);
            }
            while (stk.top() != -1) {
                int h = left[stk.top()][j];
                stk.pop();
                int id_left = stk.top();
                int val = h * (m - id_left - 1);
                ans = ans > val ? ans : val;
            }
        }
        stk.pop();
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1"]]\n
// @lcpr case=end

 */
