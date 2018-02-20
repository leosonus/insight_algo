#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int head = 0;
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
	void* r;
	if (queue_size == 0) {
		printf("queue empty!\n");
		return NULL;
	}
	r = queue[head];
	head = (head + 1) % QUEUE_CAPACITY;
	queue_size--;
	return r;
}

// --------------------

#define M 3
#define N 3

#define MAXH 362880 

char move[MAXH];
int from[MAXH];

void print_moves(int h)
{
	if (from[h] < 0)
		return;
	print_moves(from[h]);
	printf("%c", move[h]);
}

int check_puzzle(int puzzle[M][N])
{
	int i;

	for (i = 0; i < M * N - 1; i++)
		if (puzzle[i / N][i % N] != i + 1)
			return 0;

	if (puzzle[M - 1][N - 1] != 0)
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

void* slide(int puzzle[M][N], int x, int y)
{
	int (*p)[N];
	int i, j;
	int zm, zn, m, n;

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			if (puzzle[i][j] == 0) {
				zm = i;
				zn = j;
			}

	m = zm + x;
	n = zn + y;

	if (m < 0 || m >= M || n < 0 || n >= N)
		return NULL;

	p = malloc(sizeof(int) * M * N);
	memcpy(p, puzzle, sizeof(int) * M * N);

	p[zm][zn] = p[m][n];
	p[m][n] = 0;
	return p;
}

void enqueue_state(int previous_state_number, void *state, char m)
{
	int state_number = perm_count(state, M * N);
	if (move[state_number])
		return;
	move[state_number] = m;
	from[state_number] = previous_state_number;
	enqueuep(state);
}

void solve_puzzle(int initial[M][N])
{
	int (*state)[N];
	int (*next_state)[N];

	enqueue_state(-1, slide(initial, 0, 0), 1);

	while ((state = dequeuep()) != NULL) {
		if (check_puzzle(state)) {
			print_moves(perm_count((int*) state, M * N));
			free(state);
			return;
		}

		int state_number = perm_count((int *) state, M * N);

		next_state = slide(state, -1, 0);
		if (next_state != NULL)
			enqueue_state(state_number, next_state, 'U');

		next_state = slide(state, 0, -1);
		if (next_state != NULL)
			enqueue_state(state_number, next_state, 'L');

		next_state = slide(state, 0, 1);
		if (next_state != NULL)
			enqueue_state(state_number, next_state, 'R');

		next_state = slide(state, 1, 0);
		if (next_state != NULL)
			enqueue_state(state_number, next_state, 'D');

		free(state);
	}
	printf("impossible\n");
}

int main()
{
	int initial[M][N];
	int i, j;

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &initial[i][j]);

	solve_puzzle(initial);
	return 0;
}
