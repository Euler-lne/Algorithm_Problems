#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100010;
int n, k, m;
int a[N], s[N];
bool check(int mid)
{
    memset(s, 0, sizeof s);
    int sum = 0, l = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + (a[i] >= mid);
    for (int i = k; i <= n; i++) {
        while (s[i] - s[l] >= k)
            l++;
        sum += l;
    }
    return sum >= m;
}
signed main()
{
    int T;
    cin >> T;

    while (T--) {
        scanf("%lld%lld%lld", &n, &k, &m);
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), r = max(a[i], r);
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        printf("%lld\n", r);
    }
}
