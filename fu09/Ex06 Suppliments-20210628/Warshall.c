/*

author : Ryoma Okuda
id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INFTY 99999

int Warshall(int, int, int);
int max(int, int);

int main()
{
    int i, j, k;

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

    /* Call main routines */
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                Data[i][j] = Warshall(Data[i][j], Data[i][k], Data[k][j]); // Warshall's Algorithm
            }
        }
    }
    // end 3-level nested loop

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (Data[i][j] == 0)
            {
                printf("(%d,%d) %d\n", i + 1, j + 1, Data[i][j]);
            }
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

/* Kernel process of Floyd's & Warshall's Algorithm */

int Warshall(int A_ij, int A_ik, int A_kj)
{
    /* Arguments A_ij, A_ik, A_kj means A^{k-1}[i][j], A^{k-1}[i][k],A^{k-1}[k][j] at the pseudo code. */
    int Ak_ij; /* A^k[i][j] */

    Ak_ij = max(A_ij, A_ik && A_kj);

    return Ak_ij;
}

int max(int x, int y)
{
    if (x > y)
        return (x);
    else
        return (y);
}