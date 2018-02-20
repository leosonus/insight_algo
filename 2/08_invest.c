#include <stdio.h>

#define MAXM 100
#define MAXN 100

int r[MAXN][MAXM];

int maxr(int n, int m)
{
    int max = -1, i, t;

    if (n == 0)
        return r[0][m];
    if (m == 0)
        return 0;
    
    for (i = 0; i <= m; i++) {
        t = maxr(n - 1, m - i) + r[n][i];
        if (t > max)
            max = t;
    }
    return max;
}

int max_return[MAXN][MAXM];

void calculate_return(int n, int m)
{
    int i, j, k, max, t;

    for (i = 0; i <= m; i++)
        max_return[0][i] = r[0][i];
    for (i = 1; i < n; i++)
        for (j = 1; j <= m; j++) {
            max = -1;
            for (k = 0; k <= j; k++) {
                t = max_return[i - 1][k] + r[i][j - k];
                if (t > max)
                    max = t;
            }
            max_return[i][j] = max;
        }
}

int main()
{
    int m, n, i, j;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        r[i][0] = 0;
    for (i = 1; i <= m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &r[j][i]);
   
    printf("Max return: %d\n", maxr(n - 1, m));
    
    calculate_return(n, m);
    printf("Max return: %d\n", max_return[n-1][m]);
#if 0
    printf("%d\n", max_return[n - 1][m]);
    for (i = 0; i <= m; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", maxr(j, i));
        printf("\n");
    }
    for (i = 0; i <= m; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", max_return[j][i]);
        printf("\n");
    }
#endif
    return 0;
}
