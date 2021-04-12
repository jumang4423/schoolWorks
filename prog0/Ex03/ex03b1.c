#include <stdio.h>

int main()

{
  double tate, yoko;
  printf("長方形の、縦の辺の長さと横の辺の長さを、cm で入力して下さい：\n");
  scanf("%le%le",&tate ,&yoko);
  printf("長方形の周の長さは、%.1fです。\n",2*tate+2*yoko);
  

  
  return 0;
}
