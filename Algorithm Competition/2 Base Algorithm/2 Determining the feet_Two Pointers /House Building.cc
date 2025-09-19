#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        int w, h, ans = 0;
        cin >> h >> w;
        vector<vector<int>> arr(h + 2, vector<int>(w + 2, 0));
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> arr[i][j];
                if (arr[i][j]) // 顶层
                    ans++;
            }
        }
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if (arr[i][j] - arr[i][j + 1] > 0)
                    ans += arr[i][j] - arr[i][j + 1];

        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if (arr[i][j] - arr[i][j - 1] > 0)
                    ans += arr[i][j] - arr[i][j - 1];

        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if (arr[i][j] - arr[i + 1][j] > 0)
                    ans += arr[i][j] - arr[i + 1][j];

        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if (arr[i][j] - arr[i - 1][j] > 0)
                    ans += arr[i][j] - arr[i - 1][j];
        cout << ans << endl;
    }
    return 0;
}