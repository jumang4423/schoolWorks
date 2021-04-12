//素数の判定
#include<stdio.h>
#include<math.h>

/* this function(algorthm) is slow for aoj
int isPrime(int x)
{
  if(x <= 1) return 0;
  for(int i = 2; i<=x-1; i++)
    {
      if(x%i==0) return 0;
    }
  return 1;
}
*/

int isPrime(int x)
{
	int i = 3;
	if(x == 2) return 1;
	else if(x < 2 || x%2 == 0) return 0;
	else 
	{
		while(i <= sqrt(x))
		{
			if(x%i == 0) return 0;
			i+= 2;
		}
		return 1;
	}
}

int main()
{
  //input
  int N,j=0, data;
  scanf("%d", &N);
  for(int i=0; i!=N; i++)
    {
      scanf("%d", &data);
      if(isPrime(data)==1) j++;
    }
  printf("%d\n", j);
  
  return 0;
  }
