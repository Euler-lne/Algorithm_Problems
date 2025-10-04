/*
二分与差分

由差分变成需要的数组，然后与现有数组比较

错误原因：需要long long存放 diff和need
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> rend_num, start_day, end_day, rest;

bool check(int x)
{
    vector<long long> diff(n + 1, 0);
    vector<long long> need(n + 1, 0);
    for (int i = 0; i < x; i++) {
        diff[start_day[i]] += rend_num[i];
        if (end_day[i] != n)
            diff[end_day[i] + 1] -= rend_num[i];
    }
    for (int i = 1; i <= n; i++) {
        need[i] = need[i - 1] + diff[i];
        if (rest[i] < need[i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rest.resize(n + 1, 0);
    rend_num.resize(m);
    start_day.resize(m);
    end_day.resize(m);
    for (int i = 1; i <= n; i++)
        cin >> rest[i];
    for (int i = 0; i < m; i++)
        cin >> rend_num[i] >> start_day[i] >> end_day[i];
    int l = 1, r = m, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid; // 为false的可能是答案
    }
    if (l == m)
        cout << "0";
    else
        cout << "-1" << endl
             << l;
    return 0;
}