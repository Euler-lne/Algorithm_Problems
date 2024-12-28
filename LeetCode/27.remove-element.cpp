// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30204
 *
 * [27] 移除元素
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
    int removeElement(vector<int> &nums, int val)
    {
        // 快慢指针
        int fast = 0, slow = 0, n = nums.size();
        for (fast = 0; fast < n; fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }

        return slow;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */
