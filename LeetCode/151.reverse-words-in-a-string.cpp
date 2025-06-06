// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] 反转字符串中的单词
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
    string reverseWords(string s)
    {
        removeEmpty(s); // 去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverseStr(s, 0, s.size() - 1);
        int start = 0; // removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i)
        {
            if (i == s.size() || s[i] == ' ')
            {                                // 到达空格或者串尾，说明一个单词结束。进行翻转。
                reverseStr(s, start, i - 1); // 翻转，注意是左闭右闭 []的翻转。
                start = i + 1;               // 更新下一个单词的开始下标start
            }
        }
        return s;
    }

private:
    void reverseStr(string &s, int l, int r)
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
    void removeEmpty(string &s)
    {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            { // 遇到非空格就处理，即删除所有空格。
                if (slow != 0)
                    s[slow++] = ' '; // 手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ')
                { // 补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); // slow的大小即为去除多余空格后的大小。
    }
};
// @lc code=end

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
