#include <gtest/gtest.h>
#include <unordered_map>

class Solution
{
public:

    bool checkInclusion(std::string s1, std::string s2)
    {
        std::unordered_map<char, int> targetWindow;
        for (auto index = 0; index < s1.size(); ++index)
        {
            ++targetWindow[s1[index]];
        }

        int currentWindowSize = 0;
        std::unordered_map<char, int> window;
        
        int left = 0;
        for (int right = 0; right < s2.size(); ++right)
        {
            const auto newCharacter = s2[right];
            ++window[newCharacter];
            ++currentWindowSize;

            while (currentWindowSize > s1.size())
            {
                const auto oldCharacter = s2[left];
                --window[oldCharacter];
                if (0 == window[oldCharacter])
                {
                    window.erase(oldCharacter);
                }
                ++left;
                --currentWindowSize;
            }

            if (window == targetWindow)
            {
                return true;
            }
        }
        
        return false;
    }

};
    
TEST (SolutionTest, Example1)
{
    const auto s1 = "ab";
    const auto s2 = "eidbaooo";
    const auto result = Solution{}.checkInclusion(s1, s2);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}
    
TEST (SolutionTest, Example2)
{
    const auto s1 = "ab";
    const auto s2 = "eidboaoo";
    const auto result = Solution{}.checkInclusion(s1, s2);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}
    
TEST (SolutionTest, Example3)
{
    const auto s1 = "abc";
    const auto s2 = "lecabee";
    const auto result = Solution{}.checkInclusion(s1, s2);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}
    
TEST (SolutionTest, Example4)
{
    const auto s1 = "abc";
    const auto s2 = "lecaabee";
    const auto result = Solution{}.checkInclusion(s1, s2);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
