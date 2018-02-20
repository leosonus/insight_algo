#include <stdio.h>

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void comb(int set[], int set_size, int n, int k, int index)
{
    if (k == 0) {
        print_arr(set, set_size);
	} else if (index == n) {
        return;
	} else {
        set[set_size] = index;
        comb(set, set_size + 1, n, k - 1, index + 1);
        comb(set, set_size, n, k, index + 1);
    }
}

void comb2(int bits[], int n, int k, int index)
{
    int i;

    if (k == 0) {
        for (i = index; i < n; i++)
            bits[i] = 0;
        print_arr(bits, n);
    } else if (index == n) {
        return;
	} else {
        bits[index] = 0;
        comb2(bits, n, k, index + 1);
        bits[index] = 1;
        comb2(bits, n, k - 1, index + 1);
    }
}

#define MAXN 100

int main()
{
    int set[MAXN], n, k;

    printf("input n, k: ");
    scanf("%d %d", &n, &k);
    //comb(set, 0, n, k, 0);
    comb2(set, n, k, 0);
    return 0;
}
