// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=21909
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]); // map自带的方法
            if (iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i)); // 插入元素pair
        }
        return {};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
