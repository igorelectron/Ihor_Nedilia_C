#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void deallocateMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void inputMatrix(int **matrix, int rows, int cols)
{
    printf("Enter matrix elements (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int determinant(int **matrix, int size)
{
    if (size == 1)
    {
        return matrix[0][0];
    }

    if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;

    for (int i = 0; i < size; ++i)
    {
        int **submatrix = allocateMatrix(size - 1, size - 1);

        for (int j = 1; j < size; ++j)
        {
            for (int k = 0, l = 0; k < size; ++k)
            {
                if (k != i)
                {
                    submatrix[j - 1][l++] = matrix[j][k];
                }
            }
        }

        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix, size - 1);

        deallocateMatrix(submatrix, size - 1);
    }

    return det;
}

int rank(int **matrix, int rows, int cols)
{
    int rank = 0;
    int limit = (rows < cols) ? rows : cols;

    for (int i = 0; i < limit; ++i)
    {
        int **submatrix = allocateMatrix(rows - 1, cols - 1);

        for (int j = 1; j < rows; ++j)
        {
            for (int k = 0, l = 0; k < cols; ++k)
            {
                if (k != i)
                {
                    submatrix[j - 1][l++] = matrix[j][k];
                }
            }
        }

        rank += (determinant(submatrix, rows - 1) != 0) ? 1 : 0;

        deallocateMatrix(submatrix, rows - 1);
    }

    return rank;
}

int main()
{
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **matrix = allocateMatrix(rows, cols);

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    int det = determinant(matrix, rows);
    printf("Determinant: %d\n", det);

    int matrixRank = rank(matrix, rows, cols);
    printf("Rank: %d\n", matrixRank);

    deallocateMatrix(matrix, rows);

    return 0;
}
