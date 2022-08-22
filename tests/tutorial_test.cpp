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
    ASSERT_EQ(0, tutorial());
}
