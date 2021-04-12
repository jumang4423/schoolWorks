#include<stdio.h>

int main()
{

    //input
  int N, swap, cnt=0;
  scanf("%d", &N);
  int A[N];
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  //calc
  for(int i=0; i<N; i++)
    {
      for(int j=N-1; j>=i+1; j--)
	{
	  if(A[j] < A[j-1])
	  {
	    swap=A[j];
	    A[j] = A[j-1];
	    A[j-1] = swap;
	    cnt++;
	  }
	}
    }

  for(int i=0; i<N; i++)
  {
    printf("%d", A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n", cnt);
  return 0;

}
