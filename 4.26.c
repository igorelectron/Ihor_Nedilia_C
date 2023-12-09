/* 4.26 Скоротити дріб n/m для заданих цілого числа n та натурального числа m */

#include <stdio.h>

// Алгоритм Евкліда для знаходження НСД для скорочення
int gcd(int a, unsigned b)
{
    if (b % a == 0)
    {
        return a;
    }
    return gcd(b % a, a);
}

int main()
{
    int n;
    unsigned m;
    printf("Введіть ціле число n (чисельник дробу, який необхідно скоротити):\n");
    scanf("%d", &n);
    printf("Введіть натуральне число m (знаменник дробу, який необхідно скоротити):\n");
    scanf("%u", &m);
    int dil = gcd(n, m);
    if (dil == 1)
    {
        printf("Дріб %d/%u є нескоротним.", n, m);
    }
    else
    {
        n /= dil;
        m /= dil;
        printf("Маємо скорочений дріб: %d/%u", n, m);
    }
}