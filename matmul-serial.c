#include "matmul.h"

Matrix matmul(Matrix a, Matrix b) {
    Matrix c = matrix_new(a.n_rows, b.n_cols);
    for (int row = 0; row < a.n_rows; row++) {
        for (int col = 0; col < b.n_cols; col++) {
            double sum = 0.0;
            for (int i = 0; i < a.n_cols; i++) {
                sum += a.buf[row][i] * b.buf[i][col];
            }
            c.buf[row][col] = sum;
        }
    }
    return c;
}