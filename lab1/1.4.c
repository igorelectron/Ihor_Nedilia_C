/*Обчислити силу притягання F в науковому
(експоненційному) форматі між двома тілами, що мають маси m1 та m2 на відстані r.
Шукана сила визначається за формулою F = gamma*((m1*m2)/r^2)*/

#include <stdio.h>
int main()
{
    const long double gamma = 6.673e-11L;
    // довільні значення мас та відстані, які вводяться в програмі
    const long double m1 = 69e3;
    const long double m2 = 23e3;
    const long double r = 12.;
    long double F = gamma * ((m1 * m2) / r);
    printf("F=%Le\n", F);
}