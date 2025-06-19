#include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode* pHead)
    {
        ListNode* pFast = pHead;
        ListNode* pSlow = pHead;

        // Find middle
        while (nullptr != pFast && nullptr != pFast->next)
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        
        // Reorder right part
        ListNode* pPrevious = nullptr;
        for (ListNode* pCurrent = pSlow; nullptr != pCurrent;)
        {
            ListNode* pNext = pCurrent->next;
            pCurrent->next = pPrevious;
            pPrevious = pCurrent;
            pCurrent = pNext;
        }

        // Insert reordered
        ListNode* pReorderedHead = pPrevious;
        for (ListNode* pCurrent = pHead; nullptr != pCurrent;)
        {
            ListNode* pNext = pCurrent->next;
            ListNode* pNextReordered = pReorderedHead->next;

            if (
                nullptr != pNext 
                && nullptr != pNextReordered 
                && pCurrent != pReorderedHead
            )
            {
                pCurrent->next = pReorderedHead;
                pReorderedHead->next = pNext;
            }
            
            pCurrent = pNext;
            pReorderedHead = pNextReordered;

            if (nullptr == pReorderedHead)
            {
                return;
            }
        }
    }
};

TEST (SolutionTest, Example1)
{
    auto node5 = std::make_unique<ListNode>(5, nullptr);  
    auto node4 = std::make_unique<ListNode>(4, node5.get()); 
    auto node3 = std::make_unique<ListNode>(3, node4.get()); 
    auto node2 = std::make_unique<ListNode>(2, node3.get()); 
    auto node1 = std::make_unique<ListNode>(1, node2.get()); 
    
    std::vector<int> expected{
        1, 5, 2, 4, 3
    };
    
    Solution{}.reorderList(node1.get());

    std::vector<int> result;
    for (ListNode* pCurrentNode = node1.get(); nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto node6 = std::make_unique<ListNode>(6, nullptr);  
    auto node5 = std::make_unique<ListNode>(5, node6.get());  
    auto node4 = std::make_unique<ListNode>(4, node5.get()); 
    auto node3 = std::make_unique<ListNode>(3, node4.get()); 
    auto node2 = std::make_unique<ListNode>(2, node3.get()); 
    auto node1 = std::make_unique<ListNode>(1, node2.get()); 
    
    std::vector<int> expected{
        1, 6, 2, 5, 3, 4
    };
    
    Solution{}.reorderList(node1.get());

    std::vector<int> result;
    for (ListNode* pCurrentNode = node1.get(); nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
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
