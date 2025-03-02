#include <gtest/gtest.h>

#include <vector>

class Solution
{

public:

    int maxArea(std::vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;

        int area = (right - left) * std::min(height[left], height[right]);

        while (left < right)
        {
            if (height[left] < height[right])
            {
                ++left;
            }
            else if (height[left] > height[right])
            {
                --right;
            }
            else if (height[left] == height[right])
            {
                ++left;
                --right;
            }
            const int currentArea = (right - left) * std::min(height[left], height[right]);
            if (currentArea > area)
            {
                area = currentArea;
            }
        }  
        
        return area;
    }

};

TEST (SolutionTest, Example1)
{
    std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    const auto& expected = 49;
    const auto& result = Solution{}.maxArea(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> height = { 1, 1 };
    const auto& expected = 1;
    const auto& result = Solution{}.maxArea(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> height = { 1, 7, 2, 5, 4, 7, 3, 6 };
    const auto& expected = 36;
    const auto& result = Solution{}.maxArea(height);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase1)
{
    std::vector<int> height = { 1,7,2,5,12,3,500,500,7,8,4,7,3,6 };
    const auto& expected = 500;
    const auto& result = Solution{}.maxArea(height);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
