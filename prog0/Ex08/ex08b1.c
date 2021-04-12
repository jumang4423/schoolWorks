#include<stdio.h>

int main()
{
    //init
    int jks[6]={3,5,10,4,8,6};
    int jbt[6]={0,0,0,0,0,0};
    int jmh[6]={130,120,200,80,150,110};
    int coin[4]={10,10,10,10};
    int insert[6];
    int moneyin, i,lostflag, moneytx, moneyback, out, moneybback, tho=0;
    moneytx=0;
    //start
    while(1){

    for(i=0;i<6;i++)
    {
        if(jks[i]!=0)printf("%d(o) %d\n",i+1,jmh[i]);
        else if(jks[i]==0)printf("%d(x) %d\n",i+1,jmh[i]);
    }
    //moneylost check
    lostflag=0;
    for(i=0;i<4;i++)
    {
        if(coin[i]<=5) lostflag=1;
    }
    if(lostflag==0) printf("釣り銭切れ(x)\n");
    else if(lostflag!=0) printf("釣り銭切れ(o)\n");
    //input
    printf("\nお金と飲み物番号を入力してください\n");
    printf("1000 500 100 50 10 飲み物番号\n");

    for(i=0;i<6;i++)
    {
        out=0;
        if(scanf("%d",&insert[i]) == EOF) {
            out=1;
            break;
        }
    }
    if(out==1) break;
    //calc
    printf("ー状態表示エリアー\n");
    moneyin=0;
    moneyin+=insert[0]*1000;
    moneyin+=insert[1]*500;
    moneyin+=insert[2]*100;
    moneyin+=insert[3]*50;
    moneyin+=insert[4]*10;
    // printf("%d %d\n", moneyin, jmh[insert[5]]);

    //釣り銭check
    lostflag=0;
    for(i=0;i<4;i++)
    {
        if(coin[i]<=5) lostflag=1;
    }

    if(lostflag==1){
        printf("つり銭切れです\n");
        printf("お金%d円が戻ります\n", moneyin);
    }

    else if(lostflag==0)
    {
        if(jks[insert[5]]==0) {
            printf("飲み物%dは売り切れです\n", insert[5]);
            printf("お金%d円が戻ります\n", moneyin);
        }
        else if(jks[insert[5]]!=0)
        {
            if(jmh[insert[5]-1]>moneyin)
            {
                printf("投入金額が足りません\n");
                printf("お金%d円が戻ります\n", moneyin);
            }
            else if(jmh[insert[5]-1]<=moneyin)
            {
                printf("飲み物%dがでます\n",insert[5]);

                moneyback=moneyin-jmh[insert[5]-1];

                if(moneyback!=0){

                printf("お釣り\n");
                moneybback=moneyback;
                if(moneybback/500!=0){
                    printf("%d*500円\n", moneybback/500);
                    moneybback-=(int)(moneyback/500)*500;
                }
                 if(moneybback/100!=0){
                    printf("%d*100円\n", moneybback/100);
                    moneybback-=(int)(moneybback/100)*100;
                }
                 if(moneybback/50!=0){
                    printf("%d*50円\n", moneybback/50);
                    moneybback-=(int)(moneybback/50)*50;
                }
                 if(moneybback/10!=0){
                    printf("%d*10円\n", moneybback/10);
                    moneybback-=(int)(moneybback/10)*10;
                }

                }
                else if(moneyback==0) printf("お釣りはありません\n");

                //売上の追加
                jbt[insert[5-1]]+=1;
                moneytx+=jmh[insert[5]-1];
                //calc2
                tho+=insert[0];
                for(i=0;i<4;i++)
                {
                    coin[i]+=insert[i+1];
                }

                //moneyback
                if(moneyback/500!=0){
                    coin[0]-=moneyback/500;
                    moneyback-=(int)(moneyback/500)*500;
                }
                 if(moneyback/100!=0){
                    coin[1]-=moneyback/100;
                    moneyback-=(int)(moneyback/100)*100;
                }
                 if(moneyback/50!=0){
                    coin[2]-=moneyback/50;
                    moneyback-=(int)(moneyback/50)*50;
                }
                 if(moneyback/10!=0){
                    coin[3]-=moneyback/10;
                    moneyback-=(int)(moneyback/10)*10;
                }

            }
        }
    }

    }

    printf("ー売上サマリー\n");
    printf("売れた飲み物の番号毎の個数\n");
    for(i=0;i<6;i++)
    {
        printf("%d:%d\n",i+1, jbt[i]);
    }
    printf("総売上\n%d円\n\n", moneytx);
    printf("書く金種毎の保有枚数\n");
    printf("1000円:%d\n",tho);
    printf("500円:%d\n",coin[0]);
    printf("100円:%d\n",coin[1]);
    printf("50円:%d\n",coin[2]);
    printf("10円:%d\n",coin[3]);




    return 0;
}
