#include <gtest/gtest.h>

class MyLinkedList
{

public:

    struct Node
    {
        int value;
        Node* next;
        Node* prev;
    };

public:
    
    MyLinkedList()
        : m_head{ nullptr }
        , m_tail{ nullptr }
        , m_size{ 0 }
    {
    }
    
    int get(int index)
    {
        if (index < 0 || index > m_size)
        {
            return -1;
        }

        int currentIndex = 0;
        int currentValue = -1;
        for (Node* pCurrent = m_head; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            if (index == currentIndex)
            {
                currentValue = pCurrent->value;
                break;
            }
            ++currentIndex;
        }

        return currentValue;
    }
    
    void addAtHead(int value) 
    {
        if (empty())
        {
            createFirstNode(value);
            return;
        }

        Node* pNewNode = new Node(value, nullptr, nullptr);
        m_head->prev = pNewNode;
        pNewNode->next = m_head;
        m_head = pNewNode;

        ++m_size;
    }
    
    void addAtTail(int value)
    {
        if (empty())
        {
            createFirstNode(value);
            return;
        }

        Node* pNewNode = new Node(value, nullptr, nullptr);
        pNewNode->prev = m_tail;
        m_tail->next = pNewNode;
        m_tail = pNewNode;

        ++m_size;
    }
    
    void addAtIndex(
        int index, 
        int value
    )
    {
        if (index > m_size)
        {
            return;
        }
        if (index == m_size)
        {
            addAtTail(value);
            return;
        }
        if (index == 0)
        {
            addAtHead(value);
            return;
        }

        int currentIndex = 0;
        for (Node* pCurrent = m_head; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            if (index == currentIndex)
            {
                Node* pPrevious = pCurrent->prev;
                Node* pNewNode = new Node(value, pCurrent, pPrevious);
                pCurrent->prev = pNewNode;
                pPrevious->next = pNewNode;
                ++m_size;
                break;
            }
            ++currentIndex;
        }
    }

    void deleteAtHead()
    {
        if (empty())
        {
            return;
        }
        if (m_size == 1)
        {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            --m_size;
            return;
        }
        
        Node* pNodeToDelete = m_head;
        m_head = m_head->next;
        m_head->prev = nullptr;

        delete pNodeToDelete;
        pNodeToDelete = nullptr;

        --m_size;
    }

    void deleteAtTail()
    {
        if (empty())
        {
            return;
        }
        if (m_size == 1)
        {
            delete m_tail;
            m_head = nullptr;
            m_tail = nullptr;
            --m_size;
            return;
        }
        
        Node* pNodeToDelete = m_tail;
        m_tail = m_tail->prev;
        m_tail->next = nullptr;

        delete pNodeToDelete;
        pNodeToDelete = nullptr;

        --m_size;
    }
    
    void deleteAtIndex(int index)
    {
        if (index >= m_size || index < 0)
        {
            return;
        }
        // delete at head
        if (index == 0)
        {
            deleteAtHead();
            return;
        }
        // delete at tail
        if (index == m_size - 1)
        {
            deleteAtTail();
            return;
        }
        
        // delete strictly between head & tail
        int currentIndex = 0;
        for (Node* pCurrent = m_head; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            if (index == currentIndex)
            {
                Node* pPrevious = pCurrent->prev;
                Node* pNext = pCurrent->next;
                
                pPrevious->next = pNext;
                pNext->prev = pPrevious;
                
                delete pCurrent;
                pCurrent = nullptr;

                --m_size;
                break;
            }
            ++currentIndex;
        }   
    }

    std::size_t size() const
    {
        return m_size;
    }

private:

    bool empty() const
    {
        return m_head == nullptr;
    }

    void createFirstNode(int value)
    {
        Node* pNewNode = new Node(value, nullptr, nullptr);
        m_head = pNewNode;
        m_tail = pNewNode;

        ++m_size;
    }

private:

    Node* m_head;
    Node* m_tail;

    std::size_t m_size;

};

TEST (SolutionTest, CornerCase1)
{
    MyLinkedList myLinkedList;
    EXPECT_EQ(0, myLinkedList.size());

    myLinkedList.addAtHead(1);
    EXPECT_EQ(1, myLinkedList.size());

    myLinkedList.deleteAtIndex(0);
    EXPECT_EQ(0, myLinkedList.size());
}

TEST (SolutionTest, CornerCase2)
{
    MyLinkedList myLinkedList;

    EXPECT_EQ(0, myLinkedList.size());
    EXPECT_EQ(-1, myLinkedList.get(0));

    myLinkedList.addAtIndex(0, 1); // 1
    myLinkedList.addAtHead(2); // 2 -> 1
    myLinkedList.addAtTail(2); // 2 -> 1 -> 2
    myLinkedList.addAtTail(3); // 2 -> 1 -> 2 -> 3

    myLinkedList.addAtIndex(5, 10); // do nothing
    myLinkedList.addAtIndex(6, 10); // do nothing
    EXPECT_EQ(4, myLinkedList.size());
    
    myLinkedList.addAtIndex(4, 4); // 2 -> 1 -> 2 -> 3 -> 4
    EXPECT_EQ(5, myLinkedList.size());

    EXPECT_EQ(-1, myLinkedList.get(-1));
    EXPECT_EQ(-1, myLinkedList.get(10));

    EXPECT_EQ(2, myLinkedList.get(0));
    EXPECT_EQ(1, myLinkedList.get(1));
    EXPECT_EQ(4, myLinkedList.get(4));

    myLinkedList.addAtIndex(2, 10); // 2 -> 1 -> 10 -> 2 -> 3 -> 4
    EXPECT_EQ(10, myLinkedList.get(2));
    EXPECT_EQ(1, myLinkedList.get(1));
    EXPECT_EQ(2, myLinkedList.get(3));

    myLinkedList.addAtIndex(0, 12); // 12 -> 2 -> 1 -> 10 -> 2 -> 3 -> 4
    EXPECT_EQ(12, myLinkedList.get(0));

    myLinkedList.addAtIndex(7, 15); // 12 -> 2 -> 1 -> 10 -> 2 -> 3 -> 4 -> 15
    EXPECT_EQ(15, myLinkedList.get(7));

    myLinkedList.deleteAtIndex(-1); // do nothing
    EXPECT_EQ(8, myLinkedList.size());
    myLinkedList.deleteAtIndex(-2);  // do nothing
    EXPECT_EQ(8, myLinkedList.size());
    myLinkedList.deleteAtIndex(8);  // do nothing
    EXPECT_EQ(8, myLinkedList.size());

    myLinkedList.deleteAtIndex(0);  // 2 -> 1 -> 10 -> 2 -> 3 -> 4 -> 15
    EXPECT_EQ(7, myLinkedList.size());
    EXPECT_EQ(2, myLinkedList.get(0));

    myLinkedList.deleteAtIndex(6);  // 2 -> 1 -> 10 -> 2 -> 3 -> 4
    EXPECT_EQ(6, myLinkedList.size());
    EXPECT_EQ(-1, myLinkedList.get(6));
    EXPECT_EQ(4, myLinkedList.get(5));

    myLinkedList.deleteAtIndex(2);  // 2 -> 1 -> 2 -> 3 -> 4
    EXPECT_EQ(5, myLinkedList.size());
    EXPECT_EQ(2, myLinkedList.get(2));

    myLinkedList.deleteAtIndex(2);  // 2 -> 1 -> 3 -> 4
    EXPECT_EQ(4, myLinkedList.size());

    int index = 0;
    for (const auto& value : {2, 1, 3, 4} )
    {
        EXPECT_EQ(value, myLinkedList.get(index++));
    }
}

TEST (SolutionTest, Example1)
{
    MyLinkedList myLinkedList;

    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);

    int expected = 2;
    EXPECT_EQ(expected, myLinkedList.get(1));
    
    myLinkedList.deleteAtIndex(1);

    expected = 3;
    EXPECT_EQ(expected, myLinkedList.get(1));
}

TEST (SolutionTest, Example2)
{
    MyLinkedList myLinkedList;

    myLinkedList.addAtHead(1);
    myLinkedList.addAtHead(1);
    myLinkedList.addAtIndex(1, 4);

    int expected = 4;
    EXPECT_EQ(expected, myLinkedList.get(1));
    
    myLinkedList.deleteAtIndex(2);

    expected = 4;
    EXPECT_EQ(expected, myLinkedList.get(1));

    myLinkedList.addAtTail(7);

    expected = 7;
    EXPECT_EQ(expected, myLinkedList.get(2));

    myLinkedList.addAtHead(0);
    
    expected = 0;
    EXPECT_EQ(expected, myLinkedList.get(0));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
