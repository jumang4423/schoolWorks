/*

author : Ryoma Okuda
id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

void Dijkstra(int, int);

int *label; // vartex (reached or unreached), called "S" in the lecture slide
int **D;    // costs (distance matrix)
int *d;     // distance from start (root) node (sum of the costs)
int *adj;   // the parent node in shortest path spanning tree

int main()
{
    int i, j;
    int start;
    int n;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* Generate arrays (memory allocation)*/
    label = (int *)malloc(n * sizeof(int));
    d = (int *)malloc(n * sizeof(int));
    adj = (int *)malloc(n * sizeof(int));
    D = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
        D[i] = (int *)malloc(n * sizeof(int));

    /* input data (matrix)*/
    printf("Input the Distance matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &D[i][j]);
        }
    }

    /* input data (inital node)*/
    printf("Input the initial node: ");
    scanf("%d", &start);

    /* Call main routines of [ Dijkstra's Algorithm ] */
    Dijkstra(start - 1, n);

    /* Show results */
    printf("\nresult:\n");
    for (i = 0; i < n; i++)
    {
        if (i == start - 1)
            printf("vertex %d -> root\n", i + 1);
        else
            printf("vertex %d -> %d (visited_order : %d)\n", i + 1, d[i], label[i]);
    }

    /* free allocated memory*/
    for (i = 0; i < n; i++)
        free(D[i]);
    free(label);
    free(adj);
    free(D);
    free(d);

    return 0;
}

void Dijkstra(int root, int n)
{

    int i;
    int min_cost, min_node;
    int visited_order = 0;

    // **** initialization ****
    //  S = {s}; d[s] = 0;
    //  d[root] = 0;
    // ************************

    for (i = 0; i < n; i++)
    {
        label[i] = 0;
        d[i] = D[root][i];
    }
    adj[root] = -1;
    label[root] = ++visited_order;

    /* while (S != V) { */
    while (visited_order < n)
    { /* S !=V  -->  |V| < |S| */
        min_cost = INFTY;

        for (i = 0; i < n; i++)
        { // Choose a vertex w in V
            if (label[i] != 0)
                continue; // -S

            // such that...
            if (d[i] < min_cost)
            { // d[w] is a minimum;
                min_cost = d[i];
                min_node = i;
            }
        }
        /*グラフが非連結の場合、次の行は不要*/
        if (min_cost == INFTY)
            continue; /* no edges from v to w */

        // add w to S;
        label[min_node] = ++visited_order;

        for (i = 0; i < n; i++)
        { // for (v in V
            if (label[i] != 0)
                continue; // -S)

            // d[v] = min{d[v],d[w]+D[w,v]};
            if (d[i] > d[min_node] + D[min_node][i])
            {
                d[i] = d[min_node] + D[min_node][i];
                adj[i] = min_node;
            }
        }
    }
}