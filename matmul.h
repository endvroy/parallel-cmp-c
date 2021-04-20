#ifndef PARALLEL_CMP_C_MATMUL_H
#define PARALLEL_CMP_C_MATMUL_H

#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int n_rows;
    int n_cols;
    double **buf;
};

typedef struct Matrix Matrix;

Matrix matrix_new(int n_rows, int n_cols) {
    Matrix matrix;
    matrix.n_rows = n_rows;
    matrix.n_cols = n_cols;
    double **buf = malloc(matrix.n_rows * sizeof(double *));
    for (int i = 0; i < matrix.n_rows; i++) {
        buf[i] = malloc(matrix.n_cols * sizeof(double));
    }
    matrix.buf = buf;
    return matrix;
}

Matrix read_data(char *filename) {
    FILE *fp = fopen(filename, "r");
    int n_rows, n_cols;
    fscanf(fp, "%d %d", &n_rows, &n_cols);
    Matrix matrix = matrix_new(n_rows, n_cols);
    for (int i = 0; i < matrix.n_rows; i++) {
        for (int j = 0; j < matrix.n_cols; j++) {
            fscanf(fp, "%lf", &matrix.buf[i][j]);
        }
    }
    return matrix;
}

void print_matrix(Matrix m) {
    printf("Matrix(%d * %d)\n", m.n_rows, m.n_cols);
    puts("[");
    for (int row = 0; row < m.n_rows; row++) {
        putchar('[');
        for (int col = 0; col < m.n_cols; col++) {
            printf("%f", m.buf[row][col]);
            if (col != m.n_cols - 1) {
                printf(", ");
            }
        }
        puts("],");
    }
    puts("]");
}

#endif //PARALLEL_CMP_C_MATMUL_H
