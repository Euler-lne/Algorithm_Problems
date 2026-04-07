#include <cstdio>
#include <vector>

using namespace std;
vector<int> output;
int quicksort(int left, int right, int k)
{
    int mid = output[left + (right - left) / 2];
    int i = left, j = right - 1;
    while (i <= j) {
        while (output[i] < mid)
            i++;
        while (output[j] > mid)
            j--;
        if (i <= j) {
            swap(output[i], output[j]);
            i++, j--;
        }
    }
    // 结束之后 所有 output[left ... j] 都 ≤ mid。
    //         所有 output[i ... right-1] 都 ≥ mid。
    if (left <= j && k <= j)
        return quicksort(left, j + 1, k);
    if (i < right && k >= i)
        return quicksort(i, right, k);
    return output[k];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        output.push_back(temp);
    }
    int k = n / 2;
    printf("%d\n", quicksort(0, n, k));
    return 0;
}