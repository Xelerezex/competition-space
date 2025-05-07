#include <gtest/gtest.h>

#include <functional>

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num){ return 0; };

class Solution
{
public:
    int guessNumber(int n)
    {
        int result = -1;

        int left = 0;
        int right = n;

        while (left <= right)
        {
            int middle = left + ((right - left) / 2);

            if (0 == guessFunc(middle))
            {
                result = middle;
                break;
            }
            else if (-1 == guessFunc(middle))
            {
                right = middle - 1;
            }
            else if (1 == guessFunc(middle))
            {
                left = middle + 1;
            }
        }

        return result;
    }

    std::function<int(int)> guessFunc = &guess;

};

TEST (SolutionTest, Example1)
{
    Solution solution;

    int n = 10;
    int pick = 6;
    solution.guessFunc = [pick] (int n)
    {
        int result = -1;
        if (n == pick) { result = 0 ;}
        else if (n < pick) { result = 1 ;}
        else if (n > pick) { result = -1 ;}
        return result;
    };
    const auto result = solution.guessNumber(n);
    const auto& expected = 6;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    Solution solution;

    int n = 1;
    int pick = 1;
    solution.guessFunc = [pick] (int n)
    {
        int result = -1;
        if (n == pick) { result = 0 ;}
        else if (n < pick) { result = 1 ;}
        else if (n > pick) { result = -1 ;}
        return result;
    };
    const auto result = solution.guessNumber(n);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    Solution solution;

    int n = 2;
    int pick = 1;
    solution.guessFunc = [pick] (int n)
    {
        int result = -1;
        if (n == pick) { result = 0 ;}
        else if (n < pick) { result = 1 ;}
        else if (n > pick) { result = -1 ;}
        return result;
    };
    const auto result = solution.guessNumber(n);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
