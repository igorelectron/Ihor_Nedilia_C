/*3.23 в) Реалізація функцій та їх похідних з умовними конструкціями*/

#include <stdio.h>

double leakyReLu(double x, double a)
{
    if (x < 0)
    {
        return a * x;
    }
    else if (x >= 0)
    {
        return 0;
    }
}

double derivative_leakyReLu(double x, double a)
{
    if (x < 0)
    {
        return a;
    }
    else if (x >= 0)
    {
        return 0;
    }
}

int main()
{
    double x, a;
    printf("Введіть дійсне число x:\n");
    scanf("%lf", &x);
    printf("Введіть дійсне число a:\n");
    scanf("%lf", &a);
    printf("leakyReLu(%.2lf, %.2lf) = %.2lf\n", x, a, leakyReLu(x, a));
    printf("(leakyReLu(%.2lf, %.2lf))'= %.2lf", x, a, derivative_leakyReLu(x, a));
}