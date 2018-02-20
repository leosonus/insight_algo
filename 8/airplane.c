#include <stdio.h>
#include <stdlib.h>

#define T 100000
#define N 100

int rand_int(int n)
{
    return rand() % n;
}

int try() 
{
	int seat[N];
	int i, l;

	for(i=0; i<N; i++)
		seat[i] = 0;

	seat[rand_int(N)] = 1;

	for(i=1; i<N; i++) {
		l = i;
		while(seat[l] == 1) {
			l = rand_int(N);
		}
		seat[l] = 1;
	}
	return l;
}

int main()
{
	int i, t;
	int x = 0, y = 0;
	for(i=0; i<T; i++) {
		t = try();
		if (t == 0)
			x++;
		if (t == N - 1)
			y++;
	}
	printf("%d %d\n", x, y);
	return 0;
}
