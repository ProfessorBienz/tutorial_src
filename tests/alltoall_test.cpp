// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "tutorial_src/tutorial.h"
#include "mpi.h"

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
    int local_n = global_n / num_procs;
    int first_n = local_n * rank;

    double* A = new double[local_n * global_n];
    double* AT = new double[local_n * global_n];
    double* AT_new = new double[local_n * global_n];

    srand(time(NULL) + rank);
    for (int i = 0; i < local_n; i++)
    {
        for (int j = 0; j < global_n; j++)
        {
            A[i*global_n+j] = (double)(rand()) / RAND_MAX;
        }
    }

    transpose(A, AT, local_n, global_n);

    transpose_alltoall(A, AT_new, local_n, global_n);

    for (int i = 0; i < local_n; i++)
    {
        for (int j = 0; j < global_n; j++)
        {
            ASSERT_NEAR(AT[i*global_n+j], AT_new[i*global_n+j], 1e-10);
        }
    }

    delete[] A;
    delete[] AT;
    delete[] AT_new;
}
