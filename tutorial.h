#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#ifdef __cplusplus
extern "C"
{
#endif

// This method exists in tutorial_src.cpp
void jacobi_standard(double* A, double* x, double* b, double* x_new, int n);

// These are the methods that you will edit
void jacobi(double* A, double* x, double* b, double* x_new, int n);
void vectorized_jacobi(double* A, double* x, double* b, double* x_new, int n);
void parallel_jacobi(double* A, double* x, double* b, double* x_new, int n);


#ifdef __cplusplus
}
#endif
