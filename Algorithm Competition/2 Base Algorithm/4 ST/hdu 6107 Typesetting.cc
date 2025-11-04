#include <iostream>
#define N 100005

using namespace std;

int n, q, dw, pw, w;
int character[N];
int f1[N][20], f2[N][20], LOG2[N];

void init()
{
    for (int i = 1; i <= n; i++) {
        int cnt = character[i], j = i + 1;
        while (cnt + character[j] + 1 <= w && j <= n) // character[j] 能否放入
            cnt += character[j++] + 1;
        f1[i][0] = j - i; // 最小值为1
    }
    for (int k = 1; k <= LOG2[n]; k++) {
        for (int s = 1; s <= n; s++) {
            f1[s][k] = f1[s][k - 1] + (f1[s][k - 1] + s > n ? 0 : f1[f1[s][k - 1] + s][k - 1]);
            // 下一个部分的位置 f1[s][k - 1] + s，上一部分包含的单词 f1[s][k - 1]
        }
    }

    for (int i = 1; i <= n; i++) {    // 不能按照之前的来，因为可能一个都放不了
        int cnt = 0, j = i, flag = 0; // flag表示这个是不是第一个，第一个不用加空格
        while (cnt + character[j] + flag <= dw && j <= n)
            cnt += character[j++] + flag, flag = 1;
        flag = 0, cnt = 0;
        while (cnt + character[j] + flag <= w - dw - pw && j <= n)
            cnt += character[j++] + flag, flag = 1;
        f2[i][0] = j - i; // 可能为0
    }
    for (int k = 1; k <= LOG2[n]; k++) {
        for (int s = 1; s <= n; s++)
            if (f2[s][k - 1] == 0) // 可能存在前面一个都放不下的情况，不分情况也是对的0+0=0
                f2[s][k] = 0;
            else
                f2[s][k] = f2[s][k - 1] + f2[s + f2[s][k - 1]][k - 1];
    }
}

int befor_picture(int end)
{
    int cnt = 0;
    for (int k = LOG2[end]; k >= 0; k--) {
        if (cnt <= n - 1 && cnt + f1[cnt + 1][k] <= n) {
            cnt += f1[cnt + 1][k];
        }
    }
    return cnt; // 返回照片前能放多少字符
}
int between_picture(int start, int height)
{
    int cnt = start; // 字符累计
    for (int k = LOG2[height]; k >= 0; k--) {
        if (cnt <= n - 1 && cnt + f2[cnt + 1][k] <= n) {
            cnt += f2[cnt + 1][k];
        }
    }
    return cnt; // 返回到照片结束能放的字符总数
}

int get_line_from(int start) // 返回照片照片结束还需要多少行
{
    int ret = 0;
    while (start <= n) {
        int j = 0;
        while (start + f1[start][j + 1] <= n) // 尝试 j+1，退出的时候就是j
            j++;
        start += f1[start][j];
        ret += (1 << j);
    }
    return ret;
}

int min_line(int start, int height)
{
    int cnt, l;
    cnt = befor_picture(start - 1);
    if (cnt >= n)
        return height + get_line_from(1);
    cnt = between_picture(cnt, height);
    if (cnt >= n)
        return height + start - 1;
    l = get_line_from(cnt + 1);
    return l + height + start - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    LOG2[0] = -1;
    for (int i = 1; i <= N; i++)
        LOG2[i] = LOG2[i >> 1] + 1;
    while (t--) {
        cin >> n >> w >> pw >> dw;
        for (int i = 1; i <= n; i++)
            cin >> character[i];
        init();
        cin >> q;
        for (int i = 1; i <= q; i++) {
            int x, h;
            cin >> x >> h;
            cout << min_line(x, h) << endl;
        }
    }
    return 0;
}