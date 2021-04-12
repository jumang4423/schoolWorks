#include<stdio.h>
#define TRUE 1
#define FALSE 0

int isAlpha(char);
int main()
{
    char ch;
    int stat;
    printf("Input a characters: ");
    while(1)
    {
        stat = scanf("%c", &ch);
        if(stat!=1) break;
        if(ch == '\n') break;
        
        if(isAlpha(ch)==1) printf("ASCII code of a character '%c' is %d(0x%x). It's an alphabetic character.\n",ch,ch,ch );
        if(isAlpha(ch)==0) printf("ASCII code of a character '%c' is %d(0x%x). It's a non-alphabetic character.\n",ch,ch,ch );
    }

    return 0;
}

int isAlpha(char ass)
{
    if(ass>64 && ass<123) return TRUE;
    else return FALSE;
}