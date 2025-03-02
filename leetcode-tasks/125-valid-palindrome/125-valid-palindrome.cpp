#include <gtest/gtest.h>

#include <cctype>
#include <string>

class Solution
{

public:

    bool isPalindrome(std::string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (left < right && !std::isalnum(s[left]))
            {
                ++left;
            }
            while (left < right && !std::isalnum(s[right]))
            {
                --right;
            }
            
            const auto leftChar = static_cast<char>(std::tolower(s[left]));
            const auto rightChar = static_cast<char>(std::tolower(s[right]));
            if (leftChar != rightChar)
            {
                return false;
            }
            ++left;
            --right;
        }

        return true;    
    }
};

TEST (SolutionTest, Example1)
{
    auto data = "A man, a plan, a canal: Panama";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto data = "race a car";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto data =  " ";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto data = "tab a cat";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto data = "Was it a car or a cat I saw?";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example6)
{
    auto data = "0P";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example7)
{
    auto data = "121";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example8)
{
    auto data = "121";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example9)
{
    auto data = "1221";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example10)
{
    auto data = "1231";
    const auto result = Solution{}.isPalindrome(data);
    const auto expected = false;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
