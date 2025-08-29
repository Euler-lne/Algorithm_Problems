/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
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
    int trap(vector<int> &height)
    {
        // 使用单调递减 这样可以确定最低值
        // 当前值，左边值 右边值
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int cur = st.top();
                st.pop();
                if (st.empty()) // 说明没有左边界
                    break;
                int l = st.top();
                int h = min(height[l], height[i]) - height[cur];
                ans += (i - l - 1) * h;
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
