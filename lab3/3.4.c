/*3.4. Функція, що гарантовано приймає у якості аргументів
8-бітні натуральні числа та обчислює їх добуток як гарантовано
16-бітне натуральне число*/

#include <stdio.h>
#include <stdint.h>

uint16_t mult8_to_16(uint8_t a, uint8_t b)
{
    return (uint16_t)a * (uint16_t)b;
}

int main()
{
    uint8_t a, b;
    printf("Введіть два 8-бітні натуральні числа:\n");
    scanf("%hhu %hhu", &a, &b);                                                      // short short (1 byte = 8 bits)
    printf("16-бітний добуток вищевказаних 8-бітних чисел: %hu", mult8_to_16(a, b)); // short (2 bytes = 16 bits)
}