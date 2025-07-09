#include <gtest/gtest.h>
#include <queue>

class MyStack
{
public:

    MyStack()
    {
    }

    void push(int x)
    {
        m_enqueue.push(x);
    }

    int pop()
    {
        const auto value = m_enqueue.back();

        int counter = 0;
        int queueSize = static_cast<int>(m_enqueue.size());
        std::queue<int> m_dequeue;
        while (!m_enqueue.empty())
        {
            const auto frontValue = m_enqueue.front();
            if (counter != queueSize - 1)
            {
                m_dequeue.push(frontValue);
            }
            m_enqueue.pop();

            ++counter;
        }

        m_enqueue.swap(m_dequeue);

        return value;
    }

    int top()
    {
        return m_enqueue.back();
    }

    bool empty()
    {
        return m_enqueue.empty();
    }

private:

    std::queue<int> m_enqueue;
};

TEST(SolutionTest, Example1)
{
    MyStack myQueue;

    EXPECT_EQ(true, myQueue.empty());

    myQueue.push(1); // [1]
    EXPECT_EQ(false, myQueue.empty());

    myQueue.push(2); // [1, 2]
    EXPECT_EQ(false, myQueue.empty());

    EXPECT_EQ(2, myQueue.top());

    int popedValue = myQueue.pop(); // [1]
    EXPECT_EQ(2, popedValue);

    myQueue.push(3); // [1, 3]
    EXPECT_EQ(3, myQueue.top());
    myQueue.push(4); // [1, 3, 4]
    myQueue.push(5); // [1, 3, 4, 5]
    EXPECT_EQ(5, myQueue.top());

    popedValue = myQueue.pop(); // [1, 3, 4]
    EXPECT_EQ(5, popedValue);
    popedValue = myQueue.pop(); // [1, 3]
    EXPECT_EQ(4, popedValue);
    popedValue = myQueue.pop(); // [1]
    EXPECT_EQ(3, popedValue);
    popedValue = myQueue.pop(); // []
    EXPECT_EQ(1, popedValue);
    EXPECT_EQ(true, myQueue.empty());

    myQueue.push(3); // [3]
    EXPECT_EQ(3, myQueue.top());
    EXPECT_EQ(false, myQueue.empty());
}

TEST(SolutionTest, Example2)
{
    MyStack myQueue;

    EXPECT_EQ(true, myQueue.empty());

    myQueue.push(1); // [1]
    myQueue.push(2); // [1, 2]
    EXPECT_EQ(false, myQueue.empty());

    EXPECT_EQ(2, myQueue.top());

    int popedValue = myQueue.pop(); // [1]
    EXPECT_EQ(2, popedValue);

    EXPECT_EQ(false, myQueue.empty());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
