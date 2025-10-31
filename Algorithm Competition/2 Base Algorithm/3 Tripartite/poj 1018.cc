#include <algorithm>
#include <iostream>

#define MAX 105

using namespace std;
const int INF = (1 << 29);

int price[MAX][MAX], b[MAX][MAX], mi[MAX];
int n;
vector<int> all_bandwidths; // 存储所有可能的带宽值

double solve(int x)
{
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        int mint = INF;
        for (int j = 1; j <= mi[i]; j++) {
            if (all_bandwidths[x] <= b[i][j] && mint >= price[i][j])
                mint = price[i][j];
        }
        sum += mint;
    }
    return all_bandwidths[x] / sum;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        all_bandwidths.clear();
        for (int i = 1; i <= n; i++) {
            cin >> mi[i];
            for (int j = 1; j <= mi[i]; j++) {
                cin >> b[i][j] >> price[i][j];
                all_bandwidths.push_back(b[i][j]);
            }
        }
        sort(all_bandwidths.begin(), all_bandwidths.end(), [](int a, int b) {
            return a < b;
        });
        all_bandwidths.erase(unique(all_bandwidths.begin(), all_bandwidths.end()), all_bandwidths.end());
        int left = 0, right = all_bandwidths.size() - 1;
        while (right - left > 2) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            int temp1 = solve(mid1), temp2 = solve(mid2);
            if (temp1 > temp2)
                right = mid2;
            else
                left = mid1;
        }
        // 在最终的搜索区间内，计算所有点的B/P值，取最大值
        double max_ratio = 0.0;
        for (int i = left; i <= right; ++i) {
            double current_ratio = solve(i);
            if (current_ratio > max_ratio) {
                max_ratio = current_ratio;
            }
        }
        // 输出结果，保留三位小数
        printf("%.3f\n", max_ratio);
    }
    return 0;
}