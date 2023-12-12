#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    size_t rows, collumns, elems_capacity;
    double* data;
} Matrix;

Matrix mat_alloc(size_t rows, size_t collumns) {
    size_t capacity = (rows + 1) * (collumns + 1);

    double* data = (double*)malloc(capacity * sizeof(*data));

    return (Matrix) {
        .rows = rows,
        .collumns = collumns,
        .elems_capacity = capacity,
        .data = data
    };
}

void mat_free(Matrix mat) {
    if (mat.data) {
        free(mat.data);
    }
}

void mat_insert_row(Matrix* mat, size_t at) {
    if (!mat->data) return;
    bool resize = mat->elems_capacity < (mat->rows+1) * mat->collumns;
    if (resize) {

        double* new_buf = (double*)malloc(sizeof(*mat->data)*(mat->elems_capacity * 2 + mat->collumns));
        memcpy(new_buf, mat->data, sizeof(*mat->data) * at * mat->collumns);
        memset(new_buf + at * mat->collumns, 0, sizeof(*mat->data) * mat->collumns);
        memcpy(
            new_buf + (at + 1) * mat->collumns, 
            mat->data + at * mat->collumns, 
            sizeof(*mat->data) * (mat->rows - at) * mat->collumns
        );
        mat->rows += 1;
        free(mat->data);
        mat->data = new_buf;
        return;
    }

    memmove(
        mat->data + (at+1) * mat->collumns, 
        mat->data + at * mat->collumns, 
        sizeof(*mat->data) * (mat->rows - at) * mat->collumns
    );

    memset(mat->data + at * mat->collumns, 0, sizeof(*mat->data) * mat->collumns);
    mat->rows += 1;
}

int main(void) {
    size_t n, m;
    scanf("%zu%zu", &n, &m);

    Matrix mat = mat_alloc(n, m);
    for (unsigned i = 0; i < mat.rows; i++)
        for (unsigned j = 0; j < mat.collumns; j++) {
            scanf("%lf", mat.data+i*mat.collumns+j);
        }

    mat_insert_row(&mat, n/2);

    for (unsigned i = 0; i < mat.rows; i++) {
        for (unsigned j = 0; j < mat.collumns; j++) {
            printf("%lf ", *(mat.data+i*mat.collumns+j));
        }
        putchar('\n');
    }
    
    mat_free(mat);
}