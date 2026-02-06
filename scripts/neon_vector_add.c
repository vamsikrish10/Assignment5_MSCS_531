#include <stdio.h>
#include <stdlib.h>
#include <arm_neon.h>

#define N 16   // MUST be multiple of 4

int main() {
    float *a, *b, *c;

    // Properly aligned memory
    posix_memalign((void**)&a, 16, N * sizeof(float));
    posix_memalign((void**)&b, 16, N * sizeof(float));
    posix_memalign((void**)&c, 16, N * sizeof(float));

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0f;
        b[i] = i * 2.0f;
    }

    // NEON vectorized loop
    for (int i = 0; i < N; i += 4) {
        float32x4_t va = vld1q_f32(&a[i]);
        float32x4_t vb = vld1q_f32(&b[i]);
        float32x4_t vc = vaddq_f32(va, vb);
        vst1q_f32(&c[i], vc);
    }

    for (int i = 0; i < N; i++) {
        printf("c[%d] = %.2f\n", i, c[i]);
    }

    free(a);
    free(b);
    free(c);
    return 0;
}
