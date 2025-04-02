#include <gtest/gtest.h>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int maxProfit = 0;

        int left = 0;
        for (int right = 0; right < prices.size(); ++right)
        {
            auto currentProfit = prices[right] - prices[left];

            while (currentProfit < 0 && left < right)
            {
                ++left;
                currentProfit = prices[right] - prices[left];
            }

            maxProfit = std::max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};

TEST (SolutionTest, Example3)
{
    auto prices = std::vector<int>{ 7, 1, 5, 3, 6, 4 };
    const auto result = Solution{}.maxProfit(prices);
    const auto& expected = 5;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    auto prices = std::vector<int>{ 10,1,5,6,7,1 };
    const auto result = Solution{}.maxProfit(prices);
    const auto& expected = 6;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto prices = std::vector<int>{ 10,8,7,5,2 };
    const auto result = Solution{}.maxProfit(prices);
    const auto& expected = 0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto prices = std::vector<int>{ 7,6,4,3,1 };
    const auto result = Solution{}.maxProfit(prices);
    const auto& expected = 0;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
