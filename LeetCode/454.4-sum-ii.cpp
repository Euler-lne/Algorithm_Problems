/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30204
 *
 * [454] 四数相加 II
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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int n = nums1.size(), result = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map.find(nums1[i] + nums2[j]) == map.end())
                    map[nums1[i] + nums2[j]] = 1;
                else
                    map[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map.find(-(nums3[i] + nums4[j])) != map.end())
                    result += map[-(nums3[i] + nums4[j])];
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */
