#include <gtest/gtest.h>
#include <functional>

// For test
bool isBadVersion(int version) { return false; };

class Solution
{

public:

    int firstBadVersion(int n)
    {
        int leftIndex = 0;
        int rightIndex = n;

        while (leftIndex <= rightIndex)
        {
            int middle = leftIndex + ((rightIndex - leftIndex) / 2);

            if (isBadVersionFunc(middle))
            {
                rightIndex = middle - 1;
            }
            else 
            {
                leftIndex = middle + 1;
            }

        }

        return leftIndex;
    }

    std::function<int(int)> isBadVersionFunc = &isBadVersion;

};

TEST (SolutionTest, Example1)
{
    Solution solution;

    int n = 5;
    int bad = 4;
    solution.isBadVersionFunc = [bad] (int n)
    {
        return bad == n;
    };
    const auto result = solution.firstBadVersion(n);
    const auto& expected = 4;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    Solution solution;

    int n = 1;
    int bad = 1;
    solution.isBadVersionFunc = [bad] (int n)
    {
        return bad == n;
    };
    const auto result = solution.firstBadVersion(n);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
