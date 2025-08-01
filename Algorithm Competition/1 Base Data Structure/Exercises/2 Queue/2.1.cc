#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, d, k, l, r, mid;
    long long positive_sum = 0;
    vector<int> value(n + 1), distance(n + 1);
    vector<long long> prefix(n + 1);
    prefix[0] = 0;
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++) {
        cin >> distance[i] >> value[i];
        if (value[i] > 0)
            positive_sum += value[i];
        prefix[i] = prefix[i - 1] + value[i];
    }
    if (positive_sum < k) {
        cout << -1;
        return 0;
    }
    l = d - distance[1] < 0 ? distance[1] - d : d - distance[1];
    r = distance[n];
    mid = (r - l) / 2 + l;
    while (l <= r) {
        bool is_ok = true; // TODO: 判断mid是否合理，问题转换为滑动窗口之和的最大值
        // 如果mid合理 说明mid可能太大了
        if (is_ok)
            r = mid - 1;
        else
            l = mid + 1;
        mid = (r - l) / 2 + l;
    }
    return 0;
}