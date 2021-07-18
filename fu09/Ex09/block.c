/*

author : Ryoma Okuda
id     : s1270174

*/
#include <stdio.h>
#include <stdlib.h>

void FindPlace(int **, int, int, int);

int block_id = 1; //置いたＬ字型ブロックを個々に識別できるように

int main(int argc, char **argv)
{
    int i, j, n;
    int **Board;        //正方格子
    int hole_x, hole_y; //１個のブロックが最初から置かれている正方格子上の場所

    if (argc != 4)
    { //初期化関係
        fprintf(stderr, "Error: Input arguments were incorrect.\n");
        exit(1);
    }
    hole_x = atoi(argv[1]); //１個のブロックで塞いだｘ座標
    hole_y = atoi(argv[2]); //１個のブロックで塞いだｙ座標
    n = atoi(argv[3]);      //正方格子のサイズ（２のべき乗にすること）

    if (!(hole_x >= 0 && hole_x < n) || !(hole_y >= 0 && hole_y < n))
    {
        fprintf(
            stderr,
            "Error: The coodinates of blank (%d,%d) what you input was incorrect;\nThe acceptable range is 0 to %d.\n",
            hole_x, hole_y, n);
        exit(2);
    }

    Board = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        Board[i] = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == hole_y && j == hole_x)
                Board[i][j] = -1; //ブロックが最初に置かれている場所は -1 とする
            else
                Board[i][j] = 0; // 0 の場所にＬ字型ブロックを置いていく
        }
    }

    printf("Board_Initialization:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%2d", Board[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }

    FindPlace(Board, n, hole_x, hole_y); //処理本体

    printf("Print_Answer:\n"); //出力
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%2d", Board[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
        free(Board[i]);
    free(Board);
    return 0;
}

void FindPlace(int **Board, int size, int h_x, int h_y)
{
    /*
    この関数は、再帰呼び出しになるので、Boardは各部分問題の時点での大きさ(size)となる。
    既にブロックが置かれている場所はh_xとh_yで指定する
    Strassen と同様、コードの配置（処理の流れ）は以下のようになるはずである
    極小まで分解されたときの処理（再帰の打ち切り）⇒ 部分問題用の配列確保 ⇒ 再帰に持ち込むための準備の処理 ⇒ 再帰呼び出し
    */
    int i, j, mid;
    int **B1, **B2, **B3, **B4;

    printf("%d %d %d\n", size, h_x, h_y);

    if (size <= 2)
    {
        if (Board[0][0] != 0)
        {
            Board[0][1] = block_id;
            Board[1][0] = block_id;
            Board[1][1] = block_id;
        }
        if (Board[0][1] != 0)
        {
            Board[0][0] = block_id;
            Board[1][0] = block_id;
            Board[1][1] = block_id;
        }
        if (Board[1][0] != 0)
        {
            Board[0][0] = block_id;
            Board[0][1] = block_id;
            Board[1][1] = block_id;
        }
        if (Board[1][1] != 0)
        {
            Board[0][0] = block_id;
            Board[0][1] = block_id;
            Board[1][0] = block_id;
        }
        block_id++;
        return;
    }

    mid = size / 2;

    B1 = (int **)malloc(mid * sizeof(int *));
    B2 = (int **)malloc(mid * sizeof(int *));
    B3 = (int **)malloc(mid * sizeof(int *));
    B4 = (int **)malloc(mid * sizeof(int *));
    for (i = 0; i < mid; i++)
    {
        B1[i] = (int *)malloc(mid * sizeof(int *));
        B2[i] = (int *)malloc(mid * sizeof(int *));
        B3[i] = (int *)malloc(mid * sizeof(int *));
        B4[i] = (int *)malloc(mid * sizeof(int *));
    }

    // Normalize
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            B1[i][j] = Board[i][j];
            B2[i][j] = Board[i][mid + j];
            B3[i][j] = Board[mid + i][j];
            B4[i][j] = Board[mid + i][mid + j];
        }
    }

    if (mid > h_x && mid > h_y)
    { // upper left
        B2[mid - 1][0] = block_id;
        B3[0][mid - 1] = block_id;
        B4[0][0] = block_id;
        block_id++;

        FindPlace(B1, mid, h_x, h_y);
        FindPlace(B2, mid, 0, mid - 1);
        FindPlace(B3, mid, mid - 1, 0);
        FindPlace(B4, mid, 0, 0);
    }
    else if (mid <= h_x && mid < h_y)
    { // upper right
        B1[mid - 1][mid - 1] = block_id;
        B3[0][mid - 1] = block_id;
        B4[0][0] = block_id;
        block_id++;

        FindPlace(B1, mid, mid - 1, mid - 1);
        FindPlace(B2, mid, h_x - mid, h_y);
        FindPlace(B3, mid, mid - 1, 0);
        FindPlace(B4, mid, 0, 0);
    }
    else if (mid > h_x && mid >= h_y)
    { // lower left
        B1[mid - 1][mid - 1] = block_id;
        B2[mid - 1][0] = block_id;
        B4[0][0] = block_id;
        block_id++;

        FindPlace(B1, mid, mid - 1, mid - 1);
        FindPlace(B2, mid, 0, mid - 1);
        FindPlace(B3, mid, h_x, h_y - mid);
        FindPlace(B4, mid, 0, 0);
    }
    else if (mid <= h_x && mid <= h_y)
    { //lower right
        B1[mid - 1][mid - 1] = block_id;
        B2[mid - 1][0] = block_id;
        B3[0][mid - 1] = block_id;
        block_id++;

        FindPlace(B1, mid, mid - 1, mid - 1);
        FindPlace(B2, mid, 0, mid - 1);
        FindPlace(B3, mid, mid - 1, 0);
        FindPlace(B4, mid, h_x - mid, h_y - mid);
    }

    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            Board[i][j] = B1[i][j];
            Board[mid + i][j] = B2[i][j];
            Board[i][mid + j] = B3[i][j];
            Board[mid + i][mid + j] = B4[i][j];
        }
    }

    //領域開放
    for (i = 0; i < mid; i++)
    {
        free(B1[i]);
        free(B2[i]);
        free(B3[i]);
        free(B4[i]);
    }
    free(B1);
    free(B2);
    free(B3);
    free(B4);

    return;
}