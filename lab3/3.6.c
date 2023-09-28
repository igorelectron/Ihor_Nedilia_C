/* 3.6. Дано три дійсних числа. Скласти програму для знаходження числа:
найбільшого за модулем
найменше за модулем */

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, max_temp, max, min_temp, min;

    printf("Введіть три дійсних числа через пробіл:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (fabs(a) > fabs(b))
    {
        max_temp = a;
        min_temp = b;
    }
    else
    {
        max_temp = b;
        min_temp = a;
    }
    if (fabs(max_temp) > fabs(c))
    {
        max = max_temp;
    }
    else
    {
        max = c;
    }
    if (fabs(min_temp) > fabs(a))
    {
        min = a;
    }
    else
    {
        min = min_temp;
    }
    printf("Найбільше за модулем число: %.2lf: \n"
           "Найменше за модулем число: %.2lf: ",
           max, min);
}
