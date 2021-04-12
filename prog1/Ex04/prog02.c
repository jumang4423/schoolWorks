#include <stdio.h>
 
int main()
{
  double x=1.2, y=5.0;
 
  double *p, *q; /* ここで宣言したポインタを使って、以下を変数 x, y を使わない形に書き換える。*/
  p = &x;
  q = &y;

  printf(" Value x: %lf  (%p)\n", *p, p );
  printf(" Value y: %lf  (%p)\n", *q, q );
  printf(" Product: %lf\n", (*p)*(*q) );
  printf(" Quotient: %lf\n", (*p)/(*q) );
 
  return 0;
}