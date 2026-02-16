// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30204
 *
 * [41] 缺失的第一个正数
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
    int firstMissingPositive(vector<int> &nums)
    {
        // l 左边都满足i位置对应i+1这个数
        // r 右边表示垃圾区域，r最开始在n位置（取不到的那个位置）
        // 假设为美好情况

        int l = 0, r = nums.size();
        while (l < r) {
            if (nums[l] == l + 1)
                l++;
            else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) {
                // 这些都是垃圾，要放到垃圾区域
                // 1. 当前值较小 -3 1 2 3
                // 2. 当前值比垃圾区域大 100 1 2 3
                // 3. 要移动到的位置于当前值相同 5 1 2 3 5
                swap(nums, l, --r);
            } else {
                swap(nums, l, nums[l] - 1);
            }
        }
        return l + 1;
    }

    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */
