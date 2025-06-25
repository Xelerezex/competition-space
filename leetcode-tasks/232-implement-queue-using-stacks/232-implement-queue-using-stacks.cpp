#include <gtest/gtest.h>
#include <stack>

class MyQueue
{
public:
    
    MyQueue()
    {
    }
    
    void push(int x)
    {
        m_enqueue.push(x);
    }
    
    int pop()
    {
        moveDataIfNeeded();

        const int poppedValue = m_dequeue.top();
        m_dequeue.pop();
        return poppedValue;
    }
    
    int peek()
    {
        moveDataIfNeeded();

        return m_dequeue.top();
    }
    
    bool empty()
    {
        return m_enqueue.empty() && m_dequeue.empty();
    }

private:

    void moveDataIfNeeded()
    {
        if (m_dequeue.empty())
        {
            while (!m_enqueue.empty())
            {
                const int currentValue = m_enqueue.top();
                m_dequeue.push(currentValue);
                m_enqueue.pop();
            }
        }
    }

private:

    std::stack<int, std::vector<int>> m_enqueue;
    std::stack<int, std::vector<int>> m_dequeue;

};

TEST (SolutionTest, Example1)
{
    MyQueue myQueue;

    EXPECT_EQ(true, myQueue.empty());

    myQueue.push(1); // [1]
    EXPECT_EQ(false, myQueue.empty());
    
    myQueue.push(2); // [1, 2]
    EXPECT_EQ(false, myQueue.empty());

    EXPECT_EQ(1, myQueue.peek());

    int popedValue = myQueue.pop(); // [2]
    EXPECT_EQ(1, popedValue);

    myQueue.push(3); // [2, 3]
    EXPECT_EQ(2, myQueue.peek());
    myQueue.push(4); // [2, 3, 4]
    myQueue.push(5); // [2, 3, 4, 5]
    EXPECT_EQ(2, myQueue.peek());
    
    popedValue = myQueue.pop(); // [3, 4, 5]
    EXPECT_EQ(2, popedValue);
    popedValue = myQueue.pop(); // [4, 5]
    EXPECT_EQ(3, popedValue);
    popedValue = myQueue.pop(); // [5]
    EXPECT_EQ(4, popedValue);
    popedValue = myQueue.pop(); // []
    EXPECT_EQ(5, popedValue);
    EXPECT_EQ(true, myQueue.empty());

    myQueue.push(3); // [3]
    EXPECT_EQ(3, myQueue.peek());
    EXPECT_EQ(false, myQueue.empty());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
