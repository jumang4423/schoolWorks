#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned long long int all_num, given_num;
unsigned long long int *nums;
unsigned long long int answer = 0;
unsigned long long int option[2] = {-1, 1};

// 数字を算出する
int try_calc(unsigned long long int *num_copy, unsigned long long int *flags_copy)
{
    unsigned long long int result = 0;
    for (int i = 0; i < all_num; i++)
    {
        if (i != 0)
        {
            result += flags_copy[i - 1] * num_copy[i];
        }
        else
        {
            result += num_copy[i];
        }
    }

    return result;
}

// 演算を表示
void print_res(unsigned long long int *num_copy, unsigned long long int *flags_copy)
{
    printf("solution %llu:\n", given_num);

    unsigned long long int result = 0;
    for (int i = 0; i < all_num; i++)
    {
        if (i != 0)
        {
            result += flags_copy[i - 1] * num_copy[i];
            printf(" %c", flags_copy[i - 1] == 1 ? '+' : '-');
            printf("%llu", flags_copy[i - 1] * num_copy[i]);
        }
        else
        {
            result += num_copy[i];
            printf(" %llu", num_copy[i]);
        }
    }

    printf(" = %llu\n\n", result);
}

void run(unsigned long long int *flags_copy, unsigned long long int num)
{
    // もし最後まで演算子を挿入できたら
    if (num == all_num - 1)
    {
        // もし計算結果が合致していたら結果に一を足す
        if (try_calc(nums, flags_copy) == given_num)
        {
            print_res(nums, flags_copy);
            answer++;
        }
        return;
    }
    // +-で二通りで再帰する
    for (int j = 0; j < 2; j++)
    {
        flags_copy[num] = option[j];
        run(flags_copy, num + 1);
    }
}

int main()
{

    scanf("%llu %llu", &all_num, &given_num);
    nums = (unsigned long long int *)malloc(all_num * sizeof(unsigned long long int));
    for (int i = 0; i < all_num; i++)
    {
        scanf("%llu", &nums[i]);
    }

    unsigned long long int flags[all_num - 1];

    for (int i = 0; i < all_num - 1; i++)
    {
        flags[i] = 0;
    }

    run(flags, 0);

    printf("solution: %llu\n", answer);
    return 0;
}