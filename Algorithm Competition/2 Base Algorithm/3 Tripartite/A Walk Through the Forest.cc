#include <iostream>
#include <queue>
#include <vector>

#define INF 9999999
using namespace std;

typedef long long ll;

int const N = 1005;
int M[N][N] = {0};

int n;
ll dis[N];
int vis[N] = {0}, dp[N];

typedef struct Node {
    int indx;
    ll val;
    Node(int _indx, ll _val) : indx(_indx), val(_val) {}
    bool operator<(const Node &a) const // 需要小根堆
    {
        return val > a.val; // x < a 返回 false x 优先级高，这里是优先级的比较
    }
} Node;

void init()
{
    for (int i = 0; i <= n; i++) {
        dis[i] = dp[i] = -1;
        vis[i] = 0;
        for (int j = 0; j <= n; j++)
            M[i][j] = M[j][i] = 0;
    }
}

void Dijsktra(int s) // s 为源点
{
    priority_queue<Node> que;
    for (int i = 1; i <= n; i++) {
        if (M[s][i]) {
            dis[i] = M[s][i];
            Node node(i, dis[i]);
            que.push(node);
        }
    }
    dis[s] = 0;
    vis[s] = 1;
    while (!que.empty()) {
        Node min_node = que.top();
        que.pop();
        int u = min_node.indx;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[i] || !M[u][i])
                continue;
            int new_dist = dis[u] + M[u][i];
            if (dis[i] == -1 || new_dist < dis[i]) {
                dis[i] = new_dist;
                que.push(Node(i, dis[i]));
            }
        }
    }
}

int dfs(int v) // v 代表终点
{
    if (dp[v] != -1)
        return dp[v];
    if (v == 2) // 起点
        return 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[v] > dis[i] && M[v][i])
            sum += dfs(i);
    }
    dp[v] = sum;
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n && n) {
        int m;
        cin >> m;
        init();
        for (int i = 1; i <= m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            M[a][b] = M[b][a] = d;
        }
        Dijsktra(2);
        cout << dfs(1);
        cout << endl;
    }
    return 0;
}