// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=21913
 *
 * [6] N 字形变换
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int len = s.length();
        if (len - numRows <= 0 || numRows == 1)
            return s;
        vector<vector<char>> arry(numRows, vector<char>(len, '\0'));
        int index = 0;
        for (int j = 0; j < len; j++)
        {
            if (index == len)
                break;
            for (int i = 0; i < numRows && index != len; i++)
            {
                if (j % (numRows - 1) == 0)
                {
                    // 竖条
                    arry[i][j] = s[index];
                    index++;
                }
                else
                {
                    // 离散
                    arry[(numRows - 1) - (j % (numRows - 1))][j] = s[index];
                    index++;
                    break;
                }
            }
        }
        index = 0;
        for (int i = 0; i < numRows; i++)
        {
            if (index == len)
                break;
            for (int j = 0; j < len && index != len; j++)
            {
                if (arry[i][j] != '\0')
                {
                    s[index] = arry[i][j];
                    index++;
                }
            }
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

// @lcpr case=start
// "A"\n2\n
// @lcpr case=end

// @lcpr case=start
// "AB"\n1\n
// @lcpr case=end

// @lcpr case=start
// "ABC"\n2\n
// @lcpr case=end

 */
