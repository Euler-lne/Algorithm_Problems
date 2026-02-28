// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=LCP 74 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 74] 最强祝福力场
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
    int fieldOfGreatestBlessing(vector<vector<int>> &forceField)
    {
        int n = forceField.size();
        vector<long long> xs(n << 1, 0);
        vector<long long> ys(n << 1, 0); // 保存所有可能的下标值，要先放大2倍，防止出现0.5

        for (int i = 0, j = 0, k = 0; k < n; k++) {
            int x = forceField[k][0], y = forceField[k][1], r = forceField[k][2];
            xs[i++] = 2LL * x + r;
            xs[i++] = 2LL * x - r;
            ys[j++] = 2LL * y + r;
            ys[j++] = 2LL * y - r;
        }
        int sizex = sort_(xs);
        int sizey = sort_(ys);
        vector<vector<int>> arr(sizex + 2, vector<int>(sizey + 2, 0));
        for (int i = 0; i < n; i++) {
            int x = forceField[i][0], y = forceField[i][1], r = forceField[i][2];
            int a = find_index(xs, 2LL * x - r, sizex);
            int b = find_index(ys, 2LL * y - r, sizey);
            int c = find_index(xs, 2LL * x + r, sizex);
            int d = find_index(ys, 2LL * y + r, sizey);
            arr[a][b]++;
            arr[a][d + 1]--;
            arr[c + 1][b]--;
            arr[c + 1][d + 1]++;
        }

        int ans = 0;
        for (int i = 1; i <= sizex; i++) {
            for (int j = 1; j <= sizey; j++) {
                arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
                ans = max(ans, arr[i][j]);
            }
        }
        return ans;
    }
    /// @brief 排序去重函数
    /// [10,20,20,30,30,40] -> [10,20,30,40]
    /// @param nums
    /// @return
    int sort_(vector<long long> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = 1;                           // 当前值
        for (int i = 1; i < nums.size(); i++) { // i一直向后走
            if (nums[i] != nums[size - 1])
                nums[size++] = nums[i];
        }
        return size;
    }

    int find_index(vector<long long> &nums, long long value, int size)
    {
        int l = 0, r = size - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < value)
                l = mid + 1;
            else
                r = mid;
        }
        return l + 1;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=fieldOfGreatestBlessing
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[0,0,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,4,6],[7,5,3],[1,6,2],[5,6,3]]\n
// @lcpr case=end

 */
