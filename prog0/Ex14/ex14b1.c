#include<stdio.h>
#define NUM 200
int isPrime(int);

int main()
{

    int o, i, j, res[4];
    printf("200 以下の三つ子素数の組は次の通り:\n");
    for(o=5; o+2*3<=NUM; o+=2)
    {


        i=o;
        res[0]=0;
        for(j=0;j<4;j++)
        {
            if(isPrime(i+j*2)==1)
            {
                res[0]++;
                res[res[0]]=i+j*2;
            }
            if(res[0]==3)
            {
            printf("三つ子素数{   %d,   %d,  %d}\n", res[1], res[2], res[3]);
            }
        }
    }

    return 0;
}

int isPrime(int a)
{
    int i, res=1;
    for(i=2; i<a; i++)
    {
        if(a%i==0) {
        res = 0;
        break;
        }

    }
    return res;

}