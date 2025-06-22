#include <gtest/gtest.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// NOTE: Not so pretty? but good runtime. If I chose while()
//       then last if () { add additional note } should be gone
/*
class Solution
{
public:

    std::pair<ListNode*, std::size_t> reverseLinkedList(ListNode* pHead)
    {
        std::size_t length = 0;
        ListNode* pPrevious = nullptr;
        for (ListNode* pCurrent = pHead; nullptr != pCurrent;)
        {
            ListNode* pNext = pCurrent->next;
            pCurrent->next = pPrevious;
            pPrevious = pCurrent;
            pCurrent = pNext;
            ++length;
        }
        return std::make_pair(pPrevious, length);
    }

    std::size_t linkedListLength(ListNode* pHead)
    {
        std::size_t length = 0;
        for (ListNode* pCurrent = pHead; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            ++length;
        }
        return length;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        //const auto [pFirstReversed, firstLength] = reverseLinkedList(l1);
        const auto firstLength = linkedListLength(l1);

        //const auto [pSecondReversed, secondLength] = reverseLinkedList(l2);
        const auto secondLength = linkedListLength(l2);

        ListNode* pNewNode = nullptr;
        ListNode* pCurrentNewNode = nullptr;
        ListNode* pAdditionalNode = new ListNode( 0 );

        ListNode* pMaxLenthList = firstLength > secondLength 
            ? l1 
            : l2;
        ListNode* pMinLenthList = firstLength <= secondLength 
            ? l1 
            : l2;

        int additionalOne = 0;
        for (ListNode* pCurrent = pMaxLenthList; nullptr != pCurrent; pCurrent = pCurrent->next)
        {
            // Count sum
            const int firstValue = pCurrent->val;
            const int secondValue = nullptr == pMinLenthList
                ? 0
                : pMinLenthList->val;

            const bool hasTwoDigits = (firstValue + secondValue + additionalOne) > 9;

            const int currentSum = hasTwoDigits
                ? ((firstValue + secondValue + additionalOne) % 10)
                : (firstValue + secondValue + additionalOne);

            // Create new node 
            // NOTE: ListNode Dummy needed for get rid of that if else
            if (nullptr != pNewNode)
            {
                pCurrentNewNode->next = new ListNode(currentSum);
                pCurrentNewNode = pCurrentNewNode->next;
            }
            else 
            {
                pNewNode = new ListNode(currentSum);
                pCurrentNewNode = pNewNode;
            }

            if (nullptr != pMinLenthList)
            {
                pMinLenthList = pMinLenthList->next;
            }

            additionalOne = hasTwoDigits ? 1 : 0;
            if (1 == additionalOne)
            {
                pAdditionalNode->val = 1;
            }
        }

        if (1 == additionalOne)
        {
            pCurrentNewNode->next = pAdditionalNode;
        }
        else 
        {
            delete pAdditionalNode;
            pAdditionalNode = nullptr;
        }

        if (nullptr == pNewNode)
        {
            pNewNode = new ListNode( 0 );
        }
        return pNewNode;
    }
};
*/

// NOTE: Still 100 % beats in runtime. But better for memory solution
class Solution
{
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* pDummy = new ListNode(0);
        ListNode* pCurrentNode = pDummy;

        int carry = 0;

        while (nullptr != l1
            || nullptr != l2
            || 0 != carry
        )
        {
            int firstValue = (nullptr == l1) ? 0 : l1->val;
            int secondValue = (nullptr == l2) ? 0 : l2->val;

            // 1 or 2 digit number
            int sum = firstValue + secondValue + carry;
            // For next iteration
            carry = sum / 10;
            // Value to write
            sum = sum % 10;

            pCurrentNode->next = new ListNode(sum);
            pCurrentNode = pCurrentNode->next;

            l1 = (l1 == nullptr) ? nullptr : l1->next; 
            l2 = (l2 == nullptr) ? nullptr : l2->next; 
        }

        // Clear Dummy
        ListNode* result = pDummy->next;
        delete pDummy;
        
        return result;
    }
};

TEST (SolutionTest, CaseCorner2)
{
    auto node1_1 = std::make_unique<ListNode>(9, nullptr); 
    
    auto node10_2 = std::make_unique<ListNode>(9, nullptr); 
    auto node9_2 = std::make_unique<ListNode>(9, node10_2.get()); 
    auto node8_2 = std::make_unique<ListNode>(9, node9_2.get()); 
    auto node7_2 = std::make_unique<ListNode>(9, node8_2.get()); 
    auto node6_2 = std::make_unique<ListNode>(9, node7_2.get()); 
    auto node5_2 = std::make_unique<ListNode>(9, node6_2.get()); 
    auto node4_2 = std::make_unique<ListNode>(9, node5_2.get()); 
    auto node3_2 = std::make_unique<ListNode>(9, node4_2.get()); 
    auto node2_2 = std::make_unique<ListNode>(9, node3_2.get()); 
    auto node1_2 = std::make_unique<ListNode>(1, node2_2.get());

    const auto pHeadResult = Solution{}.addTwoNumbers(node1_1.get(), node1_2.get());

    std::vector<int> expected{
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
    };
    std::vector<int> result;
    for (ListNode* pCurrentNode = pHeadResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, CaseCorner1)
{
    auto node31_1 = std::make_unique<ListNode>(1, nullptr); 
    auto node30_1 = std::make_unique<ListNode>(0, node31_1.get()); 
    auto node29_1 = std::make_unique<ListNode>(0, node30_1.get()); 
    auto node28_1 = std::make_unique<ListNode>(0, node29_1.get()); 
    auto node27_1 = std::make_unique<ListNode>(0, node28_1.get()); 
    auto node26_1 = std::make_unique<ListNode>(0, node27_1.get()); 
    auto node25_1 = std::make_unique<ListNode>(0, node26_1.get()); 
    auto node24_1 = std::make_unique<ListNode>(0, node25_1.get()); 
    auto node23_1 = std::make_unique<ListNode>(0, node24_1.get()); 
    auto node22_1 = std::make_unique<ListNode>(0, node23_1.get()); 
    auto node21_1 = std::make_unique<ListNode>(0, node22_1.get()); 
    auto node20_1 = std::make_unique<ListNode>(0, node21_1.get()); 
    auto node19_1 = std::make_unique<ListNode>(0, node20_1.get()); 
    auto node18_1 = std::make_unique<ListNode>(0, node19_1.get()); 
    auto node17_1 = std::make_unique<ListNode>(0, node18_1.get()); 
    auto node16_1 = std::make_unique<ListNode>(0, node17_1.get()); 
    auto node15_1 = std::make_unique<ListNode>(0, node16_1.get()); 
    auto node14_1 = std::make_unique<ListNode>(0, node15_1.get()); 
    auto node13_1 = std::make_unique<ListNode>(0, node14_1.get()); 
    auto node12_1 = std::make_unique<ListNode>(0, node13_1.get()); 
    auto node11_1 = std::make_unique<ListNode>(0, node12_1.get()); 
    auto node10_1 = std::make_unique<ListNode>(0, node11_1.get()); 
    auto node9_1 = std::make_unique<ListNode>(0, node10_1.get()); 
    auto node8_1 = std::make_unique<ListNode>(0, node9_1.get()); 
    auto node7_1 = std::make_unique<ListNode>(0, node8_1.get()); 
    auto node6_1 = std::make_unique<ListNode>(0, node7_1.get()); 
    auto node5_1 = std::make_unique<ListNode>(0, node6_1.get()); 
    auto node4_1 = std::make_unique<ListNode>(0, node5_1.get()); 
    auto node3_1 = std::make_unique<ListNode>(0, node4_1.get()); 
    auto node2_1 = std::make_unique<ListNode>(0, node3_1.get()); 
    auto node1_1 = std::make_unique<ListNode>(1, node2_1.get());

    auto node3_2 = std::make_unique<ListNode>(4, nullptr); 
    auto node2_2 = std::make_unique<ListNode>(6, node3_2.get()); 
    auto node1_2 = std::make_unique<ListNode>(5, node2_2.get()); 

    const auto pHeadResult = Solution{}.addTwoNumbers(node1_1.get(), node1_2.get());

    std::vector<int> expected{
        6,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
    };
    std::vector<int> result;
    for (ListNode* pCurrentNode = pHeadResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example1)
{
    auto node3_1 = std::make_unique<ListNode>(3, nullptr); 
    auto node2_1 = std::make_unique<ListNode>(4, node3_1.get()); 
    auto node1_1 = std::make_unique<ListNode>(2, node2_1.get()); 
    
    auto node3_2 = std::make_unique<ListNode>(4, nullptr); 
    auto node2_2 = std::make_unique<ListNode>(6, node3_2.get()); 
    auto node1_2 = std::make_unique<ListNode>(5, node2_2.get());

    const auto pHeadResult = Solution{}.addTwoNumbers(node1_1.get(), node1_2.get());

    std::vector<int> expected{
        7, 0, 8
    };
    std::vector<int> result;
    for (ListNode* pCurrentNode = pHeadResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    auto node7_1 = std::make_unique<ListNode>(9, nullptr); 
    auto node6_1 = std::make_unique<ListNode>(9, node7_1.get()); 
    auto node5_1 = std::make_unique<ListNode>(9, node6_1.get()); 
    auto node4_1 = std::make_unique<ListNode>(9, node5_1.get()); 
    auto node3_1 = std::make_unique<ListNode>(9, node4_1.get()); 
    auto node2_1 = std::make_unique<ListNode>(9, node3_1.get()); 
    auto node1_1 = std::make_unique<ListNode>(9, node2_1.get());
    
    auto node4_2 = std::make_unique<ListNode>(9,nullptr); 
    auto node3_2 = std::make_unique<ListNode>(9, node4_2.get()); 
    auto node2_2 = std::make_unique<ListNode>(9, node3_2.get()); 
    auto node1_2 = std::make_unique<ListNode>(9, node2_2.get());

    const auto pHeadResult = Solution{}.addTwoNumbers(node1_1.get(), node1_2.get());

    std::vector<int> expected{
        8, 9, 9, 9, 0, 0, 0, 1
    };
    std::vector<int> result;
    for (ListNode* pCurrentNode = pHeadResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    auto node1_1 = std::make_unique<ListNode>(0, nullptr); 
    
    auto node1_2 = std::make_unique<ListNode>(0, nullptr);

    const auto pHeadResult = Solution{}.addTwoNumbers(node1_1.get(), node1_2.get());

    std::vector<int> expected{
        0
    };
    std::vector<int> result;
    for (ListNode* pCurrentNode = pHeadResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto node3_1 = std::make_unique<ListNode>(3, nullptr); 
    auto node2_1 = std::make_unique<ListNode>(2, node3_1.get()); 
    auto node1_1 = std::make_unique<ListNode>(1, node2_1.get()); 
    
    auto node3_2 = std::make_unique<ListNode>(6, nullptr); 
    auto node2_2 = std::make_unique<ListNode>(5, node3_2.get()); 
    auto node1_2 = std::make_unique<ListNode>(4, node2_2.get());

    const auto pHeadResult = Solution{}.addTwoNumbers(node1_1.get(), node1_2.get());

    std::vector<int> expected{
        5, 7, 9
    };
    std::vector<int> result;
    for (ListNode* pCurrentNode = pHeadResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
    {
        result.push_back(pCurrentNode->val);
    }

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example5)
{
    auto node1_1 = std::make_unique<ListNode>(9, nullptr); 
    
    auto node1_2 = std::make_unique<ListNode>(9, nullptr);

    const auto pHeadResult = Solution{}.addTwoNumbers(node1_1.get(), node1_2.get());

    std::vector<int> expected{
        8, 1
    };
    std::vector<int> result;
    for (ListNode* pCurrentNode = pHeadResult; nullptr != pCurrentNode; pCurrentNode = pCurrentNode->next)
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
