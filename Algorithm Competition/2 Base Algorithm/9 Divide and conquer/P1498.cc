#include <cstdio>

int qpow(int b, int q)
{
    int ans = 1, a = b;
    while (q) {
        if (q & 1)
            ans = ans * a;
        a *= a;
        q >>= 1;
    }
    return ans;
}

void print_singal(int offset)
{
    /*
     /\
    /__\
    */
    for (int i = 0; i < offset; i++) {
        printf(" ");
    }
    printf(" /\\\n");
    for (int i = 0; i < offset; i++) {
        printf(" ");
    }
    printf("/__\\");
}

void print(int n, int offset)
{
    if (n == 1)
        print_singal(offset);
    else {
        print(n - 1, offset + qpow(2, n - 1));
        printf("\n");
        print(n - 1, offset);
        print(n - 1, offset + qpow(2, n - 2) * 3);
        // printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    print(n, 0);
    return 0;
}
/*
 /\
/__\
   /\
  /__\
 /\  /\
/__\/__\


*/