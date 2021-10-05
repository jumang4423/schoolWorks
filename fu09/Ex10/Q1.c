#include <stdio.h>
#define N 183
#define INF 99999
int main()
{
    int i, j;
    int cent[5] = {1, 5, 10, 17, 25};
    int dp[N + 1];
    dp[0] = 0;
    for (i = 1; i <= N; i++)
        dp[i] = INF;

    for (i = 1; i <= N; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (0 <= i - cent[j])
                dp[i] = (dp[i - cent[j]] + 1 < dp[i]) ? dp[i - cent[j]] + 1 : dp[i];
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}