/* 学籍番号から所属班を判定するプログラム */
/* 作成者：                         */
/* 作成日：                         */
#include <stdio.h>
int main()
{
int id, han;

printf("学籍番号の下三桁を入力して下さい(例: 001) ");
scanf("%d", &id); /* 三桁の数値'00x'は'x'として読み込まれます */

han = id%3;

switch(han){
 case 0:
     printf("この人は１班です\n");
   break;
 case 1:
     printf("この人は２班です\n");
   break;
 case 2:
     printf("この人は３班です\n");
   break;
   default:
     printf("認識できません\n",han);
   break;
 } 
 return 0;
}
