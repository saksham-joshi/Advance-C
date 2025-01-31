/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NodePtr_t;

typedef struct
{
    NodePtr_t _head;
    NodePtr_t _tail;

} LinkedList;


inline static void pushBack(LinkedList* __obj , int __val , int *__carry)
{
    __val += *__carry;

    NodePtr_t temp = (NodePtr_t) malloc(sizeof(struct ListNode));
    temp->val = __val % 10;
    temp->next = NULL;

    if( ! __obj->_head)     __obj->_head = temp;

    else                    __obj->_tail->next = temp; 
        
    __obj->_tail = temp;

    *__carry = ( __val / 10 ) % 10;

}

inline static struct ListNode* addTwoNumbers(struct ListNode* __l1, struct ListNode* __l2)
{
    int carry = 0;

    LinkedList output = {0};

    while(  __l1 || __l2)
    {

        if ( __l1 && __l2 )
        {
            pushBack(&output , __l1->val + __l2->val , &carry);
            __l1 = __l1->next;
            __l2 = __l2->next;
        }
        else if ( __l1 )
        {
            pushBack(&output , __l1->val , &carry);
            __l1 = __l1->next;
        }
        else 
        {
            pushBack(&output , __l2->val , &carry);
            __l2 = __l2->next;
        }
    }

    if (carry) pushBack(&output, 0 , &carry);
    
    return output._head;
}