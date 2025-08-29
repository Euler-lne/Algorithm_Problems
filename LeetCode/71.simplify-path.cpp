// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30204
 *
 * [71] 简化路径
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
    string simplifyPath(string path)
    {
        deque<int> dq;
        int len = 0;
        int i = 0;
        int size = path.size();
        while (path[i]) {
            if (path[i] != '/') {
                bool is_all_point = true;
                while (path[i] != '/' && path[i]) {
                    is_all_point = path[i] == '.';
                    i++;
                    len++;
                }
                if (is_all_point && len <= 2) {
                    if (len == 2 && !dq.empty())
                        dq.pop_back();
                } else
                    dq.push_back(len * size + i - len);
            } else {
                while (path[i] == '/')
                    i++;
                len = 0;
            }
        }
        string ans = "";
        if (dq.empty())
            return "/";
        while (!dq.empty()) {
            int val = dq.front();
            dq.pop_front();
            string temp(path, val % size, val / size);
            ans += ("/" + temp);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */
