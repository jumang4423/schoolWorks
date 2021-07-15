/*

author : Ryoma Okuda
id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>
#define INFTY 99999

int Maggs_Plotkin(int, int, int);
void MST_view(int **D0, int **, int);
int max(int, int);
int min(int, int);

int main()
{
    int i, j, k;
    int **Data, n;
    int **D;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);
    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));
    D = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        Data[i] = (int *)malloc(n * sizeof(int));
        D[i] = (int *)malloc(n * sizeof(int));
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
                D[i][j] = Maggs_Plotkin(Data[i][j], Data[i][k], Data[k][j]);
            }
        }
    }
    // end 3-level nested loop

    // you can use MST_view function to obtain MST cost.
    MST_view(Data, D, n);

    /* free allocated memory*/
    for (i = 0; i < n; i++)
    {
        free(Data[i]);
    }
    free(Data);

    return 0;
}

int Maggs_Plotkin(int D_ij, int D_ik, int D_kj)
{
    int Dk_ij;

    Dk_ij = min(D_ij, max(D_ik, D_kj));

    return Dk_ij;
}

int max(int x, int y)
{
    if (x > y)
        return (x);
    else
        return (y);
}
int min(int x, int y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

void MST_view(int **D0, int **Dn, int n)
{
    int i, j;
    int costs = 0;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        { // A上で辺があったところが、A^kの全域木に採用されているなら重みを加える
            if (D0[i][j] == Dn[i][j] && D0[i][j] != INFTY)
            {
                costs += Dn[i][j];
                printf("%d\n", Dn[i][j]);
            }
        }
    }

    printf("MST total weights:%d\n", costs);
}