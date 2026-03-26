#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int h;
            scanf("%d", &h);
            if (mp[h].size() == 0) {
                mp[h].push_back(1);
            }
            mp[h].push_back(i);
        }
        for (int i = 0; i < m; i++) {
            int q;
            scanf("%d", &q);
            if (mp.find(q) != mp.end()) {
                int len = mp[q][0];
                if (len >= mp[q].size()) // 这里为大于等于
                    printf("-1\n");
                else {
                    printf("%d\n", mp[q][len] + 1);
                    mp[q][0]++;
                }
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}