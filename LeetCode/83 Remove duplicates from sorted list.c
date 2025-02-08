/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
inline static struct ListNode* deleteDuplicates(struct ListNode* __head)
{
    if ( ! __head ) return __head;

    struct ListNode* output = __head;

    int current_value = __head->val;

    while ( __head->next )
    {
        if ( __head->next->val == current_value)
        {
            __head->next = __head->next->next;
            continue;
        }
        
        current_value = __head->next->val;
        __head = __head->next;
        
    }

    return output;
}