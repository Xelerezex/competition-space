#include <gtest/gtest.h>
#include <stack>

class Solution
{
public:

    int largestRectangleArea(std::vector<int>& heights)
    {
        int largestArea = 0;

        // stack <value, current_min>
        struct MinNode
        {
            int index;
            int value;
        };
        std::stack<MinNode, std::vector<MinNode>> heightsStack;

        // Creating stack with non-decreasing order with border count 
        for (int index = 0; index < heights.size(); ++index)
        {
            const auto currentHeight = heights[index];

            if (heightsStack.empty() 
                || currentHeight >= heightsStack.top().value
            )
            {
                heightsStack.push(MinNode{index, currentHeight});
                largestArea = std::max(largestArea, currentHeight);
            }
            else if (currentHeight < heightsStack.top().value)
            {
                int indexOnStack = 0;

                while (!heightsStack.empty() 
                    && currentHeight < heightsStack.top().value
                )
                {
                    const auto valueOnStack = heightsStack.top().value;
                    indexOnStack = heightsStack.top().index;
                    const auto areaFromStack = valueOnStack * (index - indexOnStack); 
                    largestArea = std::max(largestArea, areaFromStack);
                    
                    heightsStack.pop();
                }                
                
                heightsStack.push(MinNode{indexOnStack, currentHeight});
            }
        }

        // Count data from stack
        int maxIndex = static_cast<int>(heights.size());
        while (!heightsStack.empty())
        {
            const auto valueOnStack = heightsStack.top().value;
            const int indexOnStack = heightsStack.top().index;
            const auto areaFromStack = valueOnStack * (maxIndex - indexOnStack); 
            largestArea = std::max(largestArea, areaFromStack);
            
            heightsStack.pop();
        }

        return largestArea;
    }
};

TEST (SolutionTest, CornerCase1)
{
    std::vector<int> heights = { 1, 2, 3, 4, 5 };
    const auto result = Solution{}.largestRectangleArea(heights);
    const auto& expected = 9;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    std::vector<int> heights = { 1, 2, 2};
    const auto result = Solution{}.largestRectangleArea(heights);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::vector<int> heights = { 2,1,5,6,2,3 };
    const auto result = Solution{}.largestRectangleArea(heights);
    const auto& expected = 10;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> heights = { 2, 4  };
    const auto result = Solution{}.largestRectangleArea(heights);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> heights = { 7,1,7,2,2,4  };
    const auto result = Solution{}.largestRectangleArea(heights);
    const auto& expected = 8;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> heights = { 1,3,7 };
    const auto result = Solution{}.largestRectangleArea(heights);
    const auto& expected = 7;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::vector<int> heights = { 2,1, 2, 1, 2, 1,  2 };
    const auto result = Solution{}.largestRectangleArea(heights);
    const auto& expected = 7;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
