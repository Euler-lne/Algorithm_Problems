#include <iostream>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, character, count = 0;
    queue<int> que;
    unordered_map<int, bool> map;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        cin >> character;
        if (map.empty() || map.find(character) == map.end()) {
            // 数据不存在内存中
            count++;
            if (que.size() >= m) {
                map.erase(que.front());
                que.pop();
            }
            que.push(character);
            map[character] = true;
        }
    }
    cout << count;
    return 0;
}
