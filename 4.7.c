/*Обчислення експоненти через ряд Тейлора*/

#include <stdio.h>

int main()
{
    double x;
    int n;
    int i = 1;
    printf("Введіть дійсне число x (аргумент експоненти) :\n");
    scanf("%lf", &x);
    printf("Введіть ціле число n ≥ 0:\n");
    scanf("%d", &n);
    double sum = 1.;
    double app = 1.;
    while (i <= n)
    {
        app *= x; // кожного разу множимо на x та ділимо на число в ряду натуральних чисел
        app /= i;
        sum += app;
        i += 1;
    }
    printf("e^x = 1 + (x/1!) + (x^2/2!) + (x^3/3!) + ... + (x^n/n!) = %lf", sum);
}