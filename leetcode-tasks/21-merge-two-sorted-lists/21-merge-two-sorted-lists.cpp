#include <gtest/gtest.h>
#include <limits>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:

    ListNode* mergeTwoLists(ListNode* pList1, ListNode* pList2)
    {
        ListNode pHead(0, nullptr);
        ListNode* pHeadMergedList = &pHead;

        while (pList1 != nullptr || pList2 != nullptr)
        {
            int firstValue = pList1 != nullptr ? pList1->val : std::numeric_limits<int>::max();
            int secondValue = pList2 != nullptr ? pList2->val : std::numeric_limits<int>::max();

            if (firstValue < secondValue)
            {
                if (pList1 != nullptr)
                {
                    pHeadMergedList->next = pList1;
                    pList1 = pList1->next;
                }
            }
            else
            {
                if (pList2 != nullptr)
                {
                    pHeadMergedList->next = pList2;
                    pList2 = pList2->next;
                }
            }

            pHeadMergedList = pHeadMergedList->next;
        }

        return pHead.next;
    }
};

TEST (SolutionTest, Example1)
{
    auto list1_node3 = std::make_unique<ListNode>(4, nullptr);
    auto list1_node2 = std::make_unique<ListNode>(2, list1_node3.get());
    auto list1_node1 = std::make_unique<ListNode>(1, list1_node2.get());
    
    auto list2_node3 = std::make_unique<ListNode>(4, nullptr);
    auto list2_node2 = std::make_unique<ListNode>(3, list2_node3.get());
    auto list2_node1 = std::make_unique<ListNode>(1, list2_node2.get());

    std::vector<ListNode*> sortedMergedLists;
    sortedMergedLists.push_back(list1_node1.get()); // 1
    sortedMergedLists.push_back(list2_node1.get()); // 1
    sortedMergedLists.push_back(list1_node2.get()); // 2
    sortedMergedLists.push_back(list2_node2.get()); // 3
    sortedMergedLists.push_back(list1_node3.get()); // 4
    sortedMergedLists.push_back(list2_node3.get()); // 4
    
    auto pResult = Solution{}.mergeTwoLists(list1_node1.get(), list2_node1.get());
    int indexCounter = 0;

    auto pCurrentNode = pResult;
    while (nullptr != pCurrentNode)
    {
        EXPECT_EQ(sortedMergedLists[indexCounter++]->val, pCurrentNode->val);
        // next iteration
        pCurrentNode = pCurrentNode->next;
    }
}

TEST (SolutionTest, Example2)
{
    auto list1_node3 = std::make_unique<ListNode>(4, nullptr);
    auto list1_node2 = std::make_unique<ListNode>(2, list1_node3.get());
    auto list1_node1 = std::make_unique<ListNode>(1, list1_node2.get());
    
    auto list2_node3 = std::make_unique<ListNode>(5, nullptr);
    auto list2_node2 = std::make_unique<ListNode>(3, list2_node3.get());
    auto list2_node1 = std::make_unique<ListNode>(1, list2_node2.get());

    std::vector<ListNode*> sortedMergedLists;
    sortedMergedLists.push_back(list1_node1.get()); // 1
    sortedMergedLists.push_back(list2_node1.get()); // 1
    sortedMergedLists.push_back(list1_node2.get()); // 2
    sortedMergedLists.push_back(list2_node2.get()); // 3
    sortedMergedLists.push_back(list1_node3.get()); // 4
    sortedMergedLists.push_back(list2_node3.get()); // 5
    
    auto pResult = Solution{}.mergeTwoLists(list1_node1.get(), list2_node1.get());
    int indexCounter = 0;

    auto pCurrentNode = pResult;
    while (nullptr != pCurrentNode)
    {
        EXPECT_EQ(sortedMergedLists[indexCounter++]->val, pCurrentNode->val);
        // next iteration
        pCurrentNode = pCurrentNode->next;
    }
}

TEST (SolutionTest, Example3)
{
    auto list1_node2 = std::make_unique<ListNode>(2, nullptr);
    auto list1_node1 = std::make_unique<ListNode>(1, list1_node2.get());


    std::vector<ListNode*> sortedMergedLists;
    sortedMergedLists.push_back(list1_node1.get()); // 1
    sortedMergedLists.push_back(list1_node2.get()); // 2

    
    auto pResult = Solution{}.mergeTwoLists(nullptr, list1_node1.get());
    int indexCounter = 0;

    auto pCurrentNode = pResult;
    while (nullptr != pCurrentNode)
    {
        EXPECT_EQ(sortedMergedLists[indexCounter++]->val, pCurrentNode->val);
        // next iteration
        pCurrentNode = pCurrentNode->next;
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
