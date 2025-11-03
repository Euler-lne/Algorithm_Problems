#include <iostream>

#define N 1005

using namespace std;

int n, dp_max[N][10], h[N], LOG2[N];
int max(int a, int b)
{
    return a > b ? a : b;
}
void init()
{
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        dp_max[i][0] = h[i];
    for (int k = 1; k <= LOG2[n]; k++)
        for (int s = 1; s + (1 << k) - 1 <= n; s++)
            dp_max[s][k] = max(dp_max[s][k - 1], dp_max[s + (1 << (k - 1))][k - 1]);
}

int interval_max(int L, int R)
{
    int len = R - L + 1;
    int k = LOG2[len];
    return max(dp_max[L][k], dp_max[R - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    LOG2[0] = -1;
    for (int i = 1; i <= N; i++)
        LOG2[i] = LOG2[i >> 1] + 1;
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        int q;
        cin >> q;
        while (q--) {
            int L, R;
            cin >> L >> R;
            cout << interval_max(L, R) << endl;
        }
    }
    return 0;
}