#include <stdio.h>
#define MAX 44

int main()
{
    int n,A[MAX+1], res;
    scanf("%d", &n);
    n++;
    A[0] = 1;
    A[1] = 1;
    if(n>2)
        for(int i=2; i<n+2; i++)
        {
            A[i] = A[i - 2] + A[i - 1];
        }
    
    printf("%d\n", A[n-1]);
    return 0;
}