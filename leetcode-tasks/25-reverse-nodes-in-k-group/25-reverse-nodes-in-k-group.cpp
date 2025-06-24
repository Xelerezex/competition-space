#include <gtest/gtest.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:

    std::pair<ListNode*, ListNode*> reverseLinkedList(ListNode* pHead)
    {
        ListNode* pNewHead = nullptr;
        ListNode* pNewTail = nullptr;
        
        for (ListNode* pCurrent = pHead; nullptr != pCurrent;)
        {
            // Save new tail
            pNewTail = (nullptr == pNewTail) ? pCurrent : pNewTail;

            // Reverse nodes
            ListNode* pNext = pCurrent->next;
            pCurrent->next = pNewHead;
            pNewHead = pCurrent;
            pCurrent = pNext;
        }

        return std::make_pair(pNewHead, pNewTail);
    }

    ListNode* reverseKGroup(ListNode* pHead, int k)
    {
        int counter = 0;
        ListNode* pResult = nullptr;
        ListNode* pHeadOfGroup = nullptr;
        ListNode* pPreviousGroup = nullptr;

        for (ListNode* pCurrent = pHead; nullptr != pCurrent;)
        {
            if (0 == counter)
            {
                pHeadOfGroup = pCurrent;
            }
            
            ++counter;

            // Save next
            ListNode* pNext = pCurrent->next;

            if (k == counter)
            {    
                // break links
                pCurrent->next = nullptr;

                // Reverse group
                auto [pNewHead, pNewTail] = reverseLinkedList(pHeadOfGroup);

                // Connect links
                if (nullptr != pPreviousGroup)
                {
                    pPreviousGroup->next = pNewHead;
                }
                if (nullptr != pNewTail)
                {
                    pNewTail->next = pNext;
                }

                // Once set up
                pResult = (nullptr == pResult) ? pNewHead : pResult;
                
                // Save end of previous group
                pPreviousGroup = pNewTail;

                // Discard counter
                counter = 0;
            }

            // Next iteration
            pCurrent = pNext;
        }

        return pResult;
    }
};

TEST (SolutionTest, CornerCase1)
{
    const int k = 1;

    auto node1 = std::make_unique<ListNode>(5, nullptr);

    auto pResult = Solution{}.reverseKGroup(node1.get(), k);
    std::vector<int> result;
    for (; nullptr != pResult; pResult = pResult->next)
    {
        result.push_back(pResult->val);
    }

    std::vector<int> expected{
        5
    };

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    const int k = 2;

    auto node5 = std::make_unique<ListNode>(5, nullptr); 
    auto node4 = std::make_unique<ListNode>(4, node5.get()); 
    auto node3 = std::make_unique<ListNode>(3, node4.get()); 
    auto node2 = std::make_unique<ListNode>(2, node3.get()); 
    auto node1 = std::make_unique<ListNode>(1, node2.get());

    auto pResult = Solution{}.reverseKGroup(node1.get(), k);
    std::vector<int> result;
    for (; nullptr != pResult; pResult = pResult->next)
    {
        result.push_back(pResult->val);
    }

    std::vector<int> expected{
        2,1,4,3,5
    };

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    const int k = 3;

    auto node5 = std::make_unique<ListNode>(5, nullptr); 
    auto node4 = std::make_unique<ListNode>(4, node5.get()); 
    auto node3 = std::make_unique<ListNode>(3, node4.get()); 
    auto node2 = std::make_unique<ListNode>(2, node3.get()); 
    auto node1 = std::make_unique<ListNode>(1, node2.get());

    auto pResult = Solution{}.reverseKGroup(node1.get(), k);
    std::vector<int> result;
    for (; nullptr != pResult; pResult = pResult->next)
    {
        result.push_back(pResult->val);
    }

    std::vector<int> expected{
        3, 2, 1, 4, 5
    };

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    const int k = 3;

    auto node6 = std::make_unique<ListNode>(6, nullptr); 
    auto node5 = std::make_unique<ListNode>(5, node6.get()); 
    auto node4 = std::make_unique<ListNode>(4, node5.get()); 
    auto node3 = std::make_unique<ListNode>(3, node4.get()); 
    auto node2 = std::make_unique<ListNode>(2, node3.get()); 
    auto node1 = std::make_unique<ListNode>(1, node2.get());

    auto pResult = Solution{}.reverseKGroup(node1.get(), k);
    std::vector<int> result;
    for (; nullptr != pResult; pResult = pResult->next)
    {
        result.push_back(pResult->val);
    }

    std::vector<int> expected{
        3,2,1,6,5,4
    };

    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
