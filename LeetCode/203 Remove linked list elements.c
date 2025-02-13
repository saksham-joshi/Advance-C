/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 The description of the question mentioned that we have to return a new head.

 The new head can be either a whole new linked list or another pointer pointing
 to the same list. 

 The below implementation generates a whole new list!
*/ 

typedef struct
{
    struct ListNode *_head;
    struct ListNode *_tail;

} LinkedList;

inline static void pushBackLinkedList(LinkedList *__obj, int __value)
{
    if (!__obj->_head)
    {
        __obj->_head = __obj->_tail = (struct ListNode *)malloc(sizeof(struct ListNode));
    }
    else
    {
        __obj->_tail->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        __obj->_tail = __obj->_tail->next;
    }

    __obj->_tail->val = __value;
    __obj->_tail->next = 0;
}

inline static struct ListNode *removeElements(struct ListNode *__head, int __val)
{
    LinkedList output = {0};

    while (__head)
    {
        if (__head->val != __val) pushBackLinkedList(&output, __head->val);

        __head = __head->next;
    }

    return output._head;
}