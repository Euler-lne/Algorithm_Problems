#include <iostream>
#include <vector>

#define INF 9999999
using namespace std;

typedef long long ll;

int const N = 1005;
int M[N][N] = {0};

int n;
ll dis[N];
int vis[N], dp[N];

void Dijsktra(int s) // s 为源点
{
    for (int i = 1; i < n; i++) {
        dis[i] = -1;
        vis[i] = 0;
    }
    dis[s] = 0;
    vis[s] = 1;
}

int dfs(int v) // v 代表终点
{
}

int main()
{
    ios::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        M[a][b] = d, M[b][a] = d;
    }
    Dijsktra(2);
    cout << dfs(1);
    return 0;
}