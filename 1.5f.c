/*x^64 за 6 операцій*/
#include <stdio.h>

int main()
{
    double x;
    scanf("%lf", &x);
    x = x * x; // x^2
    x = x * x; // x^4
    x = x * x; // x^8
    x = x * x; // x^16
    x = x * x; // x^32
    x = x * x; // x^64
    printf("%lf", x);
}