/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30204
 *
 * [383] 赎金信
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
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> map(26, 0);
        int n = max(ransomNote.size(), magazine.size());
        for (int i = 0; i < n; i++)
        {
            if (i < ransomNote.size())
            {
                // 生产者
                map[ransomNote[i] - 'a']--;
            }
            if (i < magazine.size())
            {
                // 消费者
                map[magazine[i] - 'a']++;
            }
        }
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */
