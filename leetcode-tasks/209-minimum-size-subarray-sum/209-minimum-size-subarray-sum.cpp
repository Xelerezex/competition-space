#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:

    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        int result = 0;
        return result;
    }
};

TEST (SolutionTest, Example1)
{
    const int target = 7;
    std::vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    const int expected = 2;
    EXPECT_EQ(expected, Solution{}.minSubArrayLen(target, nums));
}

TEST (SolutionTest, Example2)
{
    const int target = 4;
    std::vector<int> nums = { 1, 4, 4 };
    const int expected = 2;
    EXPECT_EQ(expected, Solution{}.minSubArrayLen(target, nums));
}

TEST (SolutionTest, Example3)
{
    const int target = 11;
    std::vector<int> nums = { 1,1,1,1,1,1,1,1 };
    const int expected = 0;
    EXPECT_EQ(expected, Solution{}.minSubArrayLen(target, nums));
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

