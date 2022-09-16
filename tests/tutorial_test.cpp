// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "tutorial_src/tutorial.h"

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);

    ::testing::InitGoogleTest(&argc, argv);

    int temp = RUN_ALL_TESTS();

    MPI_Finalize();
    return temp;
}

TEST(TLBTest, TestsIntests)
{
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int global_n = 1024;
    int n_ter = 1000;
    double* A = new double[global_n*global_n];
    double* x_seq = new double[global_n];
    double* x_par = new double[global_n];
    double* tmp = new double[global_n];

    for (int i = 0; i < global_n; i++)
    {
        for (int j = 0; j < global_n; j++)
        {
            A[i*global_n+j] = ((double)rand()) / RAND_MAX;
        }
        x_seq[i] = ((double)rand()) / RAND_MAX;
        x_par[i] = x_seq[i];
    }

    double lamda_seq = power_method_seq(global_n, A, x_seq, tmp, n_iter);

    int local_n = global_n / num_procs;
    int first_n = local_n * rank;
    double lambda_par = power_method(global_n, local_n, A, x_par, tmp, n_iter);


    for (int i = 0; i < global_n; i++)
        ASSERT_NEAR(x_seq, x_par, 1e-10);

    delete[] A;
    delete[] x_seq;
    delete[] x_par;
    delete[] tmp;
}
