/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=21909
 *
 * [69] x 的平方根
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
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2147395599\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
