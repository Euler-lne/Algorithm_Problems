#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<char, string> map;

void preorder(char cur)
{
    if (cur == '*')
        return;
    cout << cur;
    preorder(map[cur][1]);
    preorder(map[cur][2]);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    char start;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (i == 0)
            start = s[0];
        map.insert(pair<char, string>(s[0], s));
    }
    preorder(start);
    return 0;
}