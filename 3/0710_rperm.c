#include <stdio.h>

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void rperm(int arr[], int len, int n, int k)
{
	int i;

	if (len == k) {
		print_arr(arr, len);
		return;
	}

	for (i = 0; i < n; i++) {
		arr[len] = i;
		rperm(arr, len + 1, n, k);
	}
}

void rperm2(int arr[], int n, int k)
{
	int i;

	for (i = 0; i < k; i++)
		arr[i] = 0;
	while (1) {
		print_arr(arr, k);

		arr[k - 1]++;
		for (i = k - 1; arr[i] == n; i--) {
			if (i == 0)
				return;
			arr[i - 1]++;
			arr[i] = 0;
		}
	}
}

#define MAXN 10

int main()
{
	int arr[MAXN], n, k;

	printf("input n, k: ");
	scanf("%d %d", &n, &k);
	//rperm(arr, 0, n, k);
	rperm2(arr, n, k);
	return 0;
}
