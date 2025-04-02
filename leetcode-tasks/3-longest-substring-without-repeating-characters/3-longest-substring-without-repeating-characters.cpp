#include <gtest/gtest.h>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::size_t longestLength = 0;

        std::unordered_map<char, int> window;

        std::size_t left = 0;
        for (std::size_t right = 0; right < s.size(); ++right)
        {
            auto newCharacter = s[right];

            while (std::cend(window) != window.find(newCharacter) 
                && left <= right
            )
            {
                auto oldCharacter = s[left];
                --window[oldCharacter];
                if (0 == window[oldCharacter])
                {
                    window.erase(oldCharacter);
                }
                ++left;
            }

            ++window[newCharacter];
            longestLength = std::max(window.size(), longestLength);
        }

        return static_cast<int>(longestLength);
    }
};

TEST (SolutionTest, Example1)
{
    std::string input = "abcabcbb";
    const auto result = Solution{}.lengthOfLongestSubstring(input);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::string input = "bbbbb";
    const auto result = Solution{}.lengthOfLongestSubstring(input);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::string input = "pwwkew";
    const auto result = Solution{}.lengthOfLongestSubstring(input);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::string input = "zxyzxyz";
    const auto result = Solution{}.lengthOfLongestSubstring(input);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::string input = "xxxx";
    const auto result = Solution{}.lengthOfLongestSubstring(input);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
