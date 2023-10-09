/*x^4 за 2 операції*/

#include <stdio.h>

int main()
{
    double x, x1;
    scanf("%lf", &x);
    x = x * x;
    x = x * x;
    printf("%lf", x);
}