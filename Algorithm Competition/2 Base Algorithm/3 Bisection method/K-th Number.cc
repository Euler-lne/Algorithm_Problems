// 二分+尺取法
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n, m, k;
const int MAX = 0x7fffffff;

bool check(int mid)
{
    vector<int> s(n + 1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + (a[i - 1] >= mid); // 统计大于预计值的前缀和
    for (int i = k, j = 0; i <= n; i++) {
        while (s[i] - s[j] >= k) // 这样计算是正确的，区间长度最小为k
            j++;
        ans += j;
    }
    return ans >= m;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int l = 1, r = -1, mid;
        cin >> n >> k >> m;
        a.resize(n, 0);
        int min_val = MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            r = max(r, a[i]);
        }
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }

    return 0;
}