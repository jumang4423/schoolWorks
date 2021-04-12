#include<stdio.h>
#define hm 12
int bmi_hantei(double);
int shishagonyu(double);

int main()
{

    int i,hu=0;
    double cm[hm], kg[hm];
    printf("身長(cm)と体重(kg)を空白で区切って %d 人分入力してください。\n", hm);
    for(i=0;i<12;i++)
    {
        scanf("%lf%lf", &cm[i], &kg[i]);
    }
    printf("\n              BMI     状態\n");
    for(i=0;i<12;i++)
    {
        if(bmi_hantei(kg[i]/(cm[i]/100.0*cm[i]/100.0))==0)
        {
            printf("%d人目 %.1f 正常\n",i+1, kg[i]/(cm[i]/100.0*cm[i]/100.0));
            hu++;
        }
        else if(bmi_hantei(kg[i]/(cm[i]/100.0*cm[i]/100.0))==1) printf("%d人目 %.1f 太っている\n",i+1, kg[i]/(cm[i]/100.0*cm[i]/100.0));
        else printf("%d人目 %.1f やせている\n",i+1, kg[i]/(cm[i]/100.0*cm[i]/100.0));
    }


    printf("\nBMI 値が正常な人の割合は%dパーセントです。\n",shishagonyu(((double)hu/(double)hm)*100.0));
    return  0;
}

int bmi_hantei(double x)
{
    int res;
    if(x<18.5) res=-1;
    else if(25<=x) res=1;
    else res=0;

    return res;
}

int shishagonyu( double x )
{
    return (int)(x+0.5);
}