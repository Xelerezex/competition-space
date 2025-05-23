#include <gtest/gtest.h>

#include <stack>
#include <utility>

class MinStack
{
public:

    MinStack() = default;
    
    void push(int val)
    {
        if (m_stack.empty())
        {
            m_stack.emplace(val, val);
            return;
        }

        const auto minValue = std::min(val, getMin());
        m_stack.emplace(val, minValue);
    }
    
    void pop()
    {
        m_stack.pop();
    }
    
    int top()
    {
        return m_stack.top().first;
    }
    
    int getMin()
    {
        return m_stack.top().second;
    }

private:

    using element_t = std::pair<int, int>;
    std::stack<element_t /*, Container */> m_stack;

    // NOTE: Fun fact, if Container == std::vector<element_t> solution beats 100% in runtime :) 

};

TEST (SolutionTest, Example1)
{
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    minStack.pop();
    EXPECT_EQ(0, minStack.top());

    EXPECT_EQ(-2, minStack.getMin());
}


TEST (SolutionTest, Example2)
{
    MinStack minStack;

    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    EXPECT_EQ(0, minStack.getMin());
    minStack.pop();
    EXPECT_EQ(2, minStack.top()); 
    EXPECT_EQ(1, minStack.getMin());
}

TEST (SolutionTest, Example3)
{
    MinStack minStack;

    minStack.push(5);
    minStack.push(0);
    minStack.push(2);
    minStack.push(4);
    int result = minStack.getMin();
    EXPECT_EQ(0, result);

    minStack.pop();
    result = minStack.top();
    EXPECT_EQ(2, result);
    
    minStack.pop();
    result = minStack.getMin();
    EXPECT_EQ(0, result);
    
    minStack.pop();
    result = minStack.getMin();
    EXPECT_EQ(5, result); 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
