/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30204
 *
 * [58] 最后一个单词的长度
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
    int lengthOfLastWord(string s)
    {
        // 双指针
        int n = s.size() - 1, ans;
        while (s[n] == ' ')
            n--;
        ans = n + 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                ans = n - i;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */
