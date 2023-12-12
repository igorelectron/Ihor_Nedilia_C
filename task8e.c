#include <stdio.h>

int isFibonacci(int num)
{
    int a = 0, b = 1, c;

    while (a <= num)
    {
        if (a == num)
        {
            return 1;
        }

        c = a + b;
        a = b;
        b = c;
    }

    return 0; 
}

int main()
{
    int N;

    printf("Enter the size of the array (N): ");
    scanf("%d", &N);

    if (N <= 0)
    {
        fprintf(stderr, "Error: N must be a positive integer.\n");
        return 1;
    }

    int array[N];

    printf("Enter %d natural numbers:\n", N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &array[i]);
        if (array[i] <= 0)
        {
            fprintf(stderr, "Error: Input must be a natural number.\n");
            return 1;
        }
    }

    int fibonacciCount = 0;
    for (int i = 0; i < N; ++i)
    {
        if (isFibonacci(array[i]))
        {
            fibonacciCount++;
        }
    }

    printf("Number of Fibonacci numbers in the array: %d\n", fibonacciCount);

    return 0;
}
