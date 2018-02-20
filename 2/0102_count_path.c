#include <stdio.h>

#define M 100
#define N 100

int map[M][N];

long long num_path(int m, int n)
{
    if (map[m][n] == 0)
        return 0;
    if (m == 0 && n == 0)
        return 1;

    return ((m > 0) ? num_path(m - 1, n) : 0)
        + ((n > 0) ? num_path(m, n - 1) : 0);
}

long long path[M][N];

void calculate_path(int m, int n)
{
    int i, j;

    path[0][0] = map[0][0];
    for (i = 1; i < m; i++) {
        if (map[i][0] == 0)
            path[i][0] = 0;
        else
            path[i][0] = path[i - 1][0];
    }
    for (j = 1; j < n; j++) {
        if (map[0][j] == 0)
            path[0][j] = 0;
        else
            path[0][j] = path[0][j - 1];
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (map[i][j] == 0)
                path[i][j] = 0;
            else
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }
}

int main()
{
    int m, n, i, j;

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
#if 0
    printf("%lld\n", num_path(m - 1, n - 1));
#endif
#if 1
    calculate_path(m, n);
    #if 0
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%lld ", path[i][j]);
            }
            printf("\n");
        }
    #endif
    printf("%lld\n", path[m - 1][n - 1]);
#endif
    return 0;
}
