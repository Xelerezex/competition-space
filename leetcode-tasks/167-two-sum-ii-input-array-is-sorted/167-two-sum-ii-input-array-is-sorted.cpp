#include <gtest/gtest.h>

#include <vector>

class Solution
{

public:

    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        std::vector<int> result { 0, 0 };

        int left = 0; 
        int right = numbers.size() - 1;
        
        while (left < right)
        {
            const auto currentSum = numbers[left] + numbers[right];

            if (currentSum > target)
            {
                --right;
            }
            else if (currentSum < target)
            {
                ++left;
            }
            else if (currentSum == target)
            {
                result[0] = left + 1;
                result[1] = right + 1;
                break;
            }
        }


        return result;
    }

};

TEST (SolutionTest, Example1)
{
    auto numbers = std::vector<int>{ 
        2,7,11,15 
    };
    const auto target = 9;
    const auto& expected = std::vector<int>{
        1, 2
    };
    const auto& result = Solution{}.twoSum(numbers, target);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto numbers = std::vector<int>{ 
        2, 3, 4 
    };
    const auto target = 6;
    const auto& expected = std::vector<int>{
        1, 3
    };
    const auto& result = Solution{}.twoSum(numbers, target);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto numbers = std::vector<int>{ 
        -1, 0
    };
    const auto target = -1;
    const auto& expected = std::vector<int>{
        1, 2 
    };
    const auto& result = Solution{}.twoSum(numbers, target);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto numbers = std::vector<int>{ 
        1,2,3,4 
    };
    const auto target = 3;
    const auto& expected = std::vector<int>{
        1, 2 
    };
    const auto& result = Solution{}.twoSum(numbers, target);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
