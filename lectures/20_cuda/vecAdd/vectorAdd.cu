// This program computes the sum of two vectors of length N
// Heavily borrowed from : Nick from CoffeeBeforeArch

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <fstream>
#include <helper_cuda.h>
#include <math.h>
#include <cuda_runtime.h>

// __device__ here shows that it will be called from GPU kernel
__device__ __forceinline__ float f(const float& i)
{
  return expf(i);
}

// CUDA kernel for vector addition
// __global__ means this is called from the CPU, and runs on the GPU
__global__ void vectorAdd(const float *__restrict a, const float *__restrict b,
                          float *__restrict c, int N) {
  // Calculate global thread ID
  int tid = (blockIdx.x * blockDim.x) + threadIdx.x;
  // Boundary check
  if (tid < N) 
  {
    c[tid]=0.0f;
    for(int i=0;i<50;++i)
      c[tid] += (f(a[tid]) + f(b[tid]));
  }
}


// Check vector add result
__global__ void verify_result(const float *__restrict a, const float *__restrict b,
                   const float *__restrict c, int N) {
  int tid = (blockIdx.x * blockDim.x) + threadIdx.x;
  if (tid < N) assert(abs(c[tid] - 50.0f*(f(a[tid]) + f(b[tid]))) < 0.001);
}

int main() {
  // Array size of 2^16 (65536 elements)
  constexpr int N{1 << 28}, bytes{static_cast<int>(sizeof(float) * N)};
  srand(static_cast <unsigned> (time(0)));
  // Vectors for holding the host-side (CPU-side) data
  std::vector<float> a(N, 0.0f);
  // a.reserve(N);
  std::vector<float> b(N, 0.0f);
  // b.reserve(N);
  std::vector<float> c(N, 0.0f);
  // c.reserve(N);

  // Initialize random numbers in each array
  for (int i = 0; i < N; i++) {
    a[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  }

  // Allocate memory on the device
  float *d_a, *d_b, *d_c;
  checkCudaErrors(cudaMalloc(&d_a, bytes));
  checkCudaErrors(cudaMalloc(&d_b, bytes));
  checkCudaErrors(cudaMalloc(&d_c, bytes));

  // Copy data from the host to the device (CPU -> GPU)
  checkCudaErrors(cudaMemcpy(d_a, a.data(), bytes, cudaMemcpyHostToDevice));
  checkCudaErrors(cudaMemcpy(d_b, b.data(), bytes, cudaMemcpyHostToDevice));

  // Threads per CTA (256)
  int NUM_THREADS{1 << 8};

  // CTAs per Grid
  // We need to launch at LEAST as many threads as we have elements
  // This equation pads an extra CTA to the grid if N cannot evenly be divided
  // by NUM_THREADS (e.g. N = 1025, NUM_THREADS = 1024)
  int NUM_BLOCKS = (N + NUM_THREADS - 1) / NUM_THREADS; //static_cast<size_t>(std::ceil(N/NUM_THREADS));

  // Launch the kernel on the GPU
  // Kernel calls are asynchronous (the CPU program continues execution after
  // call, but no necessarily before the kernel finishes)


  vectorAdd<<<NUM_BLOCKS, NUM_THREADS>>>(d_a, d_b, d_c, N);
  // Stop timer and calculate execution duration

  // Copy sum vector from device to host
  // cudaMemcpy is a synchronous operation, and waits for the prior kernel
  // launch to complete (both go to the default stream in this case).
  // Therefore, this cudaMemcpy acts as both a memcpy and synchronization
  // barrier.
  checkCudaErrors(cudaMemcpy(c.data(), d_c, bytes, cudaMemcpyDeviceToHost));


  verify_result<<<NUM_BLOCKS, NUM_THREADS>>>(d_a, d_b, d_c, N);

  // Free memory on device
  checkCudaErrors(cudaFree(d_a));
  checkCudaErrors(cudaFree(d_b));
  checkCudaErrors(cudaFree(d_c));

  std::cout << "COMPLETED SUCCESSFULLY\n";

  return 0;
}
