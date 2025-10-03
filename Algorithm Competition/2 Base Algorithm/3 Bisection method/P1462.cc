/*
思路是二分答案 + 最短路。
本题是要求在保证血量不变为负的前提下，
单次最大收费的最小值可以是多少。容易知道，
对于单次最大收费小于等于x xx的情形如果存在方案，
那么对于更大的x xx当然也存在方案。
从而我们可以用二分。由于起点和终点显然是要收费的，
所以二分左端点为max ⁡ { f1 , fn }；
单次最大收费的最大可能即为max fi，此为右端点。
对于每个位于区间内的x，我们判断只走收费不超过x的城市，
是否能从1走到n，也即判断从1走到n，如果将耗血量视为费用，
最短路长度是否小于等于b，可以用Dijkstra算法来做。
如果能，则收缩右端点；否则收缩左端点。
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

typedef struct Item {
    int idx;
    long long val;
    Item() : idx(0), val(0) {}
    Item(int i, long long v) : idx(i), val(v) {}
    // 重载 < 运算符
    /*
    * 不可以。重载 > 号对于默认的 priority_queue 是无效的。
        默认的 priority_queue 只使用 std::less，
        而 std::less 内部只调用 < 运算符：
    *
    * 返回大于号，最小堆；重载符号只用小于
    * */
    bool operator<(const Item &a) const
    {
        // 注意：在优先队列中，返回true表示当前对象的优先级低于a
        // 想让val小的优先级高，那么当当前val > a.val时，当前对象优先级更低
        return val > a.val; // 这里用 > 号
    }
} Item;
typedef struct GNode {
    int idx;
    int val;
    GNode *next;
} GNode;

using namespace std;
const int INF = 0x7fffffff;

int n, m, b;
vector<int> f;
vector<GNode *> g;

void InsertNode(int a, int b, int c)
{
    GNode *node = new GNode();
    node->idx = a - 1;
    node->val = c;
    node->next = g[b - 1];
    g[b - 1] = node;
}

int Dijkstra(int mid)
{
    priority_queue<Item> heap;
    vector<bool> visited(n, false);
    vector<long long> dist(n, -1);
    heap.push(Item(0, 0));
    dist[0] = 0;
    while (heap.size()) {
        int from_idx = heap.top().idx;
        long long cur_dist = heap.top().val;
        heap.pop();
        if (visited[from_idx])
            continue;
        visited[from_idx] = true;
        // 如果到达终点，可以提前结束
        if (from_idx == n - 1)
            break;
        for (GNode *node = g[from_idx]; node; node = node->next) {
            int to_index = node->idx;
            if (f[to_index] > mid || visited[to_index])
                continue;
            long long new_dist = cur_dist + node->val;
            if (dist[to_index] == -1 || new_dist < dist[to_index]) {
                dist[to_index] = new_dist;
                heap.push(Item(to_index, dist[to_index]));
            }
        }
    }
    return dist[n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> b;
    f.resize(n);
    g.resize(n, nullptr);
    int max_val = -1;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        if (f[i] > max_val)
            max_val = f[i];
    }
    int min_val = f[0] > f[n - 1] ? f[0] : f[n - 1]; // 要选大的
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        InsertNode(a, b, c);
        InsertNode(b, a, c);
    }
    int l = min_val, r = max_val, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        int min_blood = Dijkstra(mid);
        if (min_blood <= b && min_blood != -1)
            r = mid;
        else
            l = mid + 1;
    }
    int min_blood = Dijkstra(l);
    if (min_blood > b || min_blood == -1)
        cout << "AFK";
    else
        cout << l;

    // 释放内存
    for (int i = 0; i < n; i++) {
        GNode *node = g[i];
        while (node) {
            GNode *temp = node;
            node = node->next;
            delete temp;
        }
    }

    return 0;
}
