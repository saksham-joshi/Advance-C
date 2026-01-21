/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if(list1 && list2)
    {
        struct ListNode* output_head;
        
        // assigning output_head
        if(list1->val < list2->val)
        {
            output_head = list1;

            list1 = list1->next;
        }
        else
        {
            output_head = list2;

            list2 = list2->next;
        }

        struct ListNode* output_tail = output_head;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                output_tail->next = list1;

                list1 = list1->next;
            }
            else
            {
                output_tail->next = list2;

                list2 = list2->next;
            }

            output_tail = output_tail->next;
        }

        while(list1)
        {
            output_tail->next = list1;

            list1 = list1->next;

            output_tail = output_tail->next;
        }

        while(list2)
        {
            output_tail->next = list2;

            list2 = list2->next;

            output_tail = output_tail->next;
        }

        return output_head;
    }

    return (list1) ? list1 : list2;
}