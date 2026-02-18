#include <cstdio>

const int MAX_N = 100 + 2;

int arr[MAX_N][MAX_N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, c;
        scanf("%d %d", &s, &c);
        for (int i = 0; i < s; i++)
            scanf("%d", &arr[0][i]);
        int same_index = s - 1;
        for (int i = 1; i < s; i++) {
            bool is_same = true;
            for (int j = 0; i + j < s; j++) {
                arr[i][j] = arr[i - 1][j + 1] - arr[i - 1][j];
                if (j > 0)
                    is_same &= (arr[i][j] == arr[i][j - 1]);
            }
            if (is_same) {
                same_index = i;
                break;
            }
        }
        for (int i = 0; i < (s + c); i++) {
            arr[same_index + 1][i] = 0;
        }
        for (int i = same_index; i >= 0; i--) {
            for (int j = s - same_index; j < (s + c); j++) {
                arr[i][j] = arr[i][j - 1] + arr[i + 1][j - 1];
            }
        }
        printf("%d", arr[0][s]);
        for (int i = s + 1; i < (s + c); i++)
            printf(" %d", arr[0][i]);
        if (t)
            printf("\n");
    }
    return 0;
}