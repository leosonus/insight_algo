
#include <stdio.h>

// copied
int all_is(int arr[], int arr_len, int k)
{
	int i;

	for (i = 0; i < arr_len; i++)
		if (arr[i] != k)
			return 0;

	return 1;
}

#define MAX_COINS 24

typedef struct {
	int win;
	int pos;
	int get;
} move_t;

#define MEMO_LEN (((unsigned)1)<<(MAX_COINS+1))

int memo[MEMO_LEN];

void init_memo()
{
    int i;

    for (i = 0; i < MEMO_LEN; i++)
        memo[i] = -1;
}

int numbering(int coins[], int num_coin)
{
	int s = 0, b = 1, i;

	for (i = 0; i < num_coin; i++) {
		if (coins[i] == 1)
			s += b;
		b *= 2;
	}
	return s;
}

move_t best_move_kayles2(int coins[], int num_coin, int needmove)
{
	move_t p;
	int l, n, i;

	n = numbering(coins, num_coin);

	if (needmove == 0 && memo[n] != -1)
		return (move_t) {memo[n], -1 -1};

	for (i = 0; i < num_coin; i++) {
		if (coins[i] == 1) {
			coins[i] = 0;
			p = best_move_kayles2(coins, num_coin, 0);
			coins[i] = 1;

			if (p.win == 0) {
				memo[n] = 1;
				return (move_t) {1, i, 1};
			}
		}

		if (coins[i] == 1 && i + 1 < num_coin && coins[i + 1] == 1) {
			coins[i] = coins[i + 1] = 0;
			p = best_move_kayles2(coins, num_coin, 0);
			coins[i] = coins[i + 1] = 1;

			if (p.win == 0) {
				memo[n] = 1;
				return (move_t) {1, i, 2};
			}
		}
	}

	for (i = 0; i < num_coin; i++) {
		if (coins[i] > 0) {
			l = i;
			break;
		}
	}

	memo[n] = 0;
	return (move_t) {0, l, 1};
}


void print_coins(int coins[], int num_coin)
{
	int i;

	printf("State: ");
	for (i = 0; i < num_coin; i++) {
		if (coins[i])
			printf("%d", i % 10);
		else
			printf("_");
	}
	printf("\n");
}

int main()
{
	int coins[MAX_COINS], user_pos, user_get, n, i;
	move_t my_move;

	init_memo();

	printf("input n: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &coins[i]);
	print_coins(coins, n);
	while (1) {
		printf("Your turn: ");
		scanf("%d %d", &user_pos, &user_get);
		for (i = 0; i < user_get; i++)
			coins[user_pos + i] = 0;
		print_coins(coins, n);
		if (all_is(coins, n, 0)) {
			printf("You win\n");
			break;
		}

		my_move = best_move_kayles2(coins, n, 1);
		if (my_move.win == 1)
			printf("I will win!\n");
		printf("My turn: %d %d\n", my_move.pos, my_move.get);
		for (i = 0; i < my_move.get; i++)
			coins[my_move.pos + i] = 0;
		print_coins(coins, n);
		if (all_is(coins, n, 0)) {
			printf("I win\n");
			break;
		}
	}
	return 0;
}
