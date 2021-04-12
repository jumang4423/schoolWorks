#include<stdio.h>
#include<stdlib.h>

int h, *A;

void maxHeapify(i)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    int swap;
    if (l <= h && A[l] > A[i]) largest = l;
    else largest = i;
    if (r <= h && A[r] > A[largest]) largest = r;
    if (largest != i)
    {
        swap = A[i];
        A[i] = A[largest];
        A[largest] = swap;
        maxHeapify(largest);
    }
}

void buildMaxHeap()
{
    for(int i=h/2; i>=1; i--) maxHeapify(i);
}

int main()
{
    //input
    scanf("%d", &h);
    A = ( int*)malloc(sizeof(int)* h+1);
    for(int i = 1; i<h+1; i++ ) scanf("%d", &A[i]);
    buildMaxHeap();
    //output
    for(int i = 1; i<h+1; i++ )
    {
        printf(" %d", A[i]);
    }
    printf("\n");
    return 0;
}