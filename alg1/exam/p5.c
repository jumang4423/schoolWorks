#include <stdio.h>
#define MAX 44

int main()
{
    long long int n,A[100], res;
    //scanf("%d", &n);
    n=65;
    A[0] = 1;
    A[1] = 1;
    if(n>2)
        for(int i=2; i<n+2; i++)
        {
            A[i] = A[i - 2] + A[i - 1];
        }
    
    printf("%lld\n", A[n-1]);
    return 0;
}
