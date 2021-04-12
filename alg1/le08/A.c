#include<stdio.h>
#include <stdlib.h>

typedef struct pp{
    int num;
    struct pp *right, *left, *parent;
}PO;
PO *root, *nothing;
int n,input;
char command[7];

void ins(int n)
{
    PO *x = root;
    PO *y = nothing;
    PO *v;//what i want to put as x;
    v = (PO *)malloc(sizeof(PO));
    v->num = n;
    v->left = nothing;
    v->right = nothing;
    while(1)
    {
        if(x == nothing) break;
        y = x;
        if(v->num < x->num) x = x->left;
        else x = x->right;
    }
    v->parent = y;
    if(y == nothing) root = v;
    else
    {
        if(v->num < y->num) y->left = v;
        else y->right = v;
    }
}

void ino(PO *r)
{
    if(r == nothing) return;
    ino(r->left);
    printf(" %d", r->num);
    ino(r->right);
}

void pre(PO *r)
{
    if(r == nothing) return;
    printf(" %d", r->num);
    pre(r->left);
    pre(r->right);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", command);
        if(command[0] == 'i')
        {
            scanf("%d", &input);
            ins(input);
        }
        else if(command[0] == 'p')
        {
            ino(root);
            printf("\n");
            pre(root);
            printf("\n");
        }
    }
    return 0;
}