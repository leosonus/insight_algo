#include <stdio.h>

#define MAXN 10

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// copied
void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void print_mperm(int arr[][MAXN], int r, int t)
{
	int i, j;

	for (i = 0; i < t; i++) {
		for (j = 0; j < r; j++)
			printf("%d ", arr[i][j]);
		printf("  ");
	}
	printf("\n");
}

void mperm(int arr[][MAXN], int index, int len, int n, int r, int t)
{
	int i;

	if (index == t) {
		print_mperm(arr, r, t);
		return;
	}

	if (len == r) {
		mperm(arr, index + 1, 0, n, r, t);
		return;
	}

	for (i = len; i < n; i++) {
		swap_arr(arr[index], i, len);
		mperm(arr, index, len + 1, n, r, t);
		swap_arr(arr[index], i, len);
	}
}

int main()
{
	int arr[MAXN][MAXN], n, r, t, i, j;

	printf("input n, r, t: ");
	scanf("%d %d %d", &n, &r, &t);
	for (i = 0; i < t; i++)
		for (j = 0; j < n; j++)
			arr[i][j] = j;

	mperm(arr, 0, 0, n, r, t);
	return 0;
}
