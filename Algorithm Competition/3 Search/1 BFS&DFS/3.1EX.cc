#include <iostream>
using namespace std;
const int N = 1005;
string mp[N];
int visit[N][N] = {0};
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// 深度/广度 搜索陆地
// 依照科学家的预测，照片中有多少岛屿会被完全淹没。
int n, flag;
void dfs(int x, int y)
{
    if (x > n || y > n || x < 1 || y < 1)
        return;
    visit[x][y] = 1;
    if (mp[x][y + 1] == '#' && mp[x][y - 1] == '#' &&
        mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
        flag = 1; // 有高地
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (visit[nx][ny] == 0 && mp[nx][ny] == '#')
            dfs(nx, ny); // 为了标记这个岛
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mp[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visit[i][j] == 0 && mp[i][j] == '#') {
                flag = 0;
                dfs(i, j);
                if (flag == 0)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}