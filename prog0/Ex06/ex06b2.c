#include <stdio.h>

int main(){
  int n,r,res=0;
  printf("nとrを入力してください：");
  scanf("%d%d",&n,&r);

  int n1, n_r1,r1;
  n1=n_r1=r1=1;

  int i=0;
  //n1
  for(i=n;i>0;i--){
    n1*=i;
  }
  //(n-r)!
  for(i=n-r;i>0;i--){
    n_r1*=i;
  }
  //r1
  for(i=r;i>0;i--){
    r1 *=i;
  }
  //resalt calc
  printf("%dc%d = %d\n",n, r, (int)((double)(n1)/(double)(n_r1*r1)) );
  return 0;
}
