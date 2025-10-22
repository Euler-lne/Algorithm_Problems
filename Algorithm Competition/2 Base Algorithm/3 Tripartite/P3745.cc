#include <algorithm>
#include <iostream>

typedef long long ll;

using namespace std;
/*
对于操作操作1,21,21,2我们可以做如下变形:

使用代价为AAA, 将一列最上方的块移到另一列
使用代价为BBB, 将一列最上方的块移除(直接消失)
显然:

如果B≤AB\le AB≤A, 那么可以用BBB来代替AAA
如果A≤BA\le BA≤B, 优先将凸出来的部分 (绿色部分) 转移到空缺的部分
(蓝色部分) .如果仍有剩余, 就用222号操作消除
* */
const int N = 100005;
int n, m, t[N], b[N];
ll A, B, C, ans;

ll calc1(int p) // 计算通过A, B 操作把时间调到p的不愉快度
{
    ll x = 0, y = 0;
    for (int i = 1; i <= m; i++) {
        if (b[i] < p)
            x += p - b[i]; // 小于p的天数
        else
            y += b[i] - p; // 超过P的天数
    }
    // 如果x小说明小于p的天数不足以使用A操作
    // 如果x大则说明直接使用A操作就好了
    return A < B ? min(x, y) * A + (y - min(x, y)) * B : y * B;
}

ll calc2(int p) // 计算 第p天释放成绩学生的不愉快度
{
    ll sum;
    for (int i = 1; i <= n; i++) {
        if (t[i] < p)
            sum += (p - t[i]) * C;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> A >> B >> C >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(t + 1, t + n + 1); // 默认升序
    sort(b + 1, b + m + 1);
    if (C >= 1e16) {
        cout << calc1(t[1]) << endl; // 不能让学生等待
        return 0;
    }
    ans = 1e16;
    int l = 1, r = N;
    while (r - l > 2) {
        int mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        ll c1 = calc1(mid1) + calc2(mid1);
        ll c2 = calc1(mid2) + calc2(mid2);
        // 越小越接近答案
        if (c1 <= c2)
            r = mid2;
        else
            l = mid1;
    }
    for (int i = l; i <= r; i++) {
        ll x = calc1(i) + calc2(i);
        ans = min(ans, x);
    }
    cout << ans << endl;
    return 0;
}