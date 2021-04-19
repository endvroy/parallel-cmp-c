//
// Created by Ruoyi on 2021-04-18.
//

#ifndef PARALLEL_CMP_C_QUICKSORT_H
#define PARALLEL_CMP_C_QUICKSORT_H

int *read_data(char *filename, int *n_data) {
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d", n_data);
    int *data = malloc(*n_data * sizeof(int));
    for (int i = 0; i < *n_data; i++) {
        fscanf(fp, "%d", data + i);
    }
    return data;
}

#endif //PARALLEL_CMP_C_QUICKSORT_H
