#include <stdio.h>
#include <stdlib.h>
 
/* 文字列バッファのサイズ */
#define MAX 1000
 
int main()
{
  char in_filename[] = "data03.out";
  char in_filename2[] = "data03_answer.out";
  FILE *fpin, *fpin2;
 
  char buf[MAX]; /* 文字列バッファ */
  char buf2[MAX]; /* 文字列バッファ2 */
  int c;         /* ファイルからの 1 文字取得用バッファ */
  int n, n2, f;         /* 読み込んだ文字数 */
  int i;
  int byte;
 
  if ((fpin = fopen(in_filename, "r")) == NULL)
  {
    printf("Failed to open: %s\n", in_filename);
    exit(1);
  }
  for (n = 0; n < MAX; n++)
  {
    if ((c = fgetc(fpin)) == EOF)
    break;
    buf[n] = (char)c; /* char へのキャストを忘れない。 */
  }
  if (n == MAX)
  {
    printf("Buffer overflow !\n");
    exit(3);
  }

  if ((fpin2 = fopen(in_filename2, "r")) == NULL)
  {
    printf("Failed to open: %s\n", in_filename2);
    exit(1);
  }
  for (n2 = 0; n2 < MAX; n2++)
  {
    if ((c = fgetc(fpin2)) == EOF)
    break;
    buf2[n2] = (char)c; /* char へのキャストを忘れない。 */
  }
  if (n2 == MAX)
  {
    printf("Buffer overflow !\n");
    exit(3);
  }

  if(n>=n2) f=n;
  else f=n2;

    for(i = 0; i<f ; i++)
    {
        if(buf[i]!=buf2[i]) 
        {
          byte=1;
          printf("Two files are different at %d byte.\n", i+1);
        }
    }
    if(byte==0) printf("Two files are identical.\n");


  fclose(fpin);
  fclose(fpin2);
 
  return 0;
}