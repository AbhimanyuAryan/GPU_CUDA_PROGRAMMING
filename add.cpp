#include <iostream>
#include <math.h>

void add(int n, float *x, float *y){
	for(int i= 0; i < n; i++) 
	{
		y[i] = x[i] + y[i];
	}
}

int main(void)
{
	int N = 1<<20; // 1M elements

	float *x = new float[N];
	float *y = new float[N];

	// initialize x and y arrays on the host
	for(int i = 0; i < N; i++)
	{
		x[i] = 1.0f;
		y[i] = 2.0f;
	}

	// Run kernel on 1M elements on the CPU
	add(N,x,y);

	// Free Memory
	delete [] x;
	delete [] y;

	return 0;
}

// Kernel is function that can be executed parallel on GPU
// It's executed by an array of CUDA Threads

// Thread Block 0 	       Thread Block 1 		 Thread Block N - 1
// threadID
// It's threadID controls memory address that is used to compute things
// We can run thousands of these threadskk

// __global__ void kernel(float *in, float *out)
// {
// 	int tid = blockIdx.x * blockDim.x + threadIdx.x;
// 	out[tid] = in[tid];
// }