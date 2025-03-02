#include <gtest/gtest.h>

#include <vector>
#include <algorithm>

class Solution
{
    
public:

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> result;
        std::sort(std::begin(nums), std::end(nums));

        for (long long int first = 0; first < nums.size();)
        {
            for (long long int second = first + 1; second < nums.size();)
            {
                long long int third = second + 1;
                long long int fourth = static_cast<long long int>(nums.size()) - 1;
                while (third < fourth)
                {
                    long long int currentSum 
                        = static_cast<long long int>(nums[first]) 
                        + static_cast<long long int>(nums[second]) 
                        + static_cast<long long int>(nums[third])
                        + static_cast<long long int>(nums[fourth]);
                    if (target == currentSum)
                    {
                        result.push_back({ nums[first], nums[second], nums[third], nums[fourth]});
                        ++third;
                        --fourth;
                        
                        // Skip duplicates
                        while (third < fourth && nums[third] == nums[third - 1])
                        {
                            ++third;
                        }
                    }
                    else if (target > currentSum)
                    {
                        ++third;
                    }
                    else if (target < currentSum)
                    {
                        --fourth;
                    }
                }

                // Skip duplicates
                ++second;
                while (second < fourth && nums[second] == nums[second - 1])
                {
                    ++second;
                }
            }

            // Skip duplicates
            ++first;
            while (first < nums.size() && nums[first] == nums[first - 1])
            {
                ++first;
            }
        }

        return result;
    }
};

TEST (SolutionTest, Example1)
{
    auto nums = std::vector<int>{ 1, 0, -1, 0, -2, 2 };
    const int target = 0;
    const auto& expected = std::vector<std::vector<int>>{
        { -2, -1,1, 2 },
        { -2,  0,0, 2 },
        { -1,  0,0, 1 },
    };
    const auto& result = Solution{}.fourSum(nums, target);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto nums = std::vector<int>{ 2, 2, 2, 2, 2 };
    const int target = 8;
    const auto& expected = std::vector<std::vector<int>>{
        { 2, 2, 2, 2 },
    };
    const auto& result = Solution{}.fourSum(nums, target);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto nums = std::vector<int>{ 1'000'000'000,1'000'000'000,1'000'000'000,1'000'000'000 };
    const int target = 0;
    const auto& expected = std::vector<std::vector<int>>{
        std::vector<std::vector<int>>{},
    };
    const auto& result = Solution{}.fourSum(nums, target);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
