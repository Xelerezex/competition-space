#include <gtest/gtest.h>

#include <stack>
#include <queue>

class Solution
{
public:
    int countStudents(
        std::vector<int>& students, 
        std::vector<int>& sandwiches
    )
    {
        std::deque<int> temporary;
        temporary.insert(
            std::begin(temporary), 
            std::rbegin(sandwiches), 
            std::rend(sandwiches)
        );
        std::stack<int, std::deque<int>> sandwichesStack(std::move(temporary));
        temporary.insert(
            std::begin(temporary), 
            std::begin(students), 
            std::end(students)
        );
        std::queue<int, std::deque<int>> studentsQueue(std::move(temporary));

        int iteration = 0;
        int studentEat = 0;
        const int studentSize = static_cast<int>(students.size());

        while (iteration != studentsQueue.size())
        {
            const auto sandwich = sandwichesStack.top();
            const auto student = studentsQueue.front();

            if (sandwich == student)
            {
                iteration = 0;
                ++studentEat;
                sandwichesStack.pop();
                studentsQueue.pop();
            }
            else 
            {
                ++iteration;
                studentsQueue.pop();
                studentsQueue.push(student);
            }

        }

        return studentSize - studentEat;
    }
};

TEST (SolutionTest, Example1)
{
    std::vector<int> students{ 1, 1, 0, 0}; 
    std::vector<int> sandwiches{0, 1, 0, 1};
    const auto result = Solution{}.countStudents(students, sandwiches);
    const auto& expected = 0;
    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<int> students{ 1,1,1,0,0,1 }; 
    std::vector<int> sandwiches{ 1,0,0,0,1,1 };
    const auto result = Solution{}.countStudents(students, sandwiches);
    const auto& expected = 3;
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
