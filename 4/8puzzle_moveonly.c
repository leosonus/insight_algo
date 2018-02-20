#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3
#define N 3
#define MAXH 1000000

static int depth[MAXH];

// copied
int fact(int n)
{
	int r = 1, i;

	for (i = 2; i <= n; i++)
		r *= i;
	return r;
}

// copied
int perm_count(int a[], int n)
{
	int r = 0, i, j, m;

	for (i = 0; i < n - 1; i++) {
		m = 0;
		for (j = 0; j < i; j++)
			if (a[j] < a[i])
				m++;

		r += (a[i] - m) * fact(n - i - 1);
	}
	return r;
}

// copied -------------- queue 
#define QUEUE_CAPACITY (1024*1024)

void *queue[QUEUE_CAPACITY];
int head = -1;
int tail = -1;
int queue_size = 0;

void enqueuep(void *p)
{
	if (queue_size == QUEUE_CAPACITY) {
		printf("queue full!\n");
		return;
	}

	tail = (tail + 1) % QUEUE_CAPACITY;
	queue_size++;
	queue[tail] = p;
}

void *dequeuep()
{
	if (queue_size == 0) {
		printf("queue empty!\n");
		return NULL;
	}
	head = (head + 1) % QUEUE_CAPACITY;
	queue_size--;
	return queue[head];
}

// --------------------



int check_puzzle(int arr[M][N])
{
	int i;

	for (i = 0; i < M * N - 1; i++)
		if (arr[i / N][i % N] != i + 1)
			return 0;

	if (arr[M - 1][N - 1] != 0)
		return 0;

	return 1;
}

#if 0
void print_puzzle(int a[M][N])
{
	int i, j;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
#endif 

#if 0
void *copy_state(int a[M][N])
{
	void *s;

	s = malloc(sizeof(int) * M * N);
	memcpy(s, a, sizeof(int) * M * N);
	return s;
}
#endif

void* slide(int arr[M][N], int x, int y)
{
	int (*p)[N];
	int i, j;
	int zm, zn, m, n;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				zm = i;
				zn = j;
			}
		}
	}

	m = zm + x;
	n = zn + y;

	if (m < 0 || m >= M || n < 0 || n >= N)
		return NULL;

	p = malloc(sizeof(int) * M * N);
	memcpy(p, arr, sizeof(int) * M * N);

	p[zm][zn] = p[m][n];
	p[m][n] = 0;
	return p;
}

void enqueue_state(int before, void *p, int m)
{
	int h = perm_count(p, M * N);
	if (before == -1) {
		depth[h] = 0;
	} else {
		if (depth[h] > 0)
			return;
		depth[h] = depth[before] + 1;
	}
	enqueuep(p);
}

int solve(int init[M][N])
{
	int (*a)[N];
	int (*p)[N];

	enqueue_state(-1, slide(init, 0, 0), 1);

	while ((a = dequeuep()) != NULL) {
		//printf("[%d]\n", queue_size);
		//print_puzzle(a);

		if (check_puzzle(a)) {
#if DEPTH
			printf("%d moves\n", depth[perm_count(a, M * N)]);
#else
			print_moves(perm_count(a, M * N));
#endif
			return 1;
		}

		int h = perm_count(a, M * N);

		p = slide(a, 0, -1);
		if (p != NULL)
			enqueue_state(h, p, 'U');

		p = slide(a, -1, 0);
		if (p != NULL)
			enqueue_state(h, p, 'L');

		p = slide(a, 1, 0);
		if (p != NULL)
			enqueue_state(h, p, 'R');

		p = slide(a, 0, 1);
		if (p != NULL)
			enqueue_state(h, p, 'D');

		free(a);
	}

	printf("impossible\n");
	return 0;
}

int main()
{
	int init[M][N];
	int i, j;

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &init[i][j]);

	solve(init);
	return 0;
}
