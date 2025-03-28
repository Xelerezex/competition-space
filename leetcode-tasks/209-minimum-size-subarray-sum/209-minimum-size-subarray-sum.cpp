#include <gtest/gtest.h>

#include <limits>
#include <vector>

class Solution
{
public:

    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        int minLength = std::numeric_limits<int>::max();

        int currentSum = 0;

        int left = 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            currentSum += nums[right];
            if (target <= currentSum)
            {
                minLength = std::min(minLength, right - left + 1);
            }
            
            while (currentSum > target && left <= right)
            {
                currentSum -= nums[left];
                ++left;
            
                if (target <= currentSum)
                {
                    minLength = std::min(minLength, right - left + 1);
                }
            }
        }

        return std::numeric_limits<int>::max() == minLength ? 0 : minLength;
    }
};

TEST (SolutionTest, CornerCase1)
{
    const int target = 6;
    std::vector<int> nums = { 10,2,3 };
    const int expected = 1;
    EXPECT_EQ(expected, Solution{}.minSubArrayLen(target, nums));
}

TEST (SolutionTest, CornerCase2)
{
    const int target = 15;
    std::vector<int> nums = { 1,2,3,4,5 };
    const int expected = 5;
    EXPECT_EQ(expected, Solution{}.minSubArrayLen(target, nums));
}

TEST (SolutionTest, CornerCase3)
{
    const int target = 11;
    std::vector<int> nums = { 1,2,3,4,5 };
    const int expected = 3;
    EXPECT_EQ(expected, Solution{}.minSubArrayLen(target, nums));
}

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
    const int expected = 1;
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

