#include<stdio.h>

int main()
{

  //init
  int i, cnt, data[10];

  //input
  for(cnt=0;cnt<10;cnt++)
  {
    scanf("%d", &data[cnt]);
    if(data[cnt]==-1) break;

  }

  //output
  for(i=cnt-1;i>=0;i--)
  {
    printf("%d ", data[i]);
  }

  printf("\n");

  return 0;
}
