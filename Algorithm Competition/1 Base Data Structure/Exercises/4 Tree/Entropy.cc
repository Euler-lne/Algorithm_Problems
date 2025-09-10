#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    while (s != "END") {
        cin >> s;
        int char_num = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end())
                m[s[i]]++;
            else {
                m.insert(pair<char, int>(s[i], 1));
                char_num++;
            }
        }
    }
}