#include <gtest/gtest.h>

class Solution
{
public:

    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::vector<std::string>> result(n + 1);
        result[0] = {""};

        for (int numberIndex = 0; numberIndex <= n; ++numberIndex)
        {
            for (int index = 0; index < numberIndex; ++index)
            {
                for (const std::string& left : result[index])
                {
                    for (const std::string& right : result[numberIndex - index - 1])
                    {
                        result[numberIndex].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return result[n];
    }
};

TEST (SolutionTest, Example1)
{
    const int n = 3;
    const auto result = Solution{}.generateParenthesis(n);
    const auto& expected = std::vector<std::string>{
        "()()()", "()(())", "(())()", "(()())", "((()))"
    };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    const int n = 1;
    const auto result = Solution{}.generateParenthesis(n);
    const auto& expected = std::vector<std::string>{
        "()"
    };
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
