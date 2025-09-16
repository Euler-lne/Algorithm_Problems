#include <iostream>
#include <queue>
/*
‌解题关键步骤‌：

1. 使用大根堆存储较小的一半数，最大只要小于小根堆顶
2. 使用小根堆存储较大的一半数，最小的这个数要大于大根堆顶
3. 保持两个堆的大小平衡 !!!
4. 在奇数位置时输出大根堆的堆顶元素

*/
using namespace std;
/// @brief 大小根堆，priority_queue默认大根
/// @return
int main()
{
    ios::sync_with_stdio(false);
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (max_heap.empty() && min_heap.empty())
            max_heap.push(temp);
        else if (min_heap.empty()) {
            // 只有插入第二个元素才进入这一步
            int max_h = max_heap.top();
            if (max_h > temp) {
                max_heap.pop();
                max_heap.push(temp);
                min_heap.push(max_h);
            } else
                min_heap.push(temp);
        } else if (!max_heap.empty() && !min_heap.empty()) {
            int max_h = max_heap.top();
            int min_h = min_heap.top();
            if (temp <= min_h) // 要放在大根堆
            {
                max_heap.push(temp);
                if (max_heap.size() > min_heap.size() + 1) {
                    max_h = max_heap.top();
                    max_heap.pop();
                    min_heap.push(max_h);
                }
            } else {
                min_heap.push(temp);
                if (min_heap.size() > max_heap.size()) {
                    min_h = min_heap.top();
                    min_heap.pop();
                    max_heap.push(min_h);
                }
            }
        }
        if ((i + 1) % 2) {
            // 奇数
            cout << max_heap.top() << endl;
        }
    }

    return 0;
}