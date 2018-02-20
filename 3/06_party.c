#include <stdio.h>

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


#define MAXN 100

int friend_count[MAXN], friend[MAXN][MAXN];
int min_cut = MAXN * MAXN, min_partition[MAXN];

void evaluate_partition(int set[], int n)
{
	int cut = 0, i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < friend_count[i]; j++)
			if (i < friend[i][j] && set[i] != set[friend[i][j]])
				cut++;
	if (cut < min_cut) {
		for (i = 0; i < n; i++)
			min_partition[i] = set[i];
		min_cut = cut;
	}
}

void comb2_partition(int bits[], int n, int k, int index)
{
	int i;

	if (k == 0) {
		for (i = index; i < n; i++)
			bits[i] = 0;
		evaluate_partition(bits, n);
	} else if (index == n) {
		return;
	} else {
		bits[index] = 0;
		comb2_partition(bits, n, k, index + 1);
		bits[index] = 1;
		comb2_partition(bits, n, k - 1, index + 1);
	}
}

int main()
{
	int set[MAXN], n, i, j;

	printf("input n: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("%d: ", i);
		scanf("%d", &friend_count[i]);
		for (j = 0; j < friend_count[i]; j++)
			scanf("%d", &friend[i][j]);
	}
	comb2_partition(set, n, n / 2, 0);

	printf("cut: %d\n", min_cut);
	print_arr(min_partition, n);
	return 0;
}
