#include <stdio.h>

#define MAXN 20

int fact(int n)
{
	int r = 1, i;

	for (i = 2; i <= n; i++)
		r *= i;
	return r;
}

int perm_count(int a[], int n)
{
	int r = 0, i, j, m;

	for (i = 0; i < n - 1; i++) {
		m = 0;
		for (j = 0; j < i; j++)
			if (a[j] < a[i])
				m++;

		r += (a[i] - m) * fact(n - i - 1);
	}
	return r;
}

int main()
{
	int a[MAXN];
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("%d\n", perm_count(a, n));

	return 0;
}
