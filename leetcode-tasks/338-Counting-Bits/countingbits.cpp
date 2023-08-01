#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
public:
    std::vector<int> countBits (int n)
    {
        std::vector<int> output;
        output.reserve(n + 1);

        for (int i = 0; i <= n; i++)
        {
            output.push_back(__builtin_popcount(i));
        }

        return output;
    }
};

/* *************************** BEST PRACTISE ******************************* */
/*    vector<int> countBits(int n) {                                         */
/*                                                                           */
/*        // n+1 as we are going to count from 0 to n                        */
/*        vector<int> t(n+1);                                                */
/*                                                                           */
/*        // t[0] will be 0 beacuse 0 has count of set bit is 0;             */
/*        t[0] = 0;                                                          */
/*                                                                           */
/*        // we can compute current set bit count using previous count       */
/*        // as x/2 in O(1) time                                             */
/*                                                                           */
/*        // i%2 will be 0 for even number ans 1 for odd number              */
/*                                                                           */
/*        for(int i = 1; i<=n; ++i)                                          */
/*            t[i] = t[i/2] + i%2;                                           */
/*                                                                           */
/*        return t;                                                          */
/*    }                                                                      */
/* ************************************************************************* */

/* ----------------------- GENERAL TESTS FROM LEETCODE --------------------- */
TEST(TestingPositiveInput, Input1)
{
    const int              input_data{2};
    const std::vector<int> expected{0, 1, 1};

    EXPECT_EQ(Solution{}.countBits(input_data), expected);
}

TEST(TestingPositiveInput, Input2)
{
    const int              input_data{5};
    const std::vector<int> expected{0, 1, 1, 2, 1, 2};

    EXPECT_EQ(Solution{}.countBits(input_data), expected);
}

/* ------------------------------- RUN ALL TESTS ---------------------------- */
int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}