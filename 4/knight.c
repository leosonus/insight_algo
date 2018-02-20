#include <stdio.h>

#define M 8
#define N 8
	
int board[M][N];

void traverse(m, n)
{
	m = M, n = N;
	int i, j;

	for(i=0; i<m; i++) 
		for(j=0; j<n; j++)
			board[m][n] = 0;

	t(m, n, 0, 0, 1);
}

void print()
{
	int i, j;

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%2d ", board[i][j]);
		}
		printf("\n");
	}
}

void t(int m, int n, int x, int y, int cnt)
{
	board[x][y] = cnt;
	if (cnt >= m * n) {
		if ((x == 1 && y == 2) || (x == 2 && y == 1))
		{
			print();
			printf("ok\n");
		}
		board[x][y] = 0;
		return;
	}

	if (can_move(m, n, x+1, y+2) && board[x+1][y+2] == 0) {
		t(m, n, x+1, y+2, cnt+1);
	}
	if (can_move(m, n, x+1, y-2) && board[x+1][y-2] == 0) {
		t(m, n, x+1, y-2, cnt+1);
	}
	if (can_move(m, n, x-1, y+2) && board[x-1][y+2] == 0) {
		t(m, n, x-1, y+2, cnt+1);
	}
	if (can_move(m, n, x-1, y-2) && board[x-1][y-2] == 0) {
		t(m, n, x-1, y-2, cnt+1);
	}
	if (can_move(m, n, x+2, y+1) && board[x+2][y+1] == 0) {
		t(m, n, x+2, y+1, cnt+1);
	}
	if (can_move(m, n, x+2, y-1) && board[x+2][y-1] == 0) {
		t(m, n, x+2, y-1, cnt+1);
	}
	if (can_move(m, n, x-2, y+1) && board[x-2][y+1] == 0) {
		t(m, n, x-2, y+1, cnt+1);
	}
	if (can_move(m, n, x-2, y-1) && board[x-2][y-1] == 0) {
		t(m, n, x-2, y-1, cnt+1);
	}
	board[x][y] = 0;
}


int can_move(int m, int n, int x, int y)
{
	if (x < 0 || y < 0) 
		return 0;
	if (x >= m || y >= n)
		return 0;
	return 1;
}

int main() 
{
	int m, n;
//	scanf("%d %d", &m, &n);
	traverse(m, n);

	return 0;
}
