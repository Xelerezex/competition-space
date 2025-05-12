#include <gtest/gtest.h>
#include <limits>

class Solution
{
public:
    
    double findMedianSortedArrays(
        std::vector<int>& nums1, 
        std::vector<int>& nums2
    )
    {
        const auto& biggerArray = nums1.size() >= nums2.size() ? nums1 : nums2;
        const auto& smallerArray = nums1.size() >= nums2.size() ? nums2 : nums1;
        
        const std::size_t totalSize = biggerArray.size() + smallerArray.size();
        const std::size_t halfSize = (totalSize + 1) / 2;

        std::size_t leftIndex = 0;
        std::size_t rightIndex = smallerArray.size();
        while (leftIndex <= rightIndex)
        {
            std::size_t middle = leftIndex + ((rightIndex - leftIndex) / 2);
            const std::size_t currentBiggerIndex = halfSize - middle;

            const int smallerLeft = middle > 0 
                ? smallerArray.at(middle - 1)  
                : std::numeric_limits<int>::min();
            const int smallerRight = middle < smallerArray.size() 
                ? smallerArray.at(middle) 
                : std::numeric_limits<int>::max();

            const int biggerLeft = currentBiggerIndex > 0 
                ? biggerArray.at(currentBiggerIndex - 1) 
                : std::numeric_limits<int>::min();
            const int biggerRight = currentBiggerIndex < biggerArray.size() 
                ? biggerArray.at(currentBiggerIndex) 
                : std::numeric_limits<int>::max();

            if (smallerLeft <= biggerRight && biggerLeft <= smallerRight)
            {
                if (totalSize % 2 == 0)
                {
                    return (std::max(smallerLeft, biggerLeft) 
                        + std::min(smallerRight, biggerRight)) / 2.0;
                }
                return std::max(smallerLeft, biggerLeft) ;
            }
            else if (smallerLeft > biggerRight)
            {
                rightIndex = middle - 1;
            }
            else
            {
                leftIndex = middle + 1;
            }
        }

        return -1.0;
    }

};

TEST (SolutionTest, CornerCase1)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8 }; 
    std::vector<int> nums2 = { 1, 2, 3, 4, 5 };
    const auto result = Solution{}.findMedianSortedArrays(nums1, nums2);
    const auto expected = 4.0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::vector<int> nums1 = {1, 2}; 
    std::vector<int> nums2 = { 3 };
    const auto result = Solution{}.findMedianSortedArrays(nums1, nums2);
    const auto expected = 2.0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums1 = {1, 3 }; 
    std::vector<int> nums2 = { 2, 4 };
    const auto result = Solution{}.findMedianSortedArrays(nums1, nums2);
    const auto expected = 2.5;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums1 = {2, 7, 12, 15 }; 
    std::vector<int> nums2 = { 8, 9, 10 };
    const auto result = Solution{}.findMedianSortedArrays(nums1, nums2);
    const auto expected = 9.0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    std::vector<int> nums1 = {2, 7, 12, 15 }; 
    std::vector<int> nums2 = { 1, 3, 4 };
    const auto result = Solution{}.findMedianSortedArrays(nums1, nums2);
    const auto expected = 4.0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    std::vector<int> nums1 = {2, 7, 12, 15 }; 
    std::vector<int> nums2 = { 8, 9 };
    const auto result = Solution{}.findMedianSortedArrays(nums1, nums2);
    const auto expected = 8.5;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example7)
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7 }; 
    std::vector<int> nums2 = { 1, 2, 3, 4, 5 };
    const auto result = Solution{}.findMedianSortedArrays(nums1, nums2);
    const auto expected = 3.5;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
