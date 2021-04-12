#include<stdio.h>
double seqavg(double);

int main()
{
    int stat, hm=1;
    double log;
    while(1)
    {
        
        double dat, av;
        printf("データを入力してください：");
        stat = scanf("%lf", &dat);
        if(stat==-1) break;
        log = seqavg(dat);
        printf("データの個数 = %d,ここまでの平均 = %.6f\n",hm, log);
        hm++;
    }
    printf("\n最終的な平均値は%.6fです\n", log);

    return 0;
}

double seqavg(double ass)
{
    static int hm = 0;
    static double av = 0.0;
    double res;
    res = ((double)av*(double)hm + ass)/(double)(hm+1.0);
    hm++;
    av = res;
    return res;

}