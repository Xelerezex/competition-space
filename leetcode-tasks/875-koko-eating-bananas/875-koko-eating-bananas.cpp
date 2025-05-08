#include <algorithm>
#include <gtest/gtest.h>

class Solution
{
public:

    bool checkData(const std::vector<int>& piles, std::size_t currentRatio, int h)
    {
        std::size_t summ = 0;
        for (const auto& pile : piles)
        {
            const double ratio = static_cast<double>(pile) / static_cast<double>(currentRatio);
            const auto ratioPerPile = static_cast<std::size_t>(std::ceil(ratio));
            summ += ratioPerPile;
        }
        return summ <= h;
    };

    int minEatingSpeed(std::vector<int>& piles, int h)
    {
        const int maxPile = *std::max_element(std::cbegin(piles), std::cend(piles));

        std::size_t left = 1;
        std::size_t right = maxPile;

        std::size_t result = maxPile;

        while (left <= right 
            && (left <= maxPile && right <= maxPile)
        )
        {
            std::size_t middle = left + ((right - left) / 2);

            if (checkData(piles, middle, h))
            {
                right = middle - 1;

                result = std::min(result, middle);
            }
            else
            {
                left = middle + 1;
            }
        }

        return static_cast<int>(result);
    }
};
  
TEST (SolutionTest, CornerCase1)
{
    std::vector<int> piles = { 805306368, 805306368, 805306368 };
    const int h = 1000000000;
    const auto result = Solution{}.minEatingSpeed(piles, h);
    const auto& expected = 3;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example1)
{
    std::vector<int> piles = { 3,6,7,11 };
    const int h = 8;
    const auto result = Solution{}.minEatingSpeed(piles, h);
    const auto& expected = 4;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> piles = { 30,11,23,4,20 };
    const int h = 5;
    const auto result = Solution{}.minEatingSpeed(piles, h);
    const auto& expected = 30;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> piles = { 1,4,3,2 };
    const int h = 9;
    const auto result = Solution{}.minEatingSpeed(piles, h);
    const auto& expected = 2;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> piles = { 30,11,23,4,20 };
    const int h = 6;
    const auto result = Solution{}.minEatingSpeed(piles, h);
    const auto& expected = 23;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example5)
{
    std::vector<int> piles = { 25,10,23,4 };
    const int h = 4;
    const auto result = Solution{}.minEatingSpeed(piles, h);
    const auto& expected = 25;
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
