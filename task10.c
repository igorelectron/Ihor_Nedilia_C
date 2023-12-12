#include <stdio.h>
#include <math.h>

double computeVn(int n)
{
    if (n == 0 || n == 1)
    {
        return 1.0; 
    }

    double u0 = 0.0, u1 = 0.0;

    double v0 = 1.0, v1 = 1.0;

    for (int i = 2; i <= n; ++i)
    {
        double u = (u1 - u0 * v1 - v0) / (1 + u1 * u1 + v1 * v1);
        double v = (u0 - u1) / (fabs(u0) + fabs(v1) + 2);

        u0 = u1;
        u1 = u;

        v0 = v1;
        v1 = v;
    }

    return v1;
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        fprintf(stderr, "Error: n must be a non-negative integer.\n");
        return 1;
    }

    double result = computeVn(n);
    printf("V_%d = %lf\n", n, result);

    return 0;
}
