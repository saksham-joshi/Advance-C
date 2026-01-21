/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void baseMiddleNode(struct ListNode* __it, int* __len, struct ListNode** __output, int* __expected_middle)
{
    if(__it)
    {
        int cur_len = ++(*__len);

        baseMiddleNode(__it->next, __len, __output, __expected_middle);

        if(*__output) return;

        else if(cur_len == *__expected_middle) 
        {
            *__output = __it;
        }   
    }
    else
    {
        *__expected_middle = (*__len / 2) + 1;
    }
}
struct ListNode* middleNode(struct ListNode* head)
{
    if(head && head->next)
    {
        int len = 0, expected_middle = 0;
        struct ListNode* output = NULL;

        baseMiddleNode(head, &len, &output, &expected_middle);

        return output;
    }

    return head;
}