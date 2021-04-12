#include <stdio.h>

int main() {
int i, imp = 0;
int res = 1;
printf("階乗を計算したい数を入力してください：");
scanf("%d",&imp);
if(imp<13 && imp>=0){
for (i=imp; i>0; i--){
res *=i;
}
printf("%d\n",res);
}
else if(imp>=13 || imp<0) printf("計算できません\n");

  return 0;

}
