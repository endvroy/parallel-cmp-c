#include "quicksort.h"
#include <stdlib.h>
#include <time.h>
#include <omp.h>


void quicksort(int arr[], int arr_len) {
    srand(time(NULL));
    if (arr_len <= 1) {
        return;
    }
    int p_idx = rand() % arr_len;
    int a, b;
    three_way_partition(arr, arr_len, p_idx, &a, &b);

#pragma omp task shared(arr)
    quicksort(arr, a);
#pragma omp task shared(arr)
    quicksort(arr + b, arr_len - b);
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    int n_threads = atoi(argv[2]);
    omp_set_num_threads(n_threads); // set num of threads
    omp_set_dynamic(0); // disable dynamic adjustment of num of threads

    int n_data = 0;
    int *data = read_data(filename, &n_data);
    quicksort(data, n_data);
    for (int i = 0; i < n_data; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}