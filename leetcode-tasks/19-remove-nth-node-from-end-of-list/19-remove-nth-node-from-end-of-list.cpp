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
    
    ListNode* removeNthFromEnd(ListNode* pHead, int n)
    {
        int index = 1;
        ListNode* pSlower = nullptr;
        ListNode* pPrevious = nullptr;
        for (ListNode* pCurrent = pHead; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            if (index > n)
            {
                pPrevious = pSlower;
                pSlower = pSlower->next;
            }
            else if (index == n)
            {
                pSlower = pHead;
            }
            ++index;
        }

        if (nullptr != pPrevious)
        {
            ListNode* pNext = pSlower->next;
            pPrevious->next = pNext;
            pSlower->next = nullptr;
            // NOTE: Comment out deletes in LeetCode
            // delete pSlower;
        }
        else
        {
            pHead = pSlower->next;
            // delete pSlower;
        }

        return pHead;
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
        1, 2, 3, 5
    };
    const int n = 2;
    ListNode* pHead = Solution{}.removeNthFromEnd(node1.get(), n);

    std::vector<int> result;
    for (ListNode* pCurrentNode = pHead; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto node1 = std::make_unique<ListNode>(1, nullptr); 
    
    const int n = 1;
    ListNode* pHead = Solution{}.removeNthFromEnd(node1.get(), n);

    EXPECT_EQ(nullptr, pHead);
}

TEST (SolutionTest, Example3)
{
    auto node2 = std::make_unique<ListNode>(2, nullptr); 
    auto node1 = std::make_unique<ListNode>(1, node2.get()); 
    
    std::vector<int> expected{
        1
    };
    const int n = 1;
    ListNode* pHead = Solution{}.removeNthFromEnd(node1.get(), n);

    std::vector<int> result;
    for (ListNode* pCurrentNode = pHead; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto node2 = std::make_unique<ListNode>(2, nullptr); 
    auto node1 = std::make_unique<ListNode>(1, node2.get()); 
    
    std::vector<int> expected{
        2
    };
    const int n = 2;
    ListNode* pHead = Solution{}.removeNthFromEnd(node1.get(), n);

    std::vector<int> result;
    for (ListNode* pCurrentNode = pHead; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
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
