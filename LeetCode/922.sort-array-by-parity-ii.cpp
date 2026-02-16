/*
 * @lc app=leetcode.cn id=922 lang=cpp
 * @lcpr version=30204
 *
 * [922] 按奇偶排序数组 II
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
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        // 一个奇数指针、一个偶数指针
        // 一个哨兵看着最后一个元素
        // 最后一个是奇数和奇数指针交换然后++
        int even = 0, odd = 1, sentinel = nums.size() - 1, exchange_index;
        if (nums.size() <= 1)
            return nums;
        while (even <= sentinel && odd <= sentinel) {
            if (nums[sentinel] % 2) { // 余数为1，说明是奇数
                exchange_index = odd;
                odd += 2;
            } else {
                exchange_index = even;
                even += 2;
            }
            int temp = nums[exchange_index];
            nums[exchange_index] = nums[sentinel];
            nums[sentinel] = temp;
        }
        return nums;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

 */
