#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>
#include <memory.h>

static const long Num_To_Sort = 1000000000;

// Sequential version of your sort
// If you're implementing the PSRS algorithm, you may ignore this section
void sort_s(int *arr) {

}

// Parallel version of your sort
void sort_p(int *arr) {

}

int main() {
    int *arr_s = malloc(sizeof(int) * Num_To_Sort);
    for (long i = 0; i < Num_To_Sort; i++) {
        arr_s[i] = rand();
    }

    // Copy the array so that the sorting function can operate on it directly.
    // Note that this doubles the memory usage.
    // You may wish to test with slightly smaller arrays if you're running out of memory.
    int *arr_p = malloc(sizeof(int) * Num_To_Sort);
    memcpy(arr_p, arr_s, sizeof(int) * Num_To_Sort);

    struct timeval start, end;

    printf("Timing sequential...\n");
    gettimeofday(&start, NULL);
    sort_s(arr_s);
    gettimeofday(&end, NULL);
    printf("Took %f seconds\n\n", end.tv_sec - start.tv_sec + (double) (end.tv_usec - start.tv_usec) / 1000000);

    free(arr_s);

    printf("Timing parallel...\n");
    gettimeofday(&start, NULL);
    sort_p(arr_p);
    gettimeofday(&end, NULL);
    printf("Took %f seconds\n\n", end.tv_sec - start.tv_sec + (double) (end.tv_usec - start.tv_usec) / 1000000);

    free(arr_p);

    return 0;
}

