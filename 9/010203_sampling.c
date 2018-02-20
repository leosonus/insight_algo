#include <stdio.h>
#include <stdlib.h>

unsigned rand_int(int n)
{
    return rand() % n;
}

void sampling(int n, int m)
{
    int c = m, i;

    for (i = 0; i < n; i++) {
        if (rand_int(n - i) < c) {
            printf("%d\n", i);
            c--;
        }
#if 0
        if (c == 0)
            break;
#endif
    }
}

void sampling2(int n, int m)
{
    int a[n], x, i;

    for (i = 0; i < n; i++)
        a[i] = 0;
    for (i = 0; i < m; i++) {
        do {
            x = rand_int(n);
        } while (a[x] == 1);
        a[x] = 1;
        printf("%d\n", x);
    }
}

int main()
{
    int n, m;

    printf("input n, m: ");
    scanf("%d %d", &n, &m);
    sampling(n, m);
    return 0;
}
