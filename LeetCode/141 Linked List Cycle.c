/*

inline static bool hasCycle(struct ListNode *__head)
{
    for(unsigned int i = 0 ; i <= 10000u ; ++i , __head = __head->next) if (! __head) return false;

    return true;
}
 
*/
inline static bool hasCycle( struct ListNode *__head )
{
    struct ListNode* slow_ptr = __head;

    struct ListNode* fast_ptr = __head->next;

    while(slow_ptr && fast_ptr)
    {
        if (slow_ptr == fast_ptr) return true;

        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;

        if ( fast_ptr ) fast_ptr = fast_ptr->next;
        else return false;
    }

    return false;
}