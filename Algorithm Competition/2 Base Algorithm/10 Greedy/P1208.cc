#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Cow {
    int p, a;
    Cow() : p(0), a(0) {};
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Cow> cows(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &cows[i].p, &cows[i].a);
    }
    sort(cows.begin(), cows.end(), [](Cow a, Cow b) {
        return a.p < b.p;
    });
    long long cost = 0;
    for (int i = 0; i < m; i++) {
        if (n > cows[i].a) {
            n -= cows[i].a;
            cost += cows[i].a * cows[i].p;
        } else {
            cost += n * cows[i].p;
            break;
        }
    }
    printf("%lld", cost);
    return 0;
}