#include <iostream>
#include <string>

using namespace std;
string s;
string ans;

int postoder(int from, int to)
{
    if (from == to) {
        cout << (s[from] == '1' ? 'I' : 'B');
        return s[from] - '0';
    }

    int mid = (from + to) / 2;

    int l = postoder(from, mid);
    int r = postoder(mid + 1, to);

    if (l == r) {
        if (l != -1)
            cout << (l == 1 ? 'I' : 'B');
        else
            cout << 'F';
        return l;
    } else {
        cout << 'F';
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> s;
    postoder(0, s.length() - 1);
    return 0;
}
