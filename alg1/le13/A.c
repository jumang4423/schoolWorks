#include<stdio.h>
#include<stdlib.h>
#define N 8
#define FREE 1
#define NAH 0
//init
int num, row[N], col[N], dpos[N*2 -1], dneg[N*2-1], input[2], init[N][N];
void print()
{
        for(int k=0; k<N; k++)
        {
            for(int l=0; l<N; l++)
            {
                if(init[k][l] == 1 && row[k] != l) return;
            }
        }
        for(int k=0; k<N; k++)
        {
            for(int l=0; l<N; l++)
            {
                if(row[k] == l) printf("Q");
                else printf(".");
            }
        printf("\n");
        }
}
void whereIsQueen(int i)
{
    if (i == N)
    {
        print();
        return;
    }
    for (int j = 0; j<=N-1; j++)
    {
        if (col[j] == NAH || dpos[i+j] == NAH || dneg[i-j+N-1] == NAH)
        {
            continue;
        }
        row[i] = j;
        col[j] = NAH;
        dpos[i+j] = NAH;
        dneg[i-j+N-1] = NAH;
        whereIsQueen(i+1);
        col[j] = FREE;
        dpos[i+j] = FREE;
        dneg[i-j+N-1] = FREE;
    }
}

int main()
{
    //init2
    for(int i=0; i<N; i++)
{
    row[i] = FREE;
    col[i] = FREE;
}
for(int i=0; i<N*2-1; i++)
{
    dpos[i] = FREE;
    dneg[i] = FREE;
}
for(int k=0; k<N; k++)
{
    for(int l=0; l<N; l++)
    {
        init[k][l] = 0;
    }
}
    //input
    scanf("%d", &num);
    for(int i=0; i<num; i++)
    {
        scanf("%d%d", &input[0], &input[1]);
        init[input[0]][input[1]] = 1;
    }
    whereIsQueen(0);
    return 0;
}