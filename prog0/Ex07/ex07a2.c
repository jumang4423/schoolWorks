#include<stdio.h>

int main()
{
  //init
  int i, cnt ,even ,odd ,data[100];

  //input
  for(cnt=0;i<100;cnt++)
  {
    scanf("%d", &data[cnt]);

    if(data[cnt]==0)
    {
      break;
    }
  }

  //check
  for(i=0;i<cnt;i++)
  {

    if(data[i]%2==0)
    {
      even++;
    }else{
      odd++;
    }
  }
  if(even>odd)
  {
    printf("偶数が多い！\n");
    for(i=0;i<cnt;i++)
    {
      if(data[i]%2==0) printf("%d ",data[i]);
    }

  }
  else if(even<odd)
  {
    printf("奇数が多い！\n");
    for(i=0;i<cnt;i++)
    {
      if(data[i]%2==1) printf("%d ",data[i]);
    }
  }
  else if(even==odd)
    {
    printf("偶数と奇数が同数\n");

    for(i=0;i<cnt;i++)
    {
      if(data[i]%2==1) printf("%d ",data[i]);
    }

    printf("\n");

    for(i=0;i<cnt;i++)
    {
      if(data[i]%2==0) printf("%d ",data[i]);
    }



  }

  printf("\n");


  return 0;
}
