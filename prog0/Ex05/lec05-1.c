/*
 * lec05-1.c
 * 月の最後の日かどうか判定する
 * 間違いバージョン１（間違ったインデント）
 * 
 */

#include <stdio.h>
int main()
{
  int m,d;
  
  printf("月と日を空白で区切って入力してください : ");
  scanf("%d %d",&m, &d);
  
  if((m == 1) || (m == 3) || (m == 5)  || (m == 7) || 
     (m == 8) || (m == 10) || (m == 12))
    if(d == 31) printf("%d月%d日は月の最後の日\n",m,d);
  else if((m == 4) || (m == 6) || (m == 9)  || (m == 11))
    if(d == 30) printf("%d月%d日は月の最後の日\n",m,d);
  else if(m == 2)
    if(d == 28) printf("%d月%d日は月の最後の日\n",m,d);
  else printf("%d月%d日は月の最後の日ではない\n",m,d);
  return 0;
}
