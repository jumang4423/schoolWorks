#include<stdio.h>
#include<stdlib.h>
#define nmax 20
void histgramfunc(int);

int main()
{
    int sc, out, data[nmax];

    for(sc=0;sc<20;sc++)
    {
        scanf("%d", &data[sc]);
        if(data[sc]<0) break;
    }
    for(out=0;out<sc;out++)
    {
        histgramfunc(data[out]);
    }
    return 0;
}

void histgramfunc(int x)
{
    int n;
    if(x>60)
    {
        printf("illegal value\n");
        exit(8);
    }
    else
    {
        if(x<10) printf("[ %d]:", x);
        if(x>=10) printf("[%d]:", x);
        for(n=0;n<x;n++)
        {
            printf("*");
        }
        printf("\n");
    }
}