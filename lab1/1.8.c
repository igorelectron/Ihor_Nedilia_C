/*1.8. Введення двох дійсних чисел у різних рядках, обчислення їх різниці та добутку*/

#include <stdio.h>

int main()
{
    float a;
    float b;
    printf("Введіть два дійсних числа у наступгих рядках:\n");
    scanf("%f%f", &a, &b);
    float diff = a - b;
    float prod = a * b;
    printf("Різниця дійсних чисел a і b: %.2f\n"
           "Добуток дійсних чисел a і b: %.2f",
           diff, prod);
}