// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
#define ISLEFT(c) (c == '(' || c == '[' || c == '{')
#define ISRIGHT(l, r) ((l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}'))
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (ISLEFT(s[i]))
                st.push(s[i]);
            else {
                if (!st.empty() && ISRIGHT(st.top(), s[i]))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */
