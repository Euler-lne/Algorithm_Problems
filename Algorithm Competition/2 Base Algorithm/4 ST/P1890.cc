#include <iostream>
using namespace std;

const int N = 1005;

int m, n, a[N];
int st[N][10];
int LOG2[N];

int gcd(int, int);
int gcd_range(int, int);
void init();

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << gcd_range(l, r) << endl;
    }
    return 0;
}

void init()
{
    LOG2[0] = -1;
    for (int i = 1; i <= N; i++)
        LOG2[i] = LOG2[i >> 1] + 1;

    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int j = 1; j <= LOG2[n]; j++) {
        for (int i = 1; i <= n; i++) {
            if (i + (1 << j) - 1 <= n)
                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int gcd_range(int start, int end)
{
    int len = end - start + 1;
    int p = LOG2[len];
    return gcd(st[start][p], st[end - (1 << p) + 1][p]);
    // 注意这里应该是 end - (1<<p) + 1，你原来写的是 end - p + 1，这是错误的！
}