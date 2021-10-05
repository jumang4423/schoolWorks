/*

  author : Ryoma Okuda
  id     : s1270174

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10

int board[20], count;
// s1270174 -> 74 -> インデックス調整のため85
int hole_c = 8, hole_r = 5;

int check_conf(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        if (board[i] == column || (abs(board[i] - column) == abs(i - row)))
        {
            return 0;
        }
    }
    return 1;
}

void run(int row)
{
    int column;

    for (column = 1; column <= N; ++column)
    {

        if (check_conf(row, column))
        {

            board[row] = column;

            // added only this 1 sentence
            if (row == N && board[hole_c] != hole_r)
                count++;
            else
                run(row + 1);
        }
    }
}

int main()
{

    run(1);
    printf("solutions excluding holes: %d\n", count);
    return 0;
}