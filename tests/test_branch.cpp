// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "tutorial_src/tutorial.h"

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

    jacobi_standard(A, x, b, x_std, n);
    jacobi(A, x, b, x_new, n);
    for (int i = 0; i < n; i++)
        ASSERT_NEAR(x_std[i], x_new[i], 1e-12);

    delete[] A;
}
