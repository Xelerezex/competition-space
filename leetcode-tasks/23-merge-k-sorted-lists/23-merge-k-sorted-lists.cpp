#include <gtest/gtest.h>
#include <limits>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0) , next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:

    ListNode* mergeTwoLists(ListNode* pFirst, ListNode* pSecond)
    {
        if (nullptr == pFirst && nullptr == pSecond)
        {
            return nullptr;
        }

        int firstValue = (nullptr != pFirst) ? pFirst->val : std::numeric_limits<int>::max(); // 1000
        int secondValue = (nullptr != pSecond) ? pSecond->val : std::numeric_limits<int>::max();

        // Set first value
        ListNode* pHead = (firstValue < secondValue)
            ? pFirst
            : pSecond;   
        if (firstValue < secondValue)
        {
            pFirst = pFirst->next;
        }
        else
        {
            pSecond = pSecond->next;
        }
        ListNode* pCurrent = pHead;

        while (nullptr != pFirst || nullptr != pSecond)
        {
            firstValue = (nullptr != pFirst) ? pFirst->val : std::numeric_limits<int>::max(); // 100'000
            secondValue = (nullptr != pSecond) ? pSecond->val : std::numeric_limits<int>::max();

            if (firstValue < secondValue)
            {
                pCurrent->next = pFirst;
                pCurrent = pCurrent->next;

                // Next iteration
                pFirst = (nullptr != pFirst) ? pFirst->next : nullptr;
            }
            else
            {
                pCurrent->next = pSecond;
                pCurrent = pCurrent->next;

                // Next iteration
                pSecond = (nullptr != pSecond) ? pSecond->next : nullptr;
            }
        }
        return pHead;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {   
        if (lists.empty())
        {
            return nullptr;
        }
        else if (lists.size() == 1)
        {
            return mergeTwoLists(lists.at(0), nullptr);
        }

        ListNode* pMerged = mergeTwoLists(lists.at(0), lists.at(1));

        for (int index = 2; index < lists.size(); ++index)
        {
            ListNode* pFirst = pMerged;
            ListNode* pSecond = lists.at(index);
            pMerged = mergeTwoLists(pFirst, pSecond);
        }

        return pMerged;                                            
    }
};

TEST (SolutionTest, Example1)
{
    auto node3_1 = std::make_unique<ListNode>(5, nullptr); 
    auto node2_1 = std::make_unique<ListNode>(4, node3_1.get()); 
    auto node1_1 = std::make_unique<ListNode>(1, node2_1.get());
    
    auto node3_2 = std::make_unique<ListNode>(4, nullptr); 
    auto node2_2 = std::make_unique<ListNode>(3, node3_2.get()); 
    auto node1_2 = std::make_unique<ListNode>(1, node2_2.get());

    auto node2_3 = std::make_unique<ListNode>(6, nullptr); 
    auto node1_3 = std::make_unique<ListNode>(2, node2_3.get());

    std::vector<ListNode*> input{ node1_1.get(), node1_2.get(), node1_3.get() };

    auto pResult = Solution{}.mergeKLists(input);
    std::vector<int> result;
    for (; nullptr != pResult; pResult = pResult->next)
    {
        result.push_back(pResult->val);
    }

    std::vector<int> expected{
        1, 1, 2, 3, 4, 4, 5, 6
    };

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example2)
{
    std::vector<ListNode*> input{};

    auto pResult = Solution{}.mergeKLists(input);
    std::vector<int> result;
    std::vector<int> expected;

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example3)
{
    std::vector<ListNode*> input{ nullptr, nullptr };

    auto pResult = Solution{}.mergeKLists(input);
    std::vector<int> result;
    std::vector<int> expected;

    EXPECT_EQ(expected, result);
}

TEST (SolutionTest, Example4)
{
    auto node3_1 = std::make_unique<ListNode>(4, nullptr); 
    auto node2_1 = std::make_unique<ListNode>(2, node3_1.get()); 
    auto node1_1 = std::make_unique<ListNode>(1, node2_1.get());
    
    auto node3_2 = std::make_unique<ListNode>(5, nullptr); 
    auto node2_2 = std::make_unique<ListNode>(3, node3_2.get()); 
    auto node1_2 = std::make_unique<ListNode>(1, node2_2.get());

    auto node2_3 = std::make_unique<ListNode>(6, nullptr); 
    auto node1_3 = std::make_unique<ListNode>(3, node2_3.get());

    std::vector<ListNode*> input{ node1_1.get(), node1_2.get(), node1_3.get() };

    auto pResult = Solution{}.mergeKLists(input);
    std::vector<int> result;
    for (; nullptr != pResult; pResult = pResult->next)
    {
        result.push_back(pResult->val);
    }

    std::vector<int> expected{
        1,1,2,3,3,4,5,6
    };

    EXPECT_EQ(expected, result);
}


TEST (SolutionTest, Example5)
{
    auto node3_1 = std::make_unique<ListNode>(99, nullptr); 
    auto node2_1 = std::make_unique<ListNode>(88, node3_1.get()); 
    auto node1_1 = std::make_unique<ListNode>(7, node2_1.get());

    std::vector<ListNode*> input{ node1_1.get() };

    auto pResult = Solution{}.mergeKLists(input);
    std::vector<int> result;
    for (; nullptr != pResult; pResult = pResult->next)
    {
        result.push_back(pResult->val);
    }

    std::vector<int> expected{
        7, 88, 99
    };

    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
