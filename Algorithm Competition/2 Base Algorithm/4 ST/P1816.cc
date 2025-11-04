#include <iostream>
#define N 100005

using namespace std;

int bill[N], dp[N][20], LOG2[N];
int m, n;

void init()
{
    LOG2[0] = -1;
    for (int i = 1; i <= m; i++)
        LOG2[i] = LOG2[i >> 1] + 1;
    for (int i = 1; i <= m; i++)
        dp[i][0] = bill[i];
    for (int k = 1; (1 << k) <= m; k++) {
        for (int s = 1; s + (1 << (k - 1)) <= m; s++) {
            dp[s][k] = min(dp[s][k - 1], dp[s + (1 << (k - 1))][k - 1]);
        }
    }
}
int get_min(int l, int r)
{
    int len = r - l + 1;
    int k = LOG2[len];
    return min(dp[l][k], dp[r + 1 - (1 << k)][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> bill[i];
    init();
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        cout << get_min(l, r) << " ";
    }
    return 0;
}