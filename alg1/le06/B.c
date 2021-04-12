#include<stdio.h>
#include<stdlib.h>
int n, *A;

int partition(int p, int r)
{
	int x = A[r];
	int i = p-1;
	int swap = 0;
	for(int j = p; j <= r-1; j++)
	{
		if(A[j] <= x)
		{
			i +=1;
			swap = A[i];
			A[i] = A[j];
			A[j] = swap;
		}
	}
	swap = A[i+1];
	A[i+1] = A[r];
	A[r] = swap;
	return i+1;
}

int main()
{
	//input
	scanf("%d", &n);
	A = (int  *)malloc(n * sizeof(int));
	for(int i = 0; i<n ; i++) scanf("%d", &A[i]);
	int ass = partition(0, n-1);
	
	for(int i = 0; i<n ; i++) 
	{
		if(i!=ass) printf("%d", A[i]);
		else printf("[%d]", A[i]);
		if(i!=n-1) printf(" ");
	}
	printf("\n");
	free(A);//smart boi
	return 0;
}