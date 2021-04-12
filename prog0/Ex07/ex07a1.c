#include<stdio.h>

int main()
{
  int imp,dataset[15]={1,5,12,15,23,30,34,45,50,56,67,70,78,89,90};
  printf("添字を入力してください:");
  scanf("%d",&imp);
  if(imp>=0 && imp<15){
    printf("dataset[%d]=%d\n",imp ,dataset[imp]);
  }else{
    printf("範囲外です！\n");
  }

  return 0;
}
