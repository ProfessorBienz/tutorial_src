#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"


#ifdef __cplusplus
extern "C"
{
#endif

double power_method_seq(int n, double* A, double* x, double* tmp, int n_iter);

double power_method(int global_n, int local_n, int first_n, double* A, double* x, double* tmp, int n_iter);

void simple_gather(const double* send_buffer, double* recv_buffer, int count, int root);

#ifdef __cplusplus
}
#endif
