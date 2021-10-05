/*

author : Ryoma OKuda
id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>

static int x = 53402397;
int data[100];

int next_rnd1(void)
{
    x = x * 65539 + 125654;
    if (x < 0)
    {
        x += 2147483647;
        x += 1;
    }
    return x;
}

int main()
{
    int getrand, i;
    int count[30] = {0};

    // 1000回生成
    for (i = 0; i < 1000; i++)
    {
        getrand = next_rnd1();
        count[getrand % 30]++;
    }

    for (i = 0; i < 30; i++)
    {
        printf("%.2d: (num) -> %d\n", i, count[i]);
    }
    printf("\n");
    return 0;
}