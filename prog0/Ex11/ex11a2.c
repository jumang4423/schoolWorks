#include<stdio.h>

int sectime(int, int, int);

int main()
{
    int hrb, mib, seb, hra, mia, sea;
    printf("はじめの時、分、秒を入力してください：");
    scanf("%d%d%d", &hrb, &mib, &seb);
    printf("おわりの時、分、秒を入力してください：");
    scanf("%d%d%d", &hra, &mia, &sea);
    printf("それぞれ0時から数えて %d 秒と %d 秒なので、\n", sectime(hrb, mib, seb), sectime(hra, mia, sea));   
    printf("時間差は %d 秒(%.3f 時間)です。\n", sectime(hra, mia, sea)-sectime(hrb, mib, seb),(double)((sectime(hra, mia, sea)-sectime(hrb, mib, seb)))/(double)3600);
    return 0;
}

int sectime(int hr,int mi,int se)
{   
    int res;
    res=hr*3600 + mi*60 + se;
    return res;
}