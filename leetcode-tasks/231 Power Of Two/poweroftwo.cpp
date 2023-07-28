#include <gmock/gmock.h>
#include <gtest/gtest.h>

class Solution
{
public:
    bool isPowerOfTwo (int n)
    {
        return n;
    }
};

/* ----------------------- GENERAL TESTS FROM LEETCODE --------------------- */
TEST(Testing, LengthSeven)
{
    const int  input_data{1};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}