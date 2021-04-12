#include<stdio.h>

double arctan(int);

int main()
{
    int kew;
    printf("級数の計算上限となる数を奇数で入力して下さい:");
    scanf("%d", &kew);
    printf("%dまで計算した場合の pi の値: %f", kew, (double)4*arctan(kew));

    return 0;
}

double arctan(int x)
{
    double res=(double)0;
    int i,c;
    for(i=1;i<x;i+=2)
    {
        if(c%2==0) res+=(double)1/(double)(i);
        else if(c%2==1) res-=(double)1/(double)(i);
        c++;
    }

    return res;
}