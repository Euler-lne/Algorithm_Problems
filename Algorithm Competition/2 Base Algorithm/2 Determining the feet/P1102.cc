#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, c;

    long long ans = 0;
    cin >> n >> c;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (m.find(t) == m.end())
            m.insert(pair<int, int>(t, 1));
        else
            m[t]++;
    }
    for (auto key : m) {
        if (m.find(key.first + c) != m.end()) {
            ans += (long long)key.second * m[key.first + c];
        }
    }
    cout << ans;
    return 0;
}