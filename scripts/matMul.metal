#include <metal_stdlib>
using namespace metal;

// Matrix multiplication kernel
kernel void matMul(device const float* A [[ buffer(0) ]],
                   device const float* B [[ buffer(1) ]],
                   device float* C [[ buffer(2) ]],
                   constant uint& N [[ buffer(3) ]],
                   uint id [[ thread_position_in_grid ]]) {

    uint row = id / N;
    uint col = id % N;

    float sum = 0.0;

    for(uint k = 0; k < N; k++){
        sum += A[row * N + k] * B[k * N + col];
    }

    C[row * N + col] = sum;
}
