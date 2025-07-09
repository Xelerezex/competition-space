#include <gtest/gtest.h>
#include <memory>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr)
    {
    }
    ListNode(int x)
        : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x), next(next)
    {
    }
};

/*
// NOTE: Regular cycle solution
class Solution
{
public:

    ListNode* reverseList(ListNode* pHead)
    {
        if (pHead == nullptr)
        {
            return nullptr;
        }

        ListNode* pPreviousNode = nullptr;
        ListNode* pCurrentNode = pHead;

        while (pCurrentNode != nullptr)
        {
            // Save pointer to next
            ListNode* pNextNode = pCurrentNode->next;

            // Switch pointers
            pCurrentNode->next = pPreviousNode;
            pPreviousNode = pCurrentNode;

            // Next iteration
            pCurrentNode = pNextNode;
        }

        return pPreviousNode;
    };

};
*/

// NOTE: recursive solution
class Solution
{
public:

    ListNode* reverseList(ListNode* pHead)
    {
        if (nullptr == pHead)
        {
            return nullptr;
        }

        ListNode* pNewHead = pHead;
        if (nullptr != pHead->next)
        {
            pNewHead = reverseList(pHead->next);
            pHead->next->next = pHead;
        }
        pHead->next = nullptr;

        return pNewHead;
    };
};

TEST(SolutionTest, Example1)
{
    auto node4 = std::make_unique<ListNode>(3, nullptr);
    auto node3 = std::make_unique<ListNode>(2, node4.get());
    auto node2 = std::make_unique<ListNode>(1, node3.get());
    auto node1 = std::make_unique<ListNode>(0, node2.get());
    std::vector<ListNode*> reverseDirection;
    reverseDirection.push_back(node4.get());
    reverseDirection.push_back(node3.get());
    reverseDirection.push_back(node2.get());
    reverseDirection.push_back(node1.get());

    auto pResult = Solution{}.reverseList(node1.get());
    int indexCounter = 0;

    auto pCurrentNode = pResult;
    while (nullptr != pCurrentNode)
    {
        EXPECT_EQ(reverseDirection[indexCounter++], pCurrentNode);

        pCurrentNode = pCurrentNode->next;
    }
}

TEST(SolutionTest, Example2)
{
    auto node2 = std::make_unique<ListNode>(2, nullptr);
    auto node1 = std::make_unique<ListNode>(1, node2.get());
    std::vector<ListNode*> reverseDirection;
    reverseDirection.push_back(node2.get());
    reverseDirection.push_back(node1.get());

    auto pResult = Solution{}.reverseList(node1.get());
    int indexCounter = 0;

    auto pCurrentNode = pResult;
    while (nullptr != pCurrentNode)
    {
        EXPECT_EQ(reverseDirection[indexCounter++], pCurrentNode);

        pCurrentNode = pCurrentNode->next;
    }
}

TEST(SolutionTest, Example3)
{
    auto node1 = std::make_unique<ListNode>(1, nullptr);
    std::vector<ListNode*> reverseDirection;
    reverseDirection.push_back(node1.get());

    auto pResult = Solution{}.reverseList(node1.get());
    int indexCounter = 0;

    auto pCurrentNode = pResult;
    while (nullptr != pCurrentNode)
    {
        EXPECT_EQ(reverseDirection[indexCounter++], pCurrentNode);

        pCurrentNode = pCurrentNode->next;
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
