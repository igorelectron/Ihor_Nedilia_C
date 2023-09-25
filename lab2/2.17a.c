/* 2.17. а) Гіперболічний тангенс і його похідна */

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double th(double x)
{
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

double th_derivative(double x)
{
    return 1 / ((exp(x) + exp(-x)) * (exp(x) + exp(-x)) / 4); // (th(x))' = 1/ch^2(x)
}

int main()
{
    double x;
    printf("Введіть дійсне число x: \n");
    scanf("%lf", &x);
    printf("th(%.2lf) = %.2lf\n", x, th(x));
    printf("(th(%.2lf))'=%.2lf", x, th_derivative(x));
}