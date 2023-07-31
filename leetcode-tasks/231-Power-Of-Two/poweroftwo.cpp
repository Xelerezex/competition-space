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

    bool isPowerOfTwo (int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (n == 1)
        {
            return true;
        }

        const double base = logbase(static_cast<double>(n), 2.0);
        double       tail{0.0};
        double       integer{0.0};

        tail = std::modf(base, &integer);

        return isApproximatelyZero(tail, 5);
    }
};

/* *************************** BEST PRACTISE ******************************* */
/* bool isPowerOfTwo (int n)                                                 */
/* {                                                                         */
/*     if (n <= 0)                                                           */
/*         return false;                                                     */
/*     return ((n & (n - 1)) == 0);                                          */
/* }                                                                         */
/* ************************************************************************* */

/* ----------------------- TRY LOGTEST ------------------------------------- */
TEST(TestingLogBase, Test0)
{
    const double input_data{0};
    const double base{2};
    const double expected{1};

    EXPECT_DOUBLE_EQ(Solution{}.logbase(input_data, base), expected);
}

TEST(TestingLogBase, Test1)
{
    const double input_data{16};
    const double base{2};
    const double expected{4};

    EXPECT_DOUBLE_EQ(Solution{}.logbase(input_data, base), expected);
}

TEST(TestingLogBase, Test2)
{
    const double input_data{65536};
    const double base{2};
    const double expected{16};

    EXPECT_DOUBLE_EQ(Solution{}.logbase(input_data, base), expected);
}

TEST(TestingLogBase, Test3)
{
    const double input_data{60'000};
    const double base{2};
    const double expected{15.872674880270607};

    EXPECT_DOUBLE_EQ(Solution{}.logbase(input_data, base), expected);
}

/* ----------------------- GENERAL TESTS FROM LEETCODE --------------------- */
TEST(TestingPositiveInput, Input1)
{
    const int  input_data{1};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, Input2)
{
    const int  input_data{2};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, Input16)
{
    const int  input_data{16};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, Input17)
{
    const int  input_data{17};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, Input2_30_minus_3)
{
    const int  input_data{static_cast<int>(std::pow(2, 30)) - 3};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, Input2_30)
{
    const int  input_data{static_cast<int>(std::pow(2, 30))};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, Input2_31)
{
    const int  input_data{static_cast<int>(std::pow(2, 31))};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, InputHuge1)
{
    // const int  input_data{536'870'912};
    const int  input_data{static_cast<int>(std::pow(2, 29))};
    const bool expected{true};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, InputHuge2)
{
    const int  input_data{1048577};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

/* ----------------------------- EXCEPTION CASES --------------------------- */
TEST(TestingNegativeInput, InputNeg1)
{
    const int  input_data{-1};
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}