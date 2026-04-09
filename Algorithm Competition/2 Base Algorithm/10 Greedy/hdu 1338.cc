// 田忌赛马

#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) == 2 && m != 0 && n != 0) {
        vector<int> card(n * m + 1, -1);
        for (int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            card[t] = 1;
        }
        // 1自己有 -1代表对手有，0代表已经出牌了
    }
    return 0;
}