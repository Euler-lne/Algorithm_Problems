#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        int n;
        scanf("%d", &n);
        vector<int> x1(n), x2(n), y1(n), y2(n), value(n);
        vector<int> xs, ys;
        unordered_map<int, int> xmp, ymp;
        for (int i = 0; i < n; ++i) {
            int a, b, c, d, v;
            scanf("%d%d%d%d%d", &a, &b, &c, &d, &v);
            x1[i] = a;
            y1[i] = b;
            x2[i] = c;
            y2[i] = d;
            value[i] = v;
            xs.push_back(a);
            xs.push_back(c);
            ys.push_back(b);
            ys.push_back(d);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        int xm = xs.size(), ym = ys.size();
        for (int i = 0; i < xm; ++i)
            xmp[xs[i]] = i;
        for (int i = 0; i < ym; ++i)
            ymp[ys[i]] = i;

        vector<vector<long long>> grid(ym, vector<long long>(xm, 0));
        for (int k = 0; k < n; ++k) {
            int xl = xmp[x1[k]], xr = xmp[x2[k]];
            int yl = ymp[y1[k]], yr = ymp[y2[k]];
            int v = value[k];
            for (int i = yl; i < yr; ++i) {
                for (int j = xl; j < xr; ++j) {
                    if (grid[i][j] < v)
                        grid[i][j] = v; // 取最大值
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < ym - 1; ++i) {
            int h = ys[i + 1] - ys[i];
            for (int j = 0; j < xm - 1; ++j) {
                int w = xs[j + 1] - xs[j];
                ans += 1LL * w * h * grid[i][j];
            }
        }
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}