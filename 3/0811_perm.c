#include <stdio.h>

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

// copied
void right_rotate(int arr[], int a, int b)
{
	int i, t;

	t = arr[b];
	for (i = b; i >= a + 1; i--)
		arr[i] = arr[i - 1];
	arr[a] = t;
}

// copied
void left_rotate(int arr[], int a, int b)
{
	int i, t;

	t = arr[a];
	for (i = a; i <= b - 1; i++)
		arr[i] = arr[i + 1];
	arr[b] = t;
}


void perm(int arr[], int len, int n, int k)
{
	int i;

	if (len == k) {
		print_arr(arr, len);
		return;
	}

	for (i = len; i < n; i++) {
		swap_arr(arr, i, len);
		perm(arr, len + 1, n, k);
		swap_arr(arr, i, len);
	}
}

void perm2(int arr[], int len, int n, int k)
{
	int i;

	if (len == k) {
		print_arr(arr, len);
		return;
	}

	for (i = len; i < n; i++) {
		right_rotate(arr, len, i);
		perm2(arr, len + 1, n, k);
		left_rotate(arr, len, i);
	}
}

#define MAXN 10

int main()
{
	int arr[MAXN], n, k, i;

	printf("input n, k: ");
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		arr[i] = i;
	perm(arr, 0, n, k);
	//perm2(arr, 0, n, k);
	return 0;
}
