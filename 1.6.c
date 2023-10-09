/*1.6. Переведення градусів Цельсія в градуси Фаренгейта*/
#include <stdio.h>

int main()
{
    float C;
    printf("Введіть дійсне число градусів Цельсія:\n");
    scanf("%f", &C);
    float F = (9 * C) / 5 + 32;
    printf("F=%g", F);
}