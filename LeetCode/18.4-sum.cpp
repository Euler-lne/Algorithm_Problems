/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n; k++)
        {
            // 一级剪枝 注意 负数加负数会变小
            if (nums[k] > target && nums[k] >= 0)
                break;
            if (k != 0 && nums[k] == nums[k - 1])
                continue;
            for (int i = k + 1; i < n; i++)
            {
                // 二级剪枝
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
                    break;
                // 注意这里是 k+1
                if (i != k + 1 && nums[i] == nums[i - 1])
                    continue;

                int l = i + 1, r = n - 1;
                // long sum = 0;
                while (l < r)
                {
                    // sum = nums[k] + nums[i] + nums[l] + nums[r];
                    if ((long)nums[k] + nums[i] + nums[l] + nums[r] < target)
                        l++;
                    else if ((long)nums[k] + nums[i] + nums[l] + nums[r] > target)
                        r--;
                    else
                    {
                        result.push_back({nums[k], nums[i], nums[l], nums[r]});
                        while (l < r && nums[r] == nums[r - 1])
                            r--;
                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        r--;
                        l++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,1000000000,1000000000,1000000000,1000000000]\n1000000000\n
// @lcpr case=end
 */
