/*
 * @lc app=leetcode.cn id=744 lang=cpp
 * @lcpr version=21909
 *
 * [744] 寻找比目标字母大的最小字母
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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if(letters[0] > target)
            return letters[0];
        int left = 0, right = letters.size() - 1;
        int mid = left + (right - left) / 2, ans = 0;
        while (left <= right) {
            if (letters[mid] <= target) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            mid = left + (right - left) / 2;
        }
        return ans == letters.size() - 1 ? letters[0] : letters[ans + 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["c", "f", "j"]\n"a"\n
// @lcpr case=end

// @lcpr case=start
// ["c","f","j"]\n"c"\n
// @lcpr case=end

// @lcpr case=start
// ["x","x","y","y"]\n"z"\n
// @lcpr case=end

 */
