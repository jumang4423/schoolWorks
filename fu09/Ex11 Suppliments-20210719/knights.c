#include <stdio.h>

#define N 6

int original[N][N];
int board[N][N];
int sol_cnt;

void print_board()
{
    int i, j;
    printf("solution%d:\n\n", sol_cnt);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void board_init()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            board[i][j] = original[i][j];
    }
}

void backtrack(int x, int y, int ori_x, int ori_y, int visit_cnt)
{
    if (x >= N || x < 0 || y >= N || y < 0 || board[y][x] != 0)
        return;

    board[y][x] = visit_cnt++;

    if (board[y][x] == 20 && x == ori_x && y == ori_y)
    {
        sol_cnt++;
        print_board();
        board[y][x] = 0;
        return;
    }

    backtrack(x - 2, y - 1, ori_x, ori_y, visit_cnt);
    backtrack(x - 2, y + 1, ori_x, ori_y, visit_cnt);
    backtrack(x - 1, y - 2, ori_x, ori_y, visit_cnt);
    backtrack(x - 1, y + 2, ori_x, ori_y, visit_cnt);
    backtrack(x + 1, y - 2, ori_x, ori_y, visit_cnt);
    backtrack(x + 1, y + 2, ori_x, ori_y, visit_cnt);
    backtrack(x + 2, y - 1, ori_x, ori_y, visit_cnt);
    backtrack(x + 2, y + 1, ori_x, ori_y, visit_cnt);

    board[y][x] = 0;
}

void start_run()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board_init();
            if (original[i][j] == 0)
                backtrack(j, i, j, i, 0);
        }
    }
}

int main()
{
    int i, j;
    sol_cnt = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d ", &original[i][j]);
        }
    }

    start_run();
    backtrack(3, 5, 3, 5, 0);
    printf("solution number: %d\n", sol_cnt);
    return 0;
}