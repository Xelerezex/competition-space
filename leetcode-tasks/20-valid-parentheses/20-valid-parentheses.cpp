#include <gtest/gtest.h>
#include <stack>

class Solution
{
public:
   
    bool isLeftBracket(char bracket)
    {
        return '[' == bracket
            || '(' == bracket
            || '{' == bracket;
    }

    bool isRightBracket(char bracket)
    {
        return ']' == bracket
            || ')' == bracket
            || '}' == bracket;
    }

    char corespondingLeftBracket(char bracket)
    {
        char result = 0;
        switch (bracket) 
        {
            case ']':
            {
                result = '[';
            } break;
            case ')':
            {
                result = '(';
            } break;
            case '}':
            {
                result = '{';
            } break;
            default:
            {
            } break;
        }
        return result;
    }

    bool isValid(std::string s)
    {
        std::stack<int> leftBrackets; 

        for (const auto bracket : s)
        {
            if (isLeftBracket(bracket))
            {
                leftBrackets.push(bracket);
            }
            else if (isRightBracket(bracket))
            {
                const char currentLeft = corespondingLeftBracket(bracket);
                if (leftBrackets.empty())
                {
                    return false;
                }
                if (currentLeft != leftBrackets.top())
                {
                    return false;
                }
                leftBrackets.pop();
            }
        }
        return leftBrackets.empty();
    }
};

TEST (SolutionTest, CornerCase0)
{
    std::string s = "]";
    const auto result = Solution{}.isValid(s);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase1)
{
    std::string s = "(";
    const auto result = Solution{}.isValid(s);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    std::string s = "((";
    const auto result = Solution{}.isValid(s);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase3)
{
    std::string s = "(()";
    const auto result = Solution{}.isValid(s);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::string s = "()";
    const auto result = Solution{}.isValid(s);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::string s = "()[]{}";
    const auto result = Solution{}.isValid(s);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::string s = "(]";
    const auto result = Solution{}.isValid(s);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::string s = "([])";
    const auto result = Solution{}.isValid(s);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::string s = "[][]{}";
    const auto result = Solution{}.isValid(s);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example6)
{
    std::string s = "([{}])";
    const auto result = Solution{}.isValid(s);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example7)
{
    std::string s = "[(])";
    const auto result = Solution{}.isValid(s);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example8)
{
    std::string s = "([]{})[]";
    const auto result = Solution{}.isValid(s);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
