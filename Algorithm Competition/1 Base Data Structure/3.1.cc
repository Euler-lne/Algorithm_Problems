#include <iostream>
using namespace std;

template <typename T>
class Deque
{
public:
    Deque(int n, bool isMax)
    {
        array_ = new T[n + 1];
        size_ = n + 1;
        front = 0;
        back = 0;
        isMax_ = isMax;
    }
    ~Deque() { delete[] array_; }
    bool IsEmpty() { return front == back; }
    bool IsFull() { return (front + 1) % size_ == back; }
    T Front() { return array_[(front - 1 + size_) % size_]; }
    T Back() { return array_[back]; }
    int GetSize() { return (front - back + size_) % size_; }
    void Push(int index, T *array);
    void Pop() { PopFront(); }
    void Print();

private:
    bool isMax_;
    int *array_;
    int front, back;
    int size_;
    void PopFront();
    void PopBack();
    void PushFront(T e);
    void PushBack(T e);
};
int main()
{
    int n, k;
    cin >> n >> k;
    Deque<int> dq1(k, false);
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        dq1.Push(i, a);
        if (i >= k - 1)
        {
            while (!dq1.IsEmpty() && dq1.Front() + k <= i)
                dq1.Pop();
            cout << a[dq1.Front()] << " ";
        }
    }
    cout << endl;
    Deque<int> dq2(k, true);
    for (int i = 0; i < n; i++)
    {
        dq2.Push(i, a);
        if (i >= k - 1)
        {
            while (!dq2.IsEmpty() && dq2.Front() + k <= i)
                dq2.Pop();
            cout << a[dq2.Front()] << " ";
        }
    }
    delete[] a;
    return 0;
}

template <typename T>
void Deque<T>::Push(int index, T *array)
{
    if (IsFull())
        Pop();
    if (isMax_)
        while (!IsEmpty() && array[index] > array[Back()])
            PopBack();
    else
        while (!IsEmpty() && array[index] < array[Back()])
            PopBack();
    PushBack(index);
}

template <typename T>
void Deque<T>::Print()
{
    int i = back;
    cout << "长度 " << GetSize() << " ";
    while (i != front % size_)
    {
        cout << array_[i] << " ";
        i++;
        i %= size_;
    }
    cout << endl;
}

template <typename T>
void Deque<T>::PopFront()
{
    int index = (front - 1 + size_) % size_;
    front = index;
}

template <typename T>
void Deque<T>::PopBack()
{
    back++;
    back %= size_;
}

template <typename T>
void Deque<T>::PushFront(T e)
{
    array_[front] = e;
    front++;
    front %= size_;
}

template <typename T>
void Deque<T>::PushBack(T e)
{
    back = back - 1 + size_;
    back %= size_;
    array_[back] = e;
}
