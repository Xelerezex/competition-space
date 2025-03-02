#include <gtest/gtest.h>

#include <vector>
#include <utility>
#include <unordered_map>

class Solution
{

public:

    int subarraySum(std::vector<int>& nums, int k)
    {
        int currentSum = 0;
        int result = 0;
        std::unordered_map<int, int> hash;
        hash.emplace(0, 1);

        for (const auto& num : nums)
        {
            currentSum += num;
            const int difference = currentSum - k;
            
            const auto& iter = std::as_const(hash).find(
                difference
            );
            if (std::cend(hash) != iter)
            {
                result += iter->second;
                
            }
            ++hash[currentSum];
        }

        return result;
    }
};

TEST (SolutionTest, Example1)
{
    std::vector<int> data = {1, 1, 1};
    int sums = 2;
    const auto result = Solution{}.subarraySum(data, sums);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> data = {1, 2, 2, 3, 4};
    int sums = 4;
    const auto result = Solution{}.subarraySum(data, sums);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> data = { 1, 2, 3 };
    int sums = 3;
    const auto result = Solution{}.subarraySum(data, sums);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> data = { 1, -1, -1, 2, -1 };
    int sums = 1;
    const auto result = Solution{}.subarraySum(data, sums);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::vector<int> data = {0, -5, 6, 9, -8, 6};
    int sums = 6;
    const auto result = Solution{}.subarraySum(data, sums);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
