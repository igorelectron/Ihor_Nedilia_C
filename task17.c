#include <stdio.h>

void rotateBlocks(int n, int matrix[][n])
{
    int g = (n - 1) / 2; 

    for (int i = 0; i <= g; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            int temp = matrix[i][j];

            matrix[i][j] = matrix[n - 1 - j][i];

            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];

            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];

            matrix[j][n - 1 - i] = temp;
        }
    }
}

void printMatrix(int n, int matrix[][n])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the size of the matrix (2g + 1): ");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        fprintf(stderr, "Error: The size of the matrix must be odd (2g + 1).\n");
        return 1;
    }

    int matrix[n][n];

    printf("Enter %d x %d matrix elements:\n", n, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotateBlocks(n, matrix);

    printf("Rotated matrix:\n");
    printMatrix(n, matrix);

    return 0;
}
