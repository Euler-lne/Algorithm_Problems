#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n, *h;
    cin >> n;
    h = new int[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && h[i] > h[s.top()])
        {
            h[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        h[s.top()] = 0;
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << h[i];
        if (i != n - 1)
            cout << endl;
    }
    delete[] h;
    return 0;
}