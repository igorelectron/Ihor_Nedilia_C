/*4.3. Функції для обчислення значень многочленів*/

#include <stdio.h>

double task3_a(double x, int n)
{
    /* y = x^n + x^(n-1) + ... + x^2 + x + 1 */
    double x_in_pow = 1; // initialization of loop variables
    double sum = 1.;
    for (int i = 0; i < n; i++)
    {
        x_in_pow *= x;
        sum += x_in_pow;
    }
    return sum;
}

double task3_b(double x, double y, int n)
{
    /* y = x^(2^n)*y^n + x^(2^(n-1))*y^(n-1) + ... + x^2*y + 1 */
    double x_in_pow = 1;
    double x2 = x * x; // special variable for x^2;
    double y_in_pow = 1;
    double sum = 1.;
    for (int i = 0; i < n; i++)
    {
        x_in_pow *= x2;
        y_in_pow *= y;
        sum += x_in_pow * y_in_pow;
    }
    return sum;
}

int main()
{
    printf("a) 2^3 + 2^2 + 2^1 + 1 = %.2lf\n", task3_a(2., 3));
    printf("б) 1^(2^4)*2^4 + 1^(2^3)*2^3 + 1^(2^2)*2^2 + 1^(2^1)*2^1 + 1 = %.2lf", task3_b(1., 2., 4));
}
