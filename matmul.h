//
// Created by Ruoyi on 2021-04-18.
//

#ifndef PARALLEL_CMP_C_MATMUL_H
#define PARALLEL_CMP_C_MATMUL_H

double **read_data(char *filename, int *n_rows, int *n_cols) {
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d &d", n_rows, n_cols);
    double **data = malloc(*n_rows * sizeof(double *));
    for (int i = 0; i < *n_rows; i++) {
        data[i] = malloc(*n_cols * sizeof(double));
    }
    for (int i = 0; i < *n_rows; i++) {
        for (int j = 0; j < *n_cols; j++) {
            fscanf(fp, "%lf", &data[i][j]);
        }
    }
    return data;
}

#endif //PARALLEL_CMP_C_MATMUL_H
