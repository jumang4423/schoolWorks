#include <stdio.h>

#define MAX 500

int dp[MAX];
int a[MAX];
int b, n;

int main()
{
    int i, j, flg = 0;

    scanf("%d %d", &n, &b);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i <= b; i++)
        dp[i] = -1;

    dp[0] = 0;

    for (i = 0; i < n; i++)
    {
        if (flg)
            break;

        for (j = b; j >= 0; j--)
        {
            if (dp[j] != -1 && dp[j] + a[i] <= b)
                dp[j + a[i]] = a[i];
            if (dp[b] != -1)
            {
                flg = 1;
                break;
            }
        }
    }

    if (flg)
        printf("YES\n");
    else
    {
        printf("NO\n");
        return 0;
    }
    i = b;
    while (dp[i] != dp[0])
    {
        printf("%d ", dp[i]);
        i -= dp[i];
    }

    printf("\n");
    return 0;
}