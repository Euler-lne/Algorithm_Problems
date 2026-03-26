#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}

map<LL, LL> dp[45]; // 字典数组
map<LL, LL>::iterator it;
void init()
{
    dp[1][1] = 1;
    for (int i = 2; i <= 40; i++) {
        dp[i] = dp[i - 1]; // 扩散 不包含i
        dp[i][i] += 1;     //  只选i
        for (it = dp[i - 1].begin(); it != dp[i - 1].end(); it++) {
            LL as = lcm(it->first, i); // 加入i时候可能的lcm，记录
            dp[i][as] += it->second;
        }
    }
}

int main()
{
    init();
    int T, t;
    scanf("%d", &T);
    int cas = 1;
    while (T--) {
        int n;
        LL m;
        scanf("%d%lld", &n, &m);
        printf("Case #%d: ", cas++);
        LL ans = 0;
        for (it = dp[n].begin(); it != dp[n].end(); it++) {
            if (it->first >= m)
                ans += it->second;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*
我们用 dp[i] 表示一个 从数字 1 到 i 中选出的所有子集（包括空集） 的 LCM 分布情况。
具体来说，dp[i] 是一个 map<LL, LL>，其中：

键：某个子集的 LCM 值

值：LCM 等于该键的子集个数

初始状态 dp[1] 只包含空集（LCM = 1），即 dp[1][1] = 1。

不选 i：所有不包含 i 的子集已经在 dp[i-1] 中，直接继承。

选 i：每个包含 i 的子集，都可以唯一地表示为“一个不包含 i 的子集 ∪ {i}”。
因此，遍历 dp[i-1] 中的所有子集，并将 i 加入，就能得到所有包含 i 的子集，且每个包含 i 的子集只会被生成一次（因为其去掉 i 后的部分是唯一的）。

所以，经过这样的转移，dp[i] 就包含了所有从 1..i 中选出的子集。
*/