#include <gtest/gtest.h>

#include <stack>

class Solution
{

public:

    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int, std::vector<int>> indecesStack;
    
        for (int index = 0; index < temperatures.size(); ++index)
        {
            const int currentValue = temperatures[index];
            if (indecesStack.empty())
            {
                indecesStack.push(index);
                continue;
            }

            const int topIndex = indecesStack.top();
            const int topValue = temperatures[topIndex];

            if (topValue >= currentValue)
            {
                indecesStack.push(index);
                continue;
            }
            // else
            while (!indecesStack.empty() 
                && temperatures[indecesStack.top()] < currentValue
            )
            {
                const int currentTopIndex = indecesStack.top();
                indecesStack.pop();
                result[currentTopIndex] = index - currentTopIndex;
            }
            indecesStack.push(index);
        }
        
        return result;
    }

};

TEST (SolutionTest, Example1)
{
    std::vector<int> temperatures = {
        30, 38, 30, 36, 35, 40, 28
    };
    const auto result = Solution{}.dailyTemperatures(
        temperatures
    );
    const auto& expected = std::vector<int>{
        1, 4, 1, 2, 1, 0, 0
    };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> temperatures = {
        22, 21, 20
    };
    const auto result = Solution{}.dailyTemperatures(
        temperatures
    );
    const auto& expected = std::vector<int>{
        0, 0, 0
    };
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
