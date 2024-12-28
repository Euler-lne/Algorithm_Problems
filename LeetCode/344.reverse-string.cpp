/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30204
 *
 * [344] 反转字符串
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
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        char t;
        while (l < r)
        {
            t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */
