#include<stdio.h>

int main()
{
    int i, j, scale;
    printf("行列の大きさを入力して下さい（最大10 x 10）：");
    scanf("%d%d", &i, &j);
    if(i>10 && j>10) printf("ERROR\n");
    else if(i<=10 && j<=10)
    {

        int data[i][j], a, b;
        printf("%d x %d行列を整数値で入力して下さい\n", i, j);
        for(a=0;a<i;a++)
        {
            for(b=0;b<j;b++)
            {
                scanf("%d", &data[a][b]);
            }
        }
        printf("行列を何倍にしますか？：");
        scanf("%d", &scale);

        for(a=0;a<i;a++)
        {
            for(b=0;b<j;b++)
            {
            if(data[a][b]*scale<10) printf(" %d ", data[a][b]*scale);
            else if(data[a][b]*scale>=10) printf("%d ", data[a][b]*scale);
            }
        printf("\n");
        }
    }


    return 0;
}