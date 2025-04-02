#include <gtest/gtest.h>

class Solution
{
public:

    int characterReplacement(std::string s, int k)
    {
        std::size_t longestLength = 0;

        std::unordered_map<char, std::size_t> window;

        std::size_t mostFrequentCharCount = 0;

        std::size_t left = 0;
        for (std::size_t right = 0; right < s.size(); ++right)
        {
            const auto newCharacter = s[right];
            ++window[newCharacter];

            mostFrequentCharCount = std::max(mostFrequentCharCount, window[newCharacter]);
            auto possibleExchanges = ((right - left) + 1) - mostFrequentCharCount;

            while (possibleExchanges > k && left < right)
            {
                const auto oldCharacter = s[left];
                --window[oldCharacter];
                if (window[oldCharacter] == 0)
                {
                    window.erase(oldCharacter);
                }
                ++left;
                --possibleExchanges;
            }

            longestLength = std::max(longestLength, (right - left) + 1);
        }

        return static_cast<int>(longestLength);
    }
};

TEST (SolutionTest, CornerCase1)
{
    const std::string input = "EOEMQLLQTRQDDCOERARHGAAARRBKCCMFTDAQOLOKARBIJBISTGNKBQGKKTALSQNFSABASNOPBMMGDIOETPTDICRBOMBAAHINTFLH";
    const int count = 7;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 11;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    const std::string input = "BAAA";
    const int count = 0;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase3)
{
    const std::string input = "A";
    const int count = 0;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    const std::string input = "XYYX";
    const int count = 0;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    const std::string input = "XYYX";
    const int count = 2;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    const std::string input = "AAABABB";
    const int count = 1;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 5;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    const std::string input = "AABABBA";
    const int count = 1;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    const std::string input = "ABAB";
    const int count = 4;
    const auto result = Solution{}.characterReplacement(input, count);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
