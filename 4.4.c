/* 4.4. Обчислення многочлена
x + 2*x^2 + ... + (n-1)*x^(n-1) + n*x^n */

#include <stdio.h>

int main()
{
    unsigned n;
    int coef = 1;
    double element, x;
    double x_in_pow = 1; // initialization of loop variables
    double sum = 0.;
    printf("Введіть натуральне число n:\n");
    scanf("%u", &n);
    printf("Введіть дійсне число x:\n");
    scanf("%lf", &x);
    for (int i = 0; i < n; i++)
    {
        x_in_pow *= x;
        element = x_in_pow * coef;
        coef += 1;
        sum += element;
    }
    printf("Значення многочлена x + 2*x^2 + ... + (n-1)*x^(n-1) + n*x^n"
           "при значеннях x = %.2lf, n = %u:\n%.2lf",
           x, n, sum);
}