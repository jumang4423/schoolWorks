/*

  author : Ryoma Okuda
  id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>

extern void my_srand();
extern int my_getRand();
int Fermat_test(int);

int main(int argc, char *argv[])
{
    int status;
    int P;
    int i, n, flag;
    int judge[2] = {0, 0};

    if (argc == 2)
    {
        n = atoi(argv[1]);
    }
    else
    {
        printf("Error: Number of testing is required.\n");
        exit(1);
    }

    printf("input number of P(>=4):\n->");
    status = scanf("%d", &P);
    if (status != 1 || P < 4)
    {
        printf("Error: Illegal input is detected.\n");
        exit(0);
    }

    /* [ Complete Here!! (Initialize the seed of your random number generator) ] */
    my_srand();

    for (i = 0; i < n; i++)
    {
        flag = Fermat_test(P);

        if (flag == 1)
            judge[1]++;
        else
            judge[0]++;
    }

    printf("Tested %d times. Judged as ...\n", n);
    printf("[Prime number]  %5d times /  [Composite number] %5d times.\n", judge[1], judge[0]);
    if (judge[0] == 0)
        printf("%d is probably a prime number.\n", P);
    else
        printf("%d is a composite number.\n", P);

    return 0;
}

// 0:not prime, 1:prime
int Fermat_test(int P)
{
    int i, n;
    long long int A, x, y;

    for (i = 1; i < 32; i++)
    {
        if (((P - 1) & (1 << i)) != 0)
        {
            n = i;
        }
    }
    n++;

    // a^{p-1}の底を乱数で生成して初期化
    // つまり、2からp-2までの乱数でAを初期化
    while (1)
    {
        A = my_getRand() % (P - 1);
        if (A >= 2 && A <= P - 2)
            break;
    }
    x = A;

    for (i = n - 2; i >= 0; i--)
    {
        y = x * x % P;
        if (y == 1 && x != 1 && x != P - 1)
            return 0;

        if (((P - 1) & (1 << i)) != 0)
        { // b[i]==1
            y = y * A % P;
        }
        x = y;
    }

    // return
    if (y == 1)
        return 1;
    else
        return 0;
}