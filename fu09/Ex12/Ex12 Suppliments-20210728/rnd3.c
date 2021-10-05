/*
author : ryoma okuda
id     : s1270174
*/

#include <stdio.h>
#include <time.h>

#define A 28271L
#define M 2147483647L
#define Q (M / A)
#define R (M % A)

int data[100];
static int a[55];
static int next = 0;
static int x = 1;

int next_rnd2(void)
{
    x = A * (x % Q) - R * (x / Q);
    if (x < 0)
        x = x + M;
    return x;
}

int next_rnd3(void)
{
    int i, j;
    i = (next + 31) % 55;
    j = (a[i] - a[next]);
    if (j < 0)
    {
        j += 2147483647;
        j += 1;
    }
    a[next] = j;
    next = (next + 1) % 55;
    return j;
}

void init_rnd(void)
{
    int i;
    for (i = 0; i < 55; i++)
        a[i] = next_rnd2();
}

int main()
{
    int getrand, i;
    int count[30] = {0};

    init_rnd();

    for (i = 0; i < 1000; i++)
    {
        getrand = next_rnd3();
        count[getrand % 30]++;
    }

    for (i = 0; i < 30; i++)
    {
        printf("%.2d: (num) -> %d\n", i, count[i]);
    }

    return 0;
}