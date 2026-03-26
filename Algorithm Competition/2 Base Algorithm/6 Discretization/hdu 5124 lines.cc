#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> x(n), y(n), line;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            line.push_back(x[i]);
            line.push_back(y[i]);
        }
        sort(line.begin(), line.end());
        line.erase(unique(line.begin(), line.end()), line.end());
        map<int, int> mp;
        for (int i = 0; i < line.size(); i++) {
            mp[line[i]] = i;
        }
        vector<long long> diff(line.size() + 1, 0);
        for (int i = 0; i < n; i++) {
            int l = x[i], r = y[i];
            // 做差分
            diff[mp[l]]++;
            diff[mp[r] + 1]--;
        }
        long long ans = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
            if (diff[i] > ans)
                ans = diff[i];
        }
        printf("%lld", ans);
    }
    return 0;
}