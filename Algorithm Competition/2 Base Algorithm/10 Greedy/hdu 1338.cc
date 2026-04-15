#include <cstdio>
#include <cstring>

int main()
{
    int m, n, caseNum = 0;
    while (scanf("%d%d", &m, &n) == 2 && (m || n)) {
        int total = m * n;
        bool my[1005] = {false}; // 标记自己的牌
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            my[x] = true;
        }

        int cnt = 0, win = 0;
        for (int i = total; i >= 1; --i) {
            if (my[i]) { // 我的牌
                if (cnt == 0)
                    ++win;
                else
                    --cnt;
            } else { // 对手的牌
                ++cnt;
            }
        }
        printf("Case %d: %d\n", ++caseNum, win);
    }
    return 0;
}