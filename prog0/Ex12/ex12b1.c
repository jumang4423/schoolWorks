#include<stdio.h>

void d2btransfunc(int);

int main()
{
    int input;
    while(1)
    {
        printf("2進数に変換したい10進数の数値を入力してください\n");
        scanf("%d", &input);
        d2btransfunc(input);
    }
    return 0;
}

void d2btransfunc(int x)
{
    int n, res[8];
        for(n=0;n<8;n++)
    {
        res[n]=0;
    }  

    for(n=0;n<8;n++)
    {
        res[8-n]=x%2;
        x/=2;
        if(x==0) break;
    }    
    for(n=0;n<8;n++)
    {
        printf("%d",res[n]);
    }
    printf("\n");
}