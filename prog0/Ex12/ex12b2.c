#include<stdio.h>
#include<math.h>
#define eps 1.0e-6

double f(double);
double df(double);

int main()
{
    double x, fx, dfx;
    printf("x(k-1)\t\tfx\t\tdfx\t\tx(k)\t\tf(x)\n");
    while((fx=f(x))>eps)
    {
        dfx = df(x);
        printf("%f\t%f\t%f",x, fx, dfx);
        x = x - fx/dfx;
        printf("\t%f\t%12.10f\n",x, f(x));
    }
    printf("x = %12.10f\n", x);
    return 0;
}

double f(double x)
{
    double fx;
    fx = exp(x) - 4.0*x;
    return fx;
}

double df(double x)
{
    double dfx;
    dfx = exp(x) - 4.0;
    return dfx; 
}