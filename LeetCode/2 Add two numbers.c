struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* output = l1;

    int carry = 0, sum = 0;

    struct ListNode* it1 = l1;
    struct ListNode* it2 = l2;

    while( it1->next && it2->next )
    {
        sum = it1->val + it2->val + carry;

        it1->val = sum % 10;

        carry = sum / 10;

        it1 = it1->next;
        it2 = it2->next;
    }

    sum = it1->val + it2->val + carry;

    it1->val = sum % 10;

    carry = sum / 10;

    if(it1->next == NULL && it2->next == NULL)
    {
        if(carry)
        {
            // reusing 2nd iterator's node
            it2->val = carry;

            it1->next = it2;

            it1 = it1->next;
        }
    }
    else if( it1->next )
    {
        it1 = it1->next;
         
        while(it1->next && carry)
        {
            sum = it1->val + carry;

            it1->val = sum % 10;

            carry = sum / 10;

            it1 = it1->next;
        }

        sum = it1->val + carry;

        it1->val = sum % 10;

        carry = sum / 10;

        if(carry)
        {
            // reusing 2nd iterator's node
            it2->val = carry;

            it1->next = it2;

            it1 = it1->next;
        }
    }
    else
    {
        it2 = it2->next;

        while(it2->next && carry)
        {
            sum = it2->val + carry;

            it2->val = sum % 10;

            carry = sum / 10;

            it1->next = it2;

            it1 = it1->next;

            it2 = it2->next;
        }

        sum = it2->val + carry;

        it2->val = sum % 10;

        carry = sum / 10;

        it1->next = it2;

        it1 = it1->next;

        if(carry)
        {
            it1->next = (struct ListNode*) malloc(sizeof(struct ListNode));

            it1->next->val = carry;

            it1->next->next = NULL;
        }
    }

    return output;
}