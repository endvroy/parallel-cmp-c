#include <time.h>
#include <stdio.h>
#include <omp.h>

int main(void) {
    omp_set_dynamic(0);
    int n_threads = 1000;
    clock_t start_t = clock();
    omp_set_num_threads(n_threads); // set num of threads
#pragma omp parallel num_threads(n_threads)
    { ; }
    clock_t end_t = clock();
    clock_t elapsed_ticks = end_t - start_t;
    double spawn_time = (double) elapsed_ticks / (CLOCKS_PER_SEC) * 1000 / n_threads;
    printf("%fms\n", spawn_time);
    return 0;
}
