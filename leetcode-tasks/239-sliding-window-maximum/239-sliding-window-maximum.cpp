#include <gtest/gtest.h>

#include <algorithm>
#include <iterator>
#include <set>

class Solution
{

public:
    
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        if (nums.size() < k)
        {
            int value = *std::max_element(
                std::begin(nums), 
                std::end(nums)
            );
            return { value };
        }

        std::vector<int> result;
        std::multiset<int> window;

        int left = 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            const auto newValue = nums[right];
            window.emplace(newValue);

            const auto currentWindowLength = (right - left) + 1;

            if (currentWindowLength == k)
            {
                const auto& value = *std::crbegin(window);
                result.push_back(value);

                const auto oldValue = nums[left];
                const auto toRemoveIter = window.lower_bound(oldValue);
                window.erase(toRemoveIter);
                ++left;
            }
        }

        return result;
    }
};


TEST (SolutionTest, CornerCase1)
{
    std::vector<int> nums = { -7,-8,7,5,7,1,6,0 }; 
    const int k = 4;
    const auto result = Solution{}.maxSlidingWindow(nums, k);
    const auto& expected = std::vector<int>{ 7,7,7,7,7 };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    std::vector<int> nums = {3 }; 
    const int k = 3;
    const auto result = Solution{}.maxSlidingWindow(nums, k);
    const auto& expected = std::vector<int>{3 };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase3)
{
    std::vector<int> nums = {3, 1, -1 }; 
    const int k = 3;
    const auto result = Solution{}.maxSlidingWindow(nums, k);
    const auto& expected = std::vector<int>{3 };
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    std::vector<int> nums = {1,3,-1,-3,5,3,6,7}; 
    const int k = 3;
    const auto result = Solution{}.maxSlidingWindow(nums, k);
    const auto& expected = std::vector<int>{3,3,5,5,6,7};
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> nums = {1}; 
    const int k = 1;
    const auto result = Solution{}.maxSlidingWindow(nums, k);
    const auto& expected = std::vector<int>{1};
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<int> nums = {1,2,1,0,4,2,6}; 
    const int k = 3;
    const auto result = Solution{}.maxSlidingWindow(nums, k);
    const auto& expected = std::vector<int>{2,2,4,4,6};
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
