#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    std::vector<int> findDiagonalOrder (std::vector<std::vector<int>>& mat)
    {
        const std::size_t             row    = mat.size();
        const std::size_t             column = mat[0].size();
        std::vector<std::vector<int>> diagonals(row + column - 1);

        std::vector<int>              out_put;

        for (size_t i = 0; i < row; ++i)
        {
            for (size_t j = 0; j < column; ++j)
            {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }

        out_put.push_back(diagonals[0][0]);

        for (size_t i = 1; i < diagonals.size(); ++i)
        {
            for (size_t j = 0; j < diagonals[i].size(); ++j)
            {
                if (i % 2 == 0)
                {
                    out_put.push_back(
                        diagonals[i][((diagonals[i].size() - 1) - j)]);
                }
                else
                {
                    out_put.push_back(diagonals[i][j]);
                }
            }
        }

        return out_put;
    }
};

/* ----------------------- GENERAL TESTS FROM LEETCODE --------------------- */
TEST(TestingGeneralInput, Test1)
{
    std::vector<std::vector<int>> input_data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    const std::vector<int>        expected{1, 2, 4, 7, 5, 3, 6, 8, 9};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

TEST(TestingGeneralInput, Test2)
{
    std::vector<std::vector<int>> input_data = {{1, 2}, {3, 4}};
    const std::vector<int>        expected   = {1, 2, 3, 4};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

TEST(TestingNxNInput, Test1)
{
    const int a = -100'000;
    const int b = 100'000;
    const int c = 50'000;
    const int d = -66'777;

    // Input
    std::vector<std::vector<int>> input_data = {
        {a, b, c, d},
        {d, a, d, c},
        {d, d, a, c},
        {d, d, c, a},
    };
    const std::vector<int> expected
        = {a, b, d, d, a, c, d, d, d, d, d, a, c, c, c, a};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

TEST(TestingNxNInput, Test2)
{
    std::vector<std::vector<int>> input_data = {
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
    };

    const std::vector<int> expected
        = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

TEST(TestingMxNInput, Test1)
{
    const int a = -100'000;
    const int b = 100'000;
    const int c = 50'000;
    const int d = -66'777;

    // Input
    std::vector<std::vector<int>> input_data = {
        {a, b, c, d},
        {d, b, c, a},
    };
    const std::vector<int> expected = {a, b, d, b, c, d, c, a};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

TEST(TestingMxNInput, Test2)
{
    const int a = -100'000;
    const int b = 100'000;
    const int c = 50'000;
    const int d = -66'777;

    // Input
    std::vector<std::vector<int>> input_data = {
        {a, b},
        {c, d},
        {d, a},
        {d, b},
    };
    const std::vector<int> expected = {a, b, c, d, d, a, d, b};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

TEST(Testing1xMor1xNInput, Test1)
{
    const int a = -100'000;
    const int b = 100'000;
    const int c = 50'000;
    const int d = -66'777;

    // Input
    std::vector<std::vector<int>> input_data = {
        {a, b, c, d, 1, 1, 1, 1, 1, 1},
    };
    const std::vector<int> expected = {a, b, c, d, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

TEST(Testing1xMor1xNInput, Test2)
{
    const int a = -100'000;
    const int b = 100'000;
    const int c = 50'000;
    const int d = -66'777;

    // Input
    std::vector<std::vector<int>> input_data = {
        {a},
        {b},
        {c},
        {d},
        {1},
        {1},
        {1},
        {1},
        {1},
        {1},
    };
    const std::vector<int> expected = {a, b, c, d, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(Solution{}.findDiagonalOrder(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}