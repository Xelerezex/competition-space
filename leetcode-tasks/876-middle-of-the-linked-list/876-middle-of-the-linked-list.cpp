#include <cmath>
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
// NOTE: My solution
class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        int elementCounter = 0;
        for (auto* pCurrentNode = head; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
        {
           elementCounter++;
        }

        const double delimiter = 2;
        int middleElement = (elementCounter % 2 == 0) 
            ? static_cast<int>(static_cast<double>(elementCounter) / delimiter) + 1
            : static_cast<int>(std::ceil(static_cast<double>(elementCounter) / delimiter));

        elementCounter = 0;
        for (auto* pCurrentNode = head; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
        {
            elementCounter++;
            if (middleElement == elementCounter)
            {
                return pCurrentNode;
            }
        }

        return nullptr;
    }
};
*/

// Faster solution
class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* pSlow = head;
        ListNode* pFast = head;
        
        while (nullptr != pFast && nullptr != pFast->next)
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        return pSlow;
    }
};

TEST (SolutionTest, Example1)
{
    auto node7 = std::make_unique<ListNode>(6, nullptr);
    auto node6 = std::make_unique<ListNode>(5, node7.get());
    auto node5 = std::make_unique<ListNode>(4, node6.get());
    auto node4 = std::make_unique<ListNode>(3, node5.get()); // <-
    auto node3 = std::make_unique<ListNode>(6, node4.get());
    auto node2 = std::make_unique<ListNode>(2, node3.get());
    auto node1 = std::make_unique<ListNode>(1, node2.get());

    auto pResult = Solution{}.middleNode(node1.get());
    EXPECT_EQ(3, pResult->val);
}

TEST (SolutionTest, Example2)
{
    auto node5 = std::make_unique<ListNode>(5, nullptr);
    auto node4 = std::make_unique<ListNode>(4, node5.get());
    auto node3 = std::make_unique<ListNode>(3, node4.get()); // <-
    auto node2 = std::make_unique<ListNode>(2, node3.get());
    auto node1 = std::make_unique<ListNode>(1, node2.get());

    auto pResult = Solution{}.middleNode(node1.get());
    EXPECT_EQ(3, pResult->val);
}

TEST (SolutionTest, Example3)
{
    auto node6 = std::make_unique<ListNode>(6, nullptr);
    auto node5 = std::make_unique<ListNode>(5, node6.get());
    auto node4 = std::make_unique<ListNode>(4, node5.get()); // <-
    auto node3 = std::make_unique<ListNode>(3, node4.get());
    auto node2 = std::make_unique<ListNode>(2, node3.get());
    auto node1 = std::make_unique<ListNode>(1, node2.get());

    auto pResult = Solution{}.middleNode(node1.get());
    EXPECT_EQ(4, pResult->val);
}

TEST (SolutionTest, Example4)
{
    auto node1 = std::make_unique<ListNode>(9, nullptr); // <-

    auto pResult = Solution{}.middleNode(node1.get());
    EXPECT_EQ(9, pResult->val);
}

TEST (SolutionTest, Example5)
{
    auto node2 = std::make_unique<ListNode>(20, nullptr); // <-
    auto node1 = std::make_unique<ListNode>(10, node2.get());

    auto pResult = Solution{}.middleNode(node1.get());
    EXPECT_EQ(20, pResult->val);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
