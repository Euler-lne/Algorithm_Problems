/*
 * @lc app=leetcode.cn id=475 lang=cpp
 * @lcpr version=30204
 *
 * [475] 供暖器
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
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        // 1. 让每个房屋选择最优供暖器
        // 2. 每个房屋试探的选择相邻供暖器
        // 3. 如果当前供暖器为最优供暖，那么房屋下移，否则供暖器于房屋下移
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int i = 0, j = 0, ans = 0;
        for (i = 0; i < houses.size(); i++) {
            while (!best_heater(houses, heaters, i, j)) {
                j++;
            }
            ans = max(ans, abs(heaters[j] - houses[i]));
        }
        return ans;
    }
    // cur_dis >= next_dis 不是最优，说明需要跳到下一个位置
    bool best_heater(vector<int> &houses, vector<int> &heaters, int i, int j)
    {
        if (j == heaters.size() - 1)
            return true;
        int cur_dis = abs(heaters[j] - houses[i]);
        int next_dis = abs(heaters[j + 1] - houses[i]);
        return cur_dis < next_dis; // 相等的时候一定要让他动，不让同一个暖气可能卡死
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n[2]\n
// @lcpr case=end

 */
