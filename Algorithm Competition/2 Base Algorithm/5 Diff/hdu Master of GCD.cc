#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;
/*
 * 思路：可以用线段树，但没必要。设第i个数做了a_i​次乘2操作，
 做了b_i次乘3操作，显然答案就是2^{min(a_i)}*3^{min(b_i)}2，
 因此开两个数组分别维护乘2操作的次数和乘3操作的次数，
通过差分把区间修改转换为单点修改，
最后遍历取最小值即可，时间复杂度O(n)，代码量也很小。
 * */

int m, n;
const int MOD_NUM = 998244353;
const int maxn = 1e5 + 5;
int arr2[maxn], arr3[maxn];
void set(int l, int r, int x);
void build();

long long qpow(int a, int b);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> n >> m;
        memset(arr2, 0, sizeof(arr2));
        memset(arr3, 0, sizeof(arr3));
        while (m--) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            set(l, r, x);
        }
        build();
        printf("%d\n", (qpow(2, arr2[0]) * qpow(3, arr3[0])) % MOD_NUM);
    }
    return 0;
}

void set(int l, int r, int x)
{
    if (x == 2) {
        arr2[l]++;
        arr2[r + 1]--;
    } else {
        arr3[l]++;
        arr3[r + 1]--;
    }
}

void build()
{
    arr2[0] = arr3[0] = INF;
    for (int i = 1; i <= n; i++) {
        arr2[i] += (i == 1 ? 0 : arr2[i - 1]);
        arr3[i] += (i == 1 ? 0 : arr3[i - 1]);
        arr2[0] = arr2[0] > arr2[i] ? arr2[i] : arr2[0];
        arr3[0] = arr3[0] > arr3[i] ? arr3[i] : arr3[0];
    }
}

/**
 * 快速幂取模运算
 * @param a 底数
 * @param p 指数（非负整数）
 * @return a^p % MOD_NUM 的值
 *
 * 原理：将指数p按二进制分解，通过平方和乘法累积结果，
 *       每轮迭代处理一个二进制位，时间复杂度O(log p)
 */
long long qpow(int a, int p)
{
    long long ans = 1;
    long long base = a; // 当前底数，初始为 a
    while (p) {
        if (p & 1)                      // 如果当前最低位为 1 奇数
            ans = ans * base % MOD_NUM; // 乘入当前底数并取模
        base = base * base % MOD_NUM;   // 底数平方
        p = p >> 1;                     // 右移一位
    }
    return ans;
}
