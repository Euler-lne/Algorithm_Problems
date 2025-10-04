#include <iostream>
#include <vector>

using namespace std;

int dist, n, m;
vector<int> d;

bool check(int mid)
{
    int count = 0;
    for (int cur = 0, pre = -1; cur <= n; cur++) {
        int t = pre == -1 ? 0 : d[pre];
        if (d[cur] - t < mid)
            count++;
        else
            pre = cur;
    }
    return count <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> dist >> n >> m;
    d.resize(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    d.push_back(dist); // 这样处理 输入n为0的时候也不会报错
    int l = 1, r = dist, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}