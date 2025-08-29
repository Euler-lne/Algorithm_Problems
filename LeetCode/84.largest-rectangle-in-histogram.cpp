// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int> &heights)
    {

        // 枚举每根柱子当高
        stack<int> stk;
        int ans = 0;
        stk.push(-1);
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (stk.top() != -1 && heights[i] < heights[stk.top()]) {
                int cur = stk.top(); // 右边第一个比他小为 i 左边为 left
                stk.pop();
                int left = stk.top(), val = heights[cur] * (i - left - 1);
                // i - left 得到的长度多了 1 要去边界，加1 就是保留两个边界，这里两个都不需要
                ans = val > ans ? val : ans;
            }
            if (stk.top() != -1 && heights[i] == heights[stk.top()])
                stk.pop(); // 只保留最右边的
            stk.push(i);
        }

        while (stk.top() != -1) {
            int cur = stk.top();
            stk.pop();
            int left = stk.top(), val = heights[cur] * (n - left - 1);
            ans = val > ans ? val : ans;
        }
        stk.pop();
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,2]\n
// @lcpr case=end

 */
