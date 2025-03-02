#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution
{

public:
 
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::sort(std::begin(nums), std::end(nums));

        for (int index = 0; index < nums.size(); ++index)
        {
            if (index > 0 && nums[index] == nums[index - 1])
            {
                continue;
            }

            int left = index + 1;
            int right = nums.size() - 1;

            while (left < right)
            {   
                int currentSum = nums[left] + nums[right];

                if (nums[index] < -currentSum)
                {
                    ++left;
                }
                else if (nums[index] > -currentSum)
                {
                    --right;
                }
                else if (nums[index] == -currentSum)
                {
                    result.push_back({nums[index], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        ++left;
                    }
                }
            }
        }
        return result;
    }
};

TEST (SolutionTest, Example1)
{
    std::vector<int> nums = { -2, 0, 0, 2, 2  };
    const auto& expected = std::vector<std::vector<int>>{
        { -2, 0, 2 },
    };
    const auto& result = Solution{}.threeSum(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums = { -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4  };
    const auto& expected = std::vector<std::vector<int>>{
        { -4,  0, 4 }, // +
        { -4,  1, 3 }, //
        { -3, -1, 4 },
        { -3,  0, 3 },
        { -3,  1, 2 },
        { -2, -1, 3 },
        { -2,  0, 2 },
        { -1, -1, 2 },
        { -1,  0, 1 },
    };
    const auto& result = Solution{}.threeSum(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums = { -1,0,1,2,-1,-4   };
    const auto& expected = std::vector<std::vector<int>>{
        std::vector{ -1,-1,2 }, 
        std::vector{ -1,0,1 }
    };
    const auto& result = Solution{}.threeSum(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase1)
{
    std::vector<int> nums = { 0, 1, 1 };
    const auto& expected = std::vector<std::vector<int>>{};
    const auto& result = Solution{}.threeSum(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    std::vector<int> nums = { 0, 0, 0 };
    const auto& expected = std::vector<std::vector<int>>{ std::vector<int>{0, 0, 0} };
    const auto& result = Solution{}.threeSum(nums);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase3)
{
    std::vector<int> nums = { 0, 0, 0, 0 };
    const auto& expected = std::vector<std::vector<int>>{ std::vector<int>{0, 0, 0} };
    const auto& result = Solution{}.threeSum(nums);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
