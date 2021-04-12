#include<stdio.h>
#define k 10000
#define MAX 2000000
int main()
{
    int n,j;
    int A[MAX+1];
    int B[MAX+1];
    int C[k+1];
	
	//input
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&A[i]);
    
    for(int j = 0; j<=k; j++) C[j] = 0;
    for(int j = 1; j<=n; j++) C[A[j]] += 1;
    for(int i = 1; i<=k; i++) C[i] = C[i] + C[i-1];
    for(int j = n; j>=1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] -= 1;
    }

    for(int i=1; i<=n; i++)
    {
        printf("%d",B[i]);
        if(i!=n) printf(" ");
    }
  printf("\n");
  return 0;
}