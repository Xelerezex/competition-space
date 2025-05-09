#include <gtest/gtest.h>
#include <limits>

class Solution
{
public:

    std::size_t mimimum_index(std::vector<int>& nums)
    {
        std::size_t leftIndex = 0;
        std::size_t rightIndex = nums.size() - 1;

        while (leftIndex < rightIndex)
        {
            const std::size_t middle = leftIndex + ((rightIndex - leftIndex) / 2);

            if (nums[middle] <= nums[rightIndex])
            {
                rightIndex = middle;
            }
            else
            {
                leftIndex = middle + 1;
            }
        }

        return leftIndex;
    }

    std::size_t binary_search(
        std::vector<int>& nums,
        std::size_t leftIndex,
        std::size_t rightIndex,
        int target
    )
    {
        if (rightIndex < leftIndex)
        {
            return std::numeric_limits<std::size_t>::max();
        }

        while (leftIndex <= rightIndex 
            && (leftIndex < nums.size() && rightIndex < nums.size())
        )
        {
            const std::size_t middle = leftIndex + ((rightIndex - leftIndex) / 2);

            if (target == nums[middle])
            {
                return middle;
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

        return std::numeric_limits<std::size_t>::max();
    }

    int search(std::vector<int>& nums, int target)
    {
        // With lower bound algorithm find minimum value
        const std::size_t minimumIndex = mimimum_index(nums);

        // Binary search in two parts
        const std::size_t firstGroupIndex = binary_search(
            nums, 
            0, 
            minimumIndex - 1, 
            target
        );
        if (std::numeric_limits<std::size_t>::max() != firstGroupIndex)
        {
            return static_cast<int>(firstGroupIndex);
        }
        const std::size_t secondGroupIndex = binary_search(
            nums, 
            minimumIndex,  
            nums.size() - 1, 
            target
        );
        if (std::numeric_limits<std::size_t>::max() != secondGroupIndex)
        {
            return static_cast<int>(secondGroupIndex);
        }
        return -1;
    }
};

TEST (SolutionTest, Example1)
{
    std::vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums{4,5,6,7,0,1,2};
    int target = 3;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = -1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums{ 1 };
    int target = 0;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = -1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> nums{ 3,4,5,6,1,2 };
    int target = 1;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::vector<int> nums{ 3,5,6,0,1,2 };
    int target = 4;
    const auto result = Solution{}.search(nums, target);
    const auto& expected = -1;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
