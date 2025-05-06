#include <gtest/gtest.h>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        std::size_t leftIndex = 0;
        std::size_t rightIndex = nums.size() - 1;

        while (leftIndex <= rightIndex 
            && (leftIndex < nums.size() && rightIndex < nums.size()) // cause of std::size_t in CornerCase1
        )
        {
            std::size_t middle = leftIndex + ((rightIndex - leftIndex) / 2);

            if (target == nums[middle])
            {
                return static_cast<int>(middle);
            }
            else if (target < nums[middle])
            {
                rightIndex = middle - 1;
            }
            else if (target > nums[middle])
            {
                leftIndex = middle + 1;
            }
        }

        return -1;
    }
};

TEST (SolutionTest, CornerCase1)
{
    std::vector<int> nums = { 5 };
    const int target = -5;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = -1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::vector<int> nums = {-1,0,3,5,9,12};
    const int target = 9;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums = { -1,0,3,5,9,12 };
    const int target = 2;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = -1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums = { -1,0,2,4,6,8 };
    const int target = 4;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> nums = { -1,0,2,4,6,8 };
    const int target = 3;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = -1;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
