#include <iostream>
using namespace std;

int main()
{
    int nodeList[100];
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        nodeList[i] = i + 1;
    }
    nodeList[n - 1] = 0;
    int cur = 0, pre = n - 1;
    while (nodeList[cur] != cur)
    {
        for (int i = 1; i < m; i++)
        {
            cur = nodeList[cur];
            pre = nodeList[pre];
        }
        cout << cur + 1 << " ";
        nodeList[pre] = nodeList[cur];
        cur = nodeList[cur];
    }
    cout << cur + 1;
    return 0;
}