#include <iostream>
#include <vector>

using namespace std;
class Heap
{
private:
    vector<int> heap;

public:
    void push(int val)
    {
        heap[0]++;
        if (heap.size() < heap[0] + 1)
            heap.push_back(val);
        else
            heap[heap[0]] = val;

        int p = heap[0] / 2, cur = heap[0];
        while (p != 0 && heap[p] > heap[cur]) {
            int temp = heap[cur];
            heap[cur] = heap[p];
            heap[p] = temp;

            cur = p;
            p = cur / 2;
        }
    }
    int top()
    {
        return heap[0] > 0 ? heap[1] : 0;
    }
    void pop()
    {
        if (heap[0] == 0)
            return;
        heap[1] = heap[heap[0]];
        heap[0]--;
        int p = 1, c;
        while (p * 2 <= heap[0]) {
            if (p * 2 + 1 <= heap[0])
                c = heap[p * 2] < heap[p * 2 + 1] ? p * 2 : p * 2 + 1;
            else
                c = p * 2;
            if (heap[p] > heap[c]) {
                int temp = heap[c];
                heap[c] = heap[p];
                heap[p] = temp;
            } else
                break;
            p = c;
        }
    }
    Heap()
    {
        heap.push_back(0);
    }
};
int main()
{
    int n;
    cin >> n;
    Heap heap;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        switch (type) {
        case 1:
            int val;
            cin >> val;
            heap.push(val);
            break;
        case 2:
            cout << heap.top() << endl;
            break;
        case 3:
            heap.pop();
            break;
        default:
            break;
        }
    }
}