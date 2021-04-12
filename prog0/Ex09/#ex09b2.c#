#include<stdio.h>
#define imax 10
#define jmax 10

int main()
{
    int i, j, a, b;
    printf("行数と列数を入力してください");
    scanf("%d%d", &i, &j);
    
    int data[i][j];

    if(i>imax || j>jmax) printf("行数または列数が配列のサイズを超えています\n");
    else if(i<=imax || j<=jmax)
    {
        printf("%d x %d行列を整数値で入力してください", i, j);
        for(a=0;a<i;a++)
        {
            for(b=0;b<j;b++)
            {
                scanf("%d", &data[a][b]);
            }
        }
        printf("入力行列：\n");

        for(a=0;a<i;a++)
        {
            for(b=0;b<j;b++)
            {
            if(data[a][b]<10) printf(" %d ", data[a][b]);
            else if(data[a][b]>=10) printf("%d ", data[a][b]);
            }
            printf("\n");
        }
        printf("転置行列：\n");

        for(a=0;a<j;a++)
        {
            for(b=0;b<i;b++)
            {
            if(data[b][a]<10) printf(" %d ", data[b][a]);
            else if(data[b][a]>=10) printf("%d ", data[b][a]);
            }
            printf("\n");
        }

    }
    return 0;
}