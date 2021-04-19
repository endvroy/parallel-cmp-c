#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"

int *calc_histogram(double data[], int n_data, int n_bins) {
    int *histogram = calloc(n_bins, sizeof(int));
    double bin_interval = 20 / (double) n_bins;
    for (int i = 0; i < n_data; i++) {
        int bin_index = (int) (data[i] / bin_interval);
        histogram[bin_index]++;
    }
    return histogram;
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
