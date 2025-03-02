#include <gtest/gtest.h>

#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_map>

class Solution
{

public:

    using Type_t = std::int64_t;

    int fourSumCount(
        std::vector<int>& nums1, 
        std::vector<int>& nums2, 
        std::vector<int>& nums3, 
        std::vector<int>& nums4
    )
    {
        // With sort it is faster lol
        std::sort(std::begin(nums1), std::end(nums1));
        std::sort(std::begin(nums2), std::end(nums2));
        std::sort(std::begin(nums3), std::end(nums3));
        std::sort(std::begin(nums4), std::end(nums4));
        
        std::unordered_map<Type_t, Type_t> hash;
        Type_t counter = 0;

        for (Type_t first = 0; first < nums1.size(); ++first)
        {
            for (Type_t second = 0; second < nums2.size(); ++second)
            {
                const Type_t sum = nums1[first] + nums2[second];
                if (std::cend(hash) != hash.find(sum))
                {
                    hash[sum] += 1;
                }
                else
                {
                    hash.emplace(sum, 1);
                }
            }
        }

        for (Type_t third = 0; third < nums3.size(); ++third)
        {
            for (Type_t fourth = 0; fourth < nums4.size(); ++fourth)
            {
                const Type_t difference = -(nums3[third] + nums4[fourth]);

                if (std::cend(hash) != hash.find(difference))
                {
                    counter += hash[difference];
                }
            }   
        }
        return counter;
    }
};

TEST (SolutionTest, Example1)
{
    auto nums1 = std::vector<int>{ 1, 2 };
    auto nums2 = std::vector<int>{ -2, -1 };
    auto nums3 = std::vector<int>{ -1, 2 };
    auto nums4 = std::vector<int>{ 0, 2 };
    const auto result = Solution{}.fourSumCount(nums1, nums2, nums3, nums4);
    const auto expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto nums1 = std::vector<int>{ 0 };
    auto nums2 = std::vector<int>{ 0 };
    auto nums3 = std::vector<int>{ 0 };
    auto nums4 = std::vector<int>{ 0 };
    const auto result = Solution{}.fourSumCount(nums1, nums2, nums3, nums4);
    const auto expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto nums1 = std::vector<int>{ };
    auto nums2 = std::vector<int>{ };
    auto nums3 = std::vector<int>{ };
    auto nums4 = std::vector<int>{ };
    const auto result = Solution{}.fourSumCount(nums1, nums2, nums3, nums4);
    const auto expected = 0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto nums1 = std::vector<int>{ 1 };
    auto nums2 = std::vector<int>{ -1 };
    auto nums3 = std::vector<int>{ 0 };
    auto nums4 = std::vector<int>{ 1 };
    const auto result = Solution{}.fourSumCount(nums1, nums2, nums3, nums4);
    const auto expected = 0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto nums1 = std::vector<int>{ -1, -1 };
    auto nums2 = std::vector<int>{ -1, 1 };
    auto nums3 = std::vector<int>{ -1, 1 };
    auto nums4 = std::vector<int>{ 1, -1 };
    const auto result = Solution{}.fourSumCount(nums1, nums2, nums3, nums4);
    const auto expected = 6;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
