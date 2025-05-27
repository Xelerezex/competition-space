#include <gtest/gtest.h>

#include <stack>

class Solution
{
public:
    
    bool isMultiplication(const std::string& sign)
    {
        return "*" == sign;
    }

    bool isDivision(const std::string& sign)
    {
        return "/" == sign;
    }

    bool isAddition(const std::string& sign)
    {
        return "+" == sign;
    }

    bool isSubtraction(const std::string& sign)
    {
        return "-" == sign;
    }

    bool isSign(const std::string& sign)
    {
        bool isSign = false;

        return isMultiplication(sign)
            || isDivision(sign)
            || isAddition(sign)
            || isSubtraction(sign);
    }

    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int, std::vector<int>> numberStack;

        for (const auto& value : tokens)
        {
            if (isSign(value))
            {
                const auto rightHand = numberStack.top();
                numberStack.pop();
                const auto leftHand = numberStack.top();
                numberStack.pop();

                int currentResult = 0;
                if (isMultiplication(value))
                {
                    currentResult = leftHand * rightHand;
                }
                else if (isDivision(value))
                {
                    currentResult = leftHand / rightHand;
                }
                else if (isAddition(value))
                {
                    currentResult = leftHand + rightHand;
                }
                else if (isSubtraction(value))
                {
                    currentResult = leftHand - rightHand;
                }
                numberStack.push(currentResult);
            }   
            else 
            {
                numberStack.push(std::stoi(value));
            }
        }

        return numberStack.top();
    }
};

TEST (SolutionTest, Example1)
{
    std::vector<std::string> tokens = {"2","1","+","3","*"}; // ((2 + 1) * 3) = 9
    const auto result = Solution{}.evalRPN(tokens);
    const auto& expected = 9;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<std::string> tokens = {"4","13","5","/","+"}; // (4 + (13 / 5)) = 6
    const auto result = Solution{}.evalRPN(tokens);
    const auto& expected = 6;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}; 
        // (10 * (6 / ((9 + 3) * -11))) + 17) + 5
    const auto result = Solution{}.evalRPN(tokens);
    const auto& expected = 22;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<std::string> tokens = {"1","2","+","3","*","4","-"}; 
        // ((1 + 2) * 3) - 4 = 5
    const auto result = Solution{}.evalRPN(tokens);
    const auto& expected = 5;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
