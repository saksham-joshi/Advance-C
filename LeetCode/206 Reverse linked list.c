inline static struct ListNode* reverseList(struct ListNode* __head)
{
    if ( ! __head ) return __head;

    struct ListNode* next = NULL;

    while ( __head->next )
    {
        struct ListNode* temp = __head->next;

        __head->next = next;

        next = __head;

        __head = temp;
    }

    __head->next = next;

    return __head; 
}