#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define INF 0x7fffffff
// （排序后的）前缀和 + 尺取法
using namespace std;

const int maxn = 1e5 + 10;
struct node {
    int id, sum;
} a[maxn];

bool cmp(node &p, node &q)
{
    return p.sum < q.sum; // 从小到到，左边小于右边
}

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    while (n && k) {
        a[0].id = 0;
        a[0].sum = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a[i].id = i;
            a[i].sum = a[i - 1].sum + x;
        }
        sort(a, a + 1 + n, cmp);
        for (int i = 0; i < k; i++) {
            int t, l = 0, r = 1, len = INF, lans, rans, ans;
            cin >> t;
            while (r <= n) {
                int cur = a[r].sum - a[l].sum; // 这个数字一定是正的，但是要用原来的右边减去左边
                if (abs(cur - t) < len) {
                    lans = a[l].id;
                    rans = a[r].id;
                    len = abs(cur - t);
                    ans = cur;
                }
                if (cur < t)
                    r++;
                else if (cur > t)
                    l++;
                else
                    break;
                if (r == l)
                    r++; // r 要比 l 大 1 由于前缀和
            }
            if (lans > rans)
                swap(lans, rans);
            cout << ans << " " << lans + 1 << " " << rans << endl;
        }
        cin >> n >> k;
    }

    return 0;
}