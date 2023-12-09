/*4.13. г) Обчислення значень виразів при заданому дійсному значенні x та натуральному значенні n*/

#include <stdio.h>

int main()
{
    double x;
    unsigned n = 1;
    printf("Введіть натуральне число n:\n");
    scanf("%u", &n);
    printf("Введіть дійсне число x:\n");
    scanf("%lf", &x);
    double app = 1.;
    double sum = 1.;
    for (int i = 2; i <= n; i++)
    {
        app *= x;
        sum += i * app;
    }
    printf("Шукане значення многочлена для n = %u, x = %.2lf:\n"
           "n*x^(n-1) + (n-1)*x^(n-2) + ... + 2*x + 1 = %.2lf",
           n, x, sum);
}