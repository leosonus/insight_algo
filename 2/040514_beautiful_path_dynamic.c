#include <stdio.h>

#define ROUTE

#define M 100 
#define N 100

int map[M][N];
int joy[M][N];

#ifdef ROUTE
int from[M][N];
//#define LEFT 1
//#define UP 2
enum {LEFT, UP};
#endif

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

void calculate_joy(int m, int n)
{
    int i, j;

    joy[0][0] = map[0][0];
    for (i = 1; i < m; i++) {
        joy[i][0] = joy[i - 1][0] + map[i][0];
#ifdef ROUTE
        from[i][0] = LEFT;
#endif
    }
    for (j = 1; j < n; j++) {
        joy[0][j] = joy[0][j - 1] + map[0][j];
#ifdef ROUTE
        from[0][j] = UP;
#endif
    }
    for (i = 1; i < m; i++)
        for (j = 1; j < n; j++) {
#ifdef ROUTE
            if (joy[i - 1][j] > joy[i][j - 1])
                from[i][j] = LEFT;
            else
                from[i][j] = UP;
#endif
            joy[i][j] = max(joy[i - 1][j], joy[i][j - 1]) + map[i][j];
        }
}

void print_path(int m, int n)
{
    if (m == 0 && n == 0)
        return;
    printf("(%d %d)", m, n);
    if (from[m][n] == LEFT)
        print_path(m - 1, n);
    else
        print_path(m, n - 1);
}

void print_path2(int m, int n)
{
    if (m == 0 && n == 0)
        return;
    if (from[m][n] == LEFT)
        print_path(m - 1, n);
    else
        print_path(m, n - 1);
    printf("(%d %d)", m, n);
}

int main()
{
    int m, n, i, j;

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    calculate_joy(m, n);
    printf("%d\n", joy[m - 1][n - 1]);
    print_path(m - 1, n - 1);
    return 0;
}
