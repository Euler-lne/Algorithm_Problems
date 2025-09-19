#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool is_ok = true;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                is_ok = false;
                break;
            }
        }
        if (is_ok)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}