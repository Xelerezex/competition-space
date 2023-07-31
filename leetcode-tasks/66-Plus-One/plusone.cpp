#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    std::vector<int> plusOne (std::vector<int>& digits)
    {
        for (auto it = rbegin(digits); it != rend(digits); ++it)
        {
            if (it == rbegin(digits))
            {
                *it += 1;
            }
            else if (it != rbegin(digits) && *(it - 1) == 10)
            {
                *(it - 1) = 0;
                *it += 1;
            }
        }

        auto it = begin(digits);
        if (*it == 10)
        {
            *(it) = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

/* ----------------------- GENERAL TESTS FROM LEETCODE --------------------- */
TEST(TestingGeneralInput, Test1)
{
    std::vector<int>       input_data = {1, 1, 1, 1, 9};
    const std::vector<int> expected   = {1, 1, 1, 2, 0};

    EXPECT_EQ(Solution{}.plusOne(input_data), expected);
}

TEST(TestingGeneralInput, Test2)
{
    std::vector<int>       input_data = {1, 2, 3};
    const std::vector<int> expected   = {1, 2, 4};

    EXPECT_EQ(Solution{}.plusOne(input_data), expected);
}

TEST(TestingGeneralInput, Test3)
{
    std::vector<int>       input_data = {4, 3, 2, 1};
    const std::vector<int> expected   = {4, 3, 2, 2};

    EXPECT_EQ(Solution{}.plusOne(input_data), expected);
}

TEST(TestingGeneralInput, Test4)
{
    std::vector<int>       input_data = {0};
    const std::vector<int> expected   = {1};

    EXPECT_EQ(Solution{}.plusOne(input_data), expected);
}

TEST(TestingGeneralInput, Test5)
{
    std::vector<int>       input_data = {9};
    const std::vector<int> expected   = {1, 0};

    EXPECT_EQ(Solution{}.plusOne(input_data), expected);
}

TEST(TestingGeneralInput, Test6)
{
    std::vector<int>       input_data = {9, 9, 9};
    const std::vector<int> expected   = {1, 0, 0, 0};

    EXPECT_EQ(Solution{}.plusOne(input_data), expected);
}

TEST(TestingGeneralInput, Test7)
{
    std::vector<int>       input_data = {99, 9};
    const std::vector<int> expected   = {100, 0};

    EXPECT_EQ(Solution{}.plusOne(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}