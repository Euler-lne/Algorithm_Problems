/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 * @lcpr version=30204
 *
 * [1351] 统计有序矩阵中的负数
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
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (vector<int> arr : grid) {
            count += get_count(arr);
        }
        return count;
    }

    int get_count(vector<int> &arr)
    {
        if (arr[arr.size() - 1] >= 0)
            return 0;
        int len = arr.size();
        int l = 0, r = len - 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (arr[mid] >= 0)
                l = mid + 1;
            else
                r = mid;
        }
        return len - r;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2],[1,0]]\n
// @lcpr case=end

 */
