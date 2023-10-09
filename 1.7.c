/*1.7. Дійсне число, знаходження його цілої та дробової частини різними способами*/
#include <stdio.h>
#include <math.h>

int main()
{
    float x; // дійсне число
    printf("Введіть дійсне число x:\n");
    scanf("%f", &x);
    int int_x1 = (int)x;             // отримання цілої частини за допомогою приведення до типу
    float float_x1 = x - int_x1;     // дробова частина = число - ціла чатсина
    int x1_plus = int_x1 + 1;        // найменше ціле число, що більше за x
    int x1_minus = int_x1;           // найбільше ціле, що менше x
    int x1_rounded = (int)(x + 0.5); // округлення

    float int_x2 = floor(x);       // отримання цілої частини за допомогою математичної функції floor
    float float_x2 = fmod(x, 1.0); // отримання дробової частини за допомогою математичної функції fmod
    float x2_plus = ceil(x);       // найменше ціле число, що більше за x
    float x2_minus = int_x2;       // найбільше ціле, що менше x
    float x2_rounded = round(x);   // округлення за допомогою математичної функції round()
    printf("Без використання математичних функцій\n"
           "Ціла частина: %d\n"
           "Дробова частина: %f\n"
           "Найменше ціле число, що більше за x: %d\n"
           "Найбільше ціле число, що менше за x: %d\n"
           "Округлення x: %d\n"
           "З використанням математичних функцій\n"
           "Ціла частина: %f\n"
           "Дробова частина: %f\n"
           "Найменше ціле число, що більше за x: %f\n"
           "Найбільше ціле число, що менше за x: %f\n"
           "Округлення x: %f\n",
           int_x1, float_x2, x1_plus,
           x1_minus, x1_rounded, int_x2,
           float_x2, x2_plus, x2_minus, x2_rounded);
}