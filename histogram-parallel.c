#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "histogram.h"

int *calc_partial_histogram(double data[], int n_data, int *histogram, int n_bins) {
    int thread_cnt = omp_get_num_threads();
    int data_interval = n_data / thread_cnt;
    int tid = omp_get_thread_num();
    // get the range of data this thread is responsible for
    int low = data_interval * tid;
    int high = low + data_interval;
    // initialize the histogram with 0
    for (int bin_idx = 0; bin_idx < n_bins; bin_idx++) {
        histogram[bin_idx] = 0;
    }
    // update the local histogram
    double bin_interval = 20 / (double) n_bins;
    for (int i = low; i < n_data && i < high; i++) {
        int bin_index = (int) (data[i] / bin_interval);
        histogram[bin_index]++;
    }
    return histogram;
}

int *calc_histogram(double data[], int n_data, int n_bins) {
    int *histogram = calloc(n_bins, sizeof(int)); // the global histogram
    int thread_cnt = omp_get_num_threads();
    int data_interval = n_data / thread_cnt;
#pragma omp parallel num_threads(thread_cnt)
    {
        // each thread calculates part of the histogram
        int local_histogram[n_bins];
        calc_partial_histogram(data, n_data, local_histogram, n_bins);
#pragma omp critical
        {
            // merge local histogram into global
            for (int bin_idx = 0; bin_idx < n_bins; bin_idx++) {
                histogram[bin_idx] += local_histogram[bin_idx];
            }
        }
    }
    return histogram;
}


int main(int argc, char *argv[]) {
    char *filename = argv[1];
    int n_threads = atoi(argv[2]);
    int n_bins = 20;
    omp_set_num_threads(n_threads); // set num of threads
    omp_set_dynamic(0); // disable dynamic adjustment of num of threads
    int n_data = 0;

    // read data from file
    double *data = read_data(filename, &n_data);
    // calc histogram
    int *histogram = calc_histogram(data, n_data, n_bins);
    // output
    for (int i = 0; i < n_bins; i++) {
        printf("bin[%d] = %d\n", i, histogram[i]);
    }
    return 0;
}
