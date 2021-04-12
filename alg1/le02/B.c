#include<stdio.h>

int main()
{

    //input
  int N, swap, cnt=0, mini;
  scanf("%d", &N);
  int A[N];
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  //calc
  for(int i=0; i<N; i++)
    {
      mini = i;
      for(int j = i; j<N; j++)
	{
	  if(A[j] < A[mini])
	  {
	    mini = j;

	  }
	}
      if(i!=mini)
	{
      	    swap=A[i];
	    A[i] = A[mini];
	    A[mini] = swap;
	    cnt++;
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
