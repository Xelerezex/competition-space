#include <gtest/gtest.h>

#include <vector>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        const auto rowCount = board.size();
        const auto columnCount = board[0].size();
        
        std::unordered_map<int, std::unordered_map<char, int>> columnValues;
        std::unordered_map<int, std::unordered_map<char, int>> squareValues{
            { 0, {} },
            { 1, {} },
            { 2, {} }
        };

        for (int row = 0; row < columnCount; ++row)
        {
            std::unordered_map<char, int> rowValues;

            for (int column = 0; column < rowCount; ++column)
            {
                const auto value = board[row][column];
                if (value == '.')
                {
                    continue;
                }
                
                // For row
                const auto& [iterRow, isUniqueInRow] = rowValues.emplace(value, 1);
                if (!isUniqueInRow)
                {
                    return false;
                }

                // For column
                const auto& [iterColumn, isUniqueInColumn] = columnValues[column].emplace(value, 1);
                if (!isUniqueInColumn)
                {
                    return false;
                }

                // For squares
                const auto& [iterSquare, isUniqueInSquare] = squareValues[column / 3].emplace(value, 1);
                if (!isUniqueInSquare)
                {
                    return false;
                }
            }

            if (row == 2 || row == 5 || row == 8)
            {
                squareValues.clear();
                squareValues = {
                    { 0, {} },
                    { 1, {} },
                    { 2, {} }
                };
            }
        }

        return true;
    }
};

TEST (SolutionTest, Example1)
{
    auto board = std::vector<std::vector<char>>{ 
        {'.','.','.','.','.','.','5','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'9','3','.','.','2','.','4','.','.'},
        {'.','.','7','.','.','.','3','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','3','4','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','.'},
        {'.','.','.','.','.','5','2','.','.'}
    };
    const auto& expected = false;
    const auto& result = Solution{}.isValidSudoku(board);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto board = std::vector<std::vector<char>>{ 
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'}, 
        {'.','9','8','.','.','.','.','6','.'}, 
        {'8','.','.','.','6','.','.','.','3'}, 
        {'4','.','.','8','.','3','.','.','1'}, 
        {'7','.','.','.','2','.','.','.','6'}, 
        {'.','6','.','.','.','.','2','8','.'}, 
        {'.','.','.','4','1','9','.','.','5'}, 
        {'.','.','.','.','8','.','.','7','9'}
    };
    const auto& expected = true;
    const auto& result = Solution{}.isValidSudoku(board);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto board = std::vector<std::vector<char>>{ 
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','8','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    const auto& expected = true;
    const auto& result = Solution{}.isValidSudoku(board);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto board = std::vector<std::vector<char>>{ 
            //        1
            {'1','2','.','.','3','.','.','.','.'},
            {'4','.','.','5','.','.','.','.','.'},
            {'.','9','1','.','.','.','.','.','3'}, // 1
            {'5','.','.','.','6','.','.','.','4'},
            {'.','.','.','8','.','3','.','.','5'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','.','.','.','.','.','2','.','.'},
            {'.','.','.','4','1','9','.','.','8'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    const auto& expected = false;
    const auto& result = Solution{}.isValidSudoku(board);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto board = std::vector<std::vector<char>>{ 
            //                                                9
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'}, 
            {'8','.','.','.','6','.','.','.','3'}, 
            {'4','.','.','8','.','9','.','.','1'}, 
            {'7','.','.','.','2','.','.','.','6'}, 
            {'.','6','.','.','.','.','2','8','.'}, 
            {'.','.','.','4','1','9','.','.','5'}, 
            {'.','.','.','.','8','.','.','7','9'}
    };
    const auto& expected = false;
    const auto& result = Solution{}.isValidSudoku(board);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example6)
{
    auto board = std::vector<std::vector<char>>{ 
            //        8
            {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'},
    };
    const auto& expected = false;
    const auto& result = Solution{}.isValidSudoku(board);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
