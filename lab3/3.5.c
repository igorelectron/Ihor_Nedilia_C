/* 3.5. Визначити більше та менше з двох чисел, введених з клавіатури */

#include <stdio.h>

int main()
{
    double a, b;
    printf("Введіть два числа через пробіл:\n");
    scanf("%lf %lf", &a, &b);
    if (a > b)
    {
        printf("Більше число: %.2lf\nМенше число: %.2lf", a, b);
    }
    else if (b > a)
    {
        printf("Більше число: %.2lf\nМенше число: %.2lf", b, a);
    }
    else if (a == b)
    {
        printf("Число %.2lf дорівнює числу %.2lf", a, b);
    }
}