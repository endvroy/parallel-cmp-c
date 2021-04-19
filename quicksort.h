#ifndef PARALLEL_CMP_C_QUICKSORT_H
#define PARALLEL_CMP_C_QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>

int *read_data(char *filename, int *n_data) {
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d", n_data);
    int *data = malloc(*n_data * sizeof(int));
    for (int i = 0; i < *n_data; i++) {
        fscanf(fp, "%d", data + i);
    }
    return data;
}

void swap(int arr[], int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void three_way_partition(int arr[], int arr_len, int p_idx, int *a, int *b) {
    int x = 0;
    int y = 1;
    int z = 1;
    swap(arr, 0, p_idx);
    while (z < arr_len) {
        if (arr[z] < arr[x]) {
            swap(arr, x, z);
            swap(arr, y, z);
            x += 1;
            y += 1;
            z += 1;
        } else if (arr[z] == arr[x]) {
            swap(arr, y, z);
            y += 1;
            z += 1;
        } else {
            z += 1;
        }
    }
    *a = x;
    *b = y;
}

#endif //PARALLEL_CMP_C_QUICKSORT_H
