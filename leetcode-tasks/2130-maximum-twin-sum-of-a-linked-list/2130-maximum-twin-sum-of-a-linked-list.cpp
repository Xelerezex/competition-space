#include <gtest/gtest.h>
#include <stack>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Note: My Solution
class Solution
{
public:

    int pairSum(ListNode* head)
    {
        int maxTwin = 0;

        std::stack<int> storage;

        ListNode* pSlow = head;
        ListNode* pFast = head;

        while (nullptr != pFast && nullptr != pFast->next)
        {
            storage.push(pSlow->val);
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        while (nullptr != pSlow)
        {
            const auto currentSum = pSlow->val + storage.top();
            maxTwin = std::max(currentSum, maxTwin);
            
            storage.pop();
            pSlow = pSlow->next;
        }

        return maxTwin;
    }
};


// NOTE: Just cool solution. Somehow it is slower
/*
class Solution
{
public:

    int pairSum(ListNode* head)
    {
        int maxTwin = 0;

        ListNode* pSlow = head;
        ListNode* pFast = head;

        // Middle of lincked list
        while (nullptr != pFast && pFast != pFast->next)
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        // Reverse right side of list
        ListNode* pNext = nullptr;
        ListNode* pPrevious = nullptr;
        while (nullptr != pSlow)
        {
            pNext = pSlow->next;

            pSlow->next = pPrevious;
            pPrevious = pSlow;

            pSlow = pNext;
        }

        // Find max
        while (nullptr != pPrevious)
        {
            maxTwin = std::max(maxTwin, pPrevious->val + head->val);
            pPrevious = pPrevious->next;
            head = head->next; 
        }

        return maxTwin;
    }
};
*/

TEST (SolutionTest, Example1)
{
    auto node4 = std::make_unique<ListNode>(1, nullptr);
    auto node3 = std::make_unique<ListNode>(2, node4.get());
    auto node2 = std::make_unique<ListNode>(4, node3.get());
    auto node1 = std::make_unique<ListNode>(5, node2.get());

    const auto result = Solution{}.pairSum(node1.get());
    const auto expected = 6;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example2)
{
    auto node4 = std::make_unique<ListNode>(3, nullptr);
    auto node3 = std::make_unique<ListNode>(2, node4.get());
    auto node2 = std::make_unique<ListNode>(2, node3.get());
    auto node1 = std::make_unique<ListNode>(4, node2.get());

    const auto result = Solution{}.pairSum(node1.get());
    const auto expected = 7;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example3)
{
    auto node2 = std::make_unique<ListNode>(100'000, nullptr);
    auto node1 = std::make_unique<ListNode>(1, node2.get());

    const auto result = Solution{}.pairSum(node1.get());
    const auto expected = 100'001;
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
