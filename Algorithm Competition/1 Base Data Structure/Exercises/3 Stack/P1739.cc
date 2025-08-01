#include <iostream>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    int s = 0;
    for (int i = 0; str[i] != '@'; i++) {
        if (str[i] == '(')
            s++;
        else if (str[i] == ')')
            s--;
        if (s < 0) { // 字符串 "())("
            cout << "NO";
            return 0;
        }
    }
    cout << (s == 0 ? "YES" : "NO");
    return 0;
}