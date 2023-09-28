/*3.1. Дано тризначне натуральне число. Знайти:
1) кількість одиниць, десятків і сотень цього числа
2) Суму цифр цього числа
3) Число, утворене при читанні заданого числа справа наліво*/

#include <stdio.h>

int main()
{
    unsigned x; // тризначне натуральне число
    printf("Введіть трьохзначне натуральне число:\n");
    scanf("%u", &x);
    printf("Маємо тризначне натуральне число %u\n", x);
    unsigned x_ones = x % 10; // одиниці
    x /= 10;                  // зменшуємо кількість розрядів за допомогою цілочисельного ділення
    unsigned x_tens = x % 10; // десятки
    x /= 10;
    unsigned x_hundreds = x % 10; // сотні
    unsigned sum_of_digits_of_x = x_ones + x_tens + x_hundreds;
    unsigned reversed_x = x_ones * 100 + x_tens * 10 + x_hundreds;
    printf("а) Кількість його одиниць: %u\n"
           "б) Кількість його десятків: %u\n"
           "в) Кількість його сотень: %u\n"
           "Сума цифр цього числа: %u + %u + %u = %u\n"
           "Число, утворене при читанні заданого числа справа наліво: %u",
           x_ones, x_tens,
           x_hundreds, x_ones, x_tens,
           x_hundreds, sum_of_digits_of_x, reversed_x);
}