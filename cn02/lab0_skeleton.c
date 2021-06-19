#include <stdio.h>
#include <stdbool.h>

// functions
int moduloOperator(int x, int n) { return x % n; }
bool congruence(int x, int y, int n) { return (x % n) == (y % n); }

int main()
{
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    printf("a mod n = %d\n", moduloOperator(a, n));
    printf("%d and %d are%s congruent modulo %d\n", a, b, (congruence(a, b, n) ? "" : " not"), n);

    return 0;
}
