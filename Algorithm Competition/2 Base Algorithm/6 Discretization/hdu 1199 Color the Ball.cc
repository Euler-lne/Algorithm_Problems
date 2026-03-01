#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct
{
    int begin, end, id;
    bool is_white;
} Item;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        vector<Item> arr(n);
        vector<int> origin(n);
        for (int i = 0; i < n; i++) {
            int begin, end;
            char color;
            scanf("%d %d %c", &begin, &end, &color);
            arr[i].begin = begin;
            arr[i].end = end;
            arr[i].is_white = color == "w";
            arr[i].id = i;
        }
        sort(arr.begin(), arr.end(), [](Item a, Item b) {
            return a.begin < b.begin;
        });
        for (int i = 0; i < n; i++) {
            origin[arr[i].id] = i;
        }
        // 没有考虑到 [1,2,3,4] [3,3]也就是区间分裂的情况
        for (int i = 1; i < n; i++) {
            Item cur_item = arr[origin[i]];
            // 下面的球是黑色
            if (cur_item.is_white)
                continue;
            Item pre_item = arr[origin[i - 1]]; // 上一个区间，准备涂黑
            while (i >= 0 && pre_item.is_white && pre_item.end >= cur_item.begin) {
                pre_item.end = cur_item.begin - 1; // 满足要求涂黑
                i--;
                pre_item = arr[origin[i - 1]]; // 上一个区间，准备涂黑
            }
        }
    }
    return 0;
}