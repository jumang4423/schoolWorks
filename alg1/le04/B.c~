#include<stdio.h>

int main()
{
  //input
  int S, T,answer = 0;
  scanf("%d", &S);
  int Ss[S];
  for(int i=0; i<S; i++) scanf("%d", &Ss[i]);
  
  scanf("%d", &T);
  int Tt[T];
  for(int i=0; i<T; i++) scanf("%d", &Tt[i]);
  
  //calc
  for(int i=0; i<T; i++)
    {
      for(int j=0; j<S; j++)
	{
	  if(Tt[i] == Ss[j])
	    {
	      answer+=1;
	      break;
	    }
	}
    }
  printf("%d\n", answer);
  return 0;
  }
