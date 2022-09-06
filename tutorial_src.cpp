#include "tutorial.h"


void jacobi_standard(double* A, double* x, double* b, double* x_new, int n)
{
    double diag = 0;
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                diag = A[i*n+j];
            else
                sum += A[i*n+j];
        }
        x_new[i] = (b[i] - sum) / diag;
    }
}
