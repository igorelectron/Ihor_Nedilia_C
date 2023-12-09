/* 4.6. Обчислення багатоповерхових коренів */

#include <stdio.h>
#include <math.h>

int main()
{
    printf("а) sqrt(2+sqrt(2+...+sqrt(2))) (n коренів)\n");
    unsigned n1, n2;
    printf("Введіть натуральне число n:\n");
    scanf("%u", &n1);
    int i1 = 0;
    double rec_sqr1 = 0.;
    while (i1 < n1)
    {
        rec_sqr1 = sqrt(2 + rec_sqr1);
        i1 += 1;
    }
    printf("Маємо: %lf\n", rec_sqr1);
    printf("а) sqrt(3 + sqrt(6 + ... +sqrt(3(n-1)+sqrt(3n))))\n");
    printf("Введіть натуральне число n:\n");
    scanf("%u", &n2);
    int i2 = 0;
    double rec_sqr2 = 0.;
    while (i2 < n2)
    {
        rec_sqr2 = sqrt(rec_sqr2 + 3 * (n2 - i2));
        i2 += 1;
    }
    printf("Маємо: %lf", rec_sqr2);
}