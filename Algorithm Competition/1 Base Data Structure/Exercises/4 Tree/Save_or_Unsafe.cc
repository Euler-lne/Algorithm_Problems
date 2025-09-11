#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        string s;
        priority_queue<int, vector<int>, greater<int>> q;
        cin >> m >> s;
        sort(s.begin(), s.end());
        int num = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (s[i] != s[i - 1]) {
                q.push(num);
                num = 1;
            } else
                num++;
        }
        int ans = 0;
        if (q.size() == 1)
            ans = s.length();
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a + b);
            ans += (a + b);
        }
        cout << (m <= ans ? "yes" : "no") << endl;
    }
}