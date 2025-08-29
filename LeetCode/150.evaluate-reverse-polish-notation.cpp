/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (string s : tokens) {
            if (is_num(s))
                stk.push(stoi(s));
            else {
                int r = stk.top();
                stk.pop();
                int l = stk.top();
                stk.pop();
                if (s == "+")
                    r = l + r;
                else if (s == "-")
                    r = l - r;
                else if (s == "*")
                    r = l * r;
                else if (s == "/")
                    r = l / r;
                stk.push(r);
            }
        }
        return stk.top();
    }

private:
    bool is_num(string s)
    {
        return s != "+" && s != "-" && s != "*" && s != "/";
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
