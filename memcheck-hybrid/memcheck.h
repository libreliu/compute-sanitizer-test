// separated device codes

__device__ int x;

__global__ void unaligned_kernel(void)
{
    *(int*) ((char*)&x + 1) = 42;
}

__device__ void out_of_bounds_function(void)
{
    *(int*) 0x87654320 = 42;
}

__global__ void out_of_bounds_kernel(void)
{
    out_of_bounds_function();
}

#include <iostream>

extern void run_unaligned(void)
{
    std::cout << "Running unaligned_kernel: ";
    unaligned_kernel<<<1,1>>>();
    std::cout << cudaGetErrorString(cudaDeviceSynchronize()) << std::endl;
}

extern void run_out_of_bounds(void)
{
    std::cout << "Running out_of_bounds_kernel: ";
    out_of_bounds_kernel<<<1,1>>>();
    std::cout << cudaGetErrorString(cudaDeviceSynchronize()) << std::endl;
}
