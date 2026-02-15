#include <iostream>
#include <vector>

using namespace std;
vector<long long> arr;
const long long MAX_X = 1e5 + 1;
const long long OFFSET = MAX_X * 3;

int n, m;

void set(int l, int r, int s, int e, int d);
void build();

// 问题1，set时候的边界条件
// 问题2，从哪里加到哪里了，要从1加到m+OFFSET
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    arr.resize(OFFSET + m + OFFSET, 0);
    while (n--) {
        int v, x;
        cin >> v >> x;
        set(x - 3 * v + 1, x - 2 * v, 1, v, 1);
        set(x - 2 * v + 1, x, v - 1, -v, -1);
        set(x + 1, x + 2 * v, -v + 1, v, 1);
        set(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
    }
    build();
    for (int i = 1; i <= m; i++)
        cout << arr[i + OFFSET] << " ";
    return 0;
}

void set(int l, int r, int s, int e, int d)
{
    arr[l + OFFSET] += s;
    arr[l + OFFSET + 1] += d - s;
    arr[r + OFFSET + 1] -= (e + d);
    arr[r + OFFSET + 2] += e;
}

void build()
{
    for (int i = 1; i <= m + OFFSET; i++)
        arr[i] += arr[i - 1];
    for (int i = 1; i <= m + OFFSET; i++)
        arr[i] += arr[i - 1];
}
