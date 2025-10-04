#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 本题类似与 1147 连续自然数和

const int INF = 0x7fffffff;

int n, m;
vector<int> x;

bool check(int mid)
{
    int ans = 1;
    for (int i = 1, pre = 0; i < n; i++) {
        if (x[i] - x[pre] < mid)
            continue;
        else {
            ans++;
            pre = i;
        }
    }
    return ans >= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int max_val = -1, min_val = INF;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        x.push_back(t);
    }
    sort(x.begin(), x.end(), [](int a, int b) { return a < b; });
    int l = 1, r = x[n - 1] - x[0], mid;
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