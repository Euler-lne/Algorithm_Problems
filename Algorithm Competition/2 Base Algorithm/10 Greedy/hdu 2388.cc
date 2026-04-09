// 贪心：优先选取结束时间最早
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct program {
    int s, e;
} Program;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        vector<Program> programs(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &programs[i].s, &programs[i].e);
        }
        sort(programs.begin(), programs.end(), [](const Program &a, const Program &b) {
            return a.e < b.e;
        });
        int ans = 0, front_end = 0;
        for (int i = 0; i < n; i++) {
            if (front_end <= programs[i].s) {
                ans++, front_end = programs[i].e;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}