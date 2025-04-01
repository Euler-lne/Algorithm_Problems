#include <iostream>
using namespace std;

class Memory
{
public:
    Memory(int n)
    {
        memory = new int[n + 1];
        front = 0;
        tail = 0;
        size = n;
    }
    ~Memory()
    {
        delete memory;
        memory = nullptr;
    }
    bool IsEmpty();
    bool IsFull();
    int GetLen();
    int Pop();
    void Push(int val);

private:
    int *memory;
    int size;
    int front;
    int tail;
};

bool Memory::IsEmpty()
{
    return front == tail;
}

bool Memory::IsFull()
{
    return (front + 1) % (size + 1) == tail;
}

int Memory::GetLen()
{
    return (front - tail) % (size + 1);
}

int Memory::Pop()
{
    if (IsEmpty())
        return -1;
    int val = memory[tail];
    tail++;
    tail %= (size + 1);
    return val;
}

void Memory::Push(int val)
{
    if (IsFull())
        return;
    memory[front] = val;
    front++;
    front %= (size + 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    bool dict[1000] = {false};
    Memory M(m);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        if (!dict[cur])
        {
            count++;
            if (M.IsFull())
            {
                int temp = M.Pop();
                dict[temp] = false;
            }
            M.Push(cur);
            dict[cur] = true;
        }
    }
    cout << count;
    return 0;
}