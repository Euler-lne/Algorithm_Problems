/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 * @lcpr version=30204
 *
 * [1314] 矩阵区域和
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
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] += (get_value(mat, i - 1, j) + get_value(mat, i, j - 1) - get_value(mat, i - 1, j - 1));
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = get_value(mat, i - k, j - k, i + k, j + k);
            }
        }
        return ans;
    }

    int get_value(vector<vector<int>> &arr, int i, int j)
    {
        int m = arr.size(), n = arr[0].size();
        if (i < 0 || j < 0)
            return 0;
        if (i >= m)
            i = m - 1;
        if (j >= n)
            j = n - 1;
        return arr[i][j];
    }

    int get_value(vector<vector<int>> &arr, int i, int j, int ei, int ej)
    {
        int m = arr.size(), n = arr[0].size();
        return get_value(arr, ei, ej) - get_value(arr, ei, j - 1) - get_value(arr, i - 1, ej) + get_value(arr, i - 1, j - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n2\n
// @lcpr case=end

 */
