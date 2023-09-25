/*2.4. Напишіть функцію, яка за найменшу кількість арифметичних операцій обчислює
значення многочлена для введеного з клавіатури значення x*/

#include <stdio.h>

double task4_1(double x)
{
    /* Функція, яка обчислює значення многочлена f(x) = x^4 + 2x^2 + 1
    за 3 операції множення та дві операції додавання */

    double x2 = x * x; // x2 = x * x = x^2
    return x2 * x2 + 2 * x2 + 1;
}

double task4_2(double x)
{
    /*Функція, яка обчислює значення многочлена f(x) = x^4 + x^3 + x^2 + x + 1
    за 2 операції множення та 3 операції додавання*/
    double x2 = x * x;        // x2 = x * x = x^2
    x += 1.;                  // (x+1)
    return x2 * (x2 + x) + x; // x^4 + x^3 + x^2 + x + 1 = x^2 * (x^2 + x + 1) + x + 1
}

double task4_e(double x)
{
    /*Функція, яка обчислює значення многочлена f(x) = x^5 + x^3 + x
    за 3 операції множення та 2 операції додавання*/
    double x2 = x * x;             // x2 = x * x = x^2
    return x * (x2 * x2 + x2 + 1); // x^5 + x^3 + x = x * (x^4 + x^2 + x)
}

int main()
{
    double x;
    printf("Введіть дійсне значення x:\n");
    scanf("%lf", &x);
    printf("a) x^4 + 2x^2 + 1 = %.2lf\n", task4_1(x));
    printf("б) x^4 + x^3 + x^2 + x + 1 = %.2lf\n", task4_2(x));
    printf("е) x^5 + x^3 + x = %.2lf\n", task4_e(x));
}