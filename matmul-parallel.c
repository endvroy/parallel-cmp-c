#include "matmul.h"
#include <omp.h>

Matrix matmul(Matrix a, Matrix b) {
    Matrix c = matrix_new(a.n_rows, b.n_cols);
#pragma omp parallel for
    for (int row = 0; row < a.n_rows; row++) {
#pragma omp parallel for
        for (int col = 0; col < b.n_cols; col++) {
            double sum = 0.0;
#pragma omp parallel for
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
    int n_threads = atoi(argv[2]);
    omp_set_num_threads(n_threads); // set num of threads
    omp_set_nested(1);
    omp_set_dynamic(0); // disable dynamic adjustment of num of threads

    // read data from file
    Matrix a = read_data(filename_a);
    Matrix b = read_data(filename_b);
    // calc histogram
    Matrix c = matmul(a, b);
    // output
    print_matrix(c);
    return 0;
}