/*

author : Ryoma Okuda
id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define N 1000000

extern void my_srand();
extern int my_getRand();

double box_muller(double x1, double x2, bool isG1)
{
    double g = 0;
    if (isG1)
    {
        g = sqrt(-2.0 * log(x1)) * cos(2 * M_PI * x2);
    }
    else
    {
        g = sqrt(-2.0 * log(x1)) * sin(2 * M_PI * x2);
    }

    return g;
}

int main()
{
    int count[8] = {0}, i, j;
    static double data_1[N], data_2[N];
    double g = 0;

    my_srand();

    for (i = 0; i < N; i++)
    {
        data_1[i] = (double)my_getRand() / (double)RAND_MAX;
        data_2[i] = (double)my_getRand() / (double)RAND_MAX;
    }

    for (i = 0; i < N; i++)
    {

        g = box_muller(data_1[i], data_2[i], true);

        for (j = 0; j < 8; j++)
        {
            if (j - 4 <= g && g < j - 3)
                count[j]++;
        }
    }

    for (i = 0; i < 8; i++)
    {
        printf("µ%dσ≤x≤µ%dσ \t (num)%d \t (rate)%.3lf\n", i - 4, i - 3, count[i], (double)count[i] / N * 100);
    }

    return 0;
}