#include <stdio.h>
#include <math.h>

double computeApproximateSum(double x, int terms)
{
    double sum = 1.0;
    double term = 1.0;

    for (int n = 1; n < terms; ++n)
    {
        term *= -(2 * n - 1) * x / (2 * n);
        sum += term;
    }

    return sum;
}

int main()
{
    double x;

    printf("Enter the value of x (|x| < 1): ");
    scanf("%lf", &x);

    if (fabs(x) >= 1)
    {
        fprintf(stderr, "Error: |x| must be less than 1.\n");
        return 1;
    }

    int terms;

    printf("Enter the number of terms to compute: ");
    scanf("%d", &terms);

    double result = computeApproximateSum(x, terms);

    printf("Approximate sum: %lf\n", result);

    return 0;
}
