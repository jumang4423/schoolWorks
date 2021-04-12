#include<stdio.h>

int main()
{

  //init
  int i, data[7];
  char *res;

  printf("7人分の評点を入力してください：");
  for(i=0;i<7;i++)
  {
    scanf("%d",&data[i]);
  }

  //out
  for(i=0;i<7;i++)
  {
    if(data[i]>=80){
    res="A";
    }
    else if(data[i]>=65 && data[i]<80){
    res="B";
    }
    else if(data[i]>=50 && data[i]<65){
    res="C";
    }
    else if(data[i]>=35 && data[i]<50){
    res="D";
    }
    else if(data[i]<35) res="F";

    printf("%d: %d %s\n",i+1 ,data[i],res);
  }
  return 0;
}
