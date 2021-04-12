#include <stdio.h>

int main(){
  double tmp;
  int hum;

  printf("温度と湿度を入力して下さい\n");
  scanf("%lf%d",&tmp ,&hum);
  printf("温度：%.2f度 湿度：%d％\n",tmp,hum);
  if(tmp < 20) printf("寒い\n");
  
  else if(tmp >= (double)20 && tmp < (double)28){
    if (hum < 60) printf("快適\n");
  }
  
  else if(tmp >= (double)20 && hum >= 60) printf("蒸し暑い\n");
  else if(tmp >= (double)28 && hum < 60) printf("暑い\n");
  return 0;
}
