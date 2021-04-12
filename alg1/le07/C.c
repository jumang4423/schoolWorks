#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int n, i, id, num;
int use[MAX];
typedef struct pp
{
    int see_it;
    int parent;
    int left, right;
}g;
g Q[MAX];

void dfs(int q, int d)
{
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

void pre(int q)
{
    if(Q[q].see_it == -1) Q[q].see_it = num;
    num++;
    if(Q[q].left != -1) pre(Q[q].left);
    if(Q[q].right != -1) pre(Q[q].right);
}

void ino(int q)
{
    if(Q[q].left != -1) ino(Q[q].left);
    if(Q[q].see_it == -1) Q[q].see_it = num;
    num++;
    if(Q[q].right != -1) ino(Q[q].right);
}

void pos(int q)
{
    if(Q[q].left != -1) pos(Q[q].left);
    if(Q[q].right != -1) pos(Q[q].right);
    if(Q[q].see_it == -1) Q[q].see_it = num;
    num++;
}

void init()
{
        for(int j=0; j<MAX; j++)
    {
        Q[j].see_it = -1;
        num = 0;
    }
}

void res(int x)
{
    if(x==0)
    {
        printf("Preorder\n");
        for(int k=0; k<n; k++)
        {
            for(int l=0; l<n; l++) if(Q[l].see_it == k)printf(" %d", l);
        }
        printf ("\n");
    }
    else if(x==1)
    {
        printf("Inorder\n");
        for(int k=0; k<n; k++)
        {
            for(int l=0; l<n; l++) if(Q[l].see_it == k)printf(" %d", l);
        }
        printf ("\n");
    }
    else
    {
        printf("Postorder\n");
        for(int k=0; k<n; k++)
        {
            for(int l=0; l<n; l++) if(Q[l].see_it == k)printf(" %d", l);
        }
        printf ("\n");
    }
}
int main()
{
    //init
    for(int j=0; j<MAX; j++)
    {
        use[j] = 0;
        Q[j].parent = -1;
    }
    //input
    scanf("%d", &n);
    while(1)
    {
        if((scanf("%d", &id)) == EOF) break;
        scanf("%d", &Q[id].left);
        scanf("%d", &Q[id].right);
        use[Q[id].left] = 1;
        use[Q[id].right] = 1;
    }
    for(int j=0; j<MAX; j++)
    {
        if(use[j] == 0) 
        {
            dfs(j, 0);
            init();
            pre(j);
            res(0);
            init();
            ino(j);
            res(1);
            init();
            pos(j);
            res(2);
            break;
        }
    }
    //output results

    return 0;
}