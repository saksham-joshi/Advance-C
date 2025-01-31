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


inline static void pushBack(LinkedList* __obj , int __val)
{

    NodePtr_t temp = (NodePtr_t) malloc(sizeof(struct ListNode));
    temp->val = __val;
    temp->next = NULL;

    if( ! __obj->_head)     __obj->_head = temp;

    else                    __obj->_tail->next = temp; 
        
    __obj->_tail = temp;

}

inline static struct ListNode* mergeTwoLists(struct ListNode* __list1, struct ListNode* __list2)
{
    LinkedList output = { 0 };

    while( __list1 || __list2 )
    {
        if ( __list1 && __list2 )
        {
            if (__list1->val < __list2->val)
            {
                pushBack(&output , __list1->val);
                __list1 = __list1->next;
            }
            else
            {
                pushBack(&output , __list2->val);
                __list2 = __list2->next;
            }
        }
        else if( __list1 )
        {
            pushBack(&output , __list1->val);
            __list1 = __list1->next;
        }
        else
        {
            pushBack(&output , __list2->val);
            __list2 = __list2->next;
        }
    }

    return output._head;
}