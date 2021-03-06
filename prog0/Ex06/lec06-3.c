/*****************************************
 * lec06-3.c
 *
 * 最大１０個の入力データの平均を計算
 * 
 * 入力データの値によって動作が異なる
 *   ・正の場合: 有効データ数を１増やし,
 *     平均の計算対象とする
 *   ・負の場合: 有効データ数を増やさず
 *     平均の計算対象ともしない
 *   ・０の場合: 入力データが１０に満たない
 *     場合でも入力を打ち切り,平均計算に
 *     移る
 * 
 * 有効データ数を表示し、
 *   ・有効データ数が０ならプログラム終了
 *   ・有効データ数が０でなければ平均を表示し 
 *     プログラム終了
 *
 *****************************************/

#include <stdio.h>
int main()
{
  int i, data;
  int num = 0, sum = 0;

  for(i = 0 ; i < 10 ; i++){
    scanf("%d",&data);
    if(data == 0) break;
    if(data < 0) continue;
    sum += data;
    num++;
  }

  printf("有効データ数 : %d\n",num);
  if(num != 0)
    printf("平均 : %f\n",(double)sum/num);
  return 0;
}
