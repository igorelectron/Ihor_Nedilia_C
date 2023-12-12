#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double **allocateArray(int rows, int cols)
{
    double **array = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i)
    {
        array[i] = (double *)malloc(cols * sizeof(double));
    }
    return array;
}


void deallocateArray(double **array, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(array[i]);
    }
    free(array);
}

void fillRandom(double **array, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            array[i][j] = rand() % 10;
        }
    }
}

void printArray(double **array, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%.2f\t", array[i][j]);
        }
        printf("\n");
    }
}

void deleteColumns(double **array, int *rows, int *cols)
{
    for (int j = 0; j < *cols; ++j)
    {
        int allLessThanOne = 1;
        for (int i = 0; i < *rows; ++i)
        {
            if (array[i][j] >= 1)
            {
                allLessThanOne = 0;
                break;
            }
        }

        if (allLessThanOne)
        {
            for (int i = 0; i < *rows; ++i)
            {
                for (int k = j; k < *cols - 1; ++k)
                {
                    array[i][k] = array[i][k + 1];
                }
            }
            --(*cols);
            --j;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    double **array = allocateArray(rows, cols);

    fillRandom(array, rows, cols);

    printf("Original array:\n");
    printArray(array, rows, cols);

    deleteColumns(array, &rows, &cols);

    printf("\nArray after deleting columns:\n");
    printArray(array, rows, cols);

    deallocateArray(array, rows);

    return 0;
}
