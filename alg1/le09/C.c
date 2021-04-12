#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000

int h=0, A[MAX+1], num;
char input[8];

void heapIncreaseKey(key)
{
    int current;
    int i = h;
    if (key < A[i]) printf("new key is smaller than current key\n");
    A[i] = key;
    while (i > 1 && A[i/2] < A[i])
    {
        current = A[i];
        A[i] = A[i/2];
        A[i/2] = current;
        i = i/2;
    }
}

void maxHeapInsert(key)
{
    h++;
    A[h] = -MAX;
    heapIncreaseKey(key);
}

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

int heapExtractMax()
{
    if (h < 1) printf("heap underflow\n");
    int max = A[1];
    A[1] = A[h];
    h--;
    maxHeapify(1);
    return max;
}

int main()
{
    while(1)
    {
        scanf("%s", input);
        if(input[2] == 'd') break;
        else if(input[0] == 'i')
        {
            scanf("%d", &num);
            maxHeapInsert(num);
        }
        else
        {
            printf("%d\n", heapExtractMax());
        }
    }
    return 0;
}