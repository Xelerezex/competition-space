#include <gtest/gtest.h>
#include <unordered_map>

// Definition for a Node.
class Node
{
public:
    int val;
    Node* next;
    Node* random;
    
    explicit Node(int _val)
        : val{_val}
        , next{ nullptr }
        , random{ nullptr }
    {
    }

    // Only for tests
    explicit Node(int value, Node* next_)
        : val{value}
        , next{ next_ }
        , random{ nullptr }
    {
    }
};

/*
// NOTE: This is my first solution with O(N) time & O(N) space
class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        std::unordered_map<Node*, std::size_t> headToIndex;
        std::vector<Node*> indexToCopy;

        Node* pCopy = nullptr;
        Node* pNewNode = nullptr;
        std::size_t index = 0;
        for (Node* pCurrent = head; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            headToIndex.emplace(pCurrent, index);
            if (nullptr != pCopy)
            {
                pNewNode->next = new Node(pCurrent->val);
                pNewNode = pNewNode->next;
                indexToCopy.push_back(pNewNode);
            }
            else
            {
                pCopy = new Node(pCurrent->val);
                pNewNode = pCopy;
                indexToCopy.push_back(pNewNode);
            }
            ++index;
        }

        Node* pCurrentCopy = pCopy;
        for (Node* pCurrent = head; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            if (nullptr != pCurrent->random)
            {
                const auto index = headToIndex.at(pCurrent->random);
                pCurrentCopy->random = indexToCopy.at(index);
            }
            pCurrentCopy = pCurrentCopy->next;
        }

        return pCopy;
    }
};
*/

// NOTE: Somehow runtime is little bit slower. But now it is 15 mb, and not 15.3 mb!
class Solution
{
public:

    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        // Merge old list with new list by rule: 
        //     OldNode -> NewNode -> OldNode -> NewNode ...
        for (Node* pCurrent = head; nullptr != pCurrent;)
        {
            Node* pNewNode = new Node(pCurrent->val);
            pNewNode->next = pCurrent->next;
            pCurrent->next = pNewNode;
            pCurrent = pNewNode->next;
        }

        // Iterate only through OldNode: OldNode -> NewNode -> OldNode -> NewNode ...
        // And move all random pointers from where they pointing to next element
        for (Node* pCurrent = head; nullptr != pCurrent; pCurrent = pCurrent->next->next)
        {
            if (nullptr != pCurrent->random)
            {
                pCurrent->next->random = pCurrent->random->next;
            }
        }

        // Move 1 step forward for list like:
        //     NewNode -> OldNode -> NewNode ...
        Node* pNewHead = head->next;

        // Separates all nodes in two lists head:     OldNode -> OldNode ...
        //                                  pNewHead: NewNode -> NewNode ...
        for (Node* pCurrent = head; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            Node* pNewNode = pCurrent->next;
            pCurrent->next = pNewNode->next;
            if (nullptr != pNewNode->next)
            {
                pNewNode->next = pNewNode->next->next;
            }
        }

        // This solution is absolute cinema!
        return pNewHead;
    }
};

TEST (SolutionTest, Example1)
{

    // 7 -> 13 -> 11 -> 10 -> 1
    auto node5 = std::make_unique<Node>(1, nullptr);  
    auto node4 = std::make_unique<Node>(10, node5.get()); 
    auto node3 = std::make_unique<Node>(11, node4.get()); 
    auto node2 = std::make_unique<Node>(13, node3.get()); 
    auto node1 = std::make_unique<Node>(7, node2.get()); 
    
    node1->random = nullptr;
    node2->random = node1.get();
    node3->random = node5.get();
    node4->random = node3.get();
    node5->random = node1.get();

    int iterCount = 0;
    auto pBasicList = node1.get();
    const auto pCopiedList = Solution{}.copyRandomList(node1.get());
    for (Node* pCurrent = pCopiedList; nullptr != pCurrent; pCurrent = pCurrent->next)
    {
        EXPECT_NE(static_cast<void*>(pCurrent), static_cast<void*>(pBasicList));

        EXPECT_EQ(pCurrent->val, pBasicList->val);
        
        if (nullptr == pCurrent->random)
        {
            EXPECT_EQ(nullptr, pCurrent->random);
            EXPECT_EQ(nullptr, pBasicList->random);
        }
        else
        {
            EXPECT_EQ(pCurrent->random->val, pBasicList->random->val);
        }

        pBasicList = pBasicList->next;
        ++iterCount;
    }
    EXPECT_EQ(5, iterCount);
}

TEST (SolutionTest, Example2)
{

    // 1 -> 2
    auto node2 = std::make_unique<Node>(2, nullptr); 
    auto node1 = std::make_unique<Node>(1, node2.get()); 
    
    node1->random = node2.get();
    node2->random = node2.get();

    int iterCount = 0;
    auto pBasicList = node1.get();
    const auto pCopiedList = Solution{}.copyRandomList(node1.get());
    for (Node* pCurrent = pCopiedList; nullptr != pCurrent; pCurrent = pCurrent->next)
    {
        EXPECT_NE(static_cast<void*>(pCurrent), static_cast<void*>(pBasicList));

        EXPECT_EQ(pCurrent->val, pBasicList->val);
        
        if (nullptr == pCurrent->random)
        {
            EXPECT_EQ(nullptr, pCurrent->random);
            EXPECT_EQ(nullptr, pBasicList->random);
        }
        else
        {
            EXPECT_EQ(pCurrent->random->val, pBasicList->random->val);
        }

        pBasicList = pBasicList->next;
        ++iterCount;
    }
    EXPECT_EQ(2, iterCount);
}

TEST (SolutionTest, Example3)
{
    // 3 -> 3 -> 3
    auto node3 = std::make_unique<Node>(3, nullptr); 
    auto node2 = std::make_unique<Node>(3, node3.get()); 
    auto node1 = std::make_unique<Node>(3, node2.get()); 
    
    node1->random = nullptr;
    node2->random = node1.get();
    node3->random = nullptr;

    int iterCount = 0;
    auto pBasicList = node1.get();
    const auto pCopiedList = Solution{}.copyRandomList(node1.get());
    for (Node* pCurrent = pCopiedList; nullptr != pCurrent; pCurrent = pCurrent->next)
    {
        EXPECT_NE(static_cast<void*>(pCurrent), static_cast<void*>(pBasicList));

        EXPECT_EQ(pCurrent->val, pBasicList->val);
        
        if (nullptr == pCurrent->random)
        {
            EXPECT_EQ(nullptr, pCurrent->random);
            EXPECT_EQ(nullptr, pBasicList->random);
        }
        else
        {
            EXPECT_EQ(pCurrent->random->val, pBasicList->random->val);
        }

        pBasicList = pBasicList->next;
        ++iterCount;
    }
    EXPECT_EQ(3, iterCount);
}

TEST (SolutionTest, Example5)
{
    // 3 -> 7 -> 4 -> 5
    auto node4 = std::make_unique<Node>(5, nullptr); 
    auto node3 = std::make_unique<Node>(4, node4.get()); 
    auto node2 = std::make_unique<Node>(7, node3.get()); 
    auto node1 = std::make_unique<Node>(3, node2.get()); 
    
    node1->random = nullptr;
    node2->random = node4.get();
    node3->random = node1.get();
    node4->random = node2.get();

    int iterCount = 0;
    auto pBasicList = node1.get();
    const auto pCopiedList = Solution{}.copyRandomList(node1.get());
    for (Node* pCurrent = pCopiedList; nullptr != pCurrent; pCurrent = pCurrent->next)
    {
        EXPECT_NE(static_cast<void*>(pCurrent), static_cast<void*>(pBasicList));

        EXPECT_EQ(pCurrent->val, pBasicList->val);
        
        if (nullptr == pCurrent->random)
        {
            EXPECT_EQ(nullptr, pCurrent->random);
            EXPECT_EQ(nullptr, pBasicList->random);
        }
        else
        {
            EXPECT_EQ(pCurrent->random->val, pBasicList->random->val);
        }

        pBasicList = pBasicList->next;
        ++iterCount;
    }
    EXPECT_EQ(4, iterCount);
}

TEST (SolutionTest, Example6)
{
    // 1 -> 2 -> 3
    auto node3 = std::make_unique<Node>(3, nullptr); 
    auto node2 = std::make_unique<Node>(2, node3.get()); 
    auto node1 = std::make_unique<Node>(1, node2.get()); 
    
    node1->random = nullptr;
    node2->random = node2.get();
    node3->random = node2.get();

    int iterCount = 0;
    auto pBasicList = node1.get();
    const auto pCopiedList = Solution{}.copyRandomList(node1.get());
    for (Node* pCurrent = pCopiedList; nullptr != pCurrent; pCurrent = pCurrent->next)
    {
        EXPECT_NE(static_cast<void*>(pCurrent), static_cast<void*>(pBasicList));

        EXPECT_EQ(pCurrent->val, pBasicList->val);
        
        if (nullptr == pCurrent->random)
        {
            EXPECT_EQ(nullptr, pCurrent->random);
            EXPECT_EQ(nullptr, pBasicList->random);
        }
        else
        {
            EXPECT_EQ(pCurrent->random->val, pBasicList->random->val);
        }

        pBasicList = pBasicList->next;
        ++iterCount;
    }
    EXPECT_EQ(3, iterCount);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
