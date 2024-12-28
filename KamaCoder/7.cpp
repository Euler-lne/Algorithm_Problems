#include <iostream>
using namespace std;
int score[4] = {4, 3, 2, 1};
int main()
{
    string s;
    while (getline(cin, s))
    {
        int flag = 1;
        float sum = 0, count = 0;
        for (char c : s)
        {
            if (c == ' ')
                continue;
            if (c >= 'A' && c <= 'F' && c != 'E')
            {
                count++;
                if (c <= 'D')
                    sum += score[c - 'A'];
            }
            else
            {
                cout << "Unknown" << endl;
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%.2f\n", sum / count);
    }
    return 0;
}