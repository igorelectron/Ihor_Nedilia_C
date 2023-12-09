/* 4.5. Обчислення подвійного факторіала за означенням */

#include <stdio.h>

unsigned two_fact(unsigned n)
{
    if (n % 2 == 0)
    {
        unsigned fact = 1;
        int i = 0;
        while (i < n)
        {
            i += 2;
            fact *= i;
        }
        return fact;
    }
    else
    {
        unsigned fact = 1;
        int i = 1;
        while (i < n)
        {
            i += 2;
            fact *= i;
        }
        return fact;
    }
}
int main()
{
    unsigned n;
    printf("Введіть натуральне число n:\n");
    scanf("%u", &n);
    printf("n!! = %u", two_fact(n));
}
