#include<stdio.h>

int main()
{
    int flag, wh, a, b, data[4][5] ={{1,2,3,4,5},{7,8,9,10,11},{12,13,14,15,16},{17,18,19,20,21}};

    printf("行要素と列要素のどちらを表示したいか選択して下さい\n(行要素:0, 列要素:1)");
    scanf("%d", &flag);

    if(flag==0)
    {
        printf("表示したい行番号を入力して下さい");
        scanf("%d", &wh);
        for(b=0;b<5;b++)
        {
            if(data[wh][b]<10) printf(" %d ", data[wh][b]);
            else if(data[wh][b]>=10) printf("%d ", data[wh][b]);
        }
        printf("\n");
    }
    else if(flag==1)
    {
        printf("表示したい列番号を入力して下さい");
        scanf("%d", &wh);
        for(a=0;a<4;a++)
        {
            if(data[a][wh]<10) printf(" %d\n", data[a][wh]);
            else if(data[a][wh]>=10) printf("%d\n", data[a][wh]);
        }
        
    }
    else
    {
        for(a=0;a<4;a++)
        {
            for(b=0;b<5;b++)
            {
            if(data[a][b]<10) printf(" %d ", data[a][b]);
            else if(data[a][b]>=10) printf("%d ", data[a][b]);
            }
            printf("\n");
        }
    }



    return 0;
}