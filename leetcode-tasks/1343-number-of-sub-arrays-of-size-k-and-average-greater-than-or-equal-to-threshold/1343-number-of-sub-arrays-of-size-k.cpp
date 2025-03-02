#include <gtest/gtest.h>

#include <cmath>
#include <vector>

class Solution
{
public:

    int numOfSubarrays(
        std::vector<int>& arr, 
        int k, 
        int threshold
    )
    {
        int left = 0;
        int currentSum = 0;
        int counter = 0;
        for (int right = 0; right < static_cast<int>(arr.size());)
        {
            int distance = std::abs(right - left) + 1;
            currentSum += arr[right];

            if (distance < k)
            {
                ++right;
            }
            else if (distance == k)
            {
                counter = (currentSum / k >= threshold)
                    ? counter + 1
                    : counter;

                currentSum -= arr[left];
                ++left;
                ++right;
            }
        }
        return counter;
    }
};

TEST (SolutionTest, Example1)
{
    std::vector<int> data{ 2,2,2,2,5,5,5,8 };
    const auto window = 3;
    const auto threshold = 4;
    const auto result = Solution{}.numOfSubarrays(data, window, threshold);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> data{ 11,13,17,23,29,31,7,5,2,3 };
    const auto window = 3;
    const auto threshold = 5;
    const auto result = Solution{}.numOfSubarrays(data, window, threshold);
    const auto& expected = 6;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
