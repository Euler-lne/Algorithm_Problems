// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30204
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s)
    {
        s = remove_invalid(s);
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    string remove_invalid(string s)
    {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z')
                ans.push_back(c);
            else if (c >= 'A' && c <= 'Z')
                ans.push_back(c - ('Z' - 'z'));
            else if (c >= '0' && c <= '9')
                ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */
