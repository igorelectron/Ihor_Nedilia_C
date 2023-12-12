#include <stdio.h>
#include <math.h>

int countEvenSquares(int n, int arr[])
{
    int k = (int)sqrt(n);

    int count = 0;

    for (int i = 1; i <= k; ++i)
    {
        int index = i * i; 

        if (index <= n && arr[index - 1] % 2 == 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        fprintf(stderr, "Error: n must be a positive integer.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int result = countEvenSquares(n, arr);
    printf("Number of even elements among a_{1^2}, a_{2^2}, ..., a_{k^2}: %d\n", result);

    return 0;
}
