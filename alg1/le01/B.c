//最大公約数
#include <stdio.h>

int ztc(int a)
{
  if(a>=0) return a;
  else return -a;
}
int gcd(int a, int b)
{
  if(b == 0) return ztc(a);
  return gcd(b, a%b);
}

int main()
{
  int a,b;
  scanf("%d%d", &a, &b);
  printf("%d\n", gcd(a,b));
  
  return 0;
}


