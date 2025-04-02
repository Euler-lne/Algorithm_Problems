#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    deque<int> dq;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
        {
            while (!dq.empty() && dq.front() + k <= i)
                dq.pop_front();
            cout << a[dq.front()] << " ";
        }
    }
    cout << endl;
    while (!dq.empty())
        dq.pop_back();
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
        {
            while (!dq.empty() && dq.front() + k <= i)
                dq.pop_front();
            cout << a[dq.front()] << " ";
        }
    }
    delete[] a;
    return 0;
}