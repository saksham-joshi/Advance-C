/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct
{
    struct ListNode *_head;
    struct ListNode *_tail;

} LinkedList;

inline static void pushBackLinkedList(LinkedList *__obj, struct ListNode *__node)
{
    if (!__obj->_head)
        __obj->_head = __obj->_tail = __node;

    else
    {
        __obj->_tail->next = __node;
        __obj->_tail = __node;
    }
}

inline static struct ListNode *removeElements(struct ListNode *__head, int __val)
{
    LinkedList output = {0};

    while ( __head )
    {
        if ( __head->val != __val ) pushBackLinkedList(&output, __head);

        __head = __head->next;
    }

    if ( output._head ) output._tail->next = 0;

    return output._head;
}