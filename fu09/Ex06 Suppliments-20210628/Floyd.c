/*

author : Ryoma Okuda
id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

int Floyd(int, int, int);
int min(int, int);

int main()
{
    int i, j, k;
    int max = 0, min = INFTY;
    int **Data, n;
    int **d;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));
    d = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        Data[i] = (int *)malloc(n * sizeof(int));
        d[i] = (int *)malloc(n * sizeof(int));
    }

    // 初期化
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            d[i][j] = INFTY;
        }
    }
    /* input data (matrix)*/
    printf("Input the Adjacency or Distance matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &Data[i][j]);
        }
    }

    /* Main routines */
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                Data[i][j] = Floyd(Data[i][j], Data[i][k], Data[k][j]); // Floyd's Algorithm
            }
        }
    }
    // end 3-level nested loop

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (max <= Data[i][j] && Data[i][j] != INFTY)
            {
                max = Data[i][j];
            }
            if (min >= Data[i][j])
            {
                min = Data[i][j];
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (max == Data[i][j])
                printf("Maximum distance (%d,%d) -> %d\n", i + 1, j + 1, Data[i][j]);
            if (min == Data[i][j])
                printf("Minimum distance (%d,%d) -> %d\n", i + 1, j + 1, Data[i][j]);
        }
    }

    /* free allocated memory*/
    for (i = 0; i < n; i++)
    {
        free(Data[i]);
        free(d[i]);
    }
    free(Data);
    free(d);

    return 0;
}

int Floyd(int D_ij, int D_ik, int D_kj)
{
    /* Arguments D_ij, D_ik, D_kj means D^{k-1}[i][j], D^{k-1}[i][k],D^{k-1}[k][j] at the pseudo code. */
    int Dk_ij; /* D^k[i][j] */

    Dk_ij = min(D_ij, D_ik + D_kj);

    return Dk_ij;
}

int min(int x, int y)
{
    if (x < y)
        return (x);
    else
        return (y);
}