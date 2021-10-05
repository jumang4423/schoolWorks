/*

  author : Ryoma Okuda
  id     : s1270174

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10

int board[20], count;

int check_conf(int row, int column)
{
    int i;

    for (i = 1; i <= row - 1; ++i)
    {
        // 対角線に対しての重複確認
        if (board[i] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
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
            if (row == N)
            {
                count++; //1盤面探索できたら+1
            }
            else
            {
                run(row + 1);
            }
        }
    }
}

int main()
{
    run(1);
    printf("solution: %d\n", count);
    return 0;
}