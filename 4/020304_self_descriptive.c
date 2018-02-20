#include <stdio.h>

#define min(x, y) (((x) < (y)) ? (x):(y))
#define CALL_COUNT

#ifdef CALL_COUNT
long call = 0;
#endif

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int check_self_descriptive2(int arr[], int len)
{
	int i, count[len];

#ifdef CALL_COUNT
	call++;
#endif
	for (i = 0; i < len; i++)
		count[i] = 0;
	for (i = 0; i < len; i++)
		count[arr[i]]++;
	for (i = 0; i < len; i++)
		if (arr[i] != count[i])
			return 0;
	return 1;
}


int check_self_descriptive(int arr[], int len)
{
	int i, j, count;

#ifdef CALL_COUNT
	call++;
#endif

	for (i = 0; i < len; i++) {
		count = 0;
		for (j = 0; j < len; j++)
			if (i == arr[j])
				count++;
		if (count != arr[i])
			return 0;
	}
	return 1;
}

void rperm_self_descriptive(int arr[], int len, int n, int k)
{
	int i;

	if (len == k) {
		if (check_self_descriptive(arr, len))
			print_arr(arr, len);
		return;
	}

	for (i = 0; i < n; i++) {
		arr[len] = i;
		rperm_self_descriptive(arr, len + 1, n, k);
	}
}

void rperm_self_descriptive2(int arr[], int len, int n, int k)
{
	int i, t = 0;

	if (len == k) {
		if (check_self_descriptive(arr, len))
			print_arr(arr, len);
		return;
	}
	for (i = 0; i < len; i++)
		if (arr[i] == len)
			t++;

	for (i = t; i < n; i++) {
		arr[len] = i;
		rperm_self_descriptive2(arr, len + 1, n, k);
	}
}

void rperm_self_descriptive3(int arr[], int len, int n, int k)
{
	int i, t = 0, s = 0;

	if (len == k) {
		if (check_self_descriptive(arr, len))
			print_arr(arr, len);
		return;
	}
	for (i = 0; i < len; i++) {
		if (arr[i] == len)
			t++;
		s += arr[i];
	}

	for (i = t; i <= n - s; i++) {
		arr[len] = i;
		rperm_self_descriptive3(arr, len + 1, n, k);
	}
}

void rperm_self_descriptive4(int arr[], int l, int n, int r, int s)
{
	int i, t;

	if (r == 0) {
		check_self_descriptive(arr, l);
		return;
	}

	t = 0;
	for (i = 0; i < l; i++)
		if (arr[i] == l)
			t++;

	for (i = t; i < min(t + (n - l), n - s + 1); i++) {
		arr[l] = i;
		rperm_self_descriptive4(arr, l + 1, n, r - 1, s + i);
	}
}

#define MAXN 20

int main()
{
	int arr[MAXN], n;

	scanf("%d", &n);
	rperm_self_descriptive3(arr, 0, n, n);

#ifdef CALL_COUNT
	printf("call: %ld\n", call);
#endif
	return 0;
}
