#include <stdio.h>

#define M 2
#define N 3

// -------------- queue 
#define Q 4096 

int* queue[Q];
int head = -1;
int tail = -1;
int queue_size = 0;

void enqueue(void* p) 
{
	if (queue_size == Q) {
		printf("queue full!");
		return;
	}
	tail = (tail + 1) % Q;
	queue_size++;
	queue[tail] = p;
}

void* dequeue()
{
	if (queue_size == 0)
		return NULL;
	head = (head + 1) % Q;
	queue_size--;
	return queue[head];
}

// --------------------

int* copy_state(int a[M][N])
{
	int* s;
	s = (int*) malloc(sizeof(int) * M * N);
	memcpy(s, a, sizeof(int) * M * N);
	return s;
}

int check(int a[M][N])
{
	int i, j;
	int t = 0;

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			if (a[i][j] != t)
				return 0;
			t++;
		}
	}
	return 1;
}

void print_state(int a[M][N])
{
	int i, j;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int sol2(int init[M][N]) 
{
	int i, j;
	int zm, zn;

	enqueue(copy_state(init));

	while(1) {
		int (*a)[N];

		a = dequeue();
		print_state(a);

		if (a == NULL)
			return 0;

		if (check(a)) {
			printf("found!\n");
			return 1;
		}

		for(i=0; i<M; i++) {
			for(j=0; j<N; j++) {
				if (a[i][j] == 0) {
					zm = i;
					zn = j;
				}
			}
		}

		if (zm > 0) {
			a[zm][zn] = a[zm-1][zn]; 
			a[zm - 1][zn] = 0; 
			enqueue(copy_state(a));
			a[zm-1][zn] = a[zm][zn]; 
			a[zm][zn] = 0; 
		}

		if (zn > 0) {
			a[zm][zn] = a[zm][zn-1]; 
			a[zm][zn - 1] = 0; 
			enqueue(copy_state(a));
			a[zm][zn-1] = a[zm][zn];
			a[zm][zn] = 0;
		}

		if (zm < M-1) {
			a[zm][zn] = a[zm+1][zn]; 
			a[zm+1][zn] = 0;
			enqueue(copy_state(a));
			a[zm+1][zn] = a[zm][zn]; 
			a[zm][zn] = 0;
		}

		if (zn < N-1) {
			a[zm][zn] = a[zm][zn+1]; 
			a[zm][zn+1] = 0;
			enqueue(copy_state(a));
			a[zm][zn+1] = a[zm][zn]; 
			a[zm][zn] = 0;
		}
		free(a);
	}
	return 0;
}

int sol(int a[M][N], int zm, int zn) 
{
	if (check(a))
		return 1;

	if (zm > 0) {
		a[zm][zn] = a[zm-1][zn]; 
		if (sol(a, zm-1, zn)) return 1;
		a[zm-1][zn] = a[zm][zn]; 
	}

	if (zn > 0) {
		a[zm][zn] = a[zm][zn-1]; 
		if (sol(a, zm, zn-1)) return 1;
		a[zm][zn-1] = a[zm][zn]; 
	}

	if (zm < M-1) {
		a[zm][zn] = a[zm+1][zn]; 
		if (sol(a, zm+1, zn)) return 1;
		a[zm+1][zn] = a[zm][zn]; 
	}

	if (zn < N-1) {
		a[zm][zn] = a[zm][zn+1]; 
		if (sol(a, zm, zn+1)) return 1;
		a[zm][zn+1] = a[zm][zn]; 
	}
	return 0;
}

int main() 
{
	int i, j;
	int n;
	int zm, zn;

	int init[M][N];

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &n);
			init[i][j] = n;
			if (n == 0) {
				zm = i;
				zn = j;
			}
		}
	}

	//sol(init, zm, zn);
	sol2(init);

	return 0;
}
