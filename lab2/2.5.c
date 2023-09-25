/* 2.5. Функція Rosenbrock2d */

#include <stdio.h>

double Rosenbrock2d(double x, double y)
{
    double z1 = x * x - y; // проміжні змінні
    double z2 = x - 1.;
    return 100. * z1 * z1 + z2 * z2;
}

int main()
{
    // 3 пари довільних дійсних чисел
    printf("Rosenbrock2d(1, 0) = %.2lf\n", Rosenbrock2d(1., 0.));
    printf("Rosenbrock2d(0, 1) = %.2lf\n", Rosenbrock2d(0., 1.));
    printf("Rosenbrock2d(2, 2) = %.2lf\n", Rosenbrock2d(2., 2.));
}
