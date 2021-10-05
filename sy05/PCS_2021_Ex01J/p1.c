#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double a){
    return (4.0 / (1.0 + a * a));
}

int main(int argc, char *argv[]){
    int n, id, np, i;
    double PI25DT = 3.141592653589793238462643;
    double h, sum, x, mypi;

    // error handling
    if (argc != 2) {
        printf("no enough arguments!");
        exit(0);
    }

    char* n_string = argv[1];

    n = atoi(n_string);

    h = 1.0 / (double)n;
    sum = 0.0;
    // main loop
    for (i = 0; i < n; i++){
        x = h * ((double)i - 0.5);
        sum += f(x);
    }
    mypi = h * sum;

    printf("pi is approximately %.16f, Error is %.16f\n", mypi, fabs(mypi - PI25DT));

    return 0;
}
