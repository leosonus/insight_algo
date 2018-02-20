#include <stdio.h>

#define NUM_DISH 4

int win(int dishes[])
{
	int num_coins, i, j;

	for (i = 0; i < NUM_DISH; i++) {
		num_coins = dishes[i];

		for (j = 1; j <= num_coins; j++) {
			dishes[i] = num_coins - j;
			if (win(dishes) == 0) {
				dishes[i] = num_coins;
				return 1;
			}
		}
		dishes[i] = num_coins;
	}
	return 0;
}

#define MAX_COIN 50

int solved[MAX_COIN + 1][MAX_COIN + 1][MAX_COIN + 1][MAX_COIN + 1];
int memo[MAX_COIN + 1][MAX_COIN + 1][MAX_COIN + 1][MAX_COIN + 1];

int win_memo(int dishes[])
{
	int num_coins, i, j;

	if (solved[dishes[0]][dishes[1]][dishes[2]][dishes[3]] == 1)
		return memo[dishes[0]][dishes[1]][dishes[2]][dishes[3]];

	solved[dishes[0]][dishes[1]][dishes[2]][dishes[3]] = 1;
	for (i = 0; i < NUM_DISH; i++) {
		num_coins = dishes[i];

		for (j = 1; j <= num_coins; j++) {
			dishes[i] = num_coins - j;
			if (win_memo(dishes) == 0) {
				dishes[i] = num_coins;
				return memo[dishes[0]][dishes[1]][dishes[2]][dishes[3]] = 1;
			}
		}
		dishes[i] = num_coins;
	}
	return memo[dishes[0]][dishes[1]][dishes[2]][dishes[3]] = 0;
}

int main()
{
	int dishes[NUM_DISH], i;

	for (i = 0; i < NUM_DISH; i++)
		scanf("%d", &dishes[i]);
	if (win_memo(dishes))
		printf("Winning state!\n");
	else
		printf("Not winning state!\n");
	return 0;
}
