/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
inline static struct ListNode *getIntersectionNode(struct ListNode *__headA, struct ListNode *__headB)
{
    
    if ( !__headA || !__headB ) return __headA;

    struct ListNode* a_iterator = __headA;
    struct ListNode* b_iterator = __headB;

    while ( a_iterator != b_iterator )
    {

        a_iterator = a_iterator ? a_iterator->next : __headB;
        b_iterator = b_iterator ? b_iterator->next : __headA;
    }

    return a_iterator;
    
}