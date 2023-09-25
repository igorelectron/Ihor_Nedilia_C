/*2.6. Функції обчислення площі трикутника через довжини сторін через координати точок*/

#include <stdio.h>
#include <math.h>

double length_of_segment(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double triangle_area(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y)
{
    double ab = length_of_segment(a_x, a_y, b_x, b_y);
    double ac = length_of_segment(a_x, a_y, c_x, c_y);
    double bc = length_of_segment(b_x, b_y, c_x, c_y);
    double p = (ab + ac + bc) / 2;
    return sqrt(p * (p - ab) * (p - ac) * (p - bc));
}

int main()
{
    double a_x, a_y, b_x, b_y, c_x, c_y;
    printf("Введіть координати точки A:\n");
    scanf("%lf %lf", &a_x, &a_y);
    printf("Введіть координати точки B:\n");
    scanf("%lf %lf", &b_x, &b_y);
    printf("Введіть координати точки C:\n");
    scanf("%lf %lf", &c_x, &c_y);
    printf("Площа трикутника з точками "
           "А (%.2lf, %.2lf), "
           "B (%.2lf, %.2lf), "
           "C (%.2lf, %.2lf): %.2lf",
           a_x, a_y,
           b_x, b_y,
           c_x, c_y,
           triangle_area(a_x, a_y,
                         b_x, b_y,
                         c_x, c_y));
}