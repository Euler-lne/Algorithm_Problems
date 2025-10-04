#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 本题类似与 1147 连续自然数和

const int INF = 0x7fffffff;

int n, m;
vector<int> x;

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
    return 0;
}