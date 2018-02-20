#include <stdio.h>

#define MAXM 10
#define MAXN 10

int r[MAXM][MAXN];
int max;

void t(int inv[], int m, int n, int k)
{
    int i;
    int earn;

    if (k == n) {
	earn = 0;
	for (i = 0; i < n; i++)
	    earn += r[inv[i]][i];

	if (earn > max) {
	    max = earn;
	    /*
	       for(i=0; i<n; i++)
	       printf("%d ", inv[i]);
	       printf("\n");
	     */
	}

	return;
    }

    for (i = 0; i <= m; i++) {
	inv[k] = i;
	t(inv, m - i, n, k + 1);
    }
}

int main()
{
    int m, n;
    int i, j;
    int inv[MAXN];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
	r[i][0] = 0;

    for (i = 1; i <= m; i++)
	for (j = 0; j < n; j++)
	    scanf("%d", &r[j][i]);

    t(inv, m, n, 0);
    printf("%d\n", max);
    return 0;
}
