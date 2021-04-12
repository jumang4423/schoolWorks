#include <stdio.h>
#include <limits.h>
#define MAX 101

int n,m[MAX][MAX], p[MAX], FUCK, ans=INT_MAX;

void matrixChainOrder()
{
    int na = n;
    for (int i = 1; i<=na; i++) m[i][i] = 0;
    for (int l = 2; l<=na; l++)
        for (int i = 1; i<=na-l+1; i++)
        {
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k = i; k<=j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(m[i][j]>=q) m[i][j]= q; 
                if(m[i][j]<ans) ans = m[i][j]; 
            }
        }
}

int main()
{
    scanf("%d", &n);    
    scanf("%d%d",&p[0], &p[1]);
    for(int i=2; i<n+1; i++)
    {
        scanf("%d%d", &FUCK, &p[i]);
    }
    matrixChainOrder();

    printf("%d\n", m[1][n]);
    return 0;
}