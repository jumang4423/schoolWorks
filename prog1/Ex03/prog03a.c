#include <stdio.h>
#include <stdlib.h>
 
/* 文字列バッファのサイズ */
#define MAX 1000
 
int main()
{
  char in_filename[] = "data01.in";
  char out_filename[] = "data03.out";
  FILE *fpin, *fpout;
 
  char buf[MAX]; /* 文字列バッファ */
  int c;         /* ファイルからの 1 文字取得用バッファ */
  int n;         /* 読み込んだ文字数 */
  int i;
 
  /* 入力ファイルを開く。 */
  if ((fpin = fopen(in_filename, "r")) == NULL)
  {
    printf("Failed to open: %s\n", in_filename);
    exit(1);
  }

 
 
  /* バッファの最大数までデータを読み込む */
  for (n = 0; n < MAX; n++)
  {
    if ((c = fgetc(fpin)) == EOF)
    break;
    buf[n] = (char)c; /* char へのキャストを忘れない。 */
  }
  /* バッファが最大数まで到達してもなおEOFにならない場合はバッファあふれとしてエラー処理する。
  */
  if (n == MAX)
  {
    printf("Buffer overflow !\n");
    exit(3);
  }
 
  /* 出力ファイルを開く。 */
  if ((fpout = fopen(out_filename, "w")) == NULL)
  {
    printf("Failed to open: %s\n", out_filename);
    fclose(fpin);
    exit(2);
  }

  /* バッファの内容を出力する。 */
  for (i = n-1; i >= 0; i--)
  {
    fprintf(fpout, "%c", buf[i]);
  }
 
  /* 開いた入出力ファイルをそれぞれ忘れずに閉じる。 */
  fclose(fpout);
  fclose(fpin);
 
  return 0;
}