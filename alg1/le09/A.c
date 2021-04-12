#include<stdio.h>
#include<stdlib.h>

int h, *A;
int main()
{
    //input
    scanf("%d", &h);
    A = ( int*)malloc(sizeof(int)* h+1);
    for(int i = 1; i<h+1; i++ ) scanf("%d", &A[i]);
    //output
    for(int i = 1; i<h+1; i++ )
    {
        printf("node %d: key = %d, ", i, A[i]); 
        if(i/2 != 0) printf("parent key = %d, ", A[(i/2)]);

        if(2*i<=h) printf("left key = %d, ", A[2*i]);
        if(2*i+1<=h) printf("right key = %d, ", A[2*i+1]);
        printf("\n");
    }
    return 0;
}