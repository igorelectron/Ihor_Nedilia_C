/*3.2. Ввести натуральне тризначне число.
Якщо в ньому всі 3 цифри різні. то вивести
всі числа, які утворюються при перестановці цифр заданого числа*/

#include <stdio.h>

int main()
{
    unsigned x;
    printf("Введіть трьохзначне натуральне число:\n");
    scanf("%u", &x);
    printf("Маємо тризначне натуральне число %u\n", x);
    unsigned x_ones = x % 10; // одиниці
    x /= 10;                  // зменшуємо кількість розрядів за допомогою цілочисельного ділення
    unsigned x_tens = x % 10; // десятки
    x /= 10;
    unsigned x_hundreds = x % 10; // сотні
    if (x_hundreds == x_tens || x_tens == x_ones)
    {
        printf("У цьому числі повторюються цифри\n");
    }
    else
    {
        printf("Всі 3! = 1 * 2 * 3 = 6 чисел, які утворюються при перестановці цифр заданого числа:\n"
               "%u%u%u\n"
               "%u%u%u\n"
               "%u%u%u\n"
               "%u%u%u\n"
               "%u%u%u\n"
               "%u%u%u\n",
               x_ones, x_tens, x_hundreds,
               x_tens, x_ones, x_hundreds,
               x_tens, x_hundreds, x_ones,
               x_hundreds, x_tens, x_ones,
               x_ones, x_hundreds, x_tens,
               x_hundreds, x_ones, x_tens);
    }
}