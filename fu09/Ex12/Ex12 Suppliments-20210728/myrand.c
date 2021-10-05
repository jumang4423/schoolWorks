/*

author : Ryoma Okuda
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
static int x2;

int my_getRand(void)
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

int next_rnd2(void)
{
    x = A * (x % Q) - R * (x / Q);
    if (x < 0)
    {
        x = x + M;
    }
    return x;
}

void init_rnd(void)
{
    int i;
    for (i = 0; i < 55; i++)
    {
        a[i] = next_rnd2();
    }
}

void my_srand(void)
{
    time_t stamp;
    struct tm *t;

    stamp = (int)time(NULL);
    t = localtime(&stamp);

    x = t->tm_sec;

    init_rnd();
}