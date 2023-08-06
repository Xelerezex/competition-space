#include <gmock/gmock.h>
#include <gtest/gtest.h>

class Solution
{
public:
    unsigned get_lastbit (unsigned number)
    {
        return number & ~(~0U << 1);
    }

    uint32_t reverseBits (uint32_t n)
    {
        uint32_t maxBitCount{32};
        uint32_t output{0};

        for (uint32_t index = 0; index < maxBitCount; ++index)
        {
            uint32_t bit = get_lastbit(n >> index);

            output |= bit << ((maxBitCount - 1) - index);
        }

        return output;
    }
};

/* *************************** BEST PRACTISE ******************************* */

/* ************************************************************************* */

/* ----------------------- GENERAL TESTS FROM LEETCODE --------------------- */
TEST(TestingPositiveInput, Input1)
{
    const uint32_t input_data{0b00000010100101000001111010011100};
    const uint32_t expected{964176192};

    EXPECT_EQ(Solution{}.reverseBits(input_data), expected);
}

TEST(TestingPositiveInput, Input2)
{
    const uint32_t input_data{0b11111111111111111111111111111101};
    const uint32_t expected{3221225471};

    EXPECT_EQ(Solution{}.reverseBits(input_data), expected);
}

TEST(TestingPositiveInput, Input3)
{
    const uint32_t input_data{3221225473};
    const uint32_t expected{2147483651};

    EXPECT_EQ(Solution{}.reverseBits(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}