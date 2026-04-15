#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Enemy {
    int dps, hp;
    Enemy() : dps(0), hp(0) {}
};

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        vector<Enemy> enemys(n);
        int total_damge = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &enemys[i].dps, &enemys[i].hp);
            total_damge += enemys[i].dps; // 每一轮可能造成的伤害
        }
        sort(enemys.begin(), enemys.end(), [](Enemy &a, Enemy &b) {
            // 按 dps/hp 降序，交叉相乘避免浮点 平均！！
            return a.dps * b.hp < b.dps * a.hp;
        });
        while (enemys.size()) {
            Enemy last = enemys[enemys.size() - 1];
            ans += total_damge * last.hp;
            total_damge -= last.dps;
            enemys.pop_back();
        }
        printf("%d\n", ans);
    }
    return 0;
}