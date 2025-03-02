#include <gtest/gtest.h>

#include <vector>

class NumArray
{
public:

    NumArray(std::vector<int>& nums)
    {
        m_nums.reserve(nums.size());

        for (int index = 0; index < nums.size(); ++index)
        {
            const auto currentValue = (index - 1 < 0) ? 0 : m_nums[index - 1];
            m_nums.push_back(currentValue + nums[index]);
        }
    }
    
    int sumRange(int left, int right)
    {
        const auto currentValue = (left - 1 < 0) ? 0 : m_nums[left - 1];
        return m_nums[right] - currentValue;
    }

private:

    std::vector<int> m_nums;

};

TEST (SolutionTest, Example1)
{
    auto nums = std::vector<int>{ -2, 0, 3, -5, 2, -1 };
    NumArray solution{nums};
    const auto& expected = 1;
    const auto& result = solution.sumRange(0, 2);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto nums = std::vector<int>{ -2, 0, 3, -5, 2, -1 };
    NumArray solution{nums};
    const auto& expected = -1;
    const auto& result = solution.sumRange(2, 5);
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto nums = std::vector<int>{ -2, 0, 3, -5, 2, -1 };
    NumArray solution{nums};
    const auto& expected = -3;
    const auto& result = solution.sumRange(0, 5);
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
