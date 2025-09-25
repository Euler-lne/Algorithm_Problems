// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30204
 *
 * [31] 下一个排列
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
    void nextPermutation(vector<int> &nums)
    {
        // 思考：从倒数第二个开始，倒数第二个要放比他刚刚好大一个数字
        //      如果没有就到倒数第三个
        // 倒数第二个和第一个比较 若倒数第一 > 倒数第二 则就是答案
        // 否则找到第一个满足上述情况的，然后回溯把小的向后调整

        // 得到的数组 yyy nums[i] nums[j] xxxx
        // j到后面的所有数字都是单调递减的
        // 这个时候 nums[i] < nums[j]

        // 之后对后面的 sums[i] xxxx 进行排序就好了

        int n = nums.size();
        int i = n - 2;
        // 查找第一个满足 nums[i] < nums[i+1] 的索引 i
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        } // 如果最大，那么i最后会等于 -1
        // 找到合适的i的位置，i插入的时候也是单调递减的
        if (i >= 0) {
            int j = n - 1;
            // 从后向前查找第一个大于 nums[i] 的索引 j
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // 反转从 i+1 到末尾的部分
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3,1]\n
// @lcpr case=end

 */
