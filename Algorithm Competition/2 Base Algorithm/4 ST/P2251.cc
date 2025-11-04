#include <iostream>
#include <queue>

#define N 100005

using namespace std;
int q[N];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && q[dq.back()] > q[i])
            dq.pop_back();
        while (!dq.empty() && i - dq.front() + 1 > m)
            dq.pop_front();
        dq.push_back(i);
        if (i >= m)
            cout << q[dq.front()] << endl;
    }
    return 0;
}