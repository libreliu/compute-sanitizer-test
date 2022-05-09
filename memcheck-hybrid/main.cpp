#include <iostream>
#include <cuda_runtime.h>

extern void run_unaligned(void);
extern void run_out_of_bounds(void);

int main() {
    int *devMem = nullptr;

    std::cout << "Mallocing memory" << std::endl;
    cudaMalloc((void**)&devMem, 1024);

    run_unaligned();
    run_out_of_bounds();

    // Omitted to demo leakcheck
    // cudaFree(devMem);

    return 0;
}
