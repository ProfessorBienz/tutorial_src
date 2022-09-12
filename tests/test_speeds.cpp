// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "tutorial_src/tutorial.h"

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

#include <omp.h>

double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}



int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    int temp = RUN_ALL_TESTS();

    return temp;
}

TEST(TLBTest, TestsIntests)
{
    int n = 100;

    double* A = new double[n*n];
    double* x = new double[n];
    double* b = new double[n];

    double* x_std = new double[n];
    double* x_new = new double[n];

    for (int i = 0; i < n; i++)
    {
        x[i] = 1.0;
        b[i] = 0.5;
        for (int j = 0; j < n; j++)
        {
            A[i*n+j] = 1.0 / (i*n+j+1);
        }
    }

    double t0, tfinal;
    int n_iter = 1000;

    jacobi_standard(A, x, b, x_std, n);
    t0 = get_time();
    for (int i = 0; i < n_iter; i++)
    {
        jacobi_standard(A, x, b, x_std, n);
    }
    tfinal = (get_time() - t0) / n_iter;
    printf("Professor's Original Implementation : %e seconds\n", tfinal);

    jacobi(A, x, b, x_std, n);
    t0 = get_time();
    for (int i = 0; i < n_iter; i++)
    {
        jacobi(A, x, b, x_std, n);
    }
    tfinal = (get_time() - t0) / n_iter;
    printf("Your Branch Prediction Implementation : %e seconds\n", tfinal);

    vectorized_jacobi(A, x, b, x_std, n);
    t0 = get_time();
    for (int i = 0; i < n_iter; i++)
    {
        vectorized_jacobi(A, x, b, x_std, n);
    }
    tfinal = (get_time() - t0) / n_iter;
    printf("Your Vectorized Implementation : %e seconds\n", tfinal);


    parallel_jacobi(A, x, b, x_std, n);
    t0 = get_time();
    for (int i = 0; i < n_iter; i++)
    {
        parallel_jacobi(A, x, b, x_std, n);
    }
    tfinal = (get_time() - t0) / n_iter;
    int n_threads;
#pragma omp parallel num_threads(4)
    {
        printf("omp num threads %d\n", omp_get_num_threads());
    }
    printf("Your Parallel Implementation (%d threads) : %e seconds\n", n_threads, tfinal);

    delete[] A;
}
