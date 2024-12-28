/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=21909
 *
 * [74] 搜索二维矩阵
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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // 先找行
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m - 1;
        int mid = left + (right - left) / 2;
        int r = 0;
        while (left <= right) {
            if (matrix[mid][n - 1] >= target) {
                r = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
        }
        int c = 0;
        left = 0;
        right = n - 1;
        mid = left + (right - left) / 2;
        // 代码含义刚好大于等于目标值
        while (left <= right) {
            if (matrix[r][mid] >= target) {
                c = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
        }
        return matrix[r][c] == target;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */
