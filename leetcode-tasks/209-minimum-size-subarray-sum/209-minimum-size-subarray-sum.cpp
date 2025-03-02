#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:

    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        
    }
};

TEST(SampleTest, Addition)
{
    EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

