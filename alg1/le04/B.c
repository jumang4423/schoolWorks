#include<stdio.h>

int main()
{
  //input
  int S, T,answer = 0;
  int left = 0, right, mid, key;
  scanf("%d", &S);
  int Ss[S];
  for(int i=0; i<S; i++) scanf("%d", &Ss[i]);
  scanf("%d", &T);
  int Tt[T];
  for(int i=0; i<T; i++) scanf("%d", &Tt[i]);
  //calc

  //actual previous search
  for(int i=0; i<T; i++)
    {
      /*
      for(int j=0; j<S; j++)
	{
	  if(Tt[i] == Ss[j])
	    {
	      answer+=1;
	      break;
	    }
	}
      */
      key = Tt[i];
      right = S;
      left = 0;
      while(left < right)
	{
	  mid = (left + right) / 2;
	  if(Ss[mid] == key)
	    {
	      answer++;
	      break;
	    }
	  else if(Ss[mid] < key) left = mid + 1;
	  else right = mid;
	}
      
    }
  
  printf("%d\n", answer);
  return 0;
  }
