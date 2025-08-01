#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    stack<int> s;
    a[0] = n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) { // 栈里大数在底
            a[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        a[s.top()] = 0;
        s.pop();
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}