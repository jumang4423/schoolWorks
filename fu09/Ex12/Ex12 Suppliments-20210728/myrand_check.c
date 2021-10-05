#include <stdio.h>

int my_getRand(void);
void my_srand(void);

int main(void)
{

    // random function init;
    my_srand();
    printf("%d", my_getRand());
}