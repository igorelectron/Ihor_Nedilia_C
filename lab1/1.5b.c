/*x^6 за 3 операції*/
#include <stdio.h>

int main()
{
    double x, y;
    scanf("%lf", &x);
    x = x * x;
    y = x * x;
    x = x * y;
    printf("%lf", x);
}