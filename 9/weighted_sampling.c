#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int weighted_rand_int(int n, int weight[], int total)
{
    int r, s = 0, i;

    r = rand() % total;
    for (i = 0; i < n; i++) {
        s += weight[i];
        if (s > r)
            break;
    }
    return i;
}

void weighted_sampling(int n, int m, int weight[], int total)
{
    int a[n], x, i;

    for (i = 0; i < n; i++)
        a[i] = 0;
    for (i = 0; i < m; i++) {
        do {
            x = weighted_rand_int(n, weight, total);
        } while (a[x] == 1);
        a[x] = 1;
        printf("%d ", x);
    }
}

int main()
{
    int i;
    int w[8] = {1, 2, 1, 2, 1, 2, 1, 2};

    for(i=0; i<1200; i++) {
        weighted_sampling(8, 2, w, 12);
        printf("\n");
    }
    return 0;
}
