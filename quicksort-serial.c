#include "quicksort.h"
#include <stdlib.h>
#include <time.h>


void quicksort(int arr[], int arr_len) {
    srand(time(NULL));
    if (arr_len <= 1) {
        return;
    }
    int p_idx = rand() % arr_len;
    int a, b;
    three_way_partition(arr, arr_len, p_idx, &a, &b);
    quicksort(arr, a);
    quicksort(arr + b, arr_len - b);
}

int main() {

}