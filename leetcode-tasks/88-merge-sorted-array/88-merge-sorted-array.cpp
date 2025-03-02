#include <gtest/gtest.h>

#include <vector>

class Solution
{

public:

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int left = m - 1;
        int right = n - 1;
        int back = m + n - 1;

        while (right >= 0)
        {
            if (left >= 0 && nums1[left] > nums2[right])
            {
                nums1[back] = nums1[left];
                --left;
            }
            else
            {
                nums1[back] = nums2[right];
                --right;
            }
            --back;
        }
    }
};

TEST (SolutionTest, Example1)
{
    auto nums1 = std::vector<int>{ 1,2,3,0,0,0 };
    int m = 3;
    auto nums2 = std::vector<int>{ 2, 5, 6 };
    int n = 3;
    const auto& expected = std::vector{ 1,2,2,3,5,6 };
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(expected, nums1);
}

TEST (SolutionTest, Example2)
{
    auto nums1 = std::vector<int>{ 1 };
    int m = 1;
    auto nums2 = std::vector<int>{ };
    int n = 0;
    const auto& expected = std::vector{ 1 };
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(expected, nums1);
}

TEST (SolutionTest, Example3)
{
    auto nums1 = std::vector<int>{ 0 };
    int m = 0;
    auto nums2 = std::vector<int>{ 1 };
    int n = 1;
    const auto& expected = std::vector{ 1 };
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(expected, nums1);
}

TEST (SolutionTest, Example4)
{
    auto nums1 = std::vector<int>{  -6, -4, -1, 0, 0, 0, 0  };
    int m = 3;
    auto nums2 = std::vector<int>{ -5, -4, -4, 1 };
    int n = 4;
    const auto& expected = std::vector{ -6, -5, -4, -4, -4, -1, 1 };
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(expected, nums1);
}

TEST (SolutionTest, Example5)
{
    auto nums1 = std::vector<int>{ 2, 0 };
    int m = 1;
    auto nums2 = std::vector<int>{ 1 };
    int n = 1;
    const auto& expected = std::vector{  1, 2 };
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(expected, nums1);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
