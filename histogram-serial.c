//
// Created by ruoyi on 4/4/21.
//
#include <stdio.h>
#include <stdlib.h>

int *calc_histogram(double data[], int n_data, int n_bins) {
    int *histogram = calloc(n_bins, sizeof(int));
    double bin_interval = 20 / (double) n_bins;
    for (int i = 0; i < n_data; i++) {
        int bin_index = (int) (data[i] / bin_interval);
        histogram[bin_index]++;
    }
    return histogram;
}

double *read_data(char *filename, int *n_data) {
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d", n_data);
    double *data = malloc(*n_data * sizeof(double));
    for (int i = 0; i < *n_data; i++) {
        fscanf(fp, "%lf", data + i);
    }
    return data;
}


int main(int argc, char *argv[]) {
    int n_bins = atoi(argv[1]);
    int n_threads = atoi(argv[2]);
    int n_data = 0;
    char *filename = argv[3];
    double *data = read_data(filename, &n_data);
    int *histogram = calc_histogram(data, n_data, n_bins);
    for (int i = 0; i < n_bins; i++) {
        printf("bin[%d] = %d\n", i, histogram[i]);
    }
    return 0;
}
