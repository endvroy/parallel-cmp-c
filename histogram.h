#ifndef PARALLEL_CMP_C_HISTOGRAM_H
#define PARALLEL_CMP_C_HISTOGRAM_H

#include <stdio.h>
#include <stdlib.h>

double *read_data(char *filename, int *n_data) {
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d", n_data);
    double *data = malloc(*n_data * sizeof(double));
    for (int i = 0; i < *n_data; i++) {
        fscanf(fp, "%lf", data + i);
    }
    return data;
}

#endif //PARALLEL_CMP_C_HISTOGRAM_H
