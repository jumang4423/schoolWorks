#include<stdio.h>

int main()
{
    //init
    int turu, kame, ten, num, ashi, flag;
    flag=0;
    turu=0;
    kame=0;
    ten=0;
    num=0;
    ashi=0;
    //input
    printf("頭数を入力してください：");
    scanf("%d", &num);

    printf("足の数を入力してください：");
    scanf("%d", &ashi);

    //calc
    for(turu=0;turu<=num;turu++)
    {
        for(kame=0;kame<=num-turu;kame++)
        {
            ten= num-kame-turu;
            if(ashi==turu*2+kame*4+ten*6){
                flag=1;
                printf("鶴が%d、亀が%d、てんとう虫が、%d\n", turu, kame, ten);
            }
        }
    }
    if(flag==0) printf("解なし\n");    

    return 0;
}
