/*4.2. Виведення рядку-обчислення факторіалу різними способами*/

#include <stdio.h>

int main()
{
    unsigned n;
    printf("Введіть натуральне число n:\n");
    scanf("%u", &n);
    printf("а) (за зростанням)\n");
    printf("%d! = 1", n); // початковий запис факторіала, "дорівнює(=)" і першого множника
    for (int i = 2; i <= n; i++)
    {
        printf("*%d", i);
    }
    printf("\nб) (за спаданням)\n");
    printf("%d! = 1", n);
    for (int i = n - 2; i >= 0; i--)
    {
        printf("*%d", n - i);
    }
}