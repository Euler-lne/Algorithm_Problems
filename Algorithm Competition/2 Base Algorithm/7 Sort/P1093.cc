#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct score {
    int total, id, chinese;
    score(int total, int id, int chinese)
    {
        this->total = total;
        this->id = id;
        this->chinese = chinese;
    }
} Score;

int main()
{
    int n;
    scanf("%d", &n);
    vector<Score> scores;
    for (int i = 1; i <= n; i++) {
        int c, m, e;
        scanf("%d%d%d", &c, &m, &e);
        Score score(c + m + e, i, c);
        scores.push_back(score);
    }
    sort(scores.begin(), scores.end(), [&](Score a, Score b) {
        if (a.total == b.total) {
            if (a.chinese == b.chinese)
                return a.id < b.id;
            return a.chinese > b.chinese;
        }
        return a.total > b.total;
    });
    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", scores[i].id, scores[i].total);
    }
    return 0;
}