#include <gtest/gtest.h>

#include <vector>
#include <unordered_set>

class Solution
{

public:

    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        if (k == 0)
        {
            return true;
        }

        auto dataCount = static_cast<int>(nums.size());
        int left = 0;

        std::unordered_set<int> window;

        for (int right = 0; right < dataCount;)
        {
            int distance = std::abs(left - right);

            if (window.contains(nums[right]))
            {
                return true;
            }
            window.insert(nums[right]);

            if (distance < k)
            {
                ++right;
            }
            else if (distance == k)
            {
                window.erase(nums[left]);
                ++left;
                ++right;
            }
        }

        return false;
    } 
};

TEST (SolutionTest, Example1)
{
    auto data = std::vector<int>{ 1,2,3,1  };
    const auto window = 3;
    const auto& expected = true;
    const auto& result = Solution{}.containsNearbyDuplicate(data, window);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto data = std::vector<int>{ 1,0,1,1 };
    const auto window = 1;
    const auto& expected = true;
    const auto& result = Solution{}.containsNearbyDuplicate(data, window);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto data = std::vector<int>{ 1, 2, 3, 1, 2, 3 };
    const auto window = 2;
    const auto& expected = false;
    const auto& result = Solution{}.containsNearbyDuplicate(data, window);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto data = std::vector<int>{ 1, 2, 3 };
    const auto window = 0;
    const auto& expected = true;
    const auto& result = Solution{}.containsNearbyDuplicate(data, window);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto data = std::vector<int>{ -1, -2, -3, -4, -5, -3 };
    const auto window = 3;
    const auto& expected = true;
    const auto& result = Solution{}.containsNearbyDuplicate(data, window);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example6)
{
    auto data = std::vector<int>{ -1, -1, -8, -4, -5, -3 };
    const auto window = 1;
    const auto& expected = true;
    const auto& result = Solution{}.containsNearbyDuplicate(data, window);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    Solution solution;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
