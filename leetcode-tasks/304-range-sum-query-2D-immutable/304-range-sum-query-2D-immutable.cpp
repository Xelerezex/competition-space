#include <gtest/gtest.h>

#include <vector>

class NumMatrix
{

public:
    
    explicit NumMatrix(const std::vector<std::vector<int>>& matrix)
    {   
        const std::size_t rowCount = matrix.size(); 
        const std::size_t columnCount = matrix[0].size(); 

        // Sums from left to right
        std::vector<std::vector<int>> prefixSums1D(matrix.size());
        for (std::size_t row = 0; row < rowCount; ++row)
        {
            prefixSums1D[row] = findPrefixSum1D(matrix[row]);
        }

        // Sums from top to buttom 
        const int prefixSum1dFirstRowSize = static_cast<int>(prefixSums1D[0].size());
        std::vector<std::vector<int>> prefixSums2D(
            prefixSums1D.size() + 1, 
            std::vector<int>(prefixSum1dFirstRowSize, 0)
        );
        for (int column = 0; column < prefixSum1dFirstRowSize; ++column)
        {       
            for (int row = 0; row < prefixSums1D.size(); ++row)
            {
                prefixSums2D[row + 1][column] = prefixSums1D[row][column] + prefixSums2D[row][column];
            }
        } 
        m_PrefixSums2D = std::move(prefixSums2D);
    }
    
    std::vector<int> findPrefixSum1D(const std::vector<int>& data)
    {
        std::vector<int> result(data.size());
        result.push_back(0);
        for (std::size_t index = 0; index < data.size(); ++index)
        {
            result[index + 1] = data[index] + result[index]; 
        }
        return result;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {  
        const int leftX = row1;
        const int rightX = row2 + 1;
        const int leftY = col1;
        const int rightY = col2 + 1;

        const int rect1 = m_PrefixSums2D[rightX][rightY];
        const int rect2 = m_PrefixSums2D[leftX][rightY];
        const int rect3 = m_PrefixSums2D[rightX][leftY];
        const int rect4 = m_PrefixSums2D[leftX][leftY];
        
        return rect1 - rect2 - rect3 + rect4;
    }

private:

    std::vector<std::vector<int>> m_PrefixSums2D;

};
   
TEST (SolutionTest, Example1)
{
    std::vector<std::vector<int>> matrix = {
        {-4, -5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(0, 0, 0, 0);
    const auto expected = -4;
    EXPECT_EQ(expected, result);
}
   
TEST (SolutionTest, Example2)
{
    std::vector<std::vector<int>> matrix = {
        {-4, -5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(0, 0, 0, 1);
    const auto expected = -9;
    EXPECT_EQ(expected, result);
}
   
TEST (SolutionTest, Example3)
{
    std::vector<std::vector<int>> matrix = {
        {-4, -5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(0, 1, 0, 1);
    const auto expected = -5;
    EXPECT_EQ(expected, result);
}
   
TEST (SolutionTest, Example4)
{
    std::vector<std::vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(0, 0, 0, 0);
    const auto expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::vector<std::vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(1, 1, 3, 3);
    const auto expected = 16;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example6)
{
    std::vector<std::vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(0, 0, 4, 4);
    const auto expected = 58;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example7)
{
    std::vector<std::vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(1, 1, 2, 2);
    const auto expected = 11;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example8)
{
    std::vector<std::vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.sumRegion(1, 2, 2, 4);
    const auto expected = 12;
    EXPECT_EQ(expected, result);
}

/* --------------------------------------------------------------------------------- */

TEST (SolutionTest, Example9)
{
    std::vector<std::vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.findPrefixSum1D(matrix[0]);
    const auto expected = std::vector{0, 1, 3, 6, 10 };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example10)
{
    std::vector<std::vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.findPrefixSum1D(matrix[1]);
    const auto expected = std::vector{0, 5, 11, 18, 26 };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example11)
{
    std::vector<std::vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.findPrefixSum1D(matrix[2]);
    const auto expected = std::vector{0, 9, 19, 30, 42 };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example12)
{
    std::vector<std::vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    NumMatrix numMatrix(matrix);
    const auto result = numMatrix.findPrefixSum1D(matrix[3]);
    const auto expected = std::vector{0, 13, 27, 42, 58 };
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
