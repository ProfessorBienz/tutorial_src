#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"


#ifdef __cplusplus
extern "C"
{
#endif

void transpose(double* A, double* AT, int local_n, int global_n);
void transpose_datatype(double* A, double* AT, int local_n, int global_n);
void transpose_alltoall(double* A, double* AT, int local_n, int global_n);

#ifdef __cplusplus
}
#endif
