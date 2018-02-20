#include <stdio.h>
#define N 3

#define CONTINUE - 2
#define LOSE -1
#define TIE 0
#define WIN 1

typedef struct {
    int result;
    int p1;
    int p2;
} move_t;

int evaluate(int (*board)[N], int player)
{
    int r;
    int i, j;
    int z;

    for (i = 0; i < N; i++) {
        r = 0;
        for (j = 0; j < N; j++)
            r += board[i][j];

        if (r == 3 * player)
            return WIN;
        if (r == -3 * player)
            return LOSE;
    }

    for (i = 0; i < N; i++) {
        r = 0;
        for (j = 0; j < N; j++)
            r += board[j][i];

        if (r == 3 * player)
            return WIN;
        if (r == -3 * player)
            return LOSE;
    }

    r = board[0][0] + board[1][1] + board[2][2];
    if (r == 3 * player)
        return WIN;
    if (r == -3 * player)
        return LOSE;

    r = board[0][2] + board[1][1] + board[2][0];
    if (r == 3 * player)
        return WIN;
    if (r == -3 * player)
        return LOSE;

    /* TIE? */
    z = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (board[i][j] == 0)
                z++;

    if (z == 0)
        return TIE;

    return CONTINUE;
}

move_t best_move(int (*board)[N], int player)
{
    int e;
    int i, j;

    int best = -10000;

    move_t t;
    move_t r;

    e = evaluate(board, player);
    if (e != CONTINUE) {
        r.result = e;
        r.p1 = -1;
        r.p2 = -1;
        return r;
    }

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (board[i][j] == 0) {
                board[i][j] = player;
                t = best_move(board, player * (-1));

                if ((-t.result) > best) {
                    r.result = -t.result;
                    r.p1 = i;
                    r.p2 = j;
                    best = -t.result;
                }
                board[i][j] = 0;
            }

    return r;
}

void print_board(int (*board)[N])
{
    int i, j;
	printf("====\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("X");
            else if (board[i][j] == -1)
                printf("O");
            else
                printf(" ");
        }
        printf("\n");
    }
	printf("====\n");
}

int main()
{
    int board[N][N];
    int i, j;
    move_t t;
    int x, y;
    int turn;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = 0;

    turn =  0;

    while (1) {
		printf("Your turn: ");
        scanf("%d %d", &x, &y);
        board[x][y] = -1;
        turn++;
        print_board(board);
        if (evaluate(board, -1) != CONTINUE) 
			break;

        t = best_move(board, 1);
        if (t.result == WIN)
            printf("I will win!\n");

        board[t.p1][t.p2] = 1;
        turn++;
        print_board(board);
        if (evaluate(board, 1) != CONTINUE) 
			break;
    }

    return 0;
}
