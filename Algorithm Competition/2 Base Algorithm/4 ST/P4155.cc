#include <algorithm>
#include <cmath>
#include <iostream>

#define N 200005

using namespace std;

typedef struct Item {
    int idx, l, r;
} Item;
Item w[N * 2];
int go[N][20]; // 2^20 远大于M
int n, m;
int res[N];

void init()
{
    int nxt = 1;
    for (int i = 1; i <= n * 2; i++) {
        while (nxt <= n * 2 && w[nxt].l <= w[i].r) // 找到刚好不相交的下一个
            nxt++;
        go[i][0] = nxt - 1; // 应为是下一个所以-1才是相交的下一个
    }
    for (int i = 1; (1 << i) <= n; i++) {
        for (int s = 1; s <= n * 2; s++) {
            go[s][i] = go[go[s][i - 1]][i - 1];
        }
    }
}
void getans(int x)
{
    int len = w[x].l + m, cur = x, ans = 1;
    for (int i = log2(n); i >= 0; i--) {
        int pos = go[cur][i];
        if (pos && w[pos].r < len) {
            cur = pos;
            ans += 1 << i;
        }
    }
    res[w[x].idx] = ans + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i].l >> w[i].r;
        w[i].idx = i;
        if (w[i].r < w[i].l)
            w[i].r += m;
    }
    sort(w + 1, w + n + 1, [](Item a, Item b) {
        return a.l < b.l;
    });
    for (int i = n + 1; i <= n * 2; i++) {
        w[i].l = w[i - n].l + m;
        w[i].r = w[i - n].r + m;
        w[i].idx = w[i - n].idx;
    }
    init();
    for (int i = 1; i <= n; i++)
        getans(i);
    for (int i = 1; i <= n; i++)
        cout << res[i] << endl;
    return 0;
}