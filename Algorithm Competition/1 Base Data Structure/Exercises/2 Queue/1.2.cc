#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    int n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<int> arr(n);
    deque<int> dq;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && arr[i] > arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
        {
            while (!dq.empty() && dq.front() + k <= i)
                dq.pop_front();
            cout << arr[dq.front()] << endl;
        }
    }
    return 0;
}