    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 1000

    char aAul(char);
    char aAlu(char);
    char aAluul(char);

     
    int main()
    {
      char in_filename[] = "data01.in"; /* 文字配列の初期化は Lec04-14,15 参照 */
      char out_filename[] = "data01.out";
      FILE *fpin, *fpout;
     
      char c;
     
      /* 読み込み専用でファイル in.txt を開く。
      * ファイルオープンに失敗した場合はエラーを表示して終了。
      */
      if ((fpin = fopen(in_filename, "r")) == NULL)
      { 
        printf("Failed to open: %s\n", in_filename);
        exit(1);
      }
      int n, ba,dat, i;
      char buf[MAX];
      for (n=0; n<MAX ; n++)
	{
	  ba = fgetc(fpin);
	  if(ba == EOF) break;
	  buf[n] = (char)ba;
	}
      dat = n;

     
      /* 書き込み専用でファイル out.txt を開く。
      * ファイルオープンに失敗した場合はエラーを表示して終了。
      * その際、上で開いた入力ファイルを忘れずに閉じる。
      */
      if ((fpout = fopen(out_filename, "w")) == NULL)
      {
        printf("Failed to open: %s\n", out_filename);
        fclose(fpin);
        exit(2);

      }
     
      /* fpin を介して入力ファイルから 1 文字ずつ読み込み、
      * そのまま fpout を介して出力ファイルに書き込む。
      * 入力ファイルを最後まで読み込んだらループを抜ける。
      */

      for(i = 0; i <= dat-1; i++)
	{
	  fprintf(fpout, "%c", aAul(buf[i]));
	}

      fprintf(fpout, "\n\n");
      
      for(i = 0; i <= dat-1; i++)
	{
	
        fprintf(fpout, "%c", aAlu(buf[i]));
      }

      fprintf(fpout, "\n\n");
      
      for(i = 0; i <= dat-1; i++)
	{
	
        fprintf(fpout, "%c", aAluul(buf[i]));
      }
      
     
      /* 開いた入出力ファイルをそれぞれ忘れずに閉じる。 */
      fclose(fpout);
      fclose(fpin);
     
      /* 正常終了を表す値0を返して終了。 */
      return 0;
    }

char aAul(char ass)
{

  if(ass>='A' && ass<='Z' ) return ass+32;
  return ass;
}

char aAlu(char ass)
{
  if(ass>='a' && ass<='z' ) return ass-32;
  else return ass;
}

char aAluul(char ass)
{

  if(ass>='A' && ass<='Z' ) return ass+32;
  else if('a'<=ass && ass<='z') return ass-32;
  else return ass;
}

