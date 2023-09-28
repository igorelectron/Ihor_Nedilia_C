/* 3.7. Визначити, скільки розв'язки має рівняння та розв'язати його:
а) ax^2 + bx + c = 0
b) ax^4 + bx^2 + c = 0 */

#include <stdio.h>
#include <math.h>

int main()
{
    double a1, b1, c1;
    const double eps = 1e-9;
    printf("Введіть коефіцієнти a, b і c для квадратного рівняння ax^2 + bx + c = 0:\n");
    printf("a = ");
    scanf("%lf", &a1);
    printf("\nb = ");
    scanf("%lf", &b1);
    printf("\nc = ");
    scanf("%lf", &c1);
    if (fabs(a1) < eps)
    {
        if (fabs(b1) < eps)
        {
            if (fabs(c1) < eps)
            {
                printf("Корінь рівняння 0*x^2 + 0*x + 0 = 0 - це будь-яке дійсне число (коренів безліч)");
            }
            else
            {
                printf("Коренів рівняння 0*x^2 + 0*x + c = 0 - не існує");
            }
        }
        else
        {
            printf("Рівняння 0*x^2 + b*x + c = 0 тотожно рівне лінійному і має єдиний корінь:\n%lf", -c1 / b1);
        }
    }
    else
    {
        double D1 = b1 * b1 - 4 * a1 * c1;
        if (D1 > 0)
        {
            printf("Квадратне рівняння має два корені:\nx1 = %lf\nx2 = %lf", (-b1 + sqrt(D1)) / 2 * a1, (-b1 - sqrt(D1)) / 2 * a1);
        }
        else if (fabs(D1) < eps)
        {
            printf("Квадратне рівняння має 1 корінь:\nx = %lf", -b1 / 2 * a1);
        }
        else if (D1 < 0)
        {
            printf("Квадратне рівняння не має коренів");
        }
    }

    printf("\nВведіть коефіцієнти a, b і c для квадратного рівняння ax^4 + bx^2 + c = 0:\n");
    double a2, b2, c2;
    printf("a = ");
    scanf("%lf", &a2);
    printf("\nb = ");
    scanf("%lf", &b2);
    printf("\nc = ");
    scanf("%lf", &c2);
    if (fabs(a2) < eps)
    {
        if (fabs(b2) < eps)
        {
            if (fabs(c2) < eps)
            {
                printf("Корінь рівняння 0*x^4 + 0*x^2 + 0 = 0 - це будь-яке дійсне число (коренів безліч)");
            }
            else
            {
                printf("Коренів рівняння 0*x^4 + 0*x^2 + c = 0 - не існує");
            }
        }
        else
        {
            printf("Квадратне рівняння 0*x^4 + b*x^2 + c = 0 тотожно рівне неповному квадратному a*x^2 = 0\n");
            if ((-c2 / a2) > 0)
            {
                printf("Має 2 корені:\nx1 = %lf\nx2 = %lf", sqrt(-c2 / a2), -sqrt(-c2 / a2));
            }
            else
            {
                printf("Коренів немає");
            }
        }
    }
    else
    {
        printf("Маємо біквадратне рівняння. Розв'язуємо його як квадратне, здійснюючи заміну x^2=t\n");
        double D2 = b2 * b2 - 4 * a2 * c2;
        if (D2 > 0)
        {
            double t1 = (-b2 + sqrt(D2)) / 2 * a2;
            double t2 = (-b2 - sqrt(D2)) / 2 * a2;
            printf("Квадратне рівняння має два корені:\nt1 = %lf\nt2 = %lf\n", t1, t2);
            if (fabs(t1) < eps) // then t2 is not zero
            {
                if (t2 < 0)
                {
                    printf("Біквадратне рівняння має 1 корінь кратності 2 - 0");
                }
                else if (t2 > 0)
                {
                    printf("Біквадратне рівняння має 3 корені:\nx1 = %lf\nx2 = %lf\nx3 = %lf", 0., sqrt(t2), -sqrt(t2));
                }
            }
            else if (fabs(t2) < eps) // then t1 is not zero
            {
                if (t1 < 0)
                {
                    printf("Біквадратне рівняння має 1 корінь кратності 2 - 0");
                }
                else if (t1 > 0)
                {
                    printf("Біквадратне рівняння має 3 корені:\nx1 = %lf\nx2 = %lf\nx3 = %lf", 0., sqrt(t1), -sqrt(t1));
                }
            }
            if (t1 > 0 && t2 > 0)
            {
                printf("Біквадратне рівняння має 4 корені:\n"
                       "x1 = %lf"
                       "x2 = %lf"
                       "x3 = %lf"
                       "x4 = %lf",
                       sqrt(t1), -sqrt(t1),
                       sqrt(t2), -sqrt(t2));
            }
            else if (t1 > 0 && t2 < 0)
            {
                printf("Біквадратне рівняння має 2 корені:\n"
                       "x1 = %lf"
                       "x2 = %lf",
                       sqrt(t1), -sqrt(t1));
            }
            else if (t2 > 0 && t1 < 0)
            {
                printf("Біквадратне рівняння має 2 корені:\n"
                       "x1 = %lf"
                       "x2 = %lf",
                       sqrt(t2), -sqrt(t2));
            }
            else if (t1 < 0 && t2 < 0)
            {
                printf("Біквадратне рівняння не має коренів");
            }
        }
        else if (fabs(D2) < eps)
        {
            double t = -b1 / 2 * a1;
            printf("Квадратне рівняння має 1 корінь:\nt = %lf\n", t);
            if (t > 0)
            {
                printf("Біквадратне рівняння має 2 корені:\nx1 = %lf\nx2 = %lf", sqrt(t), -sqrt(t));
            }
            else if (fabs(t) < eps)
            {
                printf("Біквадратне рівняння має 1 корінь кратності 2 - 0");
            }
            else if (t < 0)
            {
                printf("Біквадратне рівняння не має коренів");
            }
        }
        else if (D2 < 0)
        {
            printf("Квадратне рівняння не має коренів\n");
            printf("Біквадратне рівняння не має коренів");
        }
    }
}