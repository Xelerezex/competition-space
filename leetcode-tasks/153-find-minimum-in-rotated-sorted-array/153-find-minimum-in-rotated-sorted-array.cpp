#include <gtest/gtest.h>

/*
// NOTE: My first solution (ugly a little bit, but with good time)
class Solution
{
public:

    int findMin(std::vector<int>& nums)
    {
        std::size_t left = 0;
        std::size_t right = nums.size() - 1;

        int result = nums[left];
        if (nums[left] < nums[right])
        {
            return result;
        }

        while (left <= right)
        {
            std::size_t middle = left + ((right - left) / 2);
            int currentValue = nums[middle];

            if (nums[left] >= currentValue && currentValue <= nums[right])
            {
                result = std::min(result, currentValue);

                left = left + 1;
                right = middle;
            }
            else if (nums[right] >= currentValue)
            {
                right = middle - 1;
            }
            else if (nums[left] <= currentValue)
            {
                left = middle + 1;
            }
        }

        return result;
    }
};
*/

// NOTE: lower_bound solution
class Solution
{
public:

    int findMin(std::vector<int>& nums)
    {    
        std::size_t leftIndex = 0;
        std::size_t rightIndex = nums.size() - 1;

        while (leftIndex < rightIndex)
        {
            // if there is no leftIndex +, only (rightIndex - leftIndex) / 2, could be inf loop
            std::size_t middle = leftIndex + ((rightIndex - leftIndex) / 2);

            if (nums[middle] < nums[rightIndex])
            {
                rightIndex = middle; /* if - 1 out of range error */
            }
            else
            {
                // mnemonic: only leftIndex +1 because of algorithm name LOWER_bound (lower aka from left)
                leftIndex = middle + 1; /* +1 - garanty from infinite loop*/
            }
        }

        return nums[leftIndex];
    }
};

TEST (SolutionTest, CornerCase1)
{
    std::vector<int> nums = { 5, 1, 2, 3, 4 };
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    std::vector<int> nums = { 2, 1 };
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::vector<int> nums = {3,4,5,6,1,2};
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums = { 4,5,0,1,2,3 };
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums = { 4,5,6,7 };
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> nums = { 3,4,5,1,2 };
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::vector<int> nums = { 4,5,6,7,0,1,2 };
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example6)
{
    std::vector<int> nums = { 11,13,15,17 };
    const auto result = Solution{}.findMin(nums);
    const auto& expected = 11;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
