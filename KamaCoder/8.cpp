/*
 * 想的太复杂了，只需要计算高于平均数的累和就好了，注意输出格式
 * */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        vector<int> arr(n, 0);
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sum /= n;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > sum)
                count += (arr[i] - sum);
        }
        cout << count << endl;
        cin >> n;
    }
    return 0;
}
