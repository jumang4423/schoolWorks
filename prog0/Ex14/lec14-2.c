#include <stdio.h>
int time2min(int, int);

int main () {
  int hour, min;
  int begin_min;
  int end_min;
  int riyou_min;
  int ryoukin;

  printf("入室時刻を入力してください（例: 16 30）\n");
  scanf("%d %d", &hour, &min);
  begin_min = time2min(hour, min);

  printf("退室時刻を入力してください（例:16 30）\n");
  scanf("%d %d", &hour, &min);
  end_min = time2min(hour, min);

  /* 利用時間を分単位で計算 */
  riyou_min=end_min-begin_min;

  /* 90分までの初期料金の計算 */
  riyou_min=riyou_min-90;
  ryoukin=500;

/* 30分ごとに残り利用時間が0以下になるまでくり返す */
  while (riyou_min > 0) {
    if (end_min-riyou_min < time2min(18, 0)) {
      ryoukin=ryoukin+250; /* 18:00前 */
    } else {
      ryoukin=ryoukin+200; /* 18:00以降 */
    }
    riyou_min=riyou_min-30;
  }

  printf("利用時間は%d分でした\n", end_min-begin_min);
  printf("利用料金は%d円です\n", ryoukin);
  return 0;
}

/* 現時刻を00:00からの経過分数に変換 */
int time2min(int hour, int min) {
  return hour*60+min;
}
