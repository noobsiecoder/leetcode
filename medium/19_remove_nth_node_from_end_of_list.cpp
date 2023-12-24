#include <iostream>
#include <cassert>

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime: 3ms; Beats 67.55% of users with C++
// Memory:  11.00MB; Beats 36.40% of users with C++
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *leftNode = dummyNode;
        ListNode *rightNode = head;

        while (n > 0 && rightNode)
        {
            rightNode = rightNode->next;
            --n;
        }

        while (rightNode)
        {
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }

        leftNode->next = leftNode->next->next;

        return dummyNode->next;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = NULL;

    Solution solution;
    ListNode *value = solution.removeNthFromEnd(head, 2);

    int arr[] = {1, 2, 3, 5};
    size_t index = 0;
    while (value)
    {
        assert(value->val == arr[index]);
        ++index;
        value = value->next;
    }

    return 0;
}