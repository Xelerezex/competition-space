#include <gtest/gtest.h>

class Solution
{
public:
    
    bool isTargetInArray(
        const std::vector<int>& data,
        int target
    )
    {
        std::size_t leftIndex = 0;
        std::size_t rightIndex = data.size() - 1;

        while (leftIndex <= rightIndex
            && (leftIndex < data.size() && rightIndex < data.size())
        )
        {
            std::size_t middle = leftIndex + ((rightIndex - leftIndex) / 2);

            if (target == data[middle])
            {
                return true;
            }
            else if (target < data[middle])
            {
                rightIndex = middle - 1;
            }
            else if (target > data[middle])
            {
                leftIndex = middle + 1;
            }
        }

        return false;
    }

    bool searchMatrix(
        std::vector<std::vector<int>>& matrix, 
        int target
    )
    {

        std::size_t upIndex = 0;
        std::size_t downIndex = matrix.size() - 1;

        while (upIndex <= downIndex
            && (upIndex < matrix.size() && downIndex < matrix.size())
        )
        {
            std::size_t middle = upIndex + ((downIndex - upIndex) / 2);
            const auto& middleData = matrix.at(middle);
            const int dataLeftValue = *std::cbegin(middleData);
            const int dataRightValue = *std::crbegin(middleData);

            if (isTargetInArray(middleData, target))
            {
                return true;
            }
            else if (dataRightValue < target)
            {
                upIndex = middle + 1;
            }
            else if (dataRightValue > target)
            {
                downIndex = middle - 1;
            }
        }

        return false;
    }
};

TEST (SolutionTest, CornerCase1)
{
    std::vector<std::vector<int>> matrix = {
        { 3 }
    };
    int target = 3;
    const auto result = Solution{}.searchMatrix(matrix, target);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<std::vector<int>> matrix = {
        { 1,2,4,8 },
        { 10,11,12,13 },
        { 14,20,30,40 }
    };
    int target = 10;
    const auto result = Solution{}.searchMatrix(matrix, target);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    const auto result = Solution{}.searchMatrix(matrix, target);
    const auto& expected = true;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 13;
    const auto result = Solution{}.searchMatrix(matrix, target);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<std::vector<int>> matrix = {
        { 1,2,4,8 },
        { 10,11,12,13 },
        { 14,20,30,40 }
    };
    int target = 15;
    const auto result = Solution{}.searchMatrix(matrix, target);
    const auto& expected = false;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
