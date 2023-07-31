#include <gmock/gmock.h>
#include <gtest/gtest.h>

class Solution
{
public:
    int dominantIndex (std::vector<int>& nums)
    {
        int max_value = 0;

        for (const auto& item: nums)
        {
            max_value = (item > max_value) ? item : max_value;
        }

        for (const auto& item: nums)
        {
            bool condition = (nums.size() > 1) ?
                                 ((static_cast<double>(max_value)
                                   / static_cast<double>(item))
                                      >= 2
                                  || (max_value == item)) :
                                 true;
            if (!condition)
            {
                return -1;
            }
        }

        return static_cast<int>(find(nums.begin(), nums.end(), max_value)
                                - nums.begin());
    }
};

/* ---------------------------- Index was founded -------------------------- */
TEST(DominantIndexFoundTest, OneIndexLengthFour)

{
    std::vector<int> input_data{3, 6, 1, 0};
    const int        expected{1};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexFoundTest, ZeroIndexLengthOne)
{
    std::vector<int> input_data{1};
    const int        expected{0};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexFoundTest, EightIndexsLengthFourThirteen)
{
    std::vector<int> input_data{1, 2, 3, 4, 4, 3, 2, 1, 8, 4, 3, 2, 1};
    const int        expected{8};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexFoundTest, ZeroIndexsLengthFive)
{
    std::vector<int> input_data{8, 0, 0, 0, 0};
    const int        expected{0};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexFoundTest, FourIndexsLengthFive)
{
    std::vector<int> input_data{0, 0, 0, 0, 8};
    const int        expected{4};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexFoundTest, ZeroIndexsLengthFourSecond)
{
    std::vector<int> input_data{8, 3, 2, 1, 0};
    const int        expected{0};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexFoundTest, FourIndexsLengthFiveSecond)
{
    std::vector<int> input_data{0, 1, 2, 3, 8};
    const int        expected{4};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

/* ---------------------------- Index was founded -------------------------- */
TEST(DominantIndexNotFoundTest, LengthFour)
{
    std::vector<int> input_data = {1, 2, 3, 4};
    const int        expected{-1};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexNotFoundTest, LengthFive)
{
    std::vector<int> input_data = {1, 5, 4, 3, 9}; // 9 / 5 = 1.8
    const int        expected{-1};

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

TEST(DominantIndexNotFoundTest, LengthThirdteen)
{
    std::vector<int> input_data
        = {1, 1, 1, 1, 100, 1, 1, 1, 1, 0, 0, 0, 51}; // 100 / 51 = 1.96
    const int expected = -1;

    EXPECT_EQ(Solution{}.dominantIndex(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}