#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE (1024 * 1024)

int main() {
    float *a, *b, *c;

    // Allocate on heap (NOT stack)
    a = (float *)malloc(SIZE * sizeof(float));
    b = (float *)malloc(SIZE * sizeof(float));
    c = (float *)malloc(SIZE * sizeof(float));

    if (!a || !b || !c) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        a[i] = i * 0.5f;
        b[i] = i * 2.0f;
    }

    double start_time = omp_get_wtime();

    // Parallel loop (DLP via loop-level parallelism)
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }

    double end_time = omp_get_wtime();

    // Print first 10 results
    for (int i = 0; i < 10; i++) {
        printf("c[%d] = %f\n", i, c[i]);
    }

    printf("Execution Time: %f seconds\n", end_time - start_time);

    free(a);
    free(b);
    free(c);

    return 0;
}
