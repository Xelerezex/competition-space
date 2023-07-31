#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>
#include <cmath>

class Solution
{
public:
    bool isPowerOfFour (int n)
    {
        return false;
    }
};

/* *************************** BEST PRACTISE ******************************* */

/* ************************************************************************* */

/* ----------------------- TRY LOGTEST ------------------------------------- */
TEST(TestingLogBase, Test0)
{
    const double input_data{0};
    const bool   expected{true};

    EXPECT_DOUBLE_EQ(Solution{}.isPowerOfFour(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}