/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
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
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1, i = r;
        while (l <= r)
        {
            if (abs(nums[l]) > abs(nums[r]))
            {
                ans[i] = nums[l] * nums[l];
                l++;
            }
            else
            {
                ans[i] = nums[r] * nums[r];
                r--;
            }
            i--;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
