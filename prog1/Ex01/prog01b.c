#include <stdio.h>

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
        
        printf("ASCII code of a character '%c' is %d(0x%x)\n",ch,ch,ch );
    }

    
    return 0;
}