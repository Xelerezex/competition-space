#include <gtest/gtest.h>

#include <vector>
#include <unordered_set>

class Solution
{
public:

    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> values(std::cbegin(nums), std::cend(nums));

        int result = 0;

        for (const auto& value : values)
        {
            if (std::cend(values) != values.find(value - 1))
            {
                continue;
            }

            int currentResult = 1;

            auto nextValue = value + 1;
            while (std::cend(values) != values.find(nextValue))
            {
                ++currentResult;
                ++nextValue;
            }
            
            result = std::max(result, currentResult);
        }

        return result;
    }
};

TEST (SolutionTest, Example1)
{
    auto nums = std::vector<int>{ 100, 4, 200, 1, 3, 2 };
    const auto& expected = 4;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto nums = std::vector<int>{ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
    const auto& expected = 9;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto nums = std::vector<int>{ 2, 20, 4, 10, 3, 4, 5 };
    const auto& expected = 4;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto nums = std::vector<int>{ 0, 3, 2, 5, 4, 6, 1, 1 };
    const auto& expected = 7;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto nums = std::vector<int>{ };
    const auto& expected = 0;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase1)
{
    auto nums = std::vector<int>{ 0, 0};
    const auto& expected = 1;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    auto nums = std::vector<int>{ 0, 1, 0 };
    const auto& expected = 2;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase3)
{
    auto nums = std::vector<int>{ 0 };
    const auto& expected = 1;
    const auto& result = Solution{}.longestConsecutive(nums);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
