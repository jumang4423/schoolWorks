#include <stdio.h>

#define func(x) ((3*(x)*(x)*(x)) - ((x)*(x)) + (5*(x)) + 7)

int main()
{
    int a = 6;
    double b = 8.5;

    printf("a=%d, b=%f\n", a, b);
    printf("func(a) = %d\n", func(a));
    printf("func(a+4) = %d\n", func(a + 4));
    printf("func(a)*5 = %d\n", func(a) * 5);
    printf("func(b) = %f\n", func(b));
    printf("func(b)*2.5 = %f\n", func(b + 2.5));

}