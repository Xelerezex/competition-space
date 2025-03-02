#include <gtest/gtest.h>

#include <vector>

class Solution
{

public:

    int removeDuplicates(std::vector<int>& nums)
    {
        int left = 2;

        for (int right = 2; right < nums.size(); ++right)
        {
            if (nums[left - 1] != nums[right] || nums[left - 2] != nums[right])
            {
                std::swap(nums[left], nums[right]);
                ++left;
            }
            
        }

        return nums.size() > 1 ? left : 1;
    }
};

TEST (SolutionTest, Example1)
{
    auto nums = std::vector<int>{ 1, 5, 2, 3, 4 };
    const auto& expected1 = 5;
    const auto& result = Solution{}.removeDuplicates(nums);
    EXPECT_EQ(expected1, result);
    const auto& expected2 = std::vector<int>{ 
        1, 5, 2, 3, 4
    };
    EXPECT_EQ(expected2, nums);
}

TEST (SolutionTest, Example2)
{
    auto nums = std::vector<int>{ 
        0, 0, 1, 1, 1, 1, 2, 3, 3
    };
    const auto& expected1 = 7;
    const auto& result = Solution{}.removeDuplicates(nums);
    EXPECT_EQ(expected1, result);
    const auto& expected2 = std::vector<int>{ 
        0, 0, 1, 1, 2, 3, 3, 1, 1 
    };
    EXPECT_EQ(expected2, nums);
}

TEST (SolutionTest, Example3)
{
    auto nums = std::vector<int>{ 
        1, 1 
    };
    const auto& expected1 = 2;
    const auto& result = Solution{}.removeDuplicates(nums);
    EXPECT_EQ(expected1, result);
    const auto& expected2 = std::vector<int>{ 
        1, 1 
    };
    EXPECT_EQ(expected2, nums);
}

TEST (SolutionTest, Example4)
{
    auto nums = std::vector<int>{ 
        1, 1, 2 
    };
    const auto& expected1 = 3;
    const auto& result = Solution{}.removeDuplicates(nums);
    EXPECT_EQ(expected1, result);
    const auto& expected2 = std::vector<int>{ 
        1, 1, 2
    };
    EXPECT_EQ(expected2, nums);
}

TEST (SolutionTest, Example5)
{
    auto nums = std::vector<int>{ 
        1
    };
    const auto& expected1 = 1;
    const auto& result = Solution{}.removeDuplicates(nums);
    EXPECT_EQ(expected1, result);
    const auto& expected2 = std::vector<int>{ 
        1
    };
    EXPECT_EQ(expected2, nums);
}

TEST (SolutionTest, Example6)
{
    auto nums = std::vector<int>{ 
        -300, -200, -200, -200, -100, -100, -100, -100
    };
    const auto& expected1 = 5;
    const auto& result = Solution{}.removeDuplicates(nums);
    EXPECT_EQ(expected1, result);
    const auto& expected2 = std::vector<int>{ 
        -300, -200, -200,  -100, -100, -200,-100, -100
    };
    EXPECT_EQ(expected2, nums);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
