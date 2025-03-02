#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {

        std::vector<int> values;
        values.reserve(nums.size());
        for (const auto& value : nums)
        {
            if (value != val)
            {
                values.push_back(value);
            }
        }
        nums = std::move(values);
        return nums.size();
    }
};

TEST (SolutionTest, Example1)
{
    auto nums = std::vector<int>{ 3, 2, 2, 3 };
    const int val = 3;
    const auto& expected = 2;
    const auto& result = Solution{}.removeElement(nums, val);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto nums = std::vector<int>{};
    const int val = 0;
    const auto& expected = 0;
    const auto& result = Solution{}.removeElement(nums, val);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto nums = std::vector<int>{1};
    const int val = 1;
    const auto& expected = 0;
    const auto& result = Solution{}.removeElement(nums, val);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto nums = std::vector<int>{ 0, 1, 2, 2, 3, 0, 4, 2};
    const int val = 2;
    const auto& expected = 5;
    const auto& result = Solution{}.removeElement(nums, val);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase1)
{
    auto nums = std::vector<int>{ 3, 3 };
    const int val = 5;
    const auto& expected = 2;
    const auto& result = Solution{}.removeElement(nums, val);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    auto nums = std::vector<int>{ 3, 3 };
    const int val = 3;
    const auto& expected = 0;
    const auto& result = Solution{}.removeElement(nums, val);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
