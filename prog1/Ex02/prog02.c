#include<stdio.h>
#define INDI 3
#define INDJ 4

int main()
{

    int a[INDI][INDJ] = {
        { 1, 8, 11, 3},
        { 9, 2,  0, 7},
        { 5,10,  4, 6},
    };
    int n;


    printf("数値を入力してください: ");
    scanf("%d", &n);

    int i,j, flag=0;
    for(i=0;i<INDI;i++)
    {
        for(j=0;j<INDJ;j++)
        {
            if(a[i][j]==n)
            {
                flag=1;
                break;
            } 
        }
        if(flag==1) break;
    }
    if(flag==0) printf("2次元配列 a の要素に %d はありません\n", n);
    else printf("a[%d][%d] が %d です\n", i, j, n);

    return 0;

}