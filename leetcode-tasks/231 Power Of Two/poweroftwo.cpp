#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <bitset>
#include <cmath>

class Solution
{
public:
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

        /*
        TODO: Try
        double logbase(double a, double base)
        {
        return log(a) / log(base);
        }

        int main()
        {
        double x = 65536;
        double result;

        result = logbase(x, 2);
        printf("Log base 2 of %lf is %lf\n", x, result);
        }
        */
        // double square{std::sqrt(n)};
        double tail{0.0};

        tail = std::modf(square, &square);

        std::cout << square << " " << tail << std::endl;

        if (tail != 0.0)
        {
            return false;
        }

        long shiftedNumber{0 | (1 << static_cast<int>(square))};

        std::cout << std::bitset<std::numeric_limits<long>::digits>(
            shiftedNumber)
                  << " == " << shiftedNumber << std::endl;

        return n == shiftedNumber;
    }
};

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
    const bool expected{false};

    EXPECT_EQ(Solution{}.isPowerOfTwo(input_data), expected);
}

TEST(TestingPositiveInput, Input16)
{
    const int  input_data{16};
    const bool expected{true};

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