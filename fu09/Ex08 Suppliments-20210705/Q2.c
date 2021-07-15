#include <stdio.h>

int main()
{
    int tmp = 0;
    int total = 0;
    int coins[4] = {25, 10, 5, 1};
    int coin_cnt[4] = {0, 0, 0, 0};
    int N, coin_num[4];
    int N2;

    printf("Input numbers of each coins:\n");
    scanf("%d %d %d %d", &coin_num[0], &coin_num[1], &coin_num[2], &coin_num[3]);

    printf("Input pay amount:\n");
    scanf("%d", &N);

    N2 = N;

    while (1)
    {
        while (N2 < coins[tmp] && tmp < 4)
        {
            tmp++;
        }
        if (N2 - coins[tmp] < 0 || coin_num[tmp] < 0)
        {
            break;
        }
        // actually pay
        N2 -= coins[tmp];
        coin_cnt[tmp]++;
        coin_num[tmp]--;
    }

    if (N2 != 0)
    {
        printf("u cannot pay with these coins");
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("[%dcent] %d used \n", coins[i], coin_cnt[i]);
        total += coin_cnt[i];
    }

    printf("you used %d coins for %d cents\n", total, N);

    return 0;
}