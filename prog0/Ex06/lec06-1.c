/* lec06-1.c */
/* forループを使って、1から10までの和を求める */

#include <stdio.h>

int main() {

  int i, total;
  total = 0;

  for( i = 1; i <= 10; i++ ) {
    total += i;
  }
  printf( "1から10までの和は %d です\n", total );
  return 0;
}
