// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 长度最小的子数组
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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 滑动窗口，注意result
        int i = 0, result = nums.size() + 1, sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                int temp = j - i + 1;
                result = min(result, temp);
                // 注意移动慢指针的条件
                sum -= nums[i];
                i++;
            }
        }
        return result == nums.size() + 1 ? 0 : result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
