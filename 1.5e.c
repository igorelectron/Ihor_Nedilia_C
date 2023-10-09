/*x^28 за 6 операцій*/
#include <stdio.h>

int main(){
    double x, y, z;
    scanf("%lf", &x);
    z = x;
    x = x*x; // x^2
    y = x*x; // x^4
    x = x*y; // x^4*x^2=x^6
    x = x*z; // x^6*x=x^7
    x = x*x; // x^7*x^7=x^14
    x = x*x; // x^14*x^14=x^28
   printf("%lf", x);
}