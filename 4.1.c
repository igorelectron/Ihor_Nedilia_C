/*4.1. Функція обчислення синуса n разів:
y = sin(sin(...sin(x)..)) (n разів)*/

#include <stdio.h>
#include <math.h>

double multiple_sin(double x, unsigned n)
{
    int counter = 0;
    double y;
    double _ = x;
    while (counter < n)
    {
        y = sin(_);
        _ = y; // temp variable for holding previous sin
        counter += 1;
    }
    return y;
}

int main()
{
    double x;
    unsigned n;
    printf("Введіть значення x:\n");
    scanf("%lf", &x);
    printf("Введіть кількість разів застосування синуса (n):\n");
    scanf("%u", &n);
    printf("y = sin(sin(...sin(%.2lf)..)) = %.2lf (%u разів)", x, multiple_sin(x, n), n);
}
