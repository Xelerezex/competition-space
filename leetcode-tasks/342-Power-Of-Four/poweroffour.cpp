#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>
#include <cmath>

class Solution
{
public:
    static bool isApproximatelyZero (double number,
                                     int    rounding = 0,
                                     double tolerance
                                     = std::numeric_limits<double>::epsilon())
    {
        return std::fabs(number) <= tolerance * std::pow(10, rounding);
    }

    double logbase (double number, double base)
    {
        if (number == 0.0)
        {
            return 1.0;
        }

        return static_cast<double>(log(number))
               / static_cast<double>(log(base));
    }

    bool isPowerOfFour (int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (n == 1)
        {
            return true;
        }

        const double base = logbase(static_cast<double>(n), 4.0);
        double       tail{0.0};
        double       integer{0.0};

        tail = std::modf(base, &integer);

        return isApproximatelyZero(tail, 5);
    }
};

/* *************************** BEST PRACTISE ******************************* */

/* ************************************************************************* */

/* ----------------------- TRY LOGTEST ------------------------------------- */
TEST(TestingLogBase, Test0)
{
    const double input_data{16};
    const double base{4};
    const double expected{2};

    EXPECT_DOUBLE_EQ(Solution{}.logbase(input_data, base), expected);
}

TEST(TestingLogBase, Test4)
{
    const double input_data{4096};
    const double base{4};
    const double expected{6};

    EXPECT_DOUBLE_EQ(Solution{}.logbase(input_data, base), expected);
}

/* ----------------------- GENERAL TESTS FROM LEETCODE --------------------- */
TEST(TestingPositiveInput, Input1)
{
    const int  input_data{16};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

TEST(TestingPositiveInput, Input2)
{
    const int  input_data{5};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

TEST(TestingPositiveInput, Input3)
{
    const int  input_data{1};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

TEST(TestingPositiveInput, Input4)
{
    const int  input_data{1'073'741'824};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

TEST(TestingPositiveInput, Input5)
{
    const int  input_data{1'073'741'823};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

TEST(TestingPositiveInput, Input6)
{
    const int  input_data{1'073'741'825};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

TEST(TestingPositiveInput, Input7)
{
    const int  input_data{8};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

/* ------------------------------- RUN ALL TEST ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}