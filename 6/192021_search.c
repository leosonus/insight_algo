#include <stdio.h>
#include <stdlib.h>
#include "pbook_time.h"

int sequential_search(int v, int arr[], int len)
{
	int i;

	for (i = 0; i < len; i++)
		if (arr[i] == v)
			return i;
	return -1;
}


int binary_search(int v, int arr[], int len)
{
	int low, high, mid;

	low = 0;
	high = len - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (v < arr[mid])
			high = mid - 1;
		else if (v > arr[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int ternary_search(int v, int arr[], int len)
{
	int low, high, m1, m2;

	low = 0;
	high = len - 1;
	while (low <= high) {
		m1 = (2 * low + high) / 3;
		m2 = (low + 2 * high) / 3;

		if (v < arr[m1]) {
			high = m1 - 1;
		} else if (v == arr[m1]) {
			return m1;
		} else if (v < arr[m2]) {
			low = m1 + 1;
			high = m2 - 1;
		} else if (v == arr[m2]) {
			return m2;
		} else {		//  v > arr[m2]
			low = m2 + 1;
		}
	}
	return -1;
}

#define SEARCH(x, y, z) sequential_search(x,y,z)
//#define SEARCH(x, y, z) binary_search(x,y,z)
//#define SEARCH(x, y, z) ternary_search(x,y,z)

#define N_ELEMENTS 100000000

int main()
{
	int *a;
	int i;

	a = (int *) malloc(sizeof(int) * N_ELEMENTS);

	a[0] = 0;
	for (i = 1; i < N_ELEMENTS; i++) {
		if (rand() % 2)
			a[i] = a[i - 1];
		else
			a[i] = a[i - 1] + 3;
	}

#if 0
	for (i = 0; i < 10000; i++) {
		int r1, r2, r3;
		printf("s%d\n", i);
		r1 = sequential_search(i, a, N_ELEMENTS);
		printf("b%d\n", i);
		r2 = binary_search(i, a, N_ELEMENTS);
		printf("t%d\n", i);
		r3 = ternary_search(i, a, N_ELEMENTS);

		if (r1 != -1 && a[r1] != i) {
			printf("error!");
			exit(0);
		}

		if (r2 != -1 && a[r2] != i) {
			printf("error!");
			exit(0);
		}

		if (r3 != -1 && a[r3] != i) {
			printf("error!");
			exit(0);
		}
	}
#endif

	START_TIME;
	printf("%d\n", SEARCH(120000000, a, N_ELEMENTS));
	printf("%d\n", SEARCH(1000, a, N_ELEMENTS));
	printf("%d\n", SEARCH(0, a, N_ELEMENTS));
	printf("%d\n", SEARCH(3, a, 1));
	printf("%d\n", SEARCH(6, a, 2));
	printf("%d\n", SEARCH(9, a, 4));
	printf("%d\n", SEARCH(9, a, 20));
	END_TIME;
	return 0;
}
