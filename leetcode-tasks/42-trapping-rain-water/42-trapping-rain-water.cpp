#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <iostream>

class Solution
{

public:

    int trap(std::vector<int>& height)
    {
        int area = 0;
        
        std::vector<int> prefix(height.size(), 0);
        std::vector<int> suffix(height.size(), 0);

        int currentValue = 0;
        for (int index = 0; index < prefix.size(); ++index)
        {
            currentValue = std::max(currentValue, height[index]);
            prefix[index] = currentValue;
        }
        currentValue = 0;
        for (int index = suffix.size() - 1; index > -1; --index)
        {
            currentValue = std::max(currentValue, height[index]);
            suffix[index] = currentValue;
        }

        for (int index = 0; index < height.size(); ++index)
        {
            area += std::min(prefix[index], suffix[index]) - height[index];
        }

        return area;
    }

};

TEST (SolutionTest, Example1)
{
    auto height = std::vector<int>{ 1, 5, 2, 3, 4 };
    const auto& expected = 3;
    const auto& result = Solution{}.trap(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto height = std::vector<int>{ 
        0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 
    };
    const auto& expected = 6;
    const auto& result = Solution{}.trap(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto height = std::vector<int>{ 
        4, 2, 0, 3, 2, 5
    };
    const auto& expected = 9;
    const auto& result = Solution{}.trap(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto height = std::vector<int>{ 
        0, 2, 0, 3, 1, 0, 1, 3, 2, 1
    };
    const auto& expected = 9;
    const auto& result = Solution{}.trap(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto height = std::vector<int>{ 
        0, 1, 3, 2, 1
    };
    const auto& expected = 0;
    const auto& result = Solution{}.trap(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase1)
{
    auto height = std::vector<int>{ 
        0
    };
    const auto& expected = 0;
    const auto& result = Solution{}.trap(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    auto height = std::vector<int>{ 
        10
    };
    const auto& expected = 0;
    const auto& result = Solution{}.trap(height);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
