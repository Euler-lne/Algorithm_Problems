#include <iostream>

#define N 100005

using namespace std;

int A[N], n, m, LOG2[N];
int dp[N][20];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void init()
{
    LOG2[0] = -1;
    for (int i = 1; i <= n; i++)
        LOG2[i] = LOG2[i >> 1] + 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = A[i];

    for (int k = 1; (1 << k) <= n; k++)
        for (int s = 1; s + (1 << (k - 1)) <= n; s++)
            dp[s][k] = max(dp[s][k - 1], dp[s + (1 << (k - 1))][k - 1]);
}

int get_max(int l, int r)
{
    int len = r - l + 1;
    int k = LOG2[len];
    return max(dp[l][k], dp[r + 1 - (1 << k)][k]);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        A[i] = read();
    init();
    for (int i = 1; i <= m; i++) {
        int r, l;
        r = read(), l = read();
        cout << get_max(r, l) << endl;
    }
    return 0;
}