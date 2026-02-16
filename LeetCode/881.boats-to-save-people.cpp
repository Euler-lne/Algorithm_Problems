/*
 * @lc app=leetcode.cn id=881 lang=cpp
 * @lcpr version=30204
 *
 * [881] 救生艇
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
    int numRescueBoats(vector<int> &people, int limit)
    {
        // 先排序，然后就很简单了
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, ans = 0;
        while (l < r) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
            r--;
            ans++;
        }
        if (l == r)
            ans++;
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,5,3,4]\n5\n
// @lcpr case=end

 */
