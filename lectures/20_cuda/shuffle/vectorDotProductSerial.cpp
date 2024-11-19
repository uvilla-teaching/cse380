// This program computes the sum of two vectors of length N
// Heavily borrowed from : Nick from CoffeeBeforeArch

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>


// CUDA kernel for vector addition
// __global__ means this is called from the CPU, and runs on the GPU
float vectorDotProduct(const std::vector<float>& a, const std::vector<float>& b, const int& N) {
  float sum{0.0f};
  for(int i=0;i<N;++i)
    sum+=a[i]*b[i];
  return sum;
}



int main() {
  // Array size of 2^16 (65536 elements)
  constexpr int N{1<<28}, bytes{static_cast<int>(sizeof(float) * N)};;
  srand(static_cast <unsigned> (42));
  // Vectors for holding the host-side (CPU-side) data
  std::vector<float> a(N, 0.0f);
  std::vector<float> b(N, 0.0f);
  
  
  // Initialize random numbers in each array
  for (int i = 0; i < N; i++) {
    a[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  }

  float c{vectorDotProduct(a, b, N)};
  std::cout<<c<<"\n";

  std::cout << "COMPLETED SUCCESSFULLY\n";

  return 0;
}
