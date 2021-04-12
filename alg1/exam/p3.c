#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000

typedef struct pp{
  char name[2];
  long long int num;
}gat;

long long int n, q;
gat Q[MAX+1];
gat Q2[MAX+1];

void struct_swap(struct pp *i, struct pp *j)
{
struct pp temp;
temp = *j;
*j = *i;
*i = temp;
}

int partition(long long int p, long long int r)
{
	long long int x = Q[r].num;
        long long int i = p-1;
	for(int j = p; j <= r-1; j++)
	{
		if(Q[j].num <= x)
		{
			i +=1;
			struct_swap(&Q[i], &Q[j]);
		}
	}
	struct_swap(&Q[i+1], &Q[r]);
	return i+1;
}

void quickSort(long long int p, long long int r)
{
    if(p < r)
    {
        q = partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);   
    }
}

int main()
{
  n= MAX;
  for(int i=0; i<n; i++)
    {
      scanf("%d", &Q[i].num);
      printf("%d\n", Q[i].num);
    }
  quickSort(0, n-1);

  
  printf("%lld\n", Q[n-1001].num);
  return 0;
   }
