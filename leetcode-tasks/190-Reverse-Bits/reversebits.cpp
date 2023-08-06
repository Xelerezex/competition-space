#include <gmock/gmock.h>
#include <gtest/gtest.h>

class Solution
{
public:
public:
    uint32_t reverseBits (uint32_t n)
    {
        uint32_t maxBitCount{32};
        // uint32_t output{0};
        //  uint32_t temporary{0};

        // for (uint32_t index = 0; index < maxBitCount; ++index)
        //{
        //     output = ;
        // }

        return (n << maxBitCount) | (n >> maxBitCount);
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

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}