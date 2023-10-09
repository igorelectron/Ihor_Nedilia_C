/*1.2. Ініціалізуйте наступні числа як дійсні, подвійні дійсні та довгі дійсні: */
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    float a1 = 1e-4f;
    double a2 = 1e-4;
    long double a3 = 1e-4L;
    float b1 = 24.33e5f;
    double b2 = 24.33e5;
    long double b3 = 24.33e5L;
    float e1 = M_PI;
    double e2 = M_PI;
    long double e3 = M_PI;
    float f1 = M_E;
    double f2 = M_E;
    long double f3 = M_E;
    /*як задати число пі та експоненту?*/
    float c1 = sqrt(5);
    double c2 = sqrt(5);
    long double c3 = sqrt(5);
    float d1 = log(100);
    double d2 = log(100);
    long double d3 = log(100);
    printf("Перше число\n"
           "Дійсний формат: 10^(-4) = %8.2f\n"
           "Подвійний дійсний формат: 10^(-4) = %8.2lf\n"
           "Довгий дійсний формат: 10^(-4)=%8.2Lf\n"
           "Друге число\n"
           "Дійсний формат: 24.33Е5=%8.2f\n"
           "Подвійний дійсний формат: 24.33Е5=%8.2lf\n"
           "Довгий дійсний формат: 24.33Е5=%8.2Lf\n"
           "Третє число (пі)\n"
           "Дійсний формат: pi = %8.2f\n"
           "Подвійний дійсний формат: pi = %8.2lf\n"
           "Довгий дійсний формат: pi = %8.2Lf\n"
           "Четверте число (експонента)\n"
           "Дійсний формат: e = %8.2f\n"
           "Подвійний дійсний формат: e = %8.2lf\n"
           "Довгий дійсний формат: e = %8.2Lf\n"
           "П'яте число (корінь)\n"
           "Дійсний формат: sqrt(5)=%8.2f\n"
           "Подвійний дійсний формат: sqrt(5)=%8.2lf\n"
           "Довгий дійсний формат: sqrt(5)=%8.2Lf\n"
           "Шосте число (натуральний логарифм)\n"
           "Дійсний формат: %8.2f\n"
           "Подвійний дійсний формат: sqrt(5)=%8.2lf\n"
           "Довгий дійсний формат: %8.2Lf\n",
           a1, a2, a3,  // 10^(-4)
           b1, b2, b3,  // 23.33E5
           e1, e2, e3,  // pi
           f1, f2, f3,  // e
           c1, c2, c3,  // sqrt(5)
           d1, d2, d3); // ln(100)
}