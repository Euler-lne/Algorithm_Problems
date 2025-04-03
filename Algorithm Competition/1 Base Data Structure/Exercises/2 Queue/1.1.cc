#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    deque<int> dq;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() + m < i)
            dq.pop_front();

        if (i == 0)
            cout << "0" << endl;
        else
            cout << arr[dq.front()] << endl;

        while (!dq.empty() && arr[i] < arr[dq.back()])
            dq.pop_back(); //      如果当前的值小于末尾的值那么找到合适的位置
        dq.push_back(i);
    }
    delete[] arr;
    return 0;
}