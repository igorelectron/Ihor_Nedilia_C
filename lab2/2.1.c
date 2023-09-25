/*2.1. Ввести дійсне число х
та обчислити значення функції тригонометричного косинуса*/

#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    printf("Введіть дійсне число х:\n");
    scanf("%f", &x);
    float rez = cos(x);
    printf("cos(x) = cos(%.2f) = %.2f", x, rez);
}