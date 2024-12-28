/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30204
 *
 * [349] 两个数组的交集
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int hash[1001] = {0};
        vector<int> result;
        for (int num : nums1)
        {
            hash[num] = 1;
        }
        for (int num : nums2)
        {
            if (hash[num])
            {
                result.push_back(num);
                hash[num] = 0;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */
