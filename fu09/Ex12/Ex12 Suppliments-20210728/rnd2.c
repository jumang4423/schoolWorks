/*

author : ryoma okuda
id     : s1270174

*/
#include <stdio.h>
#include <stdlib.h>

#define A 48271L
#define M 2147483647L
#define Q (M / A)
#define R (M % A)

static int x = 1;
int data[100];

int next_rnd2(void)
{
    x = A * (x % Q) - R * (x / Q);
    if (x < 0)
        x = x + M;
    return x;
}

int main()
{
    int getrand, i;
    int count[30] = {0};

    for (i = 0; i < 1000; i++)
    {
        getrand = next_rnd2();
        count[getrand % 30]++;
    }

    for (i = 0; i < 30; i++)
    {
        printf("%.2d: (num) -> %d\n", i, count[i]);
    }
    printf("\n");
    return 0;
}