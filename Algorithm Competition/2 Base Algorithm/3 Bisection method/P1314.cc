#include <iostream>
#include <vector>

using namespace std;

const int MAX = 0x7fffffff;
const int MIN = -MAX;

int n, m;
long long s;
vector<int> weight, value, l, r;

long long get_y(int w)
{
    long long ans = 0;
    vector<long long> suff1, suff2;
    suff1.resize(n + 1);
    suff2.resize(n + 1);
    suff1[0] = 0;
    suff2[0] = 0;
    for (int i = 1; i <= n; i++) {
        bool key = weight[i - 1] >= w;
        suff1[i] = (key ? 1 : 0) + suff1[i - 1];
        suff2[i] = (key ? value[i - 1] : 0) + suff2[i - 1];
    }
    for (int i = 0; i < m; i++)
        ans += (suff1[r[i]] - suff1[l[i] - 1]) * (suff2[r[i]] - suff2[l[i] - 1]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    weight.resize(n);
    value.resize(n);
    l.resize(m);
    r.resize(m);
    int left = MAX, right = MIN, mid;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
        left = min(left, weight[i]);
        right = max(right, weight[i]);
    }
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
    long long ans = 1e18; // ans 不能设置为 MAX MAX太小了
    while (left < right) {
        mid = (left + right + 1) >> 1;
        long long y = get_y(mid);
        if (y > s) // y的值大了 mid越大y越小
            left = mid;
        else
            right = mid - 1;
        ans = min(ans, abs(y - s));
    }
    cout << ans;
    return 0;
}