#include<stdio.h>

int main()
{
  int data, ans;
  ans = 0;
  while((scanf("%d", &data))!= EOF)
    {
      if(data==2019) ans++;
    }
  printf("%d", ans);
}
