#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        q.push(t);
    }
    int ans = 0;
    if (q.size() == 1)
        ans = q.top();
    while (q.size() > 1) {
        int h1, h2;
        h1 = q.top();
        q.pop();
        h2 = q.top();
        q.pop();
        ans += h1 + h2;
        q.push(h1 + h2);
    }
    cout << ans;
    return 0;
}