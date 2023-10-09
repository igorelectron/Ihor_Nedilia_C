/*x^6 за 3 операції*/
#include <stdio.h>

int main(){
    double x, y;
    scanf("%lf", &x);
    y = x;
    x = x*x; // x^2
    x = x*x; // x^4
    x = x*x; // x^8
    x = x*y; // x^9
   printf("%lf", x);
}