/*1.9. Середнє арифметичне та середнє гармонічне двох дійсних чисел*/

#include <stdio.h>

int main()
{
    float a;
    float b;
    printf("Введіть два дійсних числа у наступних рядках: ");
    scanf("%f %f", &a, &b);
    float ariphm_mean = (a + b) / 2.; // цілі числа типу float для уникнення цілочисельного ділення
    float harmonic_mean = 2. / (1. / a + 1. / b);
    printf("Середнє арифметичне чисел а і b в науковому форматі: %le\n"
           "Середнє арифметичне чисел a і b в десятковому форматі: %f\n"
           "Середнє гармонічне чисел а і b в науковому форматі: %le\n"
           "Середнє гармонічне чисел а і b в десятковому форматі: %f\n",
           ariphm_mean, ariphm_mean,
           harmonic_mean, harmonic_mean);
}