/*1.1 Обчисліть наступні математичні вирази та виведіть результати*/

#include <stdio.h>

int main()
{
    int a = 2 + 31;
    int b = 45 * 54 - 11;
    double c = 15 / 4; // при діленні цілочисельних операндів виводиться цілочисельний результат (заокруглення)
    double d = 15.0 / 4;
    double e = 67 % 5;
    double f = (2 * 45.1 + 3.2) / 2;
    printf("2 + 31 = %d\n45 * 54 - 11 = %d\n15 / 4 = %f\n15.0 / 4 = %f\nостача від ділення: 67 на 5 = %f\n(2 * 45.1 + 3.2) / 2 = %f", a, b, c, d, e, f);
}
