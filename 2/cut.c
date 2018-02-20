#include <stdio.h>
#define MAX_CUT 50

#define MEMO

#ifdef MEMO
static int memo[MAX_CUT][MAX_CUT];
#endif

void init_memo(int n)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            memo[i][j] = -1;
}

int min_cost(int len[], int l, int u)
{
    int min;
    int m, i;

#ifdef MEMO
    if (memo[l][u] != -1) 
        return memo[l][u];
#endif

    if (l >= u)
        return 0;

    min = 10000;        /* XXX */
    for (i = l; i < u; i++) {
        int t;
        t = min_cost(len, l, i) + min_cost(len, i + 1, u);
        if (t < min)
            min = t;
    }

    m = 0;
    for (i = l; i <= u; i++)
        m += len[i];
#ifdef MEMO
    memo[l][u] = m + min;
#endif
    return m + min;
}

int costs[MAX_CUT][MAX_CUT];

void calculate_costs(int len[], int n)
{
    int i, j, k;
    int min;

    for (i = 0; i < n; i++)
        costs[i][i] = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int m = 0;
            int t;
            min = 10000;    /* XXX */

            for (k = i; k < j; k++)
                m += len[k];

            for (k = 0; k < j; k++) {
                t = costs[i][k] + costs[k + 1][j];
                if (t < min)
                    min = t;
            }

            costs[i][j] = m + min;
        }
    }
}

int main()
{
    int len[MAX_CUT + 2];
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &len[i]);

    calculate_costs(len, n);

    {
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", costs[i][j]);
            }
            printf("\n");
        }
    }
#ifdef MEMO
    init_memo(n);
#endif
#if 0
    {
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", min_cost(len, i, j));
            }
            printf("\n");
        }
    }
#endif

    printf("min: %d\n", min_cost(len, 0, n - 1));
    return 0;
}
