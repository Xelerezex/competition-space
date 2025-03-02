#include <gtest/gtest.h>

#include <vector>

class Solution
{

public:

    int pivotIndex(std::vector<int>& nums)
    {
        std::vector<int> prefixSum(nums.size() + 1, 0);
        std::vector<int> postfixSum(nums.size() + 1, 0);

        for (int index = 0; index < nums.size(); ++index)
        {
            prefixSum[index + 1] = nums[index] + prefixSum[index];

            int lastIndex = nums.size();
            int backIndex = lastIndex - index;
            postfixSum[backIndex - 1] = nums[backIndex - 1] + postfixSum[backIndex];
        }

        int result = -1;

        for (int index = 1; index < prefixSum.size(); ++index)
        {
            if (prefixSum[index] == postfixSum[index - 1] 
                && postfixSum[index] == prefixSum[index - 1]
            )
            {
                result = index - 1;
                break;
            }
        }

        return result;
    }
};
    
TEST (SolutionTest, Example1)
{
    auto height = std::vector<int>{1,7,3,6,5,6};
    const auto& result = Solution{}.pivotIndex(height);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}
    
TEST (SolutionTest, Example2)
{
    auto height = std::vector<int>{ 2 };
    const auto& result = Solution{}.pivotIndex(height);
    const auto& expected = 0;
    EXPECT_EQ(expected, result);
}
    
TEST (SolutionTest, Example3)
{
    auto height = std::vector<int>{ 1, 2, 3 };
    const auto& result = Solution{}.pivotIndex(height);
    const auto& expected = -1;
    EXPECT_EQ(expected, result);
}
    
TEST (SolutionTest, Example4)
{
    auto height = std::vector<int>{ 2, 1, -1 };
    const auto& result = Solution{}.pivotIndex(height);
    const auto& expected = 0;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
