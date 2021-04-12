#include<stdio.h>

char grade_char(int score);
int char_point(char c);
int main()
{
    double han,sta;
    while(1)
    {

        int hyo,ta,flag;
        printf("評点と単位数を入力してください（Ctrl+Dで終了）");
        flag = scanf("%d%d", &hyo, &ta);
        if(flag==-1) break;
        printf("%d 点の評価は %c で,Grade Point(GP)は %d です.（%d単位）\n",hyo, grade_char(hyo), char_point(grade_char(hyo)), ta);
        sta += (double)char_point(grade_char(hyo))*(double)ta;
        han += (double)ta;
    }
    double res;
    res = sta/han;
    printf("\nGrade Point Average(GPA): %.3f 単位数: %d\n",res,(int)han);

    return 0;
}


char grade_char(int score)
{
    char ass;
    if(score<35) ass='F';
    else if(score>=35 && score<50) ass='D';
    else if(score>=50 && score<65) ass='C';
    else if(score>=65 && score<80) ass='B';
    else ass='A';
    return ass;
}
int char_point(char c)
{
    if(c=='F' || c=='D') return 0;
    else if(c=='C') return 2;
    else if(c=='B') return 3;
    else if(c=='A') return 4;
}