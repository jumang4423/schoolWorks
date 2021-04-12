#include <stdio.h>

double subave3(double *, double *, double *); /* プロトタイプ宣言 */

int main()
{
  double a, b, c, ave;



  printf("3つ値を入力してください:\n");
  scanf("%lf%lf%lf", &a, &b, &c);

  ave = subave3( &a, &b, &c );   /* 関数の呼び出し */

  printf("平均:  %.3f\n", ave);
  printf("データと平均の差:  %+.3f  %+.3f  %+.3f\n", a, b, c);
  return 0;
}

/* 平均を計算する関数。データから平均値の引き算も行う。 */
double subave3(double *x, double *y, double *z)
{
  double ave;

  ave = (*x + *y + *z) / 3.0;   /* 平均の計算 */
  *x -= ave;   /* 各データから平均を引き算する */
  *y -= ave;
  *z -= ave;

  return ave;
}