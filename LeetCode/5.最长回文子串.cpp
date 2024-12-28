// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21909
 *
 * [5] 最长回文子串
 */
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
#include <stdbool.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;
        int maxLen = 1;
        int begin = 0;
        // dp[i][j]代表s[i..j]是否为回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化，所有长度为1的字串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递归开始
        // 先枚举子串长度
        for (int L = 2; L<=n; L++) {
            // 枚举左边边界，左边界的上线可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由于L和i可以确定右边界，即j-1+1=L
                int j = L + i - 1;
                if (j >= n)
                    break;
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                // 只要 dp[i][L] == true 成立，
                // 就表示子串 s[i..L] 是回文，
                // 此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
/*
boolean 类型有两个常量值，true 和 false，
在内存中占一位（不是一个字节），
不可以使用 0 或非 0 的整数替代 true 和 false ，
这点和 C 语言不同。 boolean 类型用来判断逻辑条件，
一般用于程序流程控制 。
*/
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
