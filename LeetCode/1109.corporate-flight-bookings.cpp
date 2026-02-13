/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 * @lcpr version=30204
 *
 * [1109] 航班预订统计
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
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> arr(n + 1, 0);
        for (vector<int> rule : bookings) {
            arr[rule[0] - 1] += rule[2];
            arr[rule[1]] -= rule[2];
        }
        for (int i = 1; i <= n; i++) {
            arr[i] += arr[i - 1];
        }
        arr.pop_back();
        return arr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,10],[2,3,20],[2,5,25]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,10],[2,2,15]]\n2\n
// @lcpr case=end

 */
