#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int n, i, id, flag = 0;
int use[MAX];
typedef struct pp
{
    int num;
    int parent;
    int dph;
    int *ch;
}g;
g Q[MAX];

void dfs(int q, int d)
{
    if(Q[q].dph<d) Q[q].dph=d;
    for(int l=0; l<Q[q].num; l++)
    {

        Q[Q[q].ch[l]].parent = q;
        dfs(Q[q].ch[l], d+1);
    }
}

int main()
{
    for(int j=0; j<MAX; j++)
    {
        use[j] = 0;
        Q[j].parent = -1;
        Q[j].dph = -1;
    }
    //input
    scanf("%d", &n);
    while(1)
    {
        if((scanf("%d", &id)) == EOF) break;
        scanf("%d", &Q[id].num);
        Q[id].ch = (int*)malloc(sizeof(int) * Q[id].num);
        for(int j=0; j<Q[id].num; j++) 
        {
            scanf("%d", &Q[id].ch[j]);
            use[Q[id].ch[j]] = 1;
        }
    }

    for(int j=0; j<MAX; j++)
    {
        if(use[j] == 0) 
        {
            dfs(j, 0);
            flag=1;
        }
        if(flag==1) break;
    }
    //output results
    for(int j=0; j<n; j++)
    {
        printf("node %d: parent = %d, depth = %d, ",j ,Q[j].parent ,Q[j].dph);
        if(Q[j].parent == -1) printf("root, [");
        else if(Q[j].num == 0) printf("leaf, [");
        else 
        {
            printf("internal node, [");
        }
        for(int k=0; k< Q[j].num; k++)
        {
            printf("%d",Q[j].ch[k]);
            if(k<Q[j].num-1) printf(", ");
        }
            printf("]\n");
    }

    return 0;
}