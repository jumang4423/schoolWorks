#include <stdio.h>

int main()
{

    char ch;
    printf("Input a character: ");
    scanf("%c", &ch);
    printf("ASCII code of a character '%c' is %d(0x%x)\n",ch,ch, ch );
    return 0;
}