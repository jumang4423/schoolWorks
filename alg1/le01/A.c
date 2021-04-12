//insection sort
#include<stdio.h>

int main()
{
  //input
  int N, v, j;
  scanf("%d", &N);
  int A[N];
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  //calc
  for(int i=1; i<N+1; i++)
    {
      for(int k=0; k<N; k++)
	{
	  printf("%d", A[k]);
	  if(k<N-1) printf(" ");
	}
      printf("\n");
      v = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > v)
	{
	  A[j+1] = A[j];
	  j--;
	  A[j+1] = v;
	}
    }
  return 0;
  }
