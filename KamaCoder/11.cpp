#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a, b;
    vector<int> arr(31, 0);
    while (cin >> n)
    {
        int i;
        for (i = 0; i < arr.size(); i++)
            arr[i] = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a >> b;
            arr[a] = b; // 保存映射关系
        }
        a = b = 0;
        i = 1; // 小明
        while (i)
        {
            i = arr[i];
            a++;
        }
        i = 2; // 小鱼
        while (i)
        {
            i = arr[i];
            b++;
        }
        if (a > b)
            cout << "You are my elder";
        else if (a < b)
            cout << "You are my younger";
        else
            cout << "You are my brother";
        cout << endl;
    }
    return 0;
}