#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> arr;
int n, m;

void add(int a, int b, int c, int d);

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    arr.resize(n + 2, vector<int>(n + 2, 0));
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] += (arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1]);
            cout
                << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
void add(int a, int b, int c, int d)
{
    arr[a][b] += 1;
    arr[a][d + 1] -= 1;
    arr[c + 1][b] -= 1;
    arr[c + 1][d + 1] += 1;
}
