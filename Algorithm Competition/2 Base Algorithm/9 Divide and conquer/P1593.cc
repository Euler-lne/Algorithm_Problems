#include <cstdio>
const int MOD = 9901;

// 快速幂（带取模）
long long qpow(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 求逆元（MOD是质数，用费马小定理），要用逆元求mod除法
long long inv(long long x)
{
    return qpow(x, MOD - 2);
}

// 计算等比数列和 S = 1 + p + p^2 + ... + p^E (mod MOD)
long long calc_sum(long long p, long long E)
{
    if (p % MOD == 1) {
        return (E + 1) % MOD;
    }
    return (qpow(p, E + 1) - 1 + MOD) % MOD * inv(p - 1) % MOD;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0) {
        printf("0\n");
        return 0;
    } // 依题意 a>=1，可忽略
    if (b == 0) {
        printf("1\n");
        return 0;
    }
    if (a == 1) {
        printf("1\n");
        return 0;
    }

    long long ans = 1;
    // 对 a 进行质因数分解
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) { // i 是 a 的一个质因子
            int cnt = 0;
            while (a % i == 0) { // 统计这个质因子的指数
                a /= i;
                cnt++;
            }
            ans = ans * calc_sum(i, 1LL * cnt * b) % MOD;
        }
    }
    if (a > 1) {
        ans = ans * calc_sum(a, 1LL * 1 * b) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}