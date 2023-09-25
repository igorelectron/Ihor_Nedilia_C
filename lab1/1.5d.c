/*x^15 за 5 операції*/
#include <stdio.h>

int main()
{
    double x, y;
    scanf("%lf", &x);
    y = x;
    x = x * x;     // x^2
    x = x * x * y; // x^4*x=x^5
    x = x * x * x; // x^9

    printf("%lf", x);
}