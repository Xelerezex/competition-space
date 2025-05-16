#include <gtest/gtest.h>


// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
// NOTE: My uglu solution that was accepted
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode* pHead = head;

        ListNode* pPrevious = head;
        for (ListNode* pCurrent = head->next; pCurrent != nullptr;)
        {
            if (val == pCurrent->val)
            {
                ListNode* pTemporary = pCurrent;
                pPrevious->next = pCurrent->next;
                //delete pTemporary;
                pCurrent = pCurrent->next;
            }
            else 
            {
                pPrevious = pCurrent;
                pCurrent = pCurrent->next;
            }
        }
        if (val == pHead->val)
        {
            if (nullptr == pHead->next)
            {
                return nullptr;
            }
            else 
            {
                pHead = pHead->next;
            }
            
        }

        return pHead;
    }
};
*/

// NOTE: Simple solution
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode pTemporary = ListNode(0, nullptr);
        pTemporary.next = head;
        ListNode* pCurrent = &pTemporary;

        while (nullptr != pCurrent->next)
        {
            if (val == pCurrent->next->val)
            {
                pCurrent->next = pCurrent->next->next;
            }
            else 
            {
                pCurrent = pCurrent->next;
            }
        }

        return pTemporary.next;
    }
};

TEST (SolutionTest, Example1)
{
    auto node7 = std::make_unique<ListNode>(6, nullptr);
    auto node6 = std::make_unique<ListNode>(5, node7.get());
    auto node5 = std::make_unique<ListNode>(4, node6.get());
    auto node4 = std::make_unique<ListNode>(3, node5.get());
    auto node3 = std::make_unique<ListNode>(6, node4.get());
    auto node2 = std::make_unique<ListNode>(2, node3.get());
    auto node1 = std::make_unique<ListNode>(1, node2.get());
    std::vector<ListNode*> reverseDirection;
    reverseDirection.push_back(node1.get()); // 1
    reverseDirection.push_back(node2.get()); // 2
    // reverseDirection.push_back(node3.get()); // deleted
    reverseDirection.push_back(node4.get()); // 3
    reverseDirection.push_back(node5.get()); // 4
    reverseDirection.push_back(node6.get()); // 5
    // reverseDirection.push_back(node7.get()); // deleted

    auto pResult = Solution{}.removeElements(node1.get(), 6);
    int indexCounter = 0;

    auto pCurrentNode = pResult;
    while (nullptr != pCurrentNode)
    {
        EXPECT_EQ(reverseDirection[indexCounter++]->val, pCurrentNode->val);
        pCurrentNode = pCurrentNode->next;
    }
}

TEST (SolutionTest, Example2)
{
    auto pResult = Solution{}.removeElements(nullptr, 1);
    EXPECT_EQ(pResult, nullptr);
}

TEST (SolutionTest, Example3)
{
    auto node4 = std::make_unique<ListNode>(7, nullptr);
    auto node3 = std::make_unique<ListNode>(7, node4.get());
    auto node2 = std::make_unique<ListNode>(7, node3.get());
    auto node1 = std::make_unique<ListNode>(7, node2.get());

    auto pResult = Solution{}.removeElements(node1.get(), 7);
    EXPECT_EQ(pResult, nullptr);
}


TEST (SolutionTest, Example4)
{
    auto node4 = std::make_unique<ListNode>(9, nullptr);
    auto node3 = std::make_unique<ListNode>(7, node4.get());
    auto node2 = std::make_unique<ListNode>(7, node3.get());
    auto node1 = std::make_unique<ListNode>(7, node2.get());

    auto pResult = Solution{}.removeElements(node1.get(), 7);
    EXPECT_EQ(pResult->val, 9);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
