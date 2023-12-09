/* Для заданого натурального числа n одержати найменше число вигляду 2^r, яке перевищує n */

#include <stdio.h>
#include <math.h>

int main()
{
    unsigned n, res = 1; // 2^0=1
    printf("Введіть натуральне число n:\n");
    scanf("%u", &n);
    int r = 0;
    while (res <= n)
    {
        r++; // 2^1, 2^2, ...
        res *= 2;
        }
    printf("Найменше число вигляду 2^%u, яке перевищує %u: %u", r, n, res);
}