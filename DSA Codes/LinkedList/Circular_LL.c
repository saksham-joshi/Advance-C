#define SINGLY_LL

#include "Base_LL.h"

typedef struct
{

    NodePtr_t _head;
    NodePtr_t _tail;
    size_t _len;

} CircularLinkedList ;

typedef CircularLinkedList* CllPtr_t;

inline static void deleteCircularLL( CllPtr_t , NodeData_t );
inline static void destroyCircularLL( CllPtr_t );
inline static CircularLinkedList makeCircularLL( void );

#if IS_NODE_DATA_PRINTABLE
    inline static void printCircularLL( CllPtr_t );
#endif

inline static void pushCircularLL( CllPtr_t , NodeData_t );
inline static void utilDestroyCircularLL( NodePtr_t , NodePtr_t );


/*
    IMPLEMENTATION STARTS FROM HERE .......
*/

inline static void deleteCircularLL( CllPtr_t __obj, NodeData_t __value )
{
    if ( ! __obj->_head ) 
    {
        puts("\n\t\t {{ Empty Linked List ! }}");
        return;
    }

    NodePtr_t iterator = __obj->_head;

    while (iterator->_next != __obj->_head && iterator->_next->_data != __value )    iterator = iterator->_next;

    if (iterator->_next->_data == __value )
    {
        // if value is found and there is only node in the linked list
        if ( __obj->_head == __obj->_tail ) { destroyCircularLL( __obj ); return; }
        
        // if value is found and it is found at head node
        else if ( iterator->_next == __obj->_head)
        {
            NodePtr_t temp = __obj->_head->_next;
            
            free(__obj->_head);

            __obj->_head = temp;
            __obj->_tail->_next = __obj->_head;
        }

        // if value is found and it is found at tail node
        else if ( iterator->_next == __obj->_tail )
        {
            free(__obj->_tail);

            iterator->_next = __obj->_head;

            __obj->_tail = iterator;
        }

        else 
        {
            NodePtr_t temp = iterator->_next;

            iterator->_next = iterator->_next->_next;

            free(temp);
        }

        -- __obj->_len;
    }
    else 
    {
        puts("\n\t {{ Value not found! }}");
    }

}

inline static void destroyCircularLL( CllPtr_t __obj )
{

    if ( ! __obj->_head ) return;

    utilDestroyCircularLL(__obj->_head , __obj->_tail);

    free(__obj->_tail);

    __obj->_head = __obj->_tail = NULL;

    __obj->_len = 0;
    
}

inline static CircularLinkedList makeCircularLL ( void )
{
    CircularLinkedList obj = {0};

    return obj;
}

inline static void peekCircularLL( CllPtr_t __obj)
{
    if ( __obj->_head ) printf("\n ||=|| Head= " FORMAT_SPECIFIER_LINKED_LIST "\t Tail= " FORMAT_SPECIFIER_LINKED_LIST "\t Len= %zu" , __obj->_head->_data , __obj->_tail->_data , __obj->_len );

    else puts("\n ||=|| Head= 0\tTail= 0\t Len=0");
}

#if IS_NODE_DATA_PRINTABLE
    inline static void printCircularLL( CllPtr_t __obj )
    {
        if ( ! __obj->_head ) {
            puts("\n\t\t{{ Empty Circular Linked List! }}");
            return;
        }

        NodePtr_t iterator = __obj->_head;

        printf("\n Circular LL: [ ");

        while(iterator != __obj->_tail )
        {
            printf(FORMAT_SPECIFIER_LINKED_LIST ", " , iterator->_data );
            iterator = iterator->_next;
        }

        printf(FORMAT_SPECIFIER_LINKED_LIST " ]\n" , iterator->_data);

    }
#endif

inline static void pushCircularLL( CllPtr_t __obj , NodeData_t __value)
{
    NodePtr_t temp = (NodePtr_t) malloc (SIZEOF_NODE);

    if ( temp ) temp->_data = __value;

    else
    {
        errno = ENOMEM;
        return;
    }

    if ( __obj->_tail ) __obj->_tail->_next = temp;
    
    else __obj->_head = temp;

    temp->_next = __obj->_head;

    __obj->_tail = temp;

    ++ __obj->_len;

}


inline static void utilDestroyCircularLL( NodePtr_t __node , NodePtr_t __end_node )
{
    if ( __node == __end_node ) return;

    utilDestroyCircularLL( __node->_next , __end_node );

    free(__node);
}



int main(void)
{
    CircularLinkedList obj = makeCircularLL();

    unsigned short int choice;

    while ( 1 )
    {
        printf(
            "\n 1. Push "
            "\n 2. Delete"
            "\n 3. Destroy"
            "\n 4. Print"
            "\n 5. Peek\n\t->_"
        );

        scanf_s("%hu", &choice);

        switch(choice)
        {
            case 1 : pushCircularLL (&obj , getInput("\n ==> Enter the value to push :- ")); break;

            case 2 : deleteCircularLL( &obj , getInput("\n ==> Enter the value to delete :- ")); break;
            
            case 3 : destroyCircularLL(&obj) ; break;

            case 4 : printCircularLL(&obj) ; break;

            case 5 : peekCircularLL(&obj); break;

            default: printf("\n |=| Invalid choice!"); return 0;
        }

        if ( errno ) perror("Caught some error");
        else puts("\n\t |+| Operation done Succesfully |+| \n");
    }

    destroyCircularLL(&obj);

    return 0;
}