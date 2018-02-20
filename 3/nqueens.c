#include <stdio.h>
#define MAXN 20

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

void print_board(int set[], int set_size)
{
    int i, j;
    for(i=0; i<set_size; i++) {
        for(j=0; j<set[i]; j++) printf(".");
        printf("Q");
        for(j+=1; j<set_size; j++) printf(".");

        printf("\n");
    }
    for(i=0; i<set_size; i++)
        printf("=");
    printf("\n");
}            

void check(int set[], int set_size)
{
    int i;
    int l1[2*set_size-1];
    int l2[2*set_size-1];

    for(i=0; i < 2*set_size-1; i++)
        l1[i] = l2[i] = 0;

    for(i=0; i < set_size; i++) {
        if (l1[i+set[i]] == 1) return;
        if (l2[i-set[i] + set_size - 1] == 1) return;

        l1[i+set[i]] = 1;
        l2[i-set[i] + set_size - 1] = 1;
    }

    for(i=0; i<set_size;i++)
        printf("%d ", set[i]);
    printf("\n");
    print_board(set, set_size);
}

void perm(int arr[], int l, int n, int r)
{
    int i;
    if (r == 0) {
        check(arr, l);
        return;
    }

    for(i=l; i < n; i++) {
        swap_arr(arr, i, l);
        perm(arr, l+1, n, r-1);
        swap_arr(arr, i, l);
    }
}

int main()
{
    int n, r;
    int arr[MAXN];
    int i;

    scanf("%d", &n);
    for(i=0; i<n; i++) 
        arr[i] = i;

    perm(arr, 0, n, n);
    return 0;
}
