#include <stdio.h>
#include <stdlib.h>

#define N 100
#define M 1000

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int subset_sum(int s[], int n, int m)
{
    if (n == 0) {
        if (m == 0)
            return 1;
        else
            return 0;
    }

#if 0
    return max(subset_sum(s, n - 1, m - s[n - 1]), subset_sum(s, n - 1, m));
#endif
#if 1
	if (subset_sum(s, n - 1, m - s[n - 1]) == 1) {
        printf("[%d]", s[n - 1]);
        return 1;
    }
    if (subset_sum(s, n - 1, m) == 1) {
        return 1;
    }
    return 0;
#endif
}

int c[N][M];

void calculate_subset_sum(int s[], int n, int m)
{
    int i, j;

    for (i = 0; i <= n; i++)
        c[i][0] = 1;

    for (i = 1; i <= m; i++)
        c[0][i] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            c[i][j] = 0;

            if (j >= s[i - 1]) {
                if (c[i - 1][j - s[i - 1]] == 1)
                    c[i][j] = 1;
            }

            if (c[i - 1][j] == 1) {
                c[i][j] = 1;
            }
        }
    }
}

int main()
{
    int s[N];
    int n, m, i;

    printf("input m, n: ");
    scanf("%d %d", &m, &n);

    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);

#if 1
    printf("%d\n", subset_sum(s, n, m));
#endif

    calculate_subset_sum(s, n, m);
#if 1
    {
        int i, j;
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= m; j++)
                printf("%d ", c[i][j]);
            printf("\n");
        }
    }
#endif
    printf("%d\n", c[n][m]);

    return 0;
}
