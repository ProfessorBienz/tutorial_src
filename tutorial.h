#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"


#ifdef __cplusplus
extern "C"
{
#endif

void transpose(int n, double* A, double* AT);
void transpose_datatype(int n, double* A, double* AT);
void transpose_alltoall(int n, double* A, double* AT);

#ifdef __cplusplus
}
#endif
