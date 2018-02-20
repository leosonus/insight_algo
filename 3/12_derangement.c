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

void dperm(int arr[], int len, int n, int k)
{
	int i;

	if (len == k) {
		print_arr(arr, len);
		return;
	}

	for (i = len; i < n; i++) {
		if (arr[i] == len) 
			continue;
		swap_arr(arr, i, len);
		dperm(arr, len + 1, n, k);
		swap_arr(arr, i, len);
	}
}

#define MAXN 10

int main()
{
	int arr[MAXN], n, i;

	printf("input n: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		arr[i] = i;
	dperm(arr, 0, n, n);
	return 0;
}
