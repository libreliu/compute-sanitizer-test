#include <iostream>
#include <cuda_runtime.h>

#if defined(_MSC_VER)
    //  Microsoft 
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    //  GCC
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
#else
    //  do nothing and hope for the best?
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

extern IMPORT void run_unaligned(void);
extern IMPORT void run_out_of_bounds(void);

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
