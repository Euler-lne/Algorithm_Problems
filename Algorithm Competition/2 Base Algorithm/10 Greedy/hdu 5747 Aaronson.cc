#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, m;
        scanf("%lld%lld", &n, &m);
        // 有效幂次只到 30，因为 2^30 > 1e9
        m = min(m, 30LL);
        long long ans = 0;
        for (long long i = m; i >= 0; --i) {
            long long val = 1LL << i; // 2^i
            ans += n / val;
            n %= val;
        }
        printf("%lld\n", ans);
    }
    return 0;
}