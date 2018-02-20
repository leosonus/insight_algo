/* Puzzle 3X3 Rotation by Kim Y H */
#include <stdio.h>

#define COL 3
#define ROW 3
#define SIZE (COL * ROW)

int is_match(int, int);
void fill_board(int);

int cmp[SIZE][2] = {
	{-1, -1}, {-1,  3}, {-1,  3},
	{ 0, -1}, { 0,  3}, { 0,  3},
	{ 0, -1}, { 0,  3}, { 0,  3}
};
int inp[SIZE][4], piece[SIZE][4][4];
int board[SIZE], rot[SIZE], flag[SIZE];
int count;

int main(void)
{
	int i, j, k;

	for(i = 0; i < SIZE; i++){
		for(j = 0; j < 4; j++)
			scanf("%d", &inp[i][j]);

		for(j = 0; j < 4; j++)
			for(k = 0; k < 4; k++)
				piece[i][j][k] = inp[i][(j+k)%4];
	}

	for(i = 0; i < SIZE; i++) 
		flag[i] = 0;
	count = 0;
	fill_board(0);
	return 1;
}

void fill_board(int n)
{
	int i, j, k, f;

	if(n == SIZE){
		printf(" %d:", ++count);
		for(i = 0; i < SIZE; i++)
			printf(" %d(%d)", board[i]+1, rot[i]);
		printf("\n");
	} else {
		for(i = 0; i < SIZE; i++){
			for(k = 0; k < 4; k++){
				if(flag[i] == 0){
					for(f = 1, j = 0; j < 2; j++){
						if(cmp[n][j] == 3 &&
								!is_match(piece[board[n-1]][rot[n-1]][1], piece[i][k][3])){
							f = 0; break;
						}
						if(cmp[n][j] == 0 &&
								!is_match(piece[board[n-3]][rot[n-3]][2], piece[i][k][0])){
							f = 0; break;
						}
					}

					if(f == 1){
						flag[i] = 1;
						board[n] = i, rot[n] = k;
						fill_board(n+1);
						flag[i] = 0;
					}
				}
			}
		}
	}
}

int is_match(int a, int b)
{
	if((a == 1 && b == 2) || (a == 2 && b == 1)
			|| (a == 3 && b == 4) || (a == 4 && b == 3)
			|| (a == 5 && b == 6) || (a == 6 && b == 5)
			|| (a == 7 && b == 8) || (a == 8 && b == 7))
		return 1;
	else return 0;
}

