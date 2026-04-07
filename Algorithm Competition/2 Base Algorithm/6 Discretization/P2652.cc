#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        groups[a].push_back(b);
    }

    int max_keep = 0;
    for (auto &p : groups) {
        vector<int> &nums = p.second;
        // 去重
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int k = nums.size();
        // 滑动窗口
        int l = 0;
        for (int r = 0; r < k; ++r) {
            while (nums[r] - nums[l] >= n) {
                ++l; // nums[r] - nums[l] == n - 1的时候刚好是n长
            }
            //  r - l + 1 代表这个窗口中有几个数
            max_keep = max(max_keep, r - l + 1);
        }
    }
    printf("%d\n", n - max_keep);
    return 0;
}