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
#define THREADS_PER_BLOCK 1024
#define FULL_MASK 0xffffffff
// CUDA kernel for vector addition
// __global__ means this is called from the CPU, and runs on the GPU

float vectorDotProduct(const std::vector<float>& a, const std::vector<float>& b, const int& N) {
  float sum{0.0f};
  for(int i=0;i<N;++i)
    sum+=a[i]*b[i];
  return sum;
}

__global__ void vectorDotProductShuffle(const float *__restrict a, const float *__restrict b, float *c, int N) {

  // Calculate global thread ID
  int gtid = (blockIdx.x * blockDim.x) + threadIdx.x;
  int tid = threadIdx.x;
  if(gtid<N)
  {
    float sum{a[gtid]*b[gtid]};
    
    __syncthreads();
    for (int d=warpSize/2; d>0; d>>=1)
        sum += __shfl_down_sync(FULL_MASK, sum, d);
    __syncthreads();
    if (0==tid%warpSize)
      atomicAdd(&c[0], sum);
  }
}

int main() {
  // Array size of 2^16 (65536 elements)
  constexpr int N{1<<12}, bytes{static_cast<int>(sizeof(float) * N)};;
  srand(static_cast <unsigned> (42));
  // Vectors for holding the host-side (CPU-side) data
  std::vector<float> a(N, 0.0f);
  std::vector<float> b(N, 0.0f);
  
  
  float* d = (float *)malloc(sizeof(float));
	d[0] = 0.0f;
  // Initialize random numbers in each array
  for (int i = 0; i < N; i++) {
    a[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  }
  const float c{vectorDotProduct(a, b, N)};
  // Allocate memory on the device
  float *d_a, *d_b, *d_d;
  checkCudaErrors(cudaMalloc(&d_a, bytes));
  checkCudaErrors(cudaMalloc(&d_b, bytes));
  checkCudaErrors(cudaMalloc(&d_d, sizeof(float)));
  // Copy data from the host to the device (CPU -> GPU)
  checkCudaErrors(cudaMemcpy(d_a, a.data(), bytes, cudaMemcpyHostToDevice));
  checkCudaErrors(cudaMemcpy(d_b, b.data(), bytes, cudaMemcpyHostToDevice));

  // Threads per CTA (256)
  constexpr int NUM_THREADS{THREADS_PER_BLOCK};

  constexpr int NUM_BLOCKS = (N + NUM_THREADS - 1) / NUM_THREADS; //static_cast<size_t>(std::ceil(N/NUM_THREADS));

  // vectorDotProduct<<<NUM_BLOCKS, NUM_THREADS>>>(d_a, d_b, d_c, N);
  vectorDotProductShuffle<<<NUM_BLOCKS, NUM_THREADS>>>(d_a, d_b, d_d, N);
  
  checkCudaErrors(cudaMemcpy(d, d_d, static_cast<int>(sizeof(float)), cudaMemcpyDeviceToHost));


  std::cout<<c<<"\t"<<*d<<"\n";
  assert(abs(c-*d)<0.0001);
  checkCudaErrors(cudaFree(d_a));
  checkCudaErrors(cudaFree(d_b));
  // checkCudaErrors(cudaFree(d_c));
  checkCudaErrors(cudaFree(d_d));

  std::cout << "COMPLETED SUCCESSFULLY\n";

  return 0;
}
