#include <iostream>

#define N 50005

using namespace std;
int n;
int h[N], LOG2[N];
int dp_max[N][22], dp_min[N][22];

void init()
{
    LOG2[0] = -1;
    for (int i = 1; i <= N; i++) {
        LOG2[i] = LOG2[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        dp_max[i][0] = h[i];
        dp_min[i][0] = h[i];
    }
    for (int k = 1; k <= LOG2[n]; k++) {
        for (int s = 1; s + (1 << k) <= n + 1; s++) {
            dp_max[s][k] = max(dp_max[s][k - 1], dp_max[s + (1 << (k - 1))][k - 1]);
            dp_min[s][k] = min(dp_min[s][k - 1], dp_min[s + (1 << (k - 1))][k - 1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    init();
    while (m--) {
        int l, r, len, k;
        cin >> l >> r;
        len = r - l + 1;
        k = LOG2[len];
        int _max = max(dp_max[l][k], dp_max[r - (1 << k) + 1][k]); // k 代表2^k
        int _min = min(dp_min[l][k], dp_min[r - (1 << k) + 1][k]);
        cout << _max - _min << endl;
    }
    return 0;
}