#include <gtest/gtest.h>

#include <vector>
#include <unordered_map>

class Solution
{

public:
 
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> hash;
        for (int index = 0; index < nums.size(); ++index)
        {
            int difference = target - nums[index];
            if (std::cend(hash) != hash.find(difference))
            {
                return { hash.at(difference), index };
            }
            hash.emplace(nums[index], index);
        }

        return {};
    }
};

TEST (SolutionTest, Example1)
{
    std::vector<int> nums = { 2,7,11,15 };
    const int target = 9;
    const auto& expected = std::vector<int>{ 0, 1 };
    const auto& result = Solution{}.twoSum(nums, target);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums = { 3, 2, 4 };
    const int target = 6;
    const auto expected = std::vector<int>{ 1, 2 };
    const auto& result = Solution{}.twoSum(nums, target);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums = { 3, 3 };
    const int target = 6;
    const auto& expected = std::vector<int>{ 0, 1 };
    const auto& result = Solution{}.twoSum(nums, target);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
