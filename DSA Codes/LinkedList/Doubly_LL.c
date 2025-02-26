#define DOUBLE_LL

#include<stdio.h>
#include "Base_LL.h"

inline NodeData_t getInput(const char* __str)
{
    printf_s("%s", __str);

    NodeData_t value;

    scanf_s("%d", &value);

    return value;
}


inline static void deleteBackNode(DLLptr_t __obj)
{
    if( ! __obj->_len )
    {
        errno = EPERM;
        perror("Cannot perform deletion in empty linked list");
        return;
    }

    else if (__obj->_len == 1) 
    {
        free(__obj->_head);
        __obj->_head = __obj->_tail = NULL;
    }
    else
    {
        __obj->_tail = __obj->_tail->_prev;
        free ( __obj->_tail->_next ) ;
        __obj->_tail->_next = NULL;
    }

    -- __obj->_len;
}

inline static void deleteFrontNode(DLLptr_t __obj)
{

    if ( ! __obj->_len )
    {
        errno = EPERM;
        perror("Cannot perform deletion in empty linked list");
        return;
    }

    else if (__obj->_len == 1) 
    {
        free(__obj->_head);
        __obj->_head = __obj->_tail = NULL;
    }
    else
    {
        __obj->_head = __obj->_head->_next;
        free(__obj->_head->_prev);
        __obj->_head->_prev = NULL;
    }

    -- __obj->_len;
}


inline static void destroyDoublyLinkedList(DLLptr_t __obj)
{
    if(!__obj->_len) return;

    Utility_destroyRecursively(__obj->_head);

    __obj->_head = __obj->_tail = NULL;

    __obj->_len = 0;
}


inline static void peekDoublyLinkedList(DLLptr_t __obj)
{

    if ( __obj->_len ) printf_s("|+| Head= %d"  
                 "\tTail= %d"
                 "\tLen= %llu", (__obj->_head->_data) , (__obj->_tail->_data), __obj->_len );
                 
    else printf_s("|+| Head= NULL\t Tail= NULL\t Len= 0");
}


inline static void printDoublyLinkedList(DLLptr_t __obj)
{
    printf_s ( "\n Doubly Linked List -- ");

    if ( ! __obj->_len ) 
    {
        puts( "[ ]" ) ;
        return ;
    }

    NodePtr_t iterator = __obj->_head;

    printf_s("[ ");

    while( iterator->_next )
    {
        printf_s("%d, " , iterator->_data);
        iterator = iterator->_next;
    }

    printf_s( "%d ]" , iterator->_data);
}


inline static void pushBackNode(DLLptr_t __obj , NodeData_t __value)
{
    NodePtr_t temp = (NodePtr_t) malloc(sizeof(struct Node));

    if ( ! temp )
    {
        errno = ENOMEM;
        perror("Cannot generate new node");
        return;
    }

    temp->_data = __value;
    temp->_next =   NULL;

    if ( ! __obj->_head )
    {
        __obj->_head = __obj->_tail = temp;
        __obj->_head->_prev = NULL;
    }

    else 
    {
        temp->_prev = __obj->_tail;
        __obj->_tail->_next = temp;
        __obj->_tail = temp;
    }

    ++ __obj->_len ;

}

inline static void pushFrontNode(DLLptr_t __obj , NodeData_t __value)
{
    NodePtr_t temp = (NodePtr_t) malloc(sizeof(struct Node));

    if ( ! temp )
    {
        errno = ENOMEM;
        perror("Cannot generate new node");
        return;
    }

    temp->_data = __value;
    temp->_prev = NULL;

    if ( ! __obj->_head )
    {
        temp->_next = NULL;
        __obj->_head = __obj->_tail = temp; 
    }
    else
    {
        temp->_next = __obj->_head;
        __obj->_head = temp;
    }

    ++ __obj->_len;
}

int main(void)
{
    struct DoublyLinkedList obj = makeDoublyLinkedList();

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

            case 5 : destroyDoublyLinkedList(&obj) ; break;

            case 6 : printDoublyLinkedList(&obj) ; break;

            case 7 : peekDoublyLinkedList(&obj); break;

            default: printf_s("\n |=| Invalid choice!"); return 0;
        }

        if ( errno ) errno = 0;
        else puts("\n\t |+| Operation done Succesfully |+| \n");
    }

    destroyDoublyLinkedList(&obj);

    return 0;
}