/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] 反转字符串 II
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
    string reverseStr(string s, int k)
    {
        int n = s.size(), end;
        for (int i = 0; i < n; i += 2 * k)
        {
            end = i + k - 1 < n ? i + k - 1 : n - 1;
            reverseStr0(s, i, end);
        }
        return s;
    }

private:
    void reverseStr0(string &s, int l, int r)
    {
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
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */
