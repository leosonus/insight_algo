#include <stdio.h>
#include <stdlib.h>

#define N 1000

int a[N];

void preprocess()
{
	return;
}

int sum(int i, int j)
{
	int s = 0, k;

	for (k = i; k < j; k++)
		s += a[k];
	return s;
}

int s[N + 1][N + 1];

void preprocess2()
{
	int i, j, k;

	for (i = 0; i <= N; i++) {
		for (j = i; j <= N; j++) {
			s[i][j] = 0;
			for (k = i; k < j; k++)
				s[i][j] += a[k];
		}
	}
}

int sum2(int i, int j)
{
	return s[i][j];
}

int t[N + 1];

void preprocess3()
{
	int i;

	t[0] = 0;
	for (i = 1; i <= N; i++)
		t[i] = t[i - 1] + a[i - 1];
}

int sum3(int i, int j)
{
	return t[j] - t[i];
}

int main()
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % 1000;

	preprocess3();
	printf("%d\n", sum3(0, 20));
	printf("%d\n", sum3(10, 100));
	printf("%d\n", sum3(5, 500));
	printf("%d\n", sum3(0, 0));
	printf("%d\n", sum3(N - 1, N));
	printf("%d\n", sum3(0, N));
	printf("%d\n", sum3(1, 0));
	return 0;
}
