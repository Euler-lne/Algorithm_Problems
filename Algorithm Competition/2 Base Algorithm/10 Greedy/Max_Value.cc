#include <cstdlib>
#include <iostream>

using namespace std;

long long qpow(long long x, int n, int mod)
{
    long long ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}

/// @brief 把n分成k份的和，最大乘积是多少
/// @param n
/// @param k
/// @return 返回最大乘积
int maxValue1(int n, int k)
{
    // 方法采用平均数的方法，不给出验证，用对数器
    int mod = 1000000007;
    long long part1 = qpow((n / k), k - (n % k), mod);
    long long part2 = qpow((n / k) + 1, n % k, mod);
    return (int)(part1 * part2 % mod);
}

int arr[10000][10000] = {0};

int maxValue2(int n, int k)
{
    int mod = 1000000007;
    if (k <= 1)
        return n;
    long long ans = 1;
    for (int i = 1; i <= n - k + 1 && i <= n; i++) {
        int t = arr[n - i][k - 1] ? arr[n - i][k - 1] : maxValue2(n - i, k - 1);
        arr[n - i][k - 1] = t;
        if (ans < i * t)
            ans = i * t;
    }
    return (int)(ans % mod);
}

int getRand(int minV, int maxV)
{
    return (rand() % (maxV - minV + 1)) + minV;
}

int main()
{
    int N = 30;
    int testTimes = 2000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        int n = getRand(2, N);
        int k = getRand(1, n);
        int ans1 = maxValue1(n, k);
        int ans2 = maxValue2(n, k);
        if (ans1 != ans2) {
            cout << " n: " << n << " k: " << k << endl;
            cout << "答案不匹配" << ans1 << " " << ans2 << endl;
        }
        if (i % 100 == 0)
            cout << " 测试到第 " << i << " 组" << endl;
    }
    cout << "测试结束" << endl;
    return 0;
}