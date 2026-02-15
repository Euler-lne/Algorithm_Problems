// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=436 lang=cpp
 * @lcpr version=30204
 *
 * [436] 寻找右区间
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
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> startIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
        }
        sort(startIntervals.begin(), startIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
            if (it != startIntervals.end()) {
                ans[i] = it->second;
            }
        }
        return ans;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4],[2,3],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[2,3],[3,4]]\n
// @lcpr case=end

 */
