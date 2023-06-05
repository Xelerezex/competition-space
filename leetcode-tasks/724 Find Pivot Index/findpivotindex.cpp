#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>

class Solution
{
public:
    int pivotIndex (std::vector<int>& nums)
    {
        int leftsum = 0, rightsum = 0;

        for (size_t item = 0; item < nums.size(); ++item)
        {
            leftsum  = std::accumulate(nums.begin(), nums.begin() + item, 0);
            rightsum = std::accumulate(
                nums.end() - ((nums.size() - 1) - item), nums.end(), 0);
            if (leftsum == rightsum)
            {
                return item;
            }
        }

        return -1;
    }
};

/* ---------------------------- Index in Right Massive --------------------- */
TEST(TestingIndexRightMassive, IndexThree)
{
    std::vector<int> input_data{1, 7, 3, 6, 5, 6};
    const int        expected{3};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

TEST(TestingIndexRightMassive, IndexSeven)
{
    std::vector<int> input_data{-1, 1, -1, 1, 1, 1, 1, 3, 1, 1, -2, 3};
    const int        expected{7};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

TEST(TestingIndexRightMassive, IndexOne)
{
    std::vector<int> input_data{10, 1, 10};
    const int        expected{1};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

/* ---------------------------- Index not Right Massive -------------------- */
TEST(TestingIndexNotRightMassive, LengthThree)
{
    std::vector<int> input_data{1, 2, 3};
    const int        expected{-1};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

TEST(TestingIndexNotRightMassive, LengthFive)
{
    std::vector<int> input_data{5, 4, 3, 2, 1};
    const int        expected{-1};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

TEST(TestingIndexNotRightMassive, LengthTwo)
{
    std::vector<int> input_data{10, 1};
    const int        expected{-1};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

/* ----------------------------- Index Extreme Massive --------------------- */
TEST(TestingIndexExtremeMassive, LengthThree)
{
    std::vector<int> input_data{2, 1, -1};
    const int        expected{0};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

TEST(TestingIndexExtremeMassive, LengthTwo)
{
    std::vector<int> input_data{30, 0};
    const int        expected{0};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

TEST(TestingIndexNotRightMassive, LengthSeven)
{
    std::vector<int> input_data{-5, 5, -5, 5, -5, 5, 17};
    const int        expected{6};

    EXPECT_EQ(Solution{}.pivotIndex(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}