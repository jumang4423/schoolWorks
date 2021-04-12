#include<stdio.h>

int gcd(int, int);

int main()
{
    int a,b, out;
    while(1)
    {
        while(1)
        {
            out=0;
            printf("Input two numbers\n");
            scanf("%d%d", &a, &b);
            if(a==0 || b==0)
            {
                out=1;
                break;
            }
            else if(a>0 && b>0)
            {
                break;
            }
            else if(a<0 || b<0)
            {
                printf("Input positive numbers again!\n");
            }
        }
        if(out==1)
        {
            break;
        }
        printf("GCD of %d and %d is %d.\n", a, b, gcd(a, b));
    }
    return 0;
}

int gcd(int x, int y)
{
    int z;

    if(x<y)
    {
        z=x;
        x=y;
        y=z;
    }

    while(1)
    {
        z=x%y;
        if(z==0) break;
        else if(z!=0)
        {
            y=x;
            y=z;
        }
    }
    
    return y;
}