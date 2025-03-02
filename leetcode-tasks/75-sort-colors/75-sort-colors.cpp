#include <gtest/gtest.h>

#include <array>
#include <vector>

class Solution
{
public:

    void sortColors(std::vector<int>& nums)
    {
        // Fixed buckets
        std::array<int, 3> buckets{ 0, 0, 0 };

        for (const auto& value : nums)
        {
            ++buckets[value];
        }

        int currentBucket = 0;
        for (int index = 0; index < nums.size();)
        {
            for (int value = 0; value < buckets[currentBucket]; ++value)
            {
                nums[index] = currentBucket;
                ++index;
            }
            ++currentBucket;
        }
    }
};

TEST (SolutionTest, Example1)
{
    auto nums = std::vector<int>{ 
        2, 0, 2, 1, 1, 0
    };
    Solution{}.sortColors(nums);
    const auto& expected = std::vector{
        0, 0, 1, 1, 2, 2
    };
    EXPECT_EQ(expected, nums);
}

TEST (SolutionTest, Example2)
{
    auto nums = std::vector<int>{ 
        2, 0, 1
    };
    Solution{}.sortColors(nums);
    const auto& expected = std::vector{
        0, 1,  2
    };
    EXPECT_EQ(expected, nums);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
