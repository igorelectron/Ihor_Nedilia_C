#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    int size;      
    double *elements; 
};

void inputVector(struct Vector *v)
{
    printf("Enter the size of the vector: ");
    scanf("%d", &v->size);

    if (v->size <= 0)
    {
        printf("Invalid vector size.\n");
        exit(1);
    }

    v->elements = (double *)malloc(v->size * sizeof(double));
    if (v->elements == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter %d elements for the vector:\n", v->size);
    for (int i = 0; i < v->size; ++i)
    {
        printf("Element %d: ", i + 1);
        scanf("%lf", &v->elements[i]);
    }
}

void outputVector(const struct Vector *v)
{
    printf("Vector (size %d): [", v->size);
    for (int i = 0; i < v->size; ++i)
    {
        printf("%.2lf", v->elements[i]);
        if (i < v->size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void freeVector(struct Vector *v)
{
    free(v->elements);
    v->size = 0;
    v->elements = NULL;
}

int main()
{
    struct Vector myVector;

    inputVector(&myVector);
    outputVector(&myVector);

    freeVector(&myVector);

    return 0;
}
