// Approximation of Pi using a simple, and not optimized, CUDA program
// Copyleft Alessandro Re
//
// This code is basically equivalent to the following Python code:
//
// def pigreco(NUM):
//     from random import random as rand
//     def sqrad():
//         x, y = rand(), rand()
//         return x*x + y*y
//     return 4 * sum(1 - int(test()) for _ in range(NUM)) / NUM
//
// Python version takes, on this machine, 3.5 seconds to compute 10M tests
// CUDA version takes, on this machine, 1.6 seconds to compute 20.48G tests
//
#include <iostream>
#include <limits>
#include <cassert>
#include <cuda.h>
#include <curand_kernel.h>

using std::cout;
using std::endl;

typedef unsigned long long Count;
typedef std::numeric_limits<double> DblLim;

const Count WARP_SIZE = 32; // Warp size
const Count NBLOCKS = 640; // Number of total cuda cores on my GPU

// This kernel is 
__global__ void picount(Count ITERATIONS, Count *totals) {
	// Define some shared memory: all threads in this block
	__shared__ Count counter[WARP_SIZE];

	// Unique ID of the thread
	int tid = threadIdx.x + blockIdx.x * blockDim.x;

	// Initialize RNG
	curandState_t rng;
	curand_init(clock64(), tid, 0, &rng);

	// Initialize the counter
	counter[threadIdx.x] = 0;

	// Computation loop
	for (int i = 0; i < ITERATIONS; i++) {
		float x = curand_uniform(&rng); // Random x position in [0,1]
		float y = curand_uniform(&rng); // Random y position in [0,1]
		counter[threadIdx.x] += 1 - int(x * x + y * y); // Hit test
	}
        __syncthreads();
	// The first thread in *every block* should sum the results
	if (threadIdx.x == 0) {
		// Reset count for this block
		totals[blockIdx.x] = 0;
		// Accumulate results
		for (int i = 0; i < WARP_SIZE; i++) {
			totals[blockIdx.x] += counter[i];
		}
	}
}

void usage()
{
  cout << "\nUsage: ./compute_pi [num_samples]\n\n";
  cout << "   where num_samples is an integer specifying the number\n";
  cout << "   of random samples to draw from using Monte Carlo to estimate pi\n\n";
  exit(1);
}

int main(int argc, char **argv) {
        
        Count ITERATIONS=10000000;	
        Count numSamples = WARP_SIZE*NBLOCKS*ITERATIONS;

        if(argc < 2)
		usage();

        numSamples=atoi(argv[1]);
        assert(numSamples > 0);
         
	ITERATIONS = (numSamples-1)/(WARP_SIZE*NBLOCKS) + 1;

	int numDev;
	cudaGetDeviceCount(&numDev);
	if (numDev < 1) {
		cout << "CUDA device missing! Do you need to use optirun?\n";
		return 1;
	}

	// Allocate host and device memory to store the counters
	Count *hOut, *dOut;
	hOut = new Count[NBLOCKS]; // Host memory
	cudaMalloc(&dOut, sizeof(Count) * NBLOCKS); // Device memory

	// Launch kernel
	picount<<<NBLOCKS, WARP_SIZE>>>(ITERATIONS, dOut);

	// Copy back memory used on device and free
	cudaMemcpy(hOut, dOut, sizeof(Count) * NBLOCKS, cudaMemcpyDeviceToHost);
	cudaFree(dOut);

	// Compute total hits
	Count total = 0;
	for (int i = 0; i < NBLOCKS; i++) {
		total += hOut[i];
	}
	Count tests = NBLOCKS * ITERATIONS * WARP_SIZE;

	double pi_approx = 4.0 * (double)total/(double)tests;
	double pi_exact = std::acos(-1);
	double error = std::abs(pi_exact - pi_approx);

  // Set maximum precision for decimal printing
  cout.precision(DblLim::max_digits10);
	cout << tests << "\t" << total << "\t" << tests - total << "\t" << pi_approx << "\t" << error << endl;

	return 0;
}
