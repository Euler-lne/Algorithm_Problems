/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=21909
 *
 * [35] 搜索插入位置
 */
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
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0])
            return 0;
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        int ans = 0;
        while(left<=right){
            if(nums[mid] <= target){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
            mid = left + (right - left) / 2;
        }
        return nums[ans] == target ? ans : ans + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */
