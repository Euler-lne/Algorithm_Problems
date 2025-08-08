// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s)
    {
        stack<char> stk;
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stk.push(s[i]);
            else {
                if (!stk.empty()) {
                    num++;
                    stk.pop();
                }
            }
        }
        return num * 2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
