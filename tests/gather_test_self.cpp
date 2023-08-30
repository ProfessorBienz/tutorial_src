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

    int max_log = 8;
    int max_s = pow(2, max_log - 1);

    double* send_buffer = new double[max_s];
    double* recv_buffer_orig = new double[max_s*num_procs];
    double* recv_buffer = new double[max_s*num_procs];

    for (int i = 0; i < max_s; i++)
        send_buffer[i] = i;

    int s;
    for (int i = 0; i < max_log; i++)
    {
        s = pow(2, i);
        int root = 0;
        MPI_Gather(send_buffer, s, MPI_DOUBLE, recv_buffer_orig, s, MPI_DOUBLE, 
                root, MPI_COMM_WORLD);
        simple_gather(send_buffer, recv_buffer, s, root);
        MPI_Barrier(MPI_COMM_WORLD); 

        if (rank == root)
            for (int j = 0; j < s*num_procs; j++)
                ASSERT_NEAR(recv_buffer_orig[j], recv_buffer[j], 1e-10);
    }

    delete[] send_buffer;
    delete[] recv_buffer;
    delete[] recv_buffer_orig;

}
