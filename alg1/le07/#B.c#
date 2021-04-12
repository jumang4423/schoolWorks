#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int n, i, id, flag = 0;
int use[MAX];
typedef struct pp
{
    int parent;
    int sib;
    int dph;
    int height;
    int left, right;
}g;
g Q[MAX];

void dfs(int q, int d)
{
    if(Q[q].dph<d) Q[q].dph=d;
    if(Q[q].left !=-1)
    {
        Q[Q[q].left].parent = q;
        dfs(Q[q].left, d+1);
    }
    if(Q[q].right !=-1)
    {
        Q[Q[q].right].parent = q;
        dfs(Q[q].right, d+1);
    }
}

void height_finder(int q)
{
    if(Q[q].parent != -1) 
    {
        if(Q[Q[q].parent].height<Q[q].height + 1) Q[Q[q].parent].height = Q[q].height + 1;
        height_finder(Q[q].parent);
    }
}

int main()
{
    for(int j=0; j<MAX; j++)
    {
        use[j] = 0;
        Q[j].parent = -1;
        Q[j].dph = -1;
        Q[j].height = 0;
    }
    //input
    scanf("%d", &n);
    while(1)
    {
        if((scanf("%d", &id)) == EOF) break;
        scanf("%d", &Q[id].left);
        scanf("%d", &Q[id].right);
        if(Q[id].left != -1)
        {
            Q[Q[id].right].sib = Q[id].left;
            use[Q[id].left] = 1;
        }
        else
        {
            Q[Q[id].right].sib = -1;
        }
        if(Q[id].right != -1)
        {
            Q[Q[id].left].sib = Q[id].right;
            use[Q[id].right] = 1;
        }
        else
        {
            Q[Q[id].left].sib = -1;
        }

    }

    for(int j=0; j<MAX; j++)
    {
        if(use[j] == 0) 
        {
            Q[j].sib = -1;
            dfs(j, 0);
            for(int k=0; k<n; k++)
            {
                if(Q[k].left == -1 && Q[k].right == -1) height_finder(k);
            }
            break;
        }
    }
    //output results
    for(int j=0; j<n; j++)
    {
        printf("node %d: ",j);
        printf("parent = %d, ",Q[j].parent);
        printf("sibling = %d, ",Q[j].sib);
        if(Q[j].right == -1 && Q[j].left == -1) printf("degree = 0, ");
        else if(Q[j].right != -1 && Q[j].left == -1) printf("degree = 1, ");
        else if(Q[j].right == -1 && Q[j].left != -1) printf("degree = 1, ");
        else printf("degree = 2, ");
        printf("depth = %d, ",Q[j].dph);
        printf("height = %d, ", Q[j].height);
        if(Q[j].parent == -1) printf("root\n");
        else if(Q[j].left == -1 && Q[j].right == -1) printf("leaf\n");
        else printf("internal node\n");
    }

    return 0;
}