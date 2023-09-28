/*3.20 Функція, яка перевіряє,
чи належить задана координатами точка
трикутнику, заданому координатами своїх вершин*/

#include <stdio.h>
#include <stdbool.h>

float skew_product(float x1, float y1, float x2, float y2)
{
    /*Функція, яка знаходить псевдоскалярний добуток
    векторів за їх координатами*/
    return x1 * y2 - y1 * x2;
}

bool is_point_in_triangle(float x0, float y0,
                          float xa, float ya,
                          float xb, float yb,
                          float xc, float yc)
{
    /*Функція, яка визначає, чи лежить точка в середині трикутника.
    Якщо псевдоскалярні добутки мають один знак, то точка лежить в межах трикутника
    Якщо це не так, то поза трикутником*/
    float p1 = skew_product(xa - x0, ya - y0, xb - xa, yb - ya);
    float p2 = skew_product(xb - x0, yb - y0, xc - xb, yc - yb);
    float p3 = skew_product(xc - x0, yc - y0, xa - xc, ya - yc);
    if ((p1 <= 0 && p2 <= 0 && p3 <= 0) || (p1 >= 0 && p2 >= 0 && p3 >= 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    float x0, y0, xa, ya, xb, yb, xc, yc;
    printf("Введіть координати вершини трикутника А: \n");
    printf("x = ");
    scanf("%f", &xa);
    printf("y = ");
    scanf("%f", &ya);
    printf("Введіть координати вершини трикутника B: \n");
    printf("x = ");
    scanf("%f", &xb);
    printf("y = ");
    scanf("%f", &yb);
    printf("Введіть координати вершини трикутника C: \n");
    printf("x = ");
    scanf("%f", &xc);
    printf("y = ");
    scanf("%f", &yc);
    printf("Введіть координати довільної точки площини: \n");
    printf("x = ");
    scanf("%f", &x0);
    printf("y = ");
    scanf("%f", &y0);
    if (is_point_in_triangle(x0, y0, xa, ya, xb, yb, xc, yc) == true)
    {
        printf("Точка з координатами (%.2f, %.2f) належить трикутнику з координатами вершин\n"
               "A (%.2f, %.2f)\n"
               "B (%.2f, %.2f)\n"
               "C (%.2f, %.2f)\n",
               x0, y0,
               xa, ya,
               xb, yb,
               xc, yc);
    }
    else
    {
        printf("Точка з координатами (%f, %f) НЕ належить трикутнику з координатами вершин\n"
               "A (%.2f, %.2f)\n"
               "B (%.2f, %.2f)\n"
               "C (%.2f, %.2f)\n",
               x0, y0,
               xa, ya,
               xb, yb,
               xc, yc);
    }
}