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

int main(int argc, char *argv[]) {
    char *filename_a = argv[1];
    char *filename_b = argv[2];

    // read data from file
    Matrix a = read_data(filename_a);
    Matrix b = read_data(filename_b);
    // calc histogram
    Matrix c = matmul(a, b);
    // output
    print_matrix(c);
    return 0;
}