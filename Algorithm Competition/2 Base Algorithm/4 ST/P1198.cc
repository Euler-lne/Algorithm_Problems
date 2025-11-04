#include <iostream>
#define N 100

using namespace std;
int dp_min[N][20], LOG2[N];
int t, n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int idx = 0;
    LOG2[0] = -1;
    for (int i = 1; i <= N; i++)
        LOG2[i] = LOG2[i >> 1] + 1;
    t = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        long long num;
        cin >> c >> num;
        switch (c) {
        case 'A': {
            num += t;
            num %= m;
            idx++;
            dp_min[idx][0] = num;
            int cur_idx = idx;
            for (int i = 1; i <= LOG2[idx]; i++) {
                cur_idx -= (1 << (i - 1));
                dp_min[cur_idx][i] = max(dp_min[cur_idx][i - 1], dp_min[cur_idx + (1 << (i - 1))][i - 1]);
            }
            break;
        }
        case 'Q': {
            int k = LOG2[num], l = idx + 1 - num;
            t = max(dp_min[l][k], dp_min[idx - (1 << k) + 1][k]);
            cout << t << endl;
            break;
        }
        }
    }
    return 0;
}
