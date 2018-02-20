#include <stdio.h>

int all_is(int arr[], int arr_len, int k)
{
	int i;

	for (i = 0; i < arr_len; i++)
		if (arr[i] != k)
			return 0;

	return 1;
}

void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void right_rotate(int arr[], int s, int t)
{
	int i, last;

	last = arr[t];
	for (i = t; i >= s + 1; i--)
		arr[i] = arr[i - 1];
	arr[s] = last;
}

void left_rotate(int arr[], int s, int t)
{
	int i, last;

	last = arr[s];
	for (i = s; i <= t - 1; i++)
		arr[i] = arr[i + 1];
	arr[t] = last;
}

void kright_rotate(int arr[], int s, int t, int k)
{
	int buf[k];
	int i;

	for(i = 0; i < k; i++)
		buf[i] = arr[t + 1 - k + i];

	for(i = t - k; i >= s; i--)
		arr[i + k] = arr[i];

	for(i = 0; i < k; i++)
		arr[s + i] = buf[i];
}

void reverse(int arr[], int s, int t)
{
	int i = s, j = t;
	int temp;

	while(i < j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

void kright_rotate2(int arr[], int s, int t, int k)
{
	reverse(arr, s, t - k);
	reverse(arr, t - k + 1, t);
	reverse(arr, s, t);
}

#define N 20

int main()
{
	int a[N], i;
	for (i = 0; i < N; i++) {
		a[i] = i;
	}
	//right_rotate(a, 3, 6);
	kright_rotate2(a, 10, 16, 3);
	print_arr(a, N);
	return 0;
}
