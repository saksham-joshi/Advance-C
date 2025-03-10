#define SINGLY_LL

#include<stdio.h>
#include "Base_LL.h"

inline NodeData_t getInput(const char* __str)
{
    printf_s("%s", __str);

    NodeData_t value;

    scanf_s("%d", &value);

    return value;
}

inline void deleteFrontNode(LLPtr __obj)
{
    if(!__obj->_head)
    {
        errno = EPERM;
        perror("Cannot perform deletion in empty linked list");
        return;
    }

    else if(__obj->_head == __obj->_tail)
    {
        free(__obj->_head);
        __obj->_head = __obj->_tail = NULL;
        __obj->_len = 0;
    }
    else
    {
        NodePtr_t temp = __obj->_head;
        __obj->_head = __obj->_head->_next;
        --__obj->_len;
        free(temp);
    }
}

inline void deleteBackNode(LLPtr __obj)
{
    if(!__obj->_head)
    {
        errno = EPERM;
        perror("Cannot perform deletion in empty linked list");
        return;
    }

    else if(__obj->_head == __obj->_tail)
    {
        free(__obj->_head);
        __obj->_head = __obj->_tail = NULL;
        __obj->_len = 0;
    }
    else
    {
        NodePtr_t iterator = __obj->_head;

        while(iterator->_next != __obj->_tail) iterator = iterator->_next;

        free(iterator->_next);

        __obj->_tail = iterator;

        iterator->_next = NULL;

        --__obj->_len;
    }
}

inline void destroyLinkedList(LLPtr __obj)
{
    if( ! __obj->_head ) return;

    Utility_destroyRecursively(__obj->_head);

    __obj->_head = __obj->_tail = NULL;

    __obj->_len = 0;
}


inline void printLinkedList(LLPtr __obj)
{
    printf("\n Linked List -- ");
        
    if(!__obj->_head)
    {
        puts("[ ]");
        return;
    }

    printf_s("[ ");

    NodePtr_t iterator = __obj->_head;

    while(iterator->_next)
    {
        printf_s("%d, ", iterator->_data);
        iterator = iterator->_next;
    }

    printf_s( "%d ]", iterator->_data);

}


inline void pushBackNode(LLPtr __obj, NodeData_t __value)
{
    NodePtr_t temp = (NodePtr_t) malloc(SIZEOF_NODE);

    if( ! temp ) 
    {
        errno = ENOMEM;
        perror("Cannot generate new node for linked list");
        return;
    }

    temp->_data = __value;
    temp->_next = NULL;

    if ( ! __obj->_head )
    {
        __obj->_head = __obj->_tail = temp;
    }
    else
    {
        __obj->_tail->_next = temp;
        __obj->_tail = temp;
    }

    ++__obj->_len;

}

inline void pushFrontNode(LLPtr __obj , NodeData_t __value)
{
    NodePtr_t temp = (NodePtr_t) malloc(SIZEOF_NODE);

    if( ! temp )
    {
        errno = ENOMEM;
        perror("Cannot generate new node");
        return;
    }

    temp->_next = __obj->_head;

    temp->_data = __value;

    __obj->_head = temp;

    if(!__obj->_head->_next)
    {
        __obj->_tail = __obj->_head;
    }

    ++__obj->_len;
}

inline void peekLinkedList(LLPtr __obj)
{
    printf_s("\n |+| ");

    if( ! __obj->_head ) printf_s("Head= NULL\tTail= NULL\tLen= 0");

    else  printf_s("Head= %d\t Tail= %d\t Len= %llu" , (__obj->_head->_data) , ( __obj->_tail->_data) , __obj->_len );
}

int main(void)
{
    struct LinkedList obj = makeLinkedList();

    unsigned short int choice;

    while ( 1 )
    {
        printf_s(
            "\n 1. Push back"
            "\n 2. Push front"
            "\n 3. Delete back"
            "\n 4. Delete front"
            "\n 5. Destroy"
            "\n 6. Print"
            "\n 7. Peek\n\t->_"
        );

        scanf_s("%hu", &choice);

        switch(choice)
        {
            case 1 : pushBackNode(&obj , getInput("\n ==> Enter the value to push :- ")); break;
            
            case 2 : pushFrontNode(&obj , getInput("\n ==> Enter the value to push :- ")); break;

            case 3 : deleteBackNode(&obj); break;

            case 4 : deleteFrontNode(&obj) ; break;

            case 5 : destroyLinkedList(&obj) ; break;

            case 6 : printLinkedList(&obj) ; break;

            case 7 : peekLinkedList(&obj); break;

            default: printf_s("\n |=| Invalid choice!"); return 0;
        }

        if (errno) errno = 0;
        else puts("\n\t |+| Operation done Succesfully |+| \n");
    }

    destroyLinkedList(&obj);

    return 0;
}