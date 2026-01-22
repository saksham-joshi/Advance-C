void baseRemoveNthFromEnd(struct ListNode* __it, int* __len, const int __target_index, struct ListNode** __target_node)
{
    if(__it->next)
    {
        baseRemoveNthFromEnd(__it->next, __len, __target_index, __target_node);

        if(__it->next == *__target_node)
        {
            __it->next = __it->next->next;
        }
        else
        {
            ++(*__len);

            if(*__len == __target_index) *__target_node = __it;
        }
    }
    else
    {
        if(__target_index == 1)
        {
            *__target_node = __it;
        }
        
        *__len = 1;
        
    }
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if( head-> next )
    {
        int len = 0;

        struct ListNode* target_node = NULL;

        baseRemoveNthFromEnd(head, &len, n, &target_node);

        if(head == target_node)
        {
            head = head->next;
        }

        return head;
    }

    // if there is only one node, then as per question's constraints,
    // we have to delete the current element
    return NULL;
}