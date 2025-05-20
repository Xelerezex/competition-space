#include <gtest/gtest.h>

// NOTE: My first solution. And it is quiet efficient
class Solution
{

public:

    int findDuplicate(std::vector<int>& nums)
    {
        int result = 0;

        for (std::size_t index = 0; index < nums.size(); ++index)
        {
            const int indexByValue = std::abs(nums[index]) - 1;
            if (nums[indexByValue] <= 0)
            {
                result = std::abs(nums[index]);
                break;
            }

            nums[indexByValue] *= -1;
        }

        return result;
    }
};


// NOTE: Second solution with Floyds Tortoise & Hare algorithm
//       It's cool, but it slower than upper solution
/*
class Solution
{

public:

    int findDuplicate(std::vector<int>& nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // Find a loop
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }

        // Find start of loop
        int slow2 = nums[0];
        while (slow2 != slow)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
*/
TEST (SolutionTest, CornerCase1)
{
    std::vector<int> nums{ 1, 3, 4, 2, 2 };
    const auto result = Solution{}.findDuplicate(nums);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::vector<int> nums{ 1, 2, 3, 2, 2 };
    const auto result = Solution{}.findDuplicate(nums);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums{ 1, 2, 3, 4, 4 };
    const auto result = Solution{}.findDuplicate(nums);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums{ 3, 1, 3, 4, 2 };
    const auto result = Solution{}.findDuplicate(nums);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> nums{ 3, 3, 3, 3, 3 };
    const auto result = Solution{}.findDuplicate(nums);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
