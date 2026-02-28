// 使用二维前缀和，这样就可以快速计算某个正方形范围内的总价了

#include <iostream>

using namespace std;

int const MAX_SIZE = 5 * 1e3 + 1;

long long arr[MAX_SIZE + 5][MAX_SIZE + 5] = {0};

int n, m;
// 中心点点做法是不对的，因为有奇数和偶数

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    int ans = 0;
    while (n--) {
        int x, y, value;
        cin >> x >> y >> value;
        arr[x + 1][y + 1] += value;
    }
    for (int i = 1; i <= MAX_SIZE; i++) {
        for (int j = 1; j <= MAX_SIZE; j++) {
            arr[i][j] += (arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
        }
    }
    for (int i = m; i <= MAX_SIZE; i++) {
        for (int j = m; j <= MAX_SIZE; j++) {
            int damage = arr[i][j] - arr[i - m][j] - arr[i][j - m] + arr[i - m][j - m];
            ans = max(ans, damage);
        }
    }
    cout << ans;
    return 0;
}
