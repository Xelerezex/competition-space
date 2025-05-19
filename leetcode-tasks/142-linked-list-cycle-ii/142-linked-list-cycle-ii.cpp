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

class Solution
{
public:

    ListNode* detectCycle(ListNode* head)
    {
        ListNode* pSlow = head;
        ListNode* pFast = head;
        ListNode* pIntersection = nullptr;

        while (nullptr != pFast && nullptr != pFast->next)
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;

            if (pSlow == pFast)
            {
                pIntersection = pSlow;
                break;
            }
        }

        // From head and intersection we try to find start of the loop
        while (nullptr != pIntersection 
            && head != pIntersection
        )
        {
            pIntersection = pIntersection->next;
            head = head->next;
        }

        return pIntersection;
    }

};

TEST (SolutionTest, Example1)
{
    auto node4 = std::make_unique<ListNode>(-4, nullptr);
    auto node3 = std::make_unique<ListNode>(0, node4.get());
    auto node2 = std::make_unique<ListNode>(2, node3.get());
    auto node1 = std::make_unique<ListNode>(3, node2.get());
    node4->next = node2.get();

    const auto result = Solution{}.detectCycle(node1.get());
    const auto expected = node2.get();
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example2)
{
    auto node4 = std::make_unique<ListNode>(-4, nullptr);
    auto node3 = std::make_unique<ListNode>(0, node4.get());
    auto node2 = std::make_unique<ListNode>(2, node3.get());
    auto node1 = std::make_unique<ListNode>(3, node2.get());

    const auto result = Solution{}.detectCycle(node1.get());
    const auto expected = nullptr;
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example3)
{
    auto node2 = std::make_unique<ListNode>(2, nullptr);
    auto node1 = std::make_unique<ListNode>(1, node2.get());
    node2->next = node1.get();

    const auto result = Solution{}.detectCycle(node1.get());
    const auto expected = node1.get();
    EXPECT_EQ(result, expected);
}

TEST (SolutionTest, Example4)
{
    auto node1 = std::make_unique<ListNode>(1, nullptr);
    
    const auto result = Solution{}.detectCycle(node1.get());
    const auto expected = nullptr;
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
