#include <stdio.h>

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// copied
int all_is(int arr[], int arr_len, int k)
{
	int i;

	for (i = 0; i < arr_len; i++)
		if (arr[i] != k)
			return 0;

	return 1;
}

#define MAX_COINS 50
#define NUM_DISH 4

typedef struct {
	int win;
	int dish;
	int get;
} move_t;

move_t memo[MAX_COINS + 1][MAX_COINS + 1][MAX_COINS + 1][MAX_COINS + 1];
int solved[MAX_COINS + 1][MAX_COINS + 1][MAX_COINS + 1][MAX_COINS + 1];

move_t best_move_nim(int dishes[])
{
	int num_coins, i, j, l;
	move_t p;

	if (solved[dishes[0]][dishes[1]][dishes[2]][dishes[3]])
		return memo[dishes[0]][dishes[1]][dishes[2]][dishes[3]];

	solved[dishes[0]][dishes[1]][dishes[2]][dishes[3]] = 1;
	for (i = 0; i < NUM_DISH; i++) {
		num_coins = dishes[i];

		for (j = 1; j <= num_coins; j++) {
			dishes[i] = num_coins - j;
			p = best_move_nim(dishes);
			if (p.win == 0) {
				dishes[i] = num_coins;
				return memo[dishes[0]][dishes[1]][dishes[2]][dishes[3]] = (move_t) {1, i, j};
			}
		}
		dishes[i] = num_coins;
	}

	for (i = 0; i < NUM_DISH; i++) {
		if (dishes[i] > 0) {
			l = i;
			break;
		}
	}

	return memo[dishes[0]][dishes[1]][dishes[2]][dishes[3]] = (move_t) {0, l, 1};
}

int main()
{
	int user_dish, user_get, dishes[NUM_DISH], i;
	move_t my_move;

	printf("input num coins: ");
	for (i = 0; i < NUM_DISH; i++)
		scanf("%d", &dishes[i]);

	printf("State: ");
	print_arr(dishes, NUM_DISH);
	while (1) {
		printf("Your turn: ");
		scanf("%d %d", &user_dish, &user_get);
		dishes[user_dish] -= user_get;
		printf("State: ");
		print_arr(dishes, NUM_DISH);

		if (all_is(dishes, NUM_DISH, 0)) {
			printf("You win\n");
			break;
		}

		my_move = best_move_nim(dishes);
		if (my_move.win == 1)
			printf("I will win!\n");
		printf("My turn: %d %d\n", my_move.dish, my_move.get);
		dishes[my_move.dish] -= my_move.get;
		printf("State: ");
		print_arr(dishes, NUM_DISH);

		if (all_is(dishes, NUM_DISH, 0)) {
			printf("I win\n");
			break;
		}
	}
	return 0;
}
