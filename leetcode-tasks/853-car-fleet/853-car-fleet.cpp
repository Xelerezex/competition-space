#include <gtest/gtest.h>

#include <stack>
#include <algorithm>

/*
class Solution
{
public:
    
    int carFleet(
        int target, 
        std::vector<int>& position, 
        std::vector<int>& speed
    )
    {
        int counter = 0;

        std::multimap<int, int> storage;
        // Ascending order
        for (std::size_t index = 0; index < position.size(); ++index)
        {
            storage.emplace(position[index], speed[index]);
        }

        std::stack<double, std::vector<double>> speedStack;

        // Descending order iteration
        for (auto iter = std::rbegin(storage); std::rend(storage) != iter; ++iter)
        {
            const auto [position, speed] = *iter;
            const double currentTime = static_cast<double>(target - position) / static_cast<double>(speed);

            double previousTime = speedStack.empty() ? 0 : speedStack.top();
            if (currentTime > previousTime)
            {
                speedStack.push(currentTime);
            }  
        }

        return static_cast<int>(speedStack.size());
    }
};
*/

class Solution
{
public:
    
    int carFleet(
        int target, 
        std::vector<int>& position, 
        std::vector<int>& speed
    )
    {
        int counter = 0;

        std::vector<std::pair<int, int>> storage;
        // Ascending order
        for (std::size_t index = 0; index < position.size(); ++index)
        {
            storage.emplace_back(position[index], speed[index]);
        }

        std::sort(std::rbegin(storage), std::rend(storage));

        std::stack<double, std::vector<double>> speedStack;

        // Descending order iteration
        for (const auto& pair : storage)
        {
            const auto [position, speed] = pair;
            const double currentTime = static_cast<double>(target - position) / static_cast<double>(speed);

            double previousTime = speedStack.empty() ? 0 : speedStack.top();
            if (currentTime > previousTime)
            {
                speedStack.push(currentTime);
            }  
        }

        return static_cast<int>(speedStack.size());
    }
};

TEST (SolutionTest, CornerCase1)
{
    const int target = 16; 
    std::vector<int> position = { 11, 14, 13, 6 }; 
    std::vector<int> speed =    {  2,  2,  6, 7 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase2)
{
    const int target = 10; 
    std::vector<int> position = { 8, 3, 7, 4, 6, 5 }; 
    std::vector<int> speed =    { 4, 4, 4, 4, 4, 4 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 6;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase3)
{
    const int target = 10; 
    std::vector<int> position = {0, 4, 2 }; 
    std::vector<int> speed = { 2, 1, 3 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CornerCase4)
{
    const int target = 10; 
    std::vector<int> position = {6, 8 }; 
    std::vector<int> speed = { 3, 2 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 2;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    const int target = 12; 
    std::vector<int> position = {10,8,0,5,3}; 
    std::vector<int> speed = {2,4,1,1,3};
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    const int target = 10; 
    std::vector<int> position = { 1, 4 }; 
    std::vector<int> speed = { 3, 2 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    const int target = 10; 
    std::vector<int> position = { 4, 1, 0, 7 }; 
    std::vector<int> speed = { 2, 2, 1, 1 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    const int target = 10; 
    std::vector<int> position = { 3 }; 
    std::vector<int> speed = { 3 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    const int target = 100; 
    std::vector<int> position = { 0, 2, 4 }; 
    std::vector<int> speed = { 4, 2, 1 };
    const auto result = Solution{}.carFleet( target, position, speed);
    const auto& expected = 1;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
