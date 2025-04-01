#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    bool dict[1000] = {false};
    int count = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        if (!dict[cur])
        {
            count++;
            if (q.size() == m)
            {
                int temp = q.front();
                dict[temp] = false;
                q.pop();
            }
            q.push(cur);
            dict[cur] = true;
        }
    }
    cout << count;
    return 0;
}