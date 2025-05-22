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

// NOTE: My solution that was accepted
/*
class Solution
{

public:
    
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* pLeftNode = head;
    
        // ListNode* pPreviousLeft = nullptr;
        ListNode* pPreviousRight = nullptr;

        for (ListNode* pRightNode = head; nullptr != pRightNode; pRightNode = pRightNode->next)
        {
            if (pLeftNode != pRightNode 
                && pRightNode->val < x
            )
            {
                // remove element right
                ListNode* pNextRight = pRightNode->next;
                pPreviousRight->next = pNextRight;

                // Insert element right
                if (pLeftNode->val < x)
                {
                    ListNode* pNextLeft = pLeftNode->next;
                    pLeftNode->next = pRightNode;
                    pRightNode->next = pNextLeft;

                    // Left node to inserted value
                    pLeftNode = pRightNode;
                }
                else
                {
                    pRightNode->next = pLeftNode;
                    pLeftNode = pRightNode;

                    head = pLeftNode;
                }

                // Right go to previous element
                pRightNode = pPreviousRight;
            }
            pPreviousRight = pRightNode;
        }

        return head;
    }
};
*/

// NOTE: Pretier solution. Main idea that we creat two separate list.
//       one [all values < x], other [all values >= x]
//       then we concatenate that lists
class Solution
{

public:
    
    ListNode* partition(ListNode* head, int x)
    {
        ListNode leftHead(0, nullptr);
        ListNode rightHead(0, nullptr);

        ListNode* pLeftNode = &leftHead;
        ListNode* pRightNode = &rightHead;
    
        for (; nullptr != head; head = head->next)
        {
            if (head->val < x)
            {
                pLeftNode->next = head;
                pLeftNode = pLeftNode->next;
            }
            else 
            {
                pRightNode->next = head;
                pRightNode = pRightNode->next;
            }
        }

        pLeftNode->next = rightHead.next;
        // Prevent cycling
        pRightNode->next = nullptr;

        return leftHead.next;
    }
};

TEST (SolutionTest, Example1)
{
    auto node6 = std::make_unique<ListNode>(2, nullptr);     // 2
    auto node5 = std::make_unique<ListNode>(5, node6.get()); // 5
    auto node4 = std::make_unique<ListNode>(2, node5.get()); // 2
    auto node3 = std::make_unique<ListNode>(3, node4.get()); // 3
    auto node2 = std::make_unique<ListNode>(4, node3.get()); // 4
    auto node1 = std::make_unique<ListNode>(1, node2.get()); // 1
    
    std::vector<int> expected{
        1, 2, 2, 4, 3, 5
    };
    const int x = 3;
    auto pResult = Solution{}.partition(node1.get(), x);
    std::vector<int> result;
    for (ListNode* pCurrentNode = pResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto node2 = std::make_unique<ListNode>(1, nullptr);     // 1
    auto node1 = std::make_unique<ListNode>(2, node2.get()); // 2
    
    std::vector<int> expected{
        1, 2
    };
    const int x = 2;
    auto pResult = Solution{}.partition(node1.get(), x);
    std::vector<int> result;
    for (ListNode* pCurrentNode = pResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto node5 = std::make_unique<ListNode>(1, nullptr);     // 1
    auto node4 = std::make_unique<ListNode>(2, node5.get()); // 2
    auto node3 = std::make_unique<ListNode>(3, node4.get()); // 3
    auto node2 = std::make_unique<ListNode>(4, node3.get()); // 4
    auto node1 = std::make_unique<ListNode>(5, node2.get()); // 5
    
    std::vector<int> expected{
        2, 1, 5, 4, 3
    };
    const int x = 3;
    auto pResult = Solution{}.partition(node1.get(), x);
    std::vector<int> result;
    for (ListNode* pCurrentNode = pResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto node4 = std::make_unique<ListNode>(2, nullptr);     // 2
    auto node3 = std::make_unique<ListNode>(1, node4.get()); // 1
    auto node2 = std::make_unique<ListNode>(4, node3.get()); // 4
    auto node1 = std::make_unique<ListNode>(3, node2.get()); // 3
    
    std::vector<int> expected{
        3, 1, 2, 4
    };
    const int x = 4;
    auto pResult = Solution{}.partition(node1.get(), x);
    std::vector<int> result;
    for (ListNode* pCurrentNode = pResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto node6 = std::make_unique<ListNode>(2, nullptr);     // 2
    auto node5 = std::make_unique<ListNode>(1, node6.get()); // 1
    auto node4 = std::make_unique<ListNode>(4, node5.get()); // 4
    auto node3 = std::make_unique<ListNode>(5, node4.get()); // 5
    auto node2 = std::make_unique<ListNode>(6, node3.get()); // 6
    auto node1 = std::make_unique<ListNode>(3, node2.get()); // 3
    
    std::vector<int> expected{
        3, 1, 2, 6, 5, 4
    };
    const int x = 4;
    auto pResult = Solution{}.partition(node1.get(), x);
    std::vector<int> result;
    for (ListNode* pCurrentNode = pResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example6)
{
    auto node8 = std::make_unique<ListNode>(2, nullptr);     // 2
    auto node7 = std::make_unique<ListNode>(7, node8.get()); // 7
    auto node6 = std::make_unique<ListNode>(1, node7.get()); // 1
    auto node5 = std::make_unique<ListNode>(8, node6.get()); // 8
    auto node4 = std::make_unique<ListNode>(4, node5.get()); // 4
    auto node3 = std::make_unique<ListNode>(5, node4.get()); // 5
    auto node2 = std::make_unique<ListNode>(6, node3.get()); // 6
    auto node1 = std::make_unique<ListNode>(3, node2.get()); // 3
    
    std::vector<int> expected{
        3, 1, 2, 6, 5, 4, 8, 7
    };
    const int x = 4;
    auto pResult = Solution{}.partition(node1.get(), x);
    std::vector<int> result;
    for (ListNode* pCurrentNode = pResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
