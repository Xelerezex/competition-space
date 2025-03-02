#include <gtest/gtest.h>

#include <vector>

class Solution
{
    
public:

    int removeDuplicates(std::vector<int>& nums)
    {
        int left = 1;

        for (int right = 1; right < nums.size(); ++right)
        {
            if (nums[left - 1] !=  nums[right])
            {
                std::swap(nums[left], nums[right]);
                ++left;
            }
        }
        return left;
    }
};

TEST (SolutionTest, Example1)
{
    auto nums = std::vector<int>{ 1, 1, 2 };
    const auto expected = 2;
    EXPECT_EQ(expected, Solution{}.removeDuplicates(nums)); 
    auto expected2 = std::vector<int>{  1, 2, 1};
    EXPECT_EQ(nums, expected2);
}

TEST (SolutionTest, Example2)
{
    auto nums = std::vector<int>{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    const auto expected = 5;
    EXPECT_EQ(expected, Solution{}.removeDuplicates(nums)); 
    auto expected2 = std::vector<int>{  0, 1, 2, 3, 4, 0, 2, 1, 3, 1  };
    EXPECT_EQ(nums, expected2);
}

TEST (SolutionTest, CornerCase1)
{
    auto nums = std::vector<int>{ 5 };
    const auto expected = 1;
    EXPECT_EQ(expected, Solution{}.removeDuplicates(nums)); 
    auto expected2 = std::vector<int>{ 5 };
    EXPECT_EQ(nums, expected2);
}

TEST (SolutionTest, CornerCase2)
{
    auto nums = std::vector<int>{ -300, -200, -200, -100, -100, -100, -100 };
    const auto expected = 3;
    EXPECT_EQ(expected, Solution{}.removeDuplicates(nums)); 
    auto expected2 = std::vector<int>{ -300, -200, -100, -200, -100, -100, -100 };
    EXPECT_EQ(nums, expected2);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}