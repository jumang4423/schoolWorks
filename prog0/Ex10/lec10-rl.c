/*
 *   rotation left 90 degree
 *
 *   pbm形式の白黒画像データを受け取って,
 *   左に９０度回転した画像を作成する
 *
 *   終了コード
 *     0 : 正常終了
 *     1 : 入力データの形式がおかしい
 *     2 : 入力データの画素数が多すぎる
 *     3 : 入力データがおかしいかデータが揃わないうちに
 *         ＥＯＦになった
 *     4 : 入力データの画素の値が０／１ではなかった
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_X 800
#define MAX_Y 800
#define BLACK 1
#define WHITE 0

int main()
{
  int img_data[MAX_Y][MAX_X];
  int i, j, x_size, y_size;

  /* 入力 */
  /* 最初にP1と書いていないものはデータ形式が違う */
  /* この部分はプログラミング入門では扱わない文字 */
  /* 型を使用しているので、今のところは呪文だと   */
  /* 思っておいてください                         */
  if (getchar() != 'P' || getchar() != '1'){
    fprintf(stderr, "データの形式が違います\n");
    exit(1);
  }

  /* x,yそれぞれの画素数を得る */
  scanf("%d", &x_size);
  scanf("%d", &y_size);
  /* 画素数が多すぎる場合 */
  if (x_size > MAX_X || y_size > MAX_Y){
    fprintf(stderr, "データが大きすぎます\n");
    exit(2);
  }

  /* 実際のデータ入力 */
  for (i = 0; i < y_size; i++){
    for (j = 0; j < x_size; j++){
      /* scanf入力データがおかしいかＥＯＦになった場合 */
      if(scanf("%d",&img_data[i][j]) != 1){
	fprintf(stderr, "データ入力に異常があります\n");
	exit(3);
      }
      /* データが０／１じゃない場合 */
      if(img_data[i][j] != WHITE && img_data[i][j] != BLACK){
	fprintf(stderr, "データが異常でした\n");
	exit(4);
      }
    }
  }
  
  /* これより上はどのプログラムも同じ */

  /* 出力 */
  /* 最初にP1とx,yの画素数を出力 */
  printf("P1\n");
  printf("%d %d\n", y_size, x_size); /* 縦横入れ換え */
  
  /* 実際のデータ出力 */
  for (i = 0; i < x_size; i++){
    for (j = 0; j < y_size; j++){
      /* 回転の処理 */
      printf("%d ",img_data[j][x_size-1-i]);
    }
    printf("\n");
  }
  exit(0);

  return 0;

}
