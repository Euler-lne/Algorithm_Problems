/*
 * @lc app=leetcode.cn id=304 lang=cpp
 * @lcpr version=30204
 *
 * [304] 二维区域和检索 - 矩阵不可变
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
class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        sum_matrix.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum_matrix[i + 1][j + 1] = sum_matrix[i][j + 1] + sum_matrix[i + 1][j] - sum_matrix[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sum_matrix[row2 + 1][col2 + 1] - sum_matrix[row2 + 1][col1] - sum_matrix[row1][col2 + 1] + sum_matrix[row1][col1];
    }

private:
    vector<vector<int>> sum_matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

/*
// @lcpr case=start
// ["NumMatrix","sumRegion","sumRegion","sumRegion"][[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */
