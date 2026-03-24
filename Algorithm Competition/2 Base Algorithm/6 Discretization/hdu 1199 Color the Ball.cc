#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> L(n), R(n);
        vector<char> C(n);
        vector<int> points; // 收集所有需要离散化的点

        // 读入所有操作，同时收集端点
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %c", &L[i], &R[i], &C[i]);
            // 使用左闭右开区间 [L, R+1) 表示每个操作
            points.push_back(L[i]);
            points.push_back(R[i] + 1);
        }

        // 离散化：排序 + 去重
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        int m = points.size();          // 离散化后的点数
        vector<char> color(m - 1, 'b'); // 每个小区间段的颜色，初始全黑

        // 建立真实值到离散化下标的映射
        map<int, int> mp;
        for (int i = 0; i < m; ++i) {
            mp[points[i]] = i;
        }

        // 模拟涂色：按顺序覆盖
        for (int i = 0; i < n; ++i) {
            int left = mp[L[i]];      // 左端点对应的离散化下标
            int right = mp[R[i] + 1]; // 右端点+1对应的离散化下标
            for (int j = left; j < right; ++j) {
                color[j] = C[i]; // 覆盖颜色
            }
        }

        // 扫描所有小区间段，寻找最长连续白色段
        long long max_len = 0;
        int best_left = -1, best_right = -1;
        int start = -1;        // 当前白色段的起始下标
        long long cur_len = 0; // 当前白色段的长度（真实长度）

        for (int i = 0; i < m - 1; ++i) {
            if (color[i] == 'w') {
                if (start == -1)
                    start = i;                                     // 开始一段白色
                cur_len += (long long)(points[i + 1] - points[i]); // 累加真实长度
            } else {
                if (start != -1) {
                    // 白色段结束，检查是否更新答案
                    if (cur_len > max_len) {
                        max_len = cur_len;
                        best_left = points[start];
                        best_right = points[i] - 1; // 注意区间是 [start, i) 所以右端点是 points[i] - 1
                    }
                    start = -1;
                    cur_len = 0;
                }
            }
        }
        // 处理最后一段白色（可能延伸到末尾）
        if (start != -1) {
            if (cur_len > max_len) {
                max_len = cur_len;
                best_left = points[start];
                best_right = points[m - 1] - 1; // 最后一个区间段到数组末尾
            }
        }

        if (max_len == 0) {
            printf("Oh, my god\n");
        } else {
            printf("%d %d\n", best_left, best_right);
        }
    }
    return 0;
}