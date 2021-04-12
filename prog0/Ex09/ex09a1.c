#include <stdio.h>

int main()
{
  int i, j, val[3][4];

  for (i=0; i<3; i++){
    for (j=0; j<4; j++){
       val[i][j]=i+(j*10);
    }
  }
  for (i=0; i<3; i++){
    for (j=0; j<4; j++){
      printf(" %2d ", val[i][j]);
    }
    printf("\n");
  }
  return 0;
}