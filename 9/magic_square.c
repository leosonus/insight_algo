#include <stdio.h>
#include <stdlib.h>

// copied
void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// copied
unsigned rand_int(int n)
{
    return rand() % n;
}

void rand_perm3(int a[], int n)
{
    int i, p;

    for(i=0; i < n; i++)
        a[i] = i + 1;
    for (i = 0; i < n - 1; i++) {
        p = rand_int(n - i);
        swap_arr(a, i, i+ p);
    }
}

void shuffle(int a[], int n)
{
    int i, p;

	for (i = 0; i < n - 1; i++) {
        p = rand_int(n - i);
        swap_arr(a, i, i+ p);
    }
}

#define N 4
int check_magic_square(int a[][N], int n)
{
	int sum1, sum2;
	int target = n * (n * n + 1) / 2;
	int i,j;

	for(i=0; i<N; i++) {
		sum1 = sum2 = 0;
		for(j=0; j<N; j++) {
			sum1 += a[i][j];
			sum2 += a[j][i];
		}

		if (sum1 != target || sum2 != target)
			return 0;
	}
	return 1;
}

int main()
{
	int a[N][N];
	int c = 0, t = 0;

	while(1) {
		t++;
		rand_perm3((int*) a, N * N);
		if (check_magic_square(a, N)) {
			c++;
			int j, k;
			for(j=0; j<N; j++) {
				for(k=0; k<N; k++)
					printf("%02d ", a[j][k]);
				printf("\n");
			}
			printf("%d/%d\n", c, t);
		}
	}

	return 0;
}
