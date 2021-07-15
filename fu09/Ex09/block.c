/*

author : your name
id     : your id

*/
#include <stdio.h>
#include <stdlib.h>

void FindPlace(int **, int, int, int);

int block_id = 1; //置いたＬ字型ブロックを個々に識別できるように

int main(int argc, char **argv) {
    int i, j, n;
    int **Board;        //正方格子
    int hole_x, hole_y; //１個のブロックが最初から置かれている正方格子上の場所

    if(argc != 4) { //初期化関係
        fprintf(stderr, "Error: Input arguments were incorrect.\n");
        exit(1);
    }
    hole_x = atoi(argv[1]); //１個のブロックで塞いだｘ座標
    hole_y = atoi(argv[2]); //１個のブロックで塞いだｙ座標
    n = atoi(argv[3]);      //正方格子のサイズ（２のべき乗にすること）

    if(!(hole_x >= 0 && hole_x < n) || !(hole_y >= 0 && hole_y < n)) {
        fprintf(
            stderr,
            "Error: The coodinates of blank (%d,%d) what you input was incorrect;\nThe acceptable range is 0 to %d.\n",
            hole_x, hole_y, n);
        exit(2);
    }

    Board = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++)
        Board[i] = (int *)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == hole_y && j == hole_x)
                Board[i][j] = -1; //ブロックが最初に置かれている場所は -1 とする
            else
                Board[i][j] = 0; // 0 の場所にＬ字型ブロックを置いていく
        }
    }

    printf("Board_Initialization:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%2d", Board[i][j]);
            if(j != n - 1)
                printf(" ");
        }
        printf("\n");
    }

    FindPlace(Board, n, hole_x, hole_y); //処理本体

    printf("Print_Answer:\n"); //出力
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%2d", Board[i][j]);
            if(j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    for(i = 0; i < n; i++)
        free(Board[i]);
    free(Board);
    return 0;
}

void FindPlace(int **Board, int size, int h_x, int h_y) {
    /*
    この関数は、再帰呼び出しになるので、Boardは各部分問題の時点での大きさ(size)となる。
    既にブロックが置かれている場所はh_xとh_yで指定する
    Strassen と同様、コードの配置（処理の流れ）は以下のようになるはずである
    極小まで分解されたときの処理（再帰の打ち切り）⇒ 部分問題用の配列確保 ⇒ 再帰に持ち込むための準備の処理 ⇒ 再帰呼び出し
    */
}