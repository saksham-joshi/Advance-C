/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

inline bool hasCycle(struct ListNode* head)
{
    if(!head) return NULL;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;

        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}