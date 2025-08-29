// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=287 lang=cpp
 * @lcpr version=30204
 *
 * [287] 寻找重复数
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
    int findDuplicate(vector<int> &nums)
    {
        int i = 0, j = 0;
        do {
            i = nums[i];
            j = nums[nums[j]];
        } while (nums[i] != nums[j]);
        // 这里只是相遇的点
        i = 0;
        while (nums[i] != nums[j]) {
            i = nums[i];
            j = nums[j];
        }

        return nums[i];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,4,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,3]\n
// @lcpr case=end

 */
