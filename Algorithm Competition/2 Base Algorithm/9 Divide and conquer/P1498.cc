#include <cstdio>

char map[1024][2048];

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

void print_singal(int offsetx, int offsety)
{
    /*
     /\
    /__\
    */
    map[offsety][offsetx + 1] = '/';
    map[offsety][offsetx + 2] = '\\';
    map[offsety + 1][offsetx] = '/';
    map[offsety + 1][offsetx + 1] = '_';
    map[offsety + 1][offsetx + 2] = '_';
    map[offsety + 1][offsetx + 3] = '\\';
}

void print(int n, int offsetx, int offsety)
{
    if (n == 1)
        print_singal(offsetx, offsety);
    else {
        print(n - 1, offsetx + qpow(2, n - 1), offsety);
        print(n - 1, offsetx, offsety + qpow(2, n - 1));
        print(n - 1, offsetx + qpow(2, n), offsety + qpow(2, n - 1));
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    print(n, 0, 0);
    for (int i = 0; i < qpow(2, n); i++) {
        for (int j = 0; j <= qpow(2, n) + i; j++) {
            if (!map[i][j])
                map[i][j] = ' ';
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
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